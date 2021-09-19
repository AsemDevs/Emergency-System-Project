## Graduation Project

### Progress

1- Inital Simulation

**First Simulation Parameters**

1- Load 
- Active Power1 = 150 KW
- Active Power2 = 150 KW
- Active Power3 = 200 KW

2- Grid Source
- Phase-to-phase voltage (Vrms): (13800)*1
- Phase angle of phase A (degrees): 0.071468
- Frequency: 60
- 3-phase short-circuit level at base voltage(VA): 1000e6
- Base voltage (Vrms ph-ph): 13.8e3
- X/R ratio: 7
- Load Flow: Generator-type > Swing

3- Synchronus Machine (Generator)
- Nominal power, line-to-line voltage, frequency [ Pn(VA)  Vn(Vrms)  fn(Hz) ]: [.6e6 2400 60]
- Reactances [ Xd  Xd'  Xd''  Xq  Xq''  Xl ] (pu): [1.56 0.296 0.177 1.06 0.277 0.052]
- Short Circuit
- Open Circuit
- [ Td'  Td''  Tqo'' ] (s): [ 3.7, 0.05, 0.05 ]
- Stator resistance Rs (pu): 0.0036
- Inertia coefficient, friction factor, pole pairs [ H(s)  F(pu)  p()]: [1.07 0 2]
- Initial conditions [ dw(%)  th(deg)  ia,ib,ic(pu)  pha,phb,phc(deg)  Vf(pu) ]: [0 0 0 0 0 0 0 0 1]
- Load Flow: Generator-type > Swing

4- Transformer
- Winding 1 connection (ABC terminals): Yg
- Winding 2 connection (abc terminals): Yg
- Core Type: 3 single-Phase Transformers
- Measurements: None
- Nominal power and frequency  [ Pn(VA) , fn(Hz) ]: [ 5e6 , 60 ]
- Winding 1 parameters [ V1 Ph-Ph(Vrms) , R1(pu) , L1(pu) ]: [13.8e3 0.0015 0.03]
- Winding 2 parameters [ V2 Ph-Ph(Vrms) , R2(pu) , L2(pu) ]: [2.4e3 0.0015 0.03]
- Magnetization resistance  Rm (pu): 200
- Magnetization inductance  Lm (pu): 200


## Progress So Far ##

- Adding Three Generators
- Putting Each Generator in a Subsystem
- Distributing the load to make 500 KW in total
- Connecting the grid and the backup System to the loads
- Putting Measurements Components in Subsystems
- Scopes are measuring 167KW power dissipated from the generator after the grid is down
- before the grid is down the scopes on the grid will measeure the whole load which equals 500KW
- The Load is perfectly Blanced and distributed equally among themselves

0 0 0 | 0 not not not | not
0 0 1 | 0 not not 1   | 0
0 1 0 | 0
0 1 1 | 1
1 0 0 | 0
1 0 1 | 1
1 1 0 | 1
1 1 1 | 0


0 1 1
1 0 1
1 1 0
connect a signal to generator to work for 8 hours
when the 8 hours ends one gen goes off and the other goes on 

Put the logic in the thesis 
The results for all cases should be in a table
Block Diagram

function [y1, y2, y3] = fcn(u1, u2, u3)

if (u2 == 1 && u3 == 1)
    y1 = 0;
    y2 = 1;
    y3 = 1;
    
elseif (u1 == 1 && u3 == 1)
    y1 = 1;
    y2 = 0;
    y3 = 1;
elseif (u1 == 1 && u2 == 1)
    y1 = 1;
    y2 = 1; 
    y3 = 0;

else 
    y1 = 0;
    y2 = 0;
    y3 = 0;
end
end






