%Code to connect to a Freescale MKl25Z
 fclose(MK); clear all; close all; clc;
 
 figure;
 time = now;
 %Serial Connection Settings
MK = serial('COM5', 'BaudRate', 115200, 'DataBits', 8, 'StopBits', 1, 'InputBufferSize', 512);

%Open Serial Connection
fopen(MK);

%Set to Read port continuously
MK.ReadAsyncMode = 'continuous'; 

%Set up Axis
figureHandle = figure('NumberTitle','off',...
    'Name','Voltage Characteristics',...
    'Color',[0 0 0],'Visible','off');

% Set axes
axesHandle = axes('Parent',figureHandle,...
    'YGrid','on',...
    'YColor',[0.9725 0.9725 0.9725],...
    'XGrid','on',...
    'XColor',[0.9725 0.9725 0.9725],...
    'Color',[0 0 0]);


while(1)
    %Read in a linescan from the camera 
    data = fscanf(MK, '%u,');
    
    %Plot Values
    plot(data, 'r', 'LineWidth', 3);
    axis([0 128 0 0.075]);   
    
    %# vertical line
    hx = graph2d.constantline(64);
    changedependvar(hx,'x');
    drawnow;
end


fclose(MK);