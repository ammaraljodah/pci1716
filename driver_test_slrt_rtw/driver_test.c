/*
 * driver_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "driver_test".
 *
 * Model version              : 1.48
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Mon Dec  3 12:06:31 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "driver_test_capi.h"
#include "driver_test.h"
#include "driver_test_private.h"

/* Block signals (auto storage) */
B_driver_test_T driver_test_B;

/* Block states (auto storage) */
DW_driver_test_T driver_test_DW;

/* Real-time model */
RT_MODEL_driver_test_T driver_test_M_;
RT_MODEL_driver_test_T *const driver_test_M = &driver_test_M_;

/* Model output function */
static void driver_test_output(void)
{
  /* S-Function (scblock): '<S1>/S-Function' */
  /* ok to acquire for <S1>/S-Function */
  driver_test_DW.SFunction_IWORK.AcquireOK = 1;

  /* S-Function (scblock): '<S2>/S-Function' */
  /* ok to acquire for <S2>/S-Function */
  driver_test_DW.SFunction_IWORK_m.AcquireOK = 1;

  /* S-Function (advantechpci1716l): '<Root>/S-Function' */

  /* Level2 S-Function Block: '<Root>/S-Function' (advantechpci1716l) */
  {
    SimStruct *rts = driver_test_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }
}

/* Model update function */
static void driver_test_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++driver_test_M->Timing.clockTick0)) {
    ++driver_test_M->Timing.clockTickH0;
  }

  driver_test_M->Timing.t[0] = driver_test_M->Timing.clockTick0 *
    driver_test_M->Timing.stepSize0 + driver_test_M->Timing.clockTickH0 *
    driver_test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void driver_test_initialize(void)
{
  /* Start for S-Function (scblock): '<S1>/S-Function' */

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("S-Function/p1"));
        rl32eSetScope(1, 4, 10000);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("S-Function/p1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 3.0);
        rl32eSetTargetScope(1, 11, 0.0);
        rl32eSetTargetScope(1, 10, 0.0);
        xpceScopeAcqOK(1, &driver_test_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for S-Function (scblock): '<S2>/S-Function' */

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,3)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("S-Function/p1"));
        rl32eSetScope(3, 4, 100000);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        xpceFSScopeSet(3, "data.dat", 0, 512, 0, 536870912);
        rl32eSetScope (3, 10, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("S-Function/p1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        xpceScopeAcqOK(3, &driver_test_DW.SFunction_IWORK_m.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Start for S-Function (advantechpci1716l): '<Root>/S-Function' */
  /* Level2 S-Function Block: '<Root>/S-Function' (advantechpci1716l) */
  {
    SimStruct *rts = driver_test_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
static void driver_test_terminate(void)
{
  /* Terminate for S-Function (advantechpci1716l): '<Root>/S-Function' */
  /* Level2 S-Function Block: '<Root>/S-Function' (advantechpci1716l) */
  {
    SimStruct *rts = driver_test_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  driver_test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  driver_test_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  driver_test_initialize();
}

void MdlTerminate(void)
{
  driver_test_terminate();
}

/* Registration function */
RT_MODEL_driver_test_T *driver_test(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)driver_test_M, 0,
                sizeof(RT_MODEL_driver_test_T));
  rtsiSetSolverName(&driver_test_M->solverInfo,"FixedStepDiscrete");
  driver_test_M->solverInfoPtr = (&driver_test_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = driver_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    driver_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    driver_test_M->Timing.sampleTimes = (&driver_test_M->
      Timing.sampleTimesArray[0]);
    driver_test_M->Timing.offsetTimes = (&driver_test_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    driver_test_M->Timing.sampleTimes[0] = (0.0004);

    /* task offsets */
    driver_test_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(driver_test_M, &driver_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = driver_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    driver_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(driver_test_M, 100.0);
  driver_test_M->Timing.stepSize0 = 0.0004;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    driver_test_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(driver_test_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(driver_test_M->rtwLogInfo, (NULL));
    rtliSetLogT(driver_test_M->rtwLogInfo, "tout");
    rtliSetLogX(driver_test_M->rtwLogInfo, "");
    rtliSetLogXFinal(driver_test_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(driver_test_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(driver_test_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(driver_test_M->rtwLogInfo, 0);
    rtliSetLogDecimation(driver_test_M->rtwLogInfo, 1);
    rtliSetLogY(driver_test_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(driver_test_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(driver_test_M->rtwLogInfo, (NULL));
  }

  driver_test_M->solverInfoPtr = (&driver_test_M->solverInfo);
  driver_test_M->Timing.stepSize = (0.0004);
  rtsiSetFixedStepSize(&driver_test_M->solverInfo, 0.0004);
  rtsiSetSolverMode(&driver_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  driver_test_M->blockIO = ((void *) &driver_test_B);
  (void) memset(((void *) &driver_test_B), 0,
                sizeof(B_driver_test_T));

  /* parameters */
  driver_test_M->defaultParam = ((real_T *)&driver_test_P);

  /* states (dwork) */
  driver_test_M->dwork = ((void *) &driver_test_DW);
  (void) memset((void *)&driver_test_DW, 0,
                sizeof(DW_driver_test_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  driver_test_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &driver_test_M->NonInlinedSFcns.sfcnInfo;
    driver_test_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(driver_test_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &driver_test_M->Sizes.numSampTimes);
    driver_test_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(driver_test_M)
      [0]);
    rtssSetTPtrPtr(sfcnInfo,driver_test_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(driver_test_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(driver_test_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(driver_test_M));
    rtssSetStepSizePtr(sfcnInfo, &driver_test_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(driver_test_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &driver_test_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &driver_test_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &driver_test_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &driver_test_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &driver_test_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &driver_test_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &driver_test_M->solverInfoPtr);
  }

  driver_test_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&driver_test_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    driver_test_M->childSfunctions =
      (&driver_test_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    driver_test_M->childSfunctions[0] =
      (&driver_test_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: driver_test/<Root>/S-Function (advantechpci1716l) */
    {
      SimStruct *rts = driver_test_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = driver_test_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = driver_test_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = driver_test_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &driver_test_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &driver_test_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, driver_test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &driver_test_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &driver_test_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &driver_test_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &driver_test_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &driver_test_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &driver_test_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 6);
        _ssSetPortInfo2ForOutputUnits(rts,
          &driver_test_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        ssSetOutputPortUnit(rts, 4, 0);
        ssSetOutputPortUnit(rts, 5, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &driver_test_B.SFunction_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &driver_test_B.SFunction_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &driver_test_B.SFunction_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &driver_test_B.SFunction_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &driver_test_B.SFunction_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &driver_test_B.SFunction_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "driver_test/S-Function");
      ssSetRTModel(rts,driver_test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &driver_test_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)driver_test_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)driver_test_P.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)driver_test_P.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)driver_test_P.SFunction_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)driver_test_P.SFunction_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &driver_test_DW.SFunction_IWORK_i);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &driver_test_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &driver_test_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &driver_test_DW.SFunction_IWORK_i);
      }

      /* registration */
      advantechpci1716l(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 0);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  driver_test_M->Sizes.numContStates = (0);/* Number of continuous states */
  driver_test_M->Sizes.numY = (0);     /* Number of model outputs */
  driver_test_M->Sizes.numU = (0);     /* Number of model inputs */
  driver_test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  driver_test_M->Sizes.numSampTimes = (1);/* Number of sample times */
  driver_test_M->Sizes.numBlocks = (3);/* Number of blocks */
  driver_test_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  driver_test_M->Sizes.numBlockPrms = (24);/* Sum of parameter "widths" */
  return driver_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
