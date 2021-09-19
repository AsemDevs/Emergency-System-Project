function y = remote(u1,u2) y = u1*u2 end

set_param('testingV7','SimulationCommand','start')
>> set_param('testingV7','SimulationCommand','stop')
>> set_param('testingV7','SimulationCommand','start')
>> set_param('testingV7','SimulationCommand','pause')
>> set_param('testingV7','SimulationCommand','continue')
>> set_param('testingV7','SimulationCommand','stop')