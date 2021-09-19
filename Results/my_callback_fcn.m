t = timer('TimerFcn',@(u1,u2,u3)fcn1(),'StartDelay',2);


t.TimerFcn = @(x,y)disp('Hello World!');
start(t)
