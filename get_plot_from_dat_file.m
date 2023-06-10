close all
clc
SimulinkRealTime.copyFileToHost('DATA.DAT');
matlab_data = SimulinkRealTime.utils.getFileScopeData('DATA.DAT');

% out= matlab_data.data(:,1);
% in= matlab_data.data(:,2);
% t= matlab_data.data(:,3);
% plot(t,in)
%%




x1= matlab_data.data(:,1);
% x2= matlab_data.data(:,2);
t= matlab_data.data(:,2);

figure 
plot(t,x1)
% figure
% plot(t,x2)
