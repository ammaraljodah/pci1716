function pt=driver_testpt
pt = [];

  
pt(1).blockname = 'S-Function';
pt(1).paramname = 'P1';
pt(1).class     = 'vector';
pt(1).nrows     = 1;
pt(1).ncols     = 6;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(1).isStruct  = false;
pt(1).symbol     = 'driver_test_P.SFunction_P1';
pt(1).baseaddr   = '&driver_test_P.SFunction_P1[0]';
pt(1).dtname     = 'real_T';

pt(getlenPT) = pt(1);


  
pt(2).blockname = 'S-Function';
pt(2).paramname = 'P2';
pt(2).class     = 'vector';
pt(2).nrows     = 1;
pt(2).ncols     = 5;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';
pt(2).isStruct  = false;
pt(2).symbol     = 'driver_test_P.SFunction_P2';
pt(2).baseaddr   = '&driver_test_P.SFunction_P2[0]';
pt(2).dtname     = 'real_T';



  
pt(3).blockname = 'S-Function';
pt(3).paramname = 'P3';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';
pt(3).isStruct  = false;
pt(3).symbol     = 'driver_test_P.SFunction_P3';
pt(3).baseaddr   = '&driver_test_P.SFunction_P3';
pt(3).dtname     = 'real_T';



  
pt(4).blockname = 'S-Function';
pt(4).paramname = 'P4';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';
pt(4).isStruct  = false;
pt(4).symbol     = 'driver_test_P.SFunction_P4';
pt(4).baseaddr   = '&driver_test_P.SFunction_P4';
pt(4).dtname     = 'real_T';



  
pt(5).blockname = 'S-Function';
pt(5).paramname = 'P5';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';
pt(5).isStruct  = false;
pt(5).symbol     = 'driver_test_P.SFunction_P5';
pt(5).baseaddr   = '&driver_test_P.SFunction_P5';
pt(5).dtname     = 'real_T';


function len = getlenPT
len = 5;

