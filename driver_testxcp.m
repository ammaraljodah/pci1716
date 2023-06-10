function xcp = driver_testxcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'driver_test';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.0004;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'driver_test_B.SFunction_o1';
    
xcp.signals(2).symbol =  'driver_test_B.SFunction_o2';
    
xcp.signals(3).symbol =  'driver_test_B.SFunction_o3';
    
xcp.signals(4).symbol =  'driver_test_B.SFunction_o4';
    
xcp.signals(5).symbol =  'driver_test_B.SFunction_o5';
    
xcp.signals(6).symbol =  'driver_test_B.SFunction_o6';
         
xcp.parameters(1).symbol = 'driver_test_P.SFunction_P1';
xcp.parameters(1).size   =  6;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&driver_test_P.SFunction_P1[0]';     
         
xcp.parameters(2).symbol = 'driver_test_P.SFunction_P2';
xcp.parameters(2).size   =  5;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&driver_test_P.SFunction_P2[0]';     
         
xcp.parameters(3).symbol = 'driver_test_P.SFunction_P3';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&driver_test_P.SFunction_P3';     
         
xcp.parameters(4).symbol = 'driver_test_P.SFunction_P4';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&driver_test_P.SFunction_P4';     
         
xcp.parameters(5).symbol = 'driver_test_P.SFunction_P5';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&driver_test_P.SFunction_P5';     

function n = getNumParameters
n = 5;

function n = getNumSignals
n = 6;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

