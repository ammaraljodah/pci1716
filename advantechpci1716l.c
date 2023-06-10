#define     S_FUNCTION_LEVEL  2
#undef      S_FUNCTION_NAME
#define     S_FUNCTION_NAME   advantechpci1716l

#include "simstruc.h"

#ifdef  MATLAB_MEX_FILE
#include    "mex.h"
#endif

#ifndef MATLAB_MEX_FILE
#include    <windows.h>
#include    "io_xpcimport.h"
#include    "pci_xpcimport.h"
#include    "util_xpcimport.h"
#include    "xpctarget.h"
#endif

#define NUM_ARGS        5
#define CHANNEL_ARG     ssGetSFcnParam(S,0) // vector of 1:16
#define RANGE_ARG       ssGetSFcnParam(S,1) // vector of {1.25, 2.5, 5, 10, -1.25, -2.5, -5, -10}
#define SAMP_TIME_ARG   ssGetSFcnParam(S,2) // seconds
#define PCI_SLOT_ARG    ssGetSFcnParam(S,3) // integer
#define PCI_BUS_ARG     ssGetSFcnParam(S,4) // integer


#define MAXCOUNT      (65535) //(2^16)-1

#define SAMP_TIME_IND   (0)

#define NUM_I_WORKS     (1) // just to store the base address
#define BASE_ADDR_I_IND (0)

#define NUM_R_WORKS     (0)

static char_T msg[256];

// card required param

#define AI_GAIN_V_Neg5To5          0
#define AI_GAIN_V_Neg2pt5To2pt5    1
#define AI_GAIN_V_Neg1pt25To1pt25  2
#define AI_GAIN_V_Neg10To10        4
#define AI_GAIN_V_0To10            16
#define AI_GAIN_V_0To5             17
#define AI_GAIN_V_0To2pt5          18
#define AI_GAIN_V_0To1pt25         19

#define DR_AI_CHCTL       0x2  //channel control reg
#define DR_AI_MUX         0x4 //mux
#define DR_AI_CONT        0x6 //control reg
#define DR_CLR_FIFO       0x9 // clear fifo
#define DR_CLR_INTER      0x8 // clear interrupt

static void mdlInitializeSizes(SimStruct *S)
{
    size_t i;
    
#ifndef MATLAB_MEX_FILE
#include    "io_xpcimport.c"
#include    "pci_xpcimport.c"
#include    "util_xpcimport.c"
#endif
    
    ssSetNumSFcnParams(S, NUM_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        sprintf(msg, "%d input args expected, %d passed", NUM_ARGS, ssGetSFcnParamsCount(S));
        ssSetErrorStatus(S, msg);
        return;
    }
    
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);
    if( !ssSetNumInputPorts(S, 0) ) return;
    
    if( !ssSetNumOutputPorts(S, (int_T)mxGetN(CHANNEL_ARG)) ) return;
    for (i = 0; i < mxGetN(CHANNEL_ARG); i++) {
        ssSetOutputPortWidth(S, i, 1);
    }
    
    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, NUM_R_WORKS);
    ssSetNumIWork(S, NUM_I_WORKS);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    
    for (i = 0; i < NUM_ARGS; i++)
        ssSetSFcnParamTunable(S, i, 0);
    
    ssSetSimStateCompliance(S, HAS_NO_SIM_STATE);
    
    ssSetOptions(S, SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME | SS_OPTION_EXCEPTION_FREE_CODE);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    if (mxGetPr(SAMP_TIME_ARG)[0] == -1.0) {
        ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
        ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
        ssSetModelReferenceSampleTimeInheritanceRule(S, USE_DEFAULT_FOR_DISCRETE_INHERITANCE);
    } else {
        ssSetSampleTime(S, 0, mxGetPr(SAMP_TIME_ARG)[0]);
        ssSetOffsetTime(S, 0, 0.0);
    }
}

#define MDL_START
static void mdlStart(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE
    int_T  *IWork    = ssGetIWork(S);
    real_T *RWork    = ssGetRWork(S);
    int_T   pciSlot  = (int_T)mxGetPr(PCI_SLOT_ARG)[0];
    int_T   pciBus  = (int_T)mxGetPr(PCI_BUS_ARG)[0];
    size_t  nChans   = mxGetN(CHANNEL_ARG);
    char_T  *deviceName;
    size_t  i;
    int_T   chan, base, deviceId,vendorId,value;
    
    real_T rangevalue;
    
    PCIDeviceInfo pciInfo;
    
    vendorId = 0x13fe; // vender id for Advantec
    deviceId = 0x1716; // device id for PCI-1716
    deviceName = "PCI-1716L"; // PCI-1716 Name
    
    //do auto search
    if (pciSlot < 0) {
        if (rl32eGetPCIInfo((uint16_T) vendorId,
                (uint16_T) deviceId, &pciInfo)) {
            sprintf(msg, "No %s found", deviceName);
            ssSetErrorStatus(S, msg);
            return;
        }
        else
            sprintf(msg, "%s has been found", deviceName);
    }
    // if you know the bus and slot you can specify them, you can use "getxpcpci all" in matlab command window to know the bus and slot number
    else if (rl32eGetPCIInfoAtSlot((uint16_T)vendorId, (uint16_T)deviceId,
            pciSlot + pciBus * 256, &pciInfo)) {
        sprintf(msg, "No %s at bus %d slot %d", deviceName, pciBus, pciSlot);
        ssSetErrorStatus(S, msg);
        return;
    }
    // get the base address, for Advantech cards the I/O base is in location 2
     base = pciInfo.BaseAddress[2];
    // store the base address in the integer work vector
    IWork[BASE_ADDR_I_IND] = base;
    // set the control reg to disable all triggers until finishing the gain setting
    value=0x0;
    rl32eOutpB(base + DR_AI_CONT, value);
    // find the coresponding code for the range
    for (i = 0; i < nChans; i++)
    {
        rangevalue=((real_T)mxGetPr(RANGE_ARG)[i]);
        if (rangevalue==1.25)
            value=AI_GAIN_V_0To1pt25;
        if (rangevalue==2.5)
            value=AI_GAIN_V_0To2pt5;
        if (rangevalue==5)
            value=AI_GAIN_V_0To5;
        if (rangevalue==10)
            value=AI_GAIN_V_0To10;
        if (rangevalue==-1.25)
            value=AI_GAIN_V_Neg1pt25To1pt25;
        if (rangevalue==-2.5)
            value=AI_GAIN_V_Neg2pt5To2pt5;
        if (rangevalue==-5)
            value=AI_GAIN_V_Neg5To5;
        if (rangevalue==-10)
            value=AI_GAIN_V_Neg10To10;
        
        // find the cahnnel
        chan = (uint16_T) mxGetPr(CHANNEL_ARG)[i];
        //Select the chan by the Mux ;
        rl32eOutpW(base + DR_AI_MUX, (chan<<8) | chan);
        //Write the range value to the gain reg
        rl32eOutpB(base + DR_AI_CHCTL, value);
    }
    // set the control reg to software trigger , all other options are disabled, Interrupt is disabled here
    value=0x01;
    rl32eOutpB(base + DR_AI_CONT, value);
    //clear FIFO and Interrupt by writing any value to their address
    rl32eOutpB(base + DR_CLR_FIFO, 0x1);
    rl32eOutpB(base + DR_CLR_INTER, 0x1);
#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE
    real_T *RWork    = ssGetRWork(S);
    int_T  *IWork    = ssGetIWork(S);
    int_T   base     = ssGetIWorkValue(S, BASE_ADDR_I_IND);
    size_t  nChans   = mxGetN(CHANNEL_ARG);
    size_t  i;
    uint16_T status;
    int_T   chan, count;
    real_T  *y,resolution,range;
    
    for (i = 0; i < nChans; i++)
    {
        chan = (uint16_T) mxGetPr(CHANNEL_ARG)[i];
        //select the chan by the mux
        rl32eOutpW(base + DR_AI_MUX, (chan<<8) | chan);
        //clear FIFO by writing any value to their address, Interrupt is disabled so you don't need to clear it here
        rl32eOutpB(base + DR_CLR_FIFO, 0x1);
        //make sure the FIFO is empty before start converting 
        status=0x00;
        while( (status & 0x01)==0x00){status=rl32eInpB(base + 0x07);}
        // start software trigger converting by write any value to the base
        rl32eOutpB(base, 0x1);
        // wait for completion, FIFO is not empty, it it empty just loop until it is not
        status=0x1;
        while( (status & 0x1)){status=rl32eInpB(base + 0x07);}
        //read the count
        count=rl32eInpW(base);
        y = ssGetOutputPortRealSignal(S, i);
        //read the range
        range=(real_T)mxGetPr(RANGE_ARG)[i];
        // if range is +ve then res=range/maxcount, else res=-2*range/maxcount
        if (range>0) {
            resolution=range/((real_T)MAXCOUNT);
            y[0] = (real_T)count * resolution;}
        else {
            resolution=-(range*2.0)/((real_T)MAXCOUNT);
            y[0] = (real_T)count * resolution + range;} // shift it because it is starting from zero
    }
    
#endif
}

static void mdlTerminate(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE
#endif
}

#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif


