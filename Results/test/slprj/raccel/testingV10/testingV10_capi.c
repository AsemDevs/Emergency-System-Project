#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "testingV10_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "testingV10.h"
#include "testingV10_capi.h"
#include "testingV10_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"testingV10/Automatic Transfer Switch/Constant3" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 1 , 1 , TARGET_STRING (
"testingV10/Cooling System/If Action Subsystem" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 2 , 2 , TARGET_STRING (
"testingV10/Cooling System/If Action Subsystem1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 3 , 3 , TARGET_STRING (
"testingV10/Cooling System/If Action Subsystem2" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING ( "testingV10/G1/Fcn1" ) ,
TARGET_STRING ( "Vt" ) , 0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"testingV10/G1/Switch1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6
, 0 , TARGET_STRING ( "testingV10/G2/Fcn1" ) , TARGET_STRING ( "Vt" ) , 0 , 0
, 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING ( "testingV10/G2/Switch1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"testingV10/G3/Fcn1" ) , TARGET_STRING ( "Vt" ) , 0 , 0 , 0 , 0 , 1 } , { 9 ,
0 , TARGET_STRING ( "testingV10/G3/Switch1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"testingV10/Power (3ph, Instantaneous)/pu->V" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"testingV10/Power (3ph, Instantaneous)/Sum4" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 12 , 28 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Switch" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 13 , 29 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Switch1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 14 , 30 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Switch2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 15 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Switch3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 16 , 0 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave A" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave B" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave C" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 19 , 1 , TARGET_STRING (
"testingV10/Cooling System/If Action Subsystem/In1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 20 , 2 , TARGET_STRING (
"testingV10/Cooling System/If Action Subsystem1/In1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 21 , 3 , TARGET_STRING (
"testingV10/Cooling System/If Action Subsystem2/In1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated6/Lookup" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 23 , 0 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated7/Lookup" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 24 , 0 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated8/Lookup" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 25 , 0 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/Gain K" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 26 , 0 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/Integrator" ) , TARGET_STRING (
"Torque" ) , 0 , 0 , 0 , 0 , 1 } , { 27 , 0 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/Product" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 28 , 0 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/CONTROL SYSTEM" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 30 , 0 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/TF1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 31 , 0 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/TF2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 32 , 0 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/ENGINE Td" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
"testingV10/G1 Mesaurements/Power (3ph, Instantaneous)1/pu->V" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 34 , 0 , TARGET_STRING (
"testingV10/G1 Mesaurements/Power (3ph, Instantaneous)1/Sum4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 35 , 0 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/Gain K" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 36 , 0 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/Integrator" ) , TARGET_STRING (
"Torque" ) , 0 , 0 , 0 , 0 , 1 } , { 37 , 0 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/Product" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 38 , 0 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 39 , 0 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/CONTROL SYSTEM" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 40 , 0 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/TF1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 41 , 0 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/TF2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 42 , 0 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/ENGINE Td" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 43 , 0 , TARGET_STRING (
"testingV10/G2 mesaurements/Power (3ph, Instantaneous)1/pu->V" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 44 , 0 , TARGET_STRING (
"testingV10/G2 mesaurements/Power (3ph, Instantaneous)1/Sum4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 45 , 0 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/Gain K" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 46 , 0 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/Integrator" ) , TARGET_STRING (
"Torque" ) , 0 , 0 , 0 , 0 , 1 } , { 47 , 0 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/Product" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 48 , 0 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 49 , 0 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/CONTROL SYSTEM" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 50 , 0 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/TF1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 51 , 0 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/TF2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 52 , 0 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/ENGINE Td" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 53 , 0 , TARGET_STRING (
"testingV10/G3 mesaurements/Power (3ph, Instantaneous)1/pu->V" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 54 , 0 , TARGET_STRING (
"testingV10/G3 mesaurements/Power (3ph, Instantaneous)1/Sum4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 55 , 0 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 1 } , { 56 , 0 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) ,
1 , 0 , 2 , 0 , 1 } , { 57 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/N" ) , TARGET_STRING ( "Vfd" ) ,
0 , 0 , 0 , 0 , 1 } , { 58 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/1_(2H)" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 59 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/1_Pb" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 60 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/F1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 61 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/t" ) , TARGET_STRING ( "theta" )
, 0 , 0 , 0 , 0 , 1 } , { 62 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/units" ) , TARGET_STRING ( "n" )
, 0 , 0 , 0 , 0 , 1 } , { 63 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/units1" ) , TARGET_STRING ( "Pe"
) , 0 , 0 , 0 , 0 , 1 } , { 64 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/units2" ) , TARGET_STRING ( "Te"
) , 0 , 0 , 0 , 0 , 1 } , { 65 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/web1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 66 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/web2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 67 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/web3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 68 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/Rotor angle dtheta" ) ,
TARGET_STRING ( "d_theta (rad)" ) , 0 , 0 , 0 , 0 , 1 } , { 69 , 0 ,
TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/Rotor speed deviation (dw)" ) ,
TARGET_STRING ( "dw" ) , 0 , 0 , 0 , 0 , 1 } , { 70 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/theta" ) , TARGET_STRING (
"d_theta (rad)" ) , 0 , 0 , 0 , 0 , 1 } , { 71 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/Sum" ) , TARGET_STRING ( "n" ) ,
0 , 0 , 0 , 0 , 1 } , { 72 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/Sum2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 73 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/Sum3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 74 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/N" ) , TARGET_STRING ( "Vfd" ) ,
0 , 0 , 0 , 0 , 1 } , { 75 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/1_(2H)" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 76 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/1_Pb" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 77 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/F1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 78 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/t" ) , TARGET_STRING ( "theta" )
, 0 , 0 , 0 , 0 , 1 } , { 79 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/units" ) , TARGET_STRING ( "n" )
, 0 , 0 , 0 , 0 , 1 } , { 80 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/units1" ) , TARGET_STRING ( "Pe"
) , 0 , 0 , 0 , 0 , 1 } , { 81 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/units2" ) , TARGET_STRING ( "Te"
) , 0 , 0 , 0 , 0 , 1 } , { 82 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/web1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 83 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/web2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 84 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/web3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 85 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/Rotor angle dtheta" ) ,
TARGET_STRING ( "d_theta (rad)" ) , 0 , 0 , 0 , 0 , 1 } , { 86 , 0 ,
TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/Rotor speed deviation (dw)" ) ,
TARGET_STRING ( "dw" ) , 0 , 0 , 0 , 0 , 1 } , { 87 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/theta" ) , TARGET_STRING (
"d_theta (rad)" ) , 0 , 0 , 0 , 0 , 1 } , { 88 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/Sum" ) , TARGET_STRING ( "n" ) ,
0 , 0 , 0 , 0 , 1 } , { 89 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/Sum2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 90 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/Sum3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 91 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/N" ) , TARGET_STRING ( "Vfd" ) ,
0 , 0 , 0 , 0 , 1 } , { 92 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/1_(2H)" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 93 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/1_Pb" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 94 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/F1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 95 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/t" ) , TARGET_STRING ( "theta" )
, 0 , 0 , 0 , 0 , 1 } , { 96 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/units" ) , TARGET_STRING ( "n" )
, 0 , 0 , 0 , 0 , 1 } , { 97 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/units1" ) , TARGET_STRING ( "Pe"
) , 0 , 0 , 0 , 0 , 1 } , { 98 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/units2" ) , TARGET_STRING ( "Te"
) , 0 , 0 , 0 , 0 , 1 } , { 99 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/web1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 100 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/web2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 101 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/web3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 102 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/Rotor angle dtheta" ) ,
TARGET_STRING ( "d_theta (rad)" ) , 0 , 0 , 0 , 0 , 1 } , { 103 , 0 ,
TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/Rotor speed deviation (dw)" ) ,
TARGET_STRING ( "dw" ) , 0 , 0 , 0 , 0 , 1 } , { 104 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/theta" ) , TARGET_STRING (
"d_theta (rad)" ) , 0 , 0 , 0 , 0 , 1 } , { 105 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/Sum" ) , TARGET_STRING ( "n" ) ,
0 , 0 , 0 , 0 , 1 } , { 106 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/Sum2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 107 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/Sum3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 108 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker A/Model/Switch3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 109 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker B/Model/Switch3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 110 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker C/Model/Switch3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 111 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Stair Generator/Model/Derivative" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 112 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Stair Generator/Model/Look-Up Table" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 113 , 0 , TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated6/LimitedCounter/Wrap To Zero/FixPt Switch"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 114 , 0 , TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated7/LimitedCounter/Wrap To Zero/FixPt Switch"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 115 , 0 , TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated8/LimitedCounter/Wrap To Zero/FixPt Switch"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 116 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/output formatting"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 1 } , { 117 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/Switch" ) ,
TARGET_STRING ( "ikq2" ) , 0 , 0 , 0 , 0 , 1 } , { 118 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 119 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 1 , 0 , 4 , 0 , 1 } , { 120 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 121 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "Lmsatd" ) , 2 , 0 , 0 , 0 , 1 } , { 122 , 11 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 1 } , { 123 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 1 } , { 124 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/change Iq Id  current signs"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 125 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Product3"
) , TARGET_STRING ( "I(k)" ) , 0 , 0 , 5 , 0 , 1 } , { 126 , 0 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Sum1"
) , TARGET_STRING ( "A" ) , 0 , 0 , 4 , 0 , 1 } , { 127 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 4 , 0 , 1 } , { 128 , 0 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 129 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 130 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch3"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 131 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/abc to qd transformation/1_Vb" )
, TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 132 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/qd to abc transformation/ib" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 133 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/qd to abc transformation/Sum" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 134 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/output formatting"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 1 } , { 135 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/Switch" ) ,
TARGET_STRING ( "ikq2" ) , 0 , 0 , 0 , 0 , 1 } , { 136 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 137 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 1 , 0 , 4 , 0 , 1 } , { 138 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 139 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "Lmsatd" ) , 2 , 0 , 0 , 0 , 1 } , { 140 , 19 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 1 } , { 141 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 1 } , { 142 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/change Iq Id  current signs"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 143 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Product3"
) , TARGET_STRING ( "I(k)" ) , 0 , 0 , 5 , 0 , 1 } , { 144 , 0 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Sum1"
) , TARGET_STRING ( "A" ) , 0 , 0 , 4 , 0 , 1 } , { 145 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 4 , 0 , 1 } , { 146 , 0 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 147 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 148 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch3"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 149 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/abc to qd transformation/1_Vb" )
, TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 150 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/qd to abc transformation/ib" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 151 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/qd to abc transformation/Sum" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 152 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/output formatting"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 1 } , { 153 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/Switch" ) ,
TARGET_STRING ( "ikq2" ) , 0 , 0 , 0 , 0 , 1 } , { 154 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 155 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 1 , 0 , 4 , 0 , 1 } , { 156 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 157 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "Lmsatd" ) , 2 , 0 , 0 , 0 , 1 } , { 158 , 27 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 1 } , { 159 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 1 } , { 160 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/change Iq Id  current signs"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 161 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Product3"
) , TARGET_STRING ( "I(k)" ) , 0 , 0 , 5 , 0 , 1 } , { 162 , 0 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Sum1"
) , TARGET_STRING ( "A" ) , 0 , 0 , 4 , 0 , 1 } , { 163 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 4 , 0 , 1 } , { 164 , 0 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 165 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 166 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch3"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 167 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/abc to qd transformation/1_Vb" )
, TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 168 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/qd to abc transformation/ib" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 169 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/qd to abc transformation/Sum" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 170 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker A/Model/Timer/Derivative" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 171 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker A/Model/Timer/Look-Up Table" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 172 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker B/Model/Timer/Derivative" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 173 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker B/Model/Timer/Look-Up Table" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 174 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker C/Model/Timer/Derivative" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 175 , 0 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker C/Model/Timer/Look-Up Table" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 176 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Gain" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 177 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Gain1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 178 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Gain3" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 179 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"Ve" ) , 0 , 0 , 0 , 0 , 1 } , { 180 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Product" ) , TARGET_STRING ( "Efd"
) , 0 , 0 , 0 , 0 , 1 } , { 181 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/VRmin" ) , TARGET_STRING ( "VR" ) ,
0 , 0 , 0 , 0 , 1 } , { 182 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Sum" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 183 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Sum1" ) , TARGET_STRING ( "Vfe" ) ,
0 , 0 , 0 , 0 , 1 } , { 184 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Sum2" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 185 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Sum4" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 186 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 187 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 188 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 189 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 190 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 191 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product5"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 192 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Sum" ) ,
TARGET_STRING ( "Peo" ) , 0 , 0 , 0 , 0 , 1 } , { 193 , 0 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Sum1" )
, TARGET_STRING ( "Qeo" ) , 0 , 0 , 0 , 0 , 1 } , { 194 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "iqs -ids" ) , 0 , 0 , 6 , 0 , 1 } , { 195 , 0 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/Mult1"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 196 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 197 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/W(1,2)=wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 198 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/W(2,1)=-wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 199 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 200 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_d"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 201 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_q"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 202 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 203 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 204 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/sum1"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 1 } , { 205 , 0 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/sum2"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 1 } , { 206 , 10 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 207 , 10 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 1 } , { 208 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Product1"
) , TARGET_STRING ( "R*Linv" ) , 0 , 0 , 4 , 0 , 1 } , { 209 , 11 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/inversion"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 4 , 0 , 1 } , { 210 , 11 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 211 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 212 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/wbase"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 213 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 214 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 215 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 216 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Gain" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 217 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Gain1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 218 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Gain3" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 219 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"Ve" ) , 0 , 0 , 0 , 0 , 1 } , { 220 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Product" ) , TARGET_STRING ( "Efd"
) , 0 , 0 , 0 , 0 , 1 } , { 221 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/VRmin" ) , TARGET_STRING ( "VR" ) ,
0 , 0 , 0 , 0 , 1 } , { 222 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Sum" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 223 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Sum1" ) , TARGET_STRING ( "Vfe" ) ,
0 , 0 , 0 , 0 , 1 } , { 224 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Sum2" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 225 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Sum4" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 226 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 227 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 228 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 229 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 230 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 231 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product5"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 232 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Sum" ) ,
TARGET_STRING ( "Peo" ) , 0 , 0 , 0 , 0 , 1 } , { 233 , 0 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Sum1" )
, TARGET_STRING ( "Qeo" ) , 0 , 0 , 0 , 0 , 1 } , { 234 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "iqs -ids" ) , 0 , 0 , 6 , 0 , 1 } , { 235 , 0 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/Mult1"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 236 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 237 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/W(1,2)=wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 238 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/W(2,1)=-wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 239 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 240 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_d"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 241 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_q"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 242 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 243 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 244 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/sum1"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 1 } , { 245 , 0 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/sum2"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 1 } , { 246 , 18 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 247 , 18 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 1 } , { 248 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Product1"
) , TARGET_STRING ( "R*Linv" ) , 0 , 0 , 4 , 0 , 1 } , { 249 , 19 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/inversion"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 4 , 0 , 1 } , { 250 , 19 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 251 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 252 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/wbase"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 253 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 254 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 255 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 256 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Gain" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 257 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Gain1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 258 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Gain3" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 259 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"Ve" ) , 0 , 0 , 0 , 0 , 1 } , { 260 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Product" ) , TARGET_STRING ( "Efd"
) , 0 , 0 , 0 , 0 , 1 } , { 261 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/VRmin" ) , TARGET_STRING ( "VR" ) ,
0 , 0 , 0 , 0 , 1 } , { 262 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Sum" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 263 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Sum1" ) , TARGET_STRING ( "Vfe" ) ,
0 , 0 , 0 , 0 , 1 } , { 264 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Sum2" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 265 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Sum4" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 266 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 267 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 268 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 269 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 270 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 271 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Product5"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 272 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Sum" ) ,
TARGET_STRING ( "Peo" ) , 0 , 0 , 0 , 0 , 1 } , { 273 , 0 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Sum1" )
, TARGET_STRING ( "Qeo" ) , 0 , 0 , 0 , 0 , 1 } , { 274 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "iqs -ids" ) , 0 , 0 , 6 , 0 , 1 } , { 275 , 0 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/Mult1"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 276 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 277 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/W(1,2)=wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 278 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/W(2,1)=-wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 279 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 280 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_d"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 281 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_q"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 282 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 283 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 284 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/sum1"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 1 } , { 285 , 0 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/sum2"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 1 } , { 286 , 26 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 287 , 26 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 1 } , { 288 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Product1"
) , TARGET_STRING ( "R*Linv" ) , 0 , 0 , 4 , 0 , 1 } , { 289 , 27 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/inversion"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 4 , 0 , 1 } , { 290 , 27 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 291 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 292 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/wbase"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 293 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 294 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 295 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 296 , 0 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 297 , 0 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 298 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/0.433<In<0.75" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 299 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 300 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 301 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/In>1.0" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 302 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/Gain" ) , TARGET_STRING (
"In" ) , 0 , 0 , 0 , 0 , 1 } , { 303 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/Merge" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 304 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Saturation Vx=Ve*Se[Ve]/Product" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 305 , 0 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Transient Gain Reduction (Tc.s+1)//(Tb.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 306 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vaminmax/Gain1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 307 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vaminmax/Gain2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 308 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 309 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vaminmax/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 310 , 0 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/Delta angle/Radians to Degrees/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 311 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Abs"
) , TARGET_STRING ( "Phisat" ) , 0 , 0 , 0 , 0 , 1 } , { 312 , 11 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lmd"
) , TARGET_STRING ( "Lmsatd" ) , 0 , 0 , 0 , 0 , 1 } , { 313 , 11 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "Ifdsat" ) , 0 , 0 , 0 , 0 , 1 } , { 314 , 8 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 315 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 316 , 10 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Abs"
) , TARGET_STRING ( "Phisat" ) , 0 , 0 , 0 , 0 , 1 } , { 317 , 10 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq"
) , TARGET_STRING ( "Lmsatq" ) , 0 , 0 , 0 , 0 , 1 } , { 318 , 10 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "Ifqsat" ) , 0 , 0 , 0 , 0 , 1 } , { 319 , 9 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 320 , 10 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 321 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/Update Lmd rows[2,3,4] col[2,3,4]"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 322 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/Update Lmq rows[1,5, (6)] col[1,5, (6)] "
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 323 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 324 , 0 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 325 , 0 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 326 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/0.433<In<0.75" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 327 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 328 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 329 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/In>1.0" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 330 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/Gain" ) , TARGET_STRING (
"In" ) , 0 , 0 , 0 , 0 , 1 } , { 331 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/Merge" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 332 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Saturation Vx=Ve*Se[Ve]/Product" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 333 , 0 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Transient Gain Reduction (Tc.s+1)//(Tb.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 334 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vaminmax/Gain1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 335 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vaminmax/Gain2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 336 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 337 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vaminmax/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 338 , 0 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/Delta angle/Radians to Degrees/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 339 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Abs"
) , TARGET_STRING ( "Phisat" ) , 0 , 0 , 0 , 0 , 1 } , { 340 , 19 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lmd"
) , TARGET_STRING ( "Lmsatd" ) , 0 , 0 , 0 , 0 , 1 } , { 341 , 19 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "Ifdsat" ) , 0 , 0 , 0 , 0 , 1 } , { 342 , 16 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 343 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 344 , 18 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Abs"
) , TARGET_STRING ( "Phisat" ) , 0 , 0 , 0 , 0 , 1 } , { 345 , 18 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq"
) , TARGET_STRING ( "Lmsatq" ) , 0 , 0 , 0 , 0 , 1 } , { 346 , 18 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "Ifqsat" ) , 0 , 0 , 0 , 0 , 1 } , { 347 , 17 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 348 , 18 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 349 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/Update Lmd rows[2,3,4] col[2,3,4]"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 350 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/Update Lmq rows[1,5, (6)] col[1,5, (6)] "
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 351 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 352 , 0 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 353 , 0 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 354 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/0.433<In<0.75" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 355 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 356 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 357 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/In>1.0" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 358 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/Gain" ) , TARGET_STRING (
"In" ) , 0 , 0 , 0 , 0 , 1 } , { 359 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/Merge" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 360 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Saturation Vx=Ve*Se[Ve]/Product" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 361 , 0 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Transient Gain Reduction (Tc.s+1)//(Tb.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 362 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vaminmax/Gain1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 363 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vaminmax/Gain2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 364 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 365 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vaminmax/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 366 , 0 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/Delta angle/Radians to Degrees/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 367 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Abs"
) , TARGET_STRING ( "Phisat" ) , 0 , 0 , 0 , 0 , 1 } , { 368 , 27 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lmd"
) , TARGET_STRING ( "Lmsatd" ) , 0 , 0 , 0 , 0 , 1 } , { 369 , 27 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "Ifdsat" ) , 0 , 0 , 0 , 0 , 1 } , { 370 , 24 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 371 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 372 , 26 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Abs"
) , TARGET_STRING ( "Phisat" ) , 0 , 0 , 0 , 0 , 1 } , { 373 , 26 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq"
) , TARGET_STRING ( "Lmsatq" ) , 0 , 0 , 0 , 0 , 1 } , { 374 , 26 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "Ifqsat" ) , 0 , 0 , 0 , 0 , 1 } , { 375 , 25 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 376 , 26 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 377 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/Update Lmd rows[2,3,4] col[2,3,4]"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 378 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/Update Lmq rows[1,5, (6)] col[1,5, (6)] "
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 379 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 380 , 0 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/0.433<In<0.75/Math Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 381 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 382 , 0 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 383 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/Math Function3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 384 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/Sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 385 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 386 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 387 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 388 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/1//Ll_d"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 389 , 11 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/Product4"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 1 } , { 390 , 11 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/sum2"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 1 } , { 391 , 10 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/Math Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 392 , 10 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 393 , 10 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 394 , 10 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 395 , 10 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 396 , 10 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/1//Ll_q"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 397 , 10 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/Product3"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 1 } , { 398 , 10 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/sum1"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 1 } , { 399 , 0 ,
TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/0.433<In<0.75/Math Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 400 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 401 , 0 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 402 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/Math Function3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 403 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/Sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 404 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 405 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 406 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 407 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/1//Ll_d"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 408 , 19 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/Product4"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 1 } , { 409 , 19 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/sum2"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 1 } , { 410 , 18 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/Math Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 411 , 18 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 412 , 18 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 413 , 18 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 414 , 18 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 415 , 18 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/1//Ll_q"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 416 , 18 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/Product3"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 1 } , { 417 , 18 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/sum1"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 1 } , { 418 , 0 ,
TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/0.433<In<0.75/Math Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 419 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 420 , 0 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 421 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/Math Function3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 422 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/Sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 423 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 424 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 425 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 426 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/1//Ll_d"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 1 } , { 427 , 27 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/Product4"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 1 } , { 428 , 27 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/sum2"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 1 } , { 429 , 26 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/Math Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 430 , 26 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 431 , 26 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 432 , 26 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 433 , 26 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 434 , 26 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/1//Ll_q"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 435 , 26 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/Product3"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 1 } , { 436 , 26 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/sum1"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 437 , TARGET_STRING (
"testingV10/600 kV   1000 MVA" ) , TARGET_STRING ( "Frequency" ) , 0 , 0 , 0
} , { 438 , TARGET_STRING ( "testingV10/Three-Phase Breaker" ) ,
TARGET_STRING ( "SwitchA" ) , 0 , 0 , 0 } , { 439 , TARGET_STRING (
"testingV10/Three-Phase Breaker" ) , TARGET_STRING ( "SwitchB" ) , 0 , 0 , 0
} , { 440 , TARGET_STRING ( "testingV10/Three-Phase Breaker" ) ,
TARGET_STRING ( "SwitchC" ) , 0 , 0 , 0 } , { 441 , TARGET_STRING (
"testingV10/Automatic Transfer Switch/Constant3" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 442 , TARGET_STRING (
"testingV10/Automatic Transfer Switch/Constant4" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 443 , TARGET_STRING (
"testingV10/Automatic Transfer Switch/Constant5" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 444 , TARGET_STRING (
"testingV10/Automatic Transfer Switch/Switch1" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 445 , TARGET_STRING ( "testingV10/B1/Kv" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 446 , TARGET_STRING (
"testingV10/B1/Kv1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 447 ,
TARGET_STRING ( "testingV10/B2/Kv" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 }
, { 448 , TARGET_STRING ( "testingV10/B2/Kv1" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 449 , TARGET_STRING ( "testingV10/B4/Kv" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 450 , TARGET_STRING ( "testingV10/B4/Kv1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 451 , TARGET_STRING (
"testingV10/B5/Kv" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 452 ,
TARGET_STRING ( "testingV10/B5/Kv1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 453 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated6" ) ,
TARGET_STRING ( "OutValues" ) , 0 , 7 , 0 } , { 454 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated6" ) ,
TARGET_STRING ( "TimeValues" ) , 0 , 7 , 0 } , { 455 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated7" ) ,
TARGET_STRING ( "OutValues" ) , 0 , 7 , 0 } , { 456 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated7" ) ,
TARGET_STRING ( "TimeValues" ) , 0 , 7 , 0 } , { 457 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated8" ) ,
TARGET_STRING ( "OutValues" ) , 0 , 7 , 0 } , { 458 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated8" ) ,
TARGET_STRING ( "TimeValues" ) , 0 , 7 , 0 } , { 459 , TARGET_STRING (
"testingV10/Cooling System/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 460 , TARGET_STRING ( "testingV10/Cooling System/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 461 , TARGET_STRING (
"testingV10/Cooling System/Constant6" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 462 , TARGET_STRING ( "testingV10/Cooling System/Switch2" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 463 , TARGET_STRING (
"testingV10/Cooling System/Switch3" ) , TARGET_STRING ( "Threshold" ) , 0 , 0
, 0 } , { 464 , TARGET_STRING ( "testingV10/Cooling System/Switch4" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 465 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor" ) , TARGET_STRING ( "K" ) , 0 , 0 , 0
} , { 466 , TARGET_STRING ( "testingV10/G1/Diesel Engine Governor" ) ,
TARGET_STRING ( "Td" ) , 0 , 0 , 0 } , { 467 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor" ) , TARGET_STRING ( "Pm0" ) , 0 , 0 ,
0 } , { 468 , TARGET_STRING ( "testingV10/G1/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 469 , TARGET_STRING ( "testingV10/G1/Constant1" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 470 , TARGET_STRING (
"testingV10/G1/Vtref (pu) " ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
471 , TARGET_STRING ( "testingV10/G1/Switch1" ) , TARGET_STRING ( "Threshold"
) , 0 , 0 , 0 } , { 472 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor" ) , TARGET_STRING ( "K" ) , 0 , 0 , 0
} , { 473 , TARGET_STRING ( "testingV10/G2/Diesel Engine Governor" ) ,
TARGET_STRING ( "Td" ) , 0 , 0 , 0 } , { 474 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor" ) , TARGET_STRING ( "Pm0" ) , 0 , 0 ,
0 } , { 475 , TARGET_STRING ( "testingV10/G2/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 476 , TARGET_STRING ( "testingV10/G2/Constant1" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 477 , TARGET_STRING (
"testingV10/G2/Vtref (pu) " ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
478 , TARGET_STRING ( "testingV10/G2/Switch1" ) , TARGET_STRING ( "Threshold"
) , 0 , 0 , 0 } , { 479 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor" ) , TARGET_STRING ( "K" ) , 0 , 0 , 0
} , { 480 , TARGET_STRING ( "testingV10/G3/Diesel Engine Governor" ) ,
TARGET_STRING ( "Td" ) , 0 , 0 , 0 } , { 481 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor" ) , TARGET_STRING ( "Pm0" ) , 0 , 0 ,
0 } , { 482 , TARGET_STRING ( "testingV10/G3/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 483 , TARGET_STRING ( "testingV10/G3/Constant1" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 484 , TARGET_STRING (
"testingV10/G3/Vtref (pu) " ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
485 , TARGET_STRING ( "testingV10/G3/Switch1" ) , TARGET_STRING ( "Threshold"
) , 0 , 0 , 0 } , { 486 , TARGET_STRING (
"testingV10/Power (3ph, Instantaneous)/pu->V" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 487 , TARGET_STRING ( "testingV10/Three-Phase Breaker/C4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 488 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Constant5" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 489 , TARGET_STRING ( "testingV10/Three-Phase Breaker/Switch" )
, TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 490 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Switch1" ) , TARGET_STRING ( "Threshold" ) ,
0 , 0 , 0 } , { 491 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Switch2" ) , TARGET_STRING ( "Threshold" ) ,
0 , 0 , 0 } , { 492 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Switch3" ) , TARGET_STRING ( "Threshold" ) ,
0 , 0 , 0 } , { 493 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave A" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 494 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave A" ) , TARGET_STRING ( "Bias" )
, 0 , 0 , 0 } , { 495 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave A" ) , TARGET_STRING ( "Phase"
) , 0 , 0 , 0 } , { 496 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave B" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 497 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave B" ) , TARGET_STRING ( "Bias" )
, 0 , 0 , 0 } , { 498 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave B" ) , TARGET_STRING ( "Phase"
) , 0 , 0 , 0 } , { 499 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave C" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 500 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave C" ) , TARGET_STRING ( "Bias" )
, 0 , 0 , 0 } , { 501 , TARGET_STRING (
"testingV10/600 kV   1000 MVA/Model/Sine Wave C" ) , TARGET_STRING ( "Phase"
) , 0 , 0 , 0 } , { 502 , TARGET_STRING (
"testingV10/Cooling System/If Action Subsystem/u1" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 503 , TARGET_STRING (
"testingV10/Cooling System/If Action Subsystem1/u2" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 504 , TARGET_STRING (
"testingV10/Cooling System/If Action Subsystem2/u3" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 505 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated6/LimitedCounter" )
, TARGET_STRING ( "uplimit" ) , 1 , 0 , 0 } , { 506 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated6/Sample Time Math"
) , TARGET_STRING ( "WtEt" ) , 0 , 0 , 0 } , { 507 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated7/LimitedCounter" )
, TARGET_STRING ( "uplimit" ) , 1 , 0 , 0 } , { 508 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated7/Sample Time Math"
) , TARGET_STRING ( "WtEt" ) , 0 , 0 , 0 } , { 509 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated8/LimitedCounter" )
, TARGET_STRING ( "uplimit" ) , 1 , 0 , 0 } , { 510 , TARGET_STRING (
"testingV10/Cooling System/Repeating Sequence Interpolated8/Sample Time Math"
) , TARGET_STRING ( "WtEt" ) , 0 , 0 , 0 } , { 511 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/Integrator" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 512 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/Integrator" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 513 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/CONTROL SYSTEM" ) , TARGET_STRING ( "A"
) , 0 , 6 , 0 } , { 514 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/CONTROL SYSTEM" ) , TARGET_STRING ( "C"
) , 0 , 8 , 0 } , { 515 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/TF1" ) , TARGET_STRING ( "A" ) , 0 , 0
, 0 } , { 516 , TARGET_STRING ( "testingV10/G1/Diesel Engine Governor/TF1" )
, TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 517 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/TF1" ) , TARGET_STRING ( "D" ) , 0 , 0
, 0 } , { 518 , TARGET_STRING ( "testingV10/G1/Diesel Engine Governor/TF2" )
, TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 519 , TARGET_STRING (
"testingV10/G1/Diesel Engine Governor/TF2" ) , TARGET_STRING ( "C" ) , 0 , 0
, 0 } , { 520 , TARGET_STRING (
"testingV10/G1 Mesaurements/Power (3ph, Instantaneous)1/pu->V" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 521 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/Integrator" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 522 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/Integrator" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 523 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/CONTROL SYSTEM" ) , TARGET_STRING ( "A"
) , 0 , 6 , 0 } , { 524 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/CONTROL SYSTEM" ) , TARGET_STRING ( "C"
) , 0 , 8 , 0 } , { 525 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/TF1" ) , TARGET_STRING ( "A" ) , 0 , 0
, 0 } , { 526 , TARGET_STRING ( "testingV10/G2/Diesel Engine Governor/TF1" )
, TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 527 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/TF1" ) , TARGET_STRING ( "D" ) , 0 , 0
, 0 } , { 528 , TARGET_STRING ( "testingV10/G2/Diesel Engine Governor/TF2" )
, TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 529 , TARGET_STRING (
"testingV10/G2/Diesel Engine Governor/TF2" ) , TARGET_STRING ( "C" ) , 0 , 0
, 0 } , { 530 , TARGET_STRING (
"testingV10/G2 mesaurements/Power (3ph, Instantaneous)1/pu->V" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 531 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/Integrator" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 532 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/Integrator" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 533 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/CONTROL SYSTEM" ) , TARGET_STRING ( "A"
) , 0 , 6 , 0 } , { 534 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/CONTROL SYSTEM" ) , TARGET_STRING ( "C"
) , 0 , 8 , 0 } , { 535 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/TF1" ) , TARGET_STRING ( "A" ) , 0 , 0
, 0 } , { 536 , TARGET_STRING ( "testingV10/G3/Diesel Engine Governor/TF1" )
, TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 537 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/TF1" ) , TARGET_STRING ( "D" ) , 0 , 0
, 0 } , { 538 , TARGET_STRING ( "testingV10/G3/Diesel Engine Governor/TF2" )
, TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 539 , TARGET_STRING (
"testingV10/G3/Diesel Engine Governor/TF2" ) , TARGET_STRING ( "C" ) , 0 , 0
, 0 } , { 540 , TARGET_STRING (
"testingV10/G3 mesaurements/Power (3ph, Instantaneous)1/pu->V" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 541 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P1" )
, 0 , 9 , 0 } , { 542 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P2" )
, 0 , 10 , 0 } , { 543 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P3" )
, 0 , 11 , 0 } , { 544 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P4" )
, 0 , 12 , 0 } , { 545 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P5" )
, 0 , 13 , 0 } , { 546 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P6" )
, 0 , 14 , 0 } , { 547 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P7" )
, 0 , 7 , 0 } , { 548 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P8" )
, 0 , 14 , 0 } , { 549 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P9" )
, 0 , 0 , 0 } , { 550 , TARGET_STRING (
"testingV10/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P10"
) , 0 , 0 , 0 } , { 551 , TARGET_STRING (
"testingV10/B1/Model/I A:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 552 , TARGET_STRING (
"testingV10/B1/Model/I B:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 553 , TARGET_STRING (
"testingV10/B1/Model/I C:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 554 , TARGET_STRING (
"testingV10/B1/Model/U A:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 555 , TARGET_STRING (
"testingV10/B1/Model/U B:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 556 , TARGET_STRING (
"testingV10/B1/Model/U C:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 557 , TARGET_STRING (
"testingV10/B2/Model/I A:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 558 , TARGET_STRING (
"testingV10/B2/Model/I B:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 559 , TARGET_STRING (
"testingV10/B2/Model/I C:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 560 , TARGET_STRING (
"testingV10/B2/Model/U A:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 561 , TARGET_STRING (
"testingV10/B2/Model/U B:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 562 , TARGET_STRING (
"testingV10/B2/Model/U C:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 563 , TARGET_STRING (
"testingV10/B4/Model/I A:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 564 , TARGET_STRING (
"testingV10/B4/Model/I B:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 565 , TARGET_STRING (
"testingV10/B4/Model/I C:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 566 , TARGET_STRING (
"testingV10/B4/Model/U A:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 567 , TARGET_STRING (
"testingV10/B4/Model/U B:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 568 , TARGET_STRING (
"testingV10/B4/Model/U C:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 569 , TARGET_STRING (
"testingV10/B5/Model/I A:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 570 , TARGET_STRING (
"testingV10/B5/Model/I B:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 571 , TARGET_STRING (
"testingV10/B5/Model/I C:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 572 , TARGET_STRING (
"testingV10/B5/Model/U A:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 573 , TARGET_STRING (
"testingV10/B5/Model/U B:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 574 , TARGET_STRING (
"testingV10/B5/Model/U C:/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 575 , TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated6/LimitedCounter/Output"
) , TARGET_STRING ( "InitialCondition" ) , 1 , 0 , 0 } , { 576 ,
TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated7/LimitedCounter/Output"
) , TARGET_STRING ( "InitialCondition" ) , 1 , 0 , 0 } , { 577 ,
TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated8/LimitedCounter/Output"
) , TARGET_STRING ( "InitialCondition" ) , 1 , 0 , 0 } , { 578 ,
TARGET_STRING ( "testingV10/G1/EXCITATION/AC1A/AC1A" ) , TARGET_STRING ( "Kd"
) , 0 , 0 , 0 } , { 579 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A" ) , TARGET_STRING ( "Kc" ) , 0 , 0 , 0 }
, { 580 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/[ Vkd =0 Vkq1=0  Vkq2=0 ]" ) ,
TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 581 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/N" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 582 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/nom. speed" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 583 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/1_(2H)" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 584 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/1_Pb" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 585 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/F1" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 586 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/t" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 587 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/units" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 588 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/units1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 589 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/units2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 590 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/web1" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 591 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/web2" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 592 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/web3" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 593 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/Rotor angle dtheta" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 594 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/Rotor speed deviation (dw)" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 595 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Mechanical model/theta" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 596 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A" ) , TARGET_STRING ( "Kd" ) , 0 , 0 , 0 }
, { 597 , TARGET_STRING ( "testingV10/G2/EXCITATION/AC1A/AC1A" ) ,
TARGET_STRING ( "Kc" ) , 0 , 0 , 0 } , { 598 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/[ Vkd =0 Vkq1=0  Vkq2=0 ]" ) ,
TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 599 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/N" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 600 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/nom. speed" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 601 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/1_(2H)" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 602 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/1_Pb" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 603 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/F1" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 604 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/t" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 605 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/units" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 606 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/units1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 607 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/units2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 608 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/web1" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 609 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/web2" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 610 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/web3" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 611 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/Rotor angle dtheta" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 612 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/Rotor speed deviation (dw)" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 613 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Mechanical model/theta" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 614 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A" ) , TARGET_STRING ( "Kd" ) , 0 , 0 , 0 }
, { 615 , TARGET_STRING ( "testingV10/G3/EXCITATION/AC1A/AC1A" ) ,
TARGET_STRING ( "Kc" ) , 0 , 0 , 0 } , { 616 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/[ Vkd =0 Vkq1=0  Vkq2=0 ]" ) ,
TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 617 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/N" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 618 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/nom. speed" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 619 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/1_(2H)" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 620 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/1_Pb" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 621 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/F1" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 622 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/t" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 623 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/units" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 624 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/units1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 625 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/units2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 626 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/web1" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 627 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/web2" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 628 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/web3" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 629 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/Rotor angle dtheta" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 630 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/Rotor speed deviation (dw)" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 631 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Mechanical model/theta" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 632 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker A/Model/C4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 633 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker A/Model/Switch3" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 634 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker B/Model/C4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 635 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker B/Model/Switch3" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 636 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker C/Model/C4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 637 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker C/Model/Switch3" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 638 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Stair Generator/Model/Hit  Crossing" ) ,
TARGET_STRING ( "HitCrossingOffset" ) , 0 , 0 , 0 } , { 639 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Stair Generator/Model/Look-Up Table" ) ,
TARGET_STRING ( "InputValues" ) , 0 , 10 , 0 } , { 640 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Stair Generator/Model/Look-Up Table" ) ,
TARGET_STRING ( "Table" ) , 0 , 10 , 0 } , { 641 , TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated6/LimitedCounter/Increment Real World/FixPt Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 642 , TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated6/LimitedCounter/Wrap To Zero/Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 643 , TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated7/LimitedCounter/Increment Real World/FixPt Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 644 , TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated7/LimitedCounter/Wrap To Zero/Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 645 , TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated8/LimitedCounter/Increment Real World/FixPt Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 646 , TARGET_STRING (
 "testingV10/Cooling System/Repeating Sequence Interpolated8/LimitedCounter/Wrap To Zero/Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 647 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/Constant1"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 648 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 649 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/output formatting"
) , TARGET_STRING ( "Gain" ) , 0 , 15 , 0 } , { 650 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 651 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 652 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 653 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 654 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 655 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant6"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 656 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant8"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 657 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Laqd_nosat"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 658 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Lmqd_nosat"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 659 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/change Iq Id  current signs"
) , TARGET_STRING ( "Gain" ) , 0 , 16 , 0 } , { 660 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 661 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 662 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch2"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 663 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch3"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 664 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/abc to qd transformation/1_Vb" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 665 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/qd to abc transformation/ib" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 666 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/Constant1"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 667 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 668 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/output formatting"
) , TARGET_STRING ( "Gain" ) , 0 , 15 , 0 } , { 669 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 670 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 671 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 672 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 673 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 674 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant6"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 675 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant8"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 676 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Laqd_nosat"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 677 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Lmqd_nosat"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 678 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/change Iq Id  current signs"
) , TARGET_STRING ( "Gain" ) , 0 , 16 , 0 } , { 679 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 680 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 681 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch2"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 682 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch3"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 683 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/abc to qd transformation/1_Vb" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 684 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/qd to abc transformation/ib" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 685 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/Constant1"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 686 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 687 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/output formatting"
) , TARGET_STRING ( "Gain" ) , 0 , 15 , 0 } , { 688 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 689 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 690 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 691 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 692 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 693 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant6"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 694 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Constant8"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 695 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Laqd_nosat"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 696 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Lmqd_nosat"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 697 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/change Iq Id  current signs"
) , TARGET_STRING ( "Gain" ) , 0 , 16 , 0 } , { 698 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 699 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 700 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch2"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 701 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Switch3"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 702 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/abc to qd transformation/1_Vb" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 703 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/qd to abc transformation/ib" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 704 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker A/Model/Timer/Hit  Crossing" ) ,
TARGET_STRING ( "HitCrossingOffset" ) , 0 , 0 , 0 } , { 705 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker A/Model/Timer/Look-Up Table" ) ,
TARGET_STRING ( "InputValues" ) , 0 , 16 , 0 } , { 706 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker A/Model/Timer/Look-Up Table" ) ,
TARGET_STRING ( "Table" ) , 0 , 16 , 0 } , { 707 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker B/Model/Timer/Hit  Crossing" ) ,
TARGET_STRING ( "HitCrossingOffset" ) , 0 , 0 , 0 } , { 708 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker B/Model/Timer/Look-Up Table" ) ,
TARGET_STRING ( "InputValues" ) , 0 , 16 , 0 } , { 709 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker B/Model/Timer/Look-Up Table" ) ,
TARGET_STRING ( "Table" ) , 0 , 16 , 0 } , { 710 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker C/Model/Timer/Hit  Crossing" ) ,
TARGET_STRING ( "HitCrossingOffset" ) , 0 , 0 , 0 } , { 711 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker C/Model/Timer/Look-Up Table" ) ,
TARGET_STRING ( "InputValues" ) , 0 , 16 , 0 } , { 712 , TARGET_STRING (
"testingV10/Three-Phase Breaker/Breaker C/Model/Timer/Look-Up Table" ) ,
TARGET_STRING ( "Table" ) , 0 , 16 , 0 } , { 713 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vaminmax" ) , TARGET_STRING ( "Ka"
) , 0 , 0 , 0 } , { 714 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vaminmax" ) , TARGET_STRING ( "Ta"
) , 0 , 0 , 0 } , { 715 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vfe0//Ka" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 716 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Gain" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 717 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Gain3" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 718 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 719 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 720 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 721 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/VRmin" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 722 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/VRmin" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 723 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 724 , TARGET_STRING (
"testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain1" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 725 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 726 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/u1"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 727 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 728 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_d"
) , TARGET_STRING ( "Gain" ) , 0 , 14 , 0 } , { 729 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_q"
) , TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 730 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 731 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/R*Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 732 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmqd"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 733 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Laqd"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 734 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant1"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 735 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant2"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 736 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant3"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 737 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/u1"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 738 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/u2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 739 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/u3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 740 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/wbase"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 741 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 742 ,
TARGET_STRING ( "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vaminmax" ) ,
TARGET_STRING ( "Ka" ) , 0 , 0 , 0 } , { 743 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vaminmax" ) , TARGET_STRING ( "Ta"
) , 0 , 0 , 0 } , { 744 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vfe0//Ka" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 745 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Gain" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 746 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Gain3" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 747 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 748 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 749 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 750 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/VRmin" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 751 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/VRmin" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 752 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 753 , TARGET_STRING (
"testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain1" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 754 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 755 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/u1"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 756 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 757 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_d"
) , TARGET_STRING ( "Gain" ) , 0 , 14 , 0 } , { 758 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_q"
) , TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 759 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 760 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/R*Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 761 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmqd"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 762 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Laqd"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 763 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant1"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 764 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant2"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 765 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant3"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 766 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/u1"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 767 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/u2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 768 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/u3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 769 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/wbase"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 770 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 771 ,
TARGET_STRING ( "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vaminmax" ) ,
TARGET_STRING ( "Ka" ) , 0 , 0 , 0 } , { 772 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vaminmax" ) , TARGET_STRING ( "Ta"
) , 0 , 0 , 0 } , { 773 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vfe0//Ka" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 774 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Gain" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 775 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Gain3" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 776 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 777 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 778 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Integrator" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 779 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/VRmin" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 780 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/VRmin" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 781 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 782 , TARGET_STRING (
"testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/PQ/Gain1" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 783 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 784 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/u1"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 785 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Matrix W/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 786 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_d"
) , TARGET_STRING ( "Gain" ) , 0 , 14 , 0 } , { 787 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_q"
) , TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 788 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 789 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/R*Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 790 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmqd"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 791 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Laqd"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 792 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant1"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 793 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant2"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 794 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant3"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 795 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/u1"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 796 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/u2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 797 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/u3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 798 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/wbase"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 799 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/phi/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 5 , 0 } , { 800 ,
TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 801 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 802 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 803 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 804 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 805 ,
TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 806 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 807 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 808 , TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 809 ,
TARGET_STRING ( "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/input" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 810 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/input1" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 811 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/input2" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 812 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Saturation Vx=Ve*Se[Ve]/Saturation"
) , TARGET_STRING ( "Table" ) , 0 , 14 , 0 } , { 813 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Saturation Vx=Ve*Se[Ve]/Saturation"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 14 , 0 } , { 814 ,
TARGET_STRING (
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Transient Gain Reduction (Tc.s+1)//(Tb.s+1)/State Space"
) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 815 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 816 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 817 ,
TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 818 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Machine measurements/Delta angle/Radians to Degrees/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 819 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 820 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lmd"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 821 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 8 , 0 } , { 822 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 8 , 0 } , { 823 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq_sat "
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 824 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq_"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 825 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 826 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 827 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 8 , 0 } , { 828 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 8 , 0 } , { 829 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/u1"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 830 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/u5"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 831 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 832 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 833 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 834 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 835 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 836 ,
TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 837 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 838 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 839 , TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 840 ,
TARGET_STRING ( "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/input" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 841 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/input1" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 842 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/input2" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 843 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Saturation Vx=Ve*Se[Ve]/Saturation"
) , TARGET_STRING ( "Table" ) , 0 , 14 , 0 } , { 844 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Saturation Vx=Ve*Se[Ve]/Saturation"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 14 , 0 } , { 845 ,
TARGET_STRING (
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Transient Gain Reduction (Tc.s+1)//(Tb.s+1)/State Space"
) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 846 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 847 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 848 ,
TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 849 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Machine measurements/Delta angle/Radians to Degrees/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 850 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 851 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lmd"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 852 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 8 , 0 } , { 853 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 8 , 0 } , { 854 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq_sat "
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 855 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq_"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 856 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 857 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 858 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 8 , 0 } , { 859 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 8 , 0 } , { 860 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/u1"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 861 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/u5"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 862 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 863 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 864 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 865 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 866 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Damping Filter Kf.s//(Tf.s+1)/State Space"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 867 ,
TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 868 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 869 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 870 , TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Low Pass Filter 1//(Tr.s+1)/State Space"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 871 ,
TARGET_STRING ( "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/input" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 872 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/input1" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 873 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/input2" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 874 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Saturation Vx=Ve*Se[Ve]/Saturation"
) , TARGET_STRING ( "Table" ) , 0 , 14 , 0 } , { 875 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Saturation Vx=Ve*Se[Ve]/Saturation"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 14 , 0 } , { 876 ,
TARGET_STRING (
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Transient Gain Reduction (Tc.s+1)//(Tb.s+1)/State Space"
) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 877 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 878 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 879 ,
TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 880 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Machine measurements/Delta angle/Radians to Degrees/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 881 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 882 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lmd"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 883 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 8 , 0 } , { 884 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 8 , 0 } , { 885 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq_sat "
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 886 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq_"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 887 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 888 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 889 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 8 , 0 } , { 890 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 8 , 0 } , { 891 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/u1"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 892 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/u5"
) , TARGET_STRING ( "Value" ) , 0 , 4 , 0 } , { 893 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/0.433<In<0.75/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 894 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 895 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 896 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 897 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 898 , TARGET_STRING (
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Rectifier/In>1.0/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 899 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/u1"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 900 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 901 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 902 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/1//Ll_d"
) , TARGET_STRING ( "Gain" ) , 0 , 14 , 0 } , { 903 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/u2"
) , TARGET_STRING ( "Value" ) , 0 , 14 , 0 } , { 904 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 905 , TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 906 ,
TARGET_STRING (
 "testingV10/G1/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/1//Ll_q"
) , TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 907 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/0.433<In<0.75/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 908 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 909 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 910 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 911 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 912 , TARGET_STRING (
"testingV10/G2/EXCITATION/AC1A/AC1A/Model/Rectifier/In>1.0/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 913 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/u1"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 914 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 915 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 916 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/1//Ll_d"
) , TARGET_STRING ( "Gain" ) , 0 , 14 , 0 } , { 917 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/u2"
) , TARGET_STRING ( "Value" ) , 0 , 14 , 0 } , { 918 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 919 , TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 920 ,
TARGET_STRING (
 "testingV10/G2/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/1//Ll_q"
) , TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 921 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/0.433<In<0.75/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 922 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 923 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/0.75<=In<=1.0/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 924 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 925 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/In<=0.433/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 926 , TARGET_STRING (
"testingV10/G3/EXCITATION/AC1A/AC1A/Model/Rectifier/In>1.0/input2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 927 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/u1"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 928 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 929 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 930 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/1//Ll_d"
) , TARGET_STRING ( "Gain" ) , 0 , 14 , 0 } , { 931 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/u2"
) , TARGET_STRING ( "Value" ) , 0 , 14 , 0 } , { 932 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 933 , TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 934 ,
TARGET_STRING (
 "testingV10/G3/SM 3.125 MVA/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/1//Ll_q"
) , TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { {
0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . e02gvifuul , & rtB . obphrpkole ,
& rtB . opow2w1mi1 , & rtB . npyj2l24ut , & rtB . npq14v1sxw , & rtB .
cpqapklze4 , & rtB . f1xtfhhhqv , & rtB . brcsbdnmx5 , & rtB . eyy42dwotr , &
rtB . j4zpdoh2yb , & rtB . m3mvlja3vc , & rtB . bgdmyntavi , & rtB .
h20osj2hz4 , & rtB . aex4uyx51s , & rtB . enckxhfxqr , & rtB . aipd2mmrrr , &
rtB . d5bucyfqa0 , & rtB . icdvip4qf2 , & rtB . ltfwzxychx , & rtB .
obphrpkole , & rtB . opow2w1mi1 , & rtB . npyj2l24ut , & rtB . izwovv53aq , &
rtB . oftl5xnv1o , & rtB . pkqtmwmhph , & rtB . g3tr54e0gh , & rtB .
ajb0jd1wax , & rtB . bzmzsahkz0 , & rtB . lmjgudxydq , & rtB . ckbwyd51fw , &
rtB . mgwenfy132 , & rtB . edtnmnr3vm , & rtB . ogontexkwa , & rtB .
phjkba00rh , & rtB . lau2uwvqvd , & rtB . lrb3pzyxyo , & rtB . is1htqzogm , &
rtB . p0ztjxbfsc , & rtB . dg5y4n2fx5 , & rtB . pucoihkeei , & rtB .
kdezj5zhgl , & rtB . k5vss3m212 , & rtB . jbvbomnw2p , & rtB . hghs1t20yw , &
rtB . a30jmyeur3 , & rtB . nwxyngwvoo , & rtB . hwewg0ullm , & rtB .
kosf4p4xvo , & rtB . prgl4v4rcs , & rtB . gecgjcwxl2 , & rtB . h2f5ohv0un , &
rtB . kfay54rwhc , & rtB . lpzstbvwnw , & rtB . kkekcv3h3x , & rtB .
mwbvfjvdmp , & rtB . bx1vifjqa5 [ 0 ] , & rtB . jaedqymkno [ 0 ] , & rtB .
bwynwxckua , & rtB . ol0nkdk5rw , & rtB . ljw0dnybdy , & rtB . ay3br3a3hq , &
rtB . icpch50dox , & rtB . fhocpb4rlk , & rtB . k3g1mw2mb1 , & rtB .
ou5as25oqf , & rtB . brvzzfgdkk , & rtB . ndv1chiwse , & rtB . ljxtwfbyom , &
rtB . dymy5fczgx , & rtB . byg1ydrnj5 , & rtB . ms5yftyqp5 , & rtB .
ebqjy0h1vz , & rtB . pqzx0wtulf , & rtB . danklhdtjg , & rtB . juqlwmzilg , &
rtB . dg4rfafxi2 , & rtB . izbaih23wf , & rtB . nm1zt5o0wf , & rtB .
ialymydhnj , & rtB . lcbyglc5pf , & rtB . kquxrsdq3f , & rtB . m1ycajq1qq , &
rtB . fr3yekodlk , & rtB . ds252cwh3s , & rtB . feadnsrfon , & rtB .
cqvzl34lfs , & rtB . jbq05nhwpa , & rtB . muz5hrtqty , & rtB . npvosve4cu , &
rtB . fpw2bhibof , & rtB . jrbkd00tcm , & rtB . cgkgxwy5lm , & rtB .
iwhl53vsbp , & rtB . e4dpd1hqdn , & rtB . k43sb00nmf , & rtB . l5jnvhxa3g , &
rtB . mjcpwqdoim , & rtB . hbasv1e1li , & rtB . mjgxqzxhn4 , & rtB .
n0ctdpimv4 , & rtB . kckr1rsmi3 , & rtB . nvzgkwwurg , & rtB . pgprp2j0mg , &
rtB . cjhy3wufru , & rtB . gveciz5cnx , & rtB . gz4h1n4arf , & rtB .
gewuongkab , & rtB . owqdlcfz5i , & rtB . bt3z4wm1qx , & rtB . l3hudrc3jb , &
rtB . gm2c3kojd1 , & rtB . brtuqherkv , & rtB . pkizjdds0x , & rtB .
egynfvvlbk , & rtB . ng0qeau1ay , & rtB . onvs14ppyq , & rtB . axj0g1at3l [ 0
] , & rtB . npdbafvddp , & rtB . gqdbtcmlhky . anumpx44cp [ 0 ] , & rtB .
gqdbtcmlhky . nyt32tufuy [ 0 ] , & rtB . gqdbtcmlhky . kguc1xjgtq , & rtB .
gqdbtcmlhky . k33sqomjhg , & rtB . gqdbtcmlhky . fbja1wrd5n , & rtB .
gqdbtcmlhky . dknardu53j , & rtB . d51r4ddhlp [ 0 ] , & rtB . axuxlimqfo [ 0
] , & rtB . muljazi4vt [ 0 ] , & rtB . my41lqaa3e [ 0 ] , & rtB . bzuabr4dvk
[ 0 ] , & rtB . ml5evcnodk [ 0 ] , & rtB . ll5lhtaahm [ 0 ] , & rtB .
fbmjaug21p [ 0 ] , & rtB . oyz4fl5tkc [ 0 ] , & rtB . mhlj2wouuq , & rtB .
fsskatoni2 [ 0 ] , & rtB . e3mykpbvxu , & rtB . puvrgymrfw . anumpx44cp [ 0 ]
, & rtB . puvrgymrfw . nyt32tufuy [ 0 ] , & rtB . puvrgymrfw . kguc1xjgtq , &
rtB . puvrgymrfw . k33sqomjhg , & rtB . puvrgymrfw . fbja1wrd5n , & rtB .
puvrgymrfw . dknardu53j , & rtB . ivbwlhlxla [ 0 ] , & rtB . i3xfrtnhpx [ 0 ]
, & rtB . kj5c5ay2lr [ 0 ] , & rtB . jt2zr3xuyu [ 0 ] , & rtB . liak5gzlbs [
0 ] , & rtB . keaofkpcfk [ 0 ] , & rtB . nwlcni0prp [ 0 ] , & rtB .
n34rsgjlm4 [ 0 ] , & rtB . h2jybzg354 [ 0 ] , & rtB . ncljwqtey4 , & rtB .
hxglkl2bua [ 0 ] , & rtB . eilem0zhx5 , & rtB . cqi4cjmse0 . anumpx44cp [ 0 ]
, & rtB . cqi4cjmse0 . nyt32tufuy [ 0 ] , & rtB . cqi4cjmse0 . kguc1xjgtq , &
rtB . cqi4cjmse0 . k33sqomjhg , & rtB . cqi4cjmse0 . fbja1wrd5n , & rtB .
cqi4cjmse0 . dknardu53j , & rtB . dk1omp4wet [ 0 ] , & rtB . p2ppvvojae [ 0 ]
, & rtB . pszjudozhd [ 0 ] , & rtB . kxg24koyh2 [ 0 ] , & rtB . btni35uwov [
0 ] , & rtB . echinzwblw [ 0 ] , & rtB . hyw4ezm3jt [ 0 ] , & rtB .
p2gohtwhoy [ 0 ] , & rtB . mhvoaxr3ny [ 0 ] , & rtB . pq54vjdlkq , & rtB .
ehtl4hikfh , & rtB . e2b1dnuz0z , & rtB . d3d4jc4vne , & rtB . e4wb3lihdw , &
rtB . nvwpe0rwjl , & rtB . h4uex5jljn , & rtB . asp4dkpswc , & rtB .
gz2qcnyb1c , & rtB . i45iq1kx0r , & rtB . bqh4htctpf , & rtB . hvcpcic14r , &
rtB . l5tveyumnb , & rtB . fg4jwggqvs , & rtB . d3prvaxezv , & rtB .
p4byd4k51j , & rtB . fsbjhr5dz0 , & rtB . kql5exxrek , & rtB . oeedo4set2 , &
rtB . m5o0jbgvyx , & rtB . pizp5zm00a , & rtB . od1v53lcod , & rtB .
iucqalgajz , & rtB . nhjs51s1ph , & rtB . pfuip4apkg , & rtB . mtaotlu3kj [ 0
] , & rtB . iodshzwwqj [ 0 ] , & rtB . d2i2d0pjwa , & rtB . lo2ggdoibh [ 0 ]
, & rtB . oydhroyllb [ 0 ] , & rtB . lh3hq5cwil , & rtB . n5u3z30051 [ 0 ] ,
& rtB . lnfeerzdwl [ 0 ] , & rtB . omolj25xda [ 0 ] , & rtB . h0135r1dh0 [ 0
] , & rtB . hn1104ars0 , & rtB . e3cyuxmtad , & rtB . gqdbtcmlhky .
privppgr4h , & rtB . gqdbtcmlhky . b3l11gphfb , & rtB . gqdbtcmlhky .
nyt32tufuy [ 0 ] , & rtB . gqdbtcmlhky . anumpx44cp [ 0 ] , & rtB .
gqdbtcmlhky . kguc1xjgtq , & rtB . gqdbtcmlhky . fbja1wrd5n , & rtB .
grwocktd5q [ 0 ] , & rtB . nyuxeims25 [ 0 ] , & rtB . haa5p2ptdq [ 0 ] , &
rtB . gtamjmvbh0 [ 0 ] , & rtB . czljrbrypr , & rtB . d54dp4nzot , & rtB .
bltflfqi2c , & rtB . leh2oxynn2 , & rtB . eeez5exivc , & rtB . in55bj1rrn , &
rtB . n5pczeolzc , & rtB . jgmqqelntj , & rtB . lmqrmcycfr , & rtB .
lfna3t2vnq , & rtB . meaoaylidx , & rtB . hnovtssll3 , & rtB . b3cqfd55dr , &
rtB . cbome3ugdq , & rtB . aacdpemjnp , & rtB . jtkc3lsddk , & rtB .
hjjlvvkayj , & rtB . o03eqw4qg4 , & rtB . ksrhlo5pxw [ 0 ] , & rtB .
bqhwxr5qcc [ 0 ] , & rtB . i025vm1xpp , & rtB . ojbcjx0grt [ 0 ] , & rtB .
okrtsi5dua [ 0 ] , & rtB . cl2yrd4l20 , & rtB . gwqqhvgmz0 [ 0 ] , & rtB .
cbo535uscm [ 0 ] , & rtB . ezhs2i41dg [ 0 ] , & rtB . mrhppm5nnj [ 0 ] , &
rtB . effezdjmri , & rtB . k1bgn3kbs2 , & rtB . puvrgymrfw . privppgr4h , &
rtB . puvrgymrfw . b3l11gphfb , & rtB . puvrgymrfw . nyt32tufuy [ 0 ] , & rtB
. puvrgymrfw . anumpx44cp [ 0 ] , & rtB . puvrgymrfw . kguc1xjgtq , & rtB .
puvrgymrfw . fbja1wrd5n , & rtB . aaxc40oml0 [ 0 ] , & rtB . p2ubfcpe4u [ 0 ]
, & rtB . nthau0fysn [ 0 ] , & rtB . mh1p4xc2nf [ 0 ] , & rtB . o2yzakmz1p ,
& rtB . fyneqtq03a , & rtB . lnyirkbasi , & rtB . dddvo3hq1e , & rtB .
kxi0hiouf4 , & rtB . i2y4p2vw1k , & rtB . f4wm3ijjcw , & rtB . o5yahrnyq3 , &
rtB . evrpjg415a , & rtB . imbchlh21y , & rtB . hyvvo1s5f2 , & rtB .
a0qycmun3l , & rtB . m1pbevt2be , & rtB . jvrusqmyep , & rtB . hz5ux0snkr , &
rtB . faanufcllo , & rtB . bzvubtagmj , & rtB . inwdxaza5z , & rtB .
kgd55h5ywl [ 0 ] , & rtB . ilnl1lw0qf [ 0 ] , & rtB . om3gsb2wta , & rtB .
j1s3mphmsm [ 0 ] , & rtB . j21pixwogm [ 0 ] , & rtB . d2o4vcwr4t , & rtB .
b3aww42o13 [ 0 ] , & rtB . e2xvdcfwjv [ 0 ] , & rtB . nkurjvw04v [ 0 ] , &
rtB . nqquna1krn [ 0 ] , & rtB . f0m4fsml1k , & rtB . dddbntcjoq , & rtB .
cqi4cjmse0 . privppgr4h , & rtB . cqi4cjmse0 . b3l11gphfb , & rtB .
cqi4cjmse0 . nyt32tufuy [ 0 ] , & rtB . cqi4cjmse0 . anumpx44cp [ 0 ] , & rtB
. cqi4cjmse0 . kguc1xjgtq , & rtB . cqi4cjmse0 . fbja1wrd5n , & rtB .
djoydjgvbg [ 0 ] , & rtB . j2hq00la3s [ 0 ] , & rtB . dfgsexyfsz [ 0 ] , &
rtB . ikmi0yu0r4 [ 0 ] , & rtB . emn13j4iq4 , & rtB . b1zkykkz5k , & rtB .
amufqu02uc , & rtB . amufqu02uc , & rtB . amufqu02uc , & rtB . amufqu02uc , &
rtB . eiwmp0uix0 , & rtB . amufqu02uc , & rtB . kb4mvzq0n3 , & rtB .
di4ji05v0o , & rtB . kkwarc0rc1 , & rtB . my43lbhgf2 , & rtB . k2ed141a0b , &
rtB . pm0bgbsy3o , & rtB . ifzgu2ee1l , & rtB . gqdbtcmlhky . kkho4m250n , &
rtB . gqdbtcmlhky . k33sqomjhg , & rtB . gqdbtcmlhky . ebabsrxrur , & rtB .
gqdbtcmlhky . mc0nzpa2g2 , & rtB . gqdbtcmlhky . iytz0y3ucg , & rtB .
gqdbtcmlhky . f2a01aevzv , & rtB . gqdbtcmlhky . privppgr4h , & rtB .
gqdbtcmlhky . ifyloqp5tf , & rtB . gqdbtcmlhky . j5vjugftgu , & rtB .
gqdbtcmlhky . ihs5uzpoqs , & rtB . gqdbtcmlhky . dos2ao4wzk [ 0 ] , & rtB .
gqdbtcmlhky . e4eaoc3n4j [ 0 ] , & rtB . gqdbtcmlhky . akb1ib2amz [ 0 ] , &
rtB . nqfjt0wu52 , & rtB . olxkln2vrn , & rtB . ipenwii4hv , & rtB .
ipenwii4hv , & rtB . ipenwii4hv , & rtB . ipenwii4hv , & rtB . lds45me1tz , &
rtB . ipenwii4hv , & rtB . fxujfy1naf , & rtB . pd4pkxomth , & rtB .
k0htkyngm1 , & rtB . bfl0othxdw , & rtB . bbuesupjvr , & rtB . geqf1klp5b , &
rtB . ibx54rryug , & rtB . puvrgymrfw . kkho4m250n , & rtB . puvrgymrfw .
k33sqomjhg , & rtB . puvrgymrfw . ebabsrxrur , & rtB . puvrgymrfw .
mc0nzpa2g2 , & rtB . puvrgymrfw . iytz0y3ucg , & rtB . puvrgymrfw .
f2a01aevzv , & rtB . puvrgymrfw . privppgr4h , & rtB . puvrgymrfw .
ifyloqp5tf , & rtB . puvrgymrfw . j5vjugftgu , & rtB . puvrgymrfw .
ihs5uzpoqs , & rtB . puvrgymrfw . dos2ao4wzk [ 0 ] , & rtB . puvrgymrfw .
e4eaoc3n4j [ 0 ] , & rtB . puvrgymrfw . akb1ib2amz [ 0 ] , & rtB . dphvgbxieu
, & rtB . biqautq04w , & rtB . i0iyh4zr0m , & rtB . i0iyh4zr0m , & rtB .
i0iyh4zr0m , & rtB . i0iyh4zr0m , & rtB . jsjdhroynv , & rtB . i0iyh4zr0m , &
rtB . l4qzjl15fy , & rtB . pyb5nlfcal , & rtB . jx22a2iggv , & rtB .
fv5a4vo3xg , & rtB . e4g0rxt1yl , & rtB . kjdjn4pvtg , & rtB . ora01btyv5 , &
rtB . cqi4cjmse0 . kkho4m250n , & rtB . cqi4cjmse0 . k33sqomjhg , & rtB .
cqi4cjmse0 . ebabsrxrur , & rtB . cqi4cjmse0 . mc0nzpa2g2 , & rtB .
cqi4cjmse0 . iytz0y3ucg , & rtB . cqi4cjmse0 . f2a01aevzv , & rtB .
cqi4cjmse0 . privppgr4h , & rtB . cqi4cjmse0 . ifyloqp5tf , & rtB .
cqi4cjmse0 . j5vjugftgu , & rtB . cqi4cjmse0 . ihs5uzpoqs , & rtB .
cqi4cjmse0 . dos2ao4wzk [ 0 ] , & rtB . cqi4cjmse0 . e4eaoc3n4j [ 0 ] , & rtB
. cqi4cjmse0 . akb1ib2amz [ 0 ] , & rtB . amufqu02uc , & rtB . amufqu02uc , &
rtB . amufqu02uc , & rtB . gqdbtcmlhky . dknardu53j , & rtB . gqdbtcmlhky .
dgj2vlo3ae , & rtB . gqdbtcmlhky . okkine1bpp , & rtB . gqdbtcmlhky .
m0j312cexm , & rtB . gqdbtcmlhky . jtahvktmal , & rtB . gqdbtcmlhky .
lzzeeexge0 [ 0 ] , & rtB . gqdbtcmlhky . bqfae1z4xm , & rtB . gqdbtcmlhky .
iwuvpqmdqd , & rtB . gqdbtcmlhky . b3l11gphfb , & rtB . gqdbtcmlhky .
hyzrfwdn0b , & rtB . gqdbtcmlhky . oelb25yqch , & rtB . gqdbtcmlhky .
kdysf2sgiq , & rtB . gqdbtcmlhky . i2v1etu5n3 , & rtB . gqdbtcmlhky .
hcoloefwbj [ 0 ] , & rtB . gqdbtcmlhky . ahmbzjodez , & rtB . gqdbtcmlhky .
igfp3wt3zj , & rtB . ipenwii4hv , & rtB . ipenwii4hv , & rtB . ipenwii4hv , &
rtB . puvrgymrfw . dknardu53j , & rtB . puvrgymrfw . dgj2vlo3ae , & rtB .
puvrgymrfw . okkine1bpp , & rtB . puvrgymrfw . m0j312cexm , & rtB .
puvrgymrfw . jtahvktmal , & rtB . puvrgymrfw . lzzeeexge0 [ 0 ] , & rtB .
puvrgymrfw . bqfae1z4xm , & rtB . puvrgymrfw . iwuvpqmdqd , & rtB .
puvrgymrfw . b3l11gphfb , & rtB . puvrgymrfw . hyzrfwdn0b , & rtB .
puvrgymrfw . oelb25yqch , & rtB . puvrgymrfw . kdysf2sgiq , & rtB .
puvrgymrfw . i2v1etu5n3 , & rtB . puvrgymrfw . hcoloefwbj [ 0 ] , & rtB .
puvrgymrfw . ahmbzjodez , & rtB . puvrgymrfw . igfp3wt3zj , & rtB .
i0iyh4zr0m , & rtB . i0iyh4zr0m , & rtB . i0iyh4zr0m , & rtB . cqi4cjmse0 .
dknardu53j , & rtB . cqi4cjmse0 . dgj2vlo3ae , & rtB . cqi4cjmse0 .
okkine1bpp , & rtB . cqi4cjmse0 . m0j312cexm , & rtB . cqi4cjmse0 .
jtahvktmal , & rtB . cqi4cjmse0 . lzzeeexge0 [ 0 ] , & rtB . cqi4cjmse0 .
bqfae1z4xm , & rtB . cqi4cjmse0 . iwuvpqmdqd , & rtB . cqi4cjmse0 .
b3l11gphfb , & rtB . cqi4cjmse0 . hyzrfwdn0b , & rtB . cqi4cjmse0 .
oelb25yqch , & rtB . cqi4cjmse0 . kdysf2sgiq , & rtB . cqi4cjmse0 .
i2v1etu5n3 , & rtB . cqi4cjmse0 . hcoloefwbj [ 0 ] , & rtB . cqi4cjmse0 .
ahmbzjodez , & rtB . cqi4cjmse0 . igfp3wt3zj , & rtP . u00kV1000MVA_Frequency
, & rtP . ThreePhaseBreaker_SwitchA , & rtP . ThreePhaseBreaker_SwitchB , &
rtP . ThreePhaseBreaker_SwitchC , & rtP . Constant3_Value , & rtP .
Constant4_Value , & rtP . Constant5_Value , & rtP .
Switch1_Threshold_nhwesj444w , & rtP . Kv_Gain_nftr42q2lb , & rtP .
Kv1_Gain_fxnn3aho5e , & rtP . Kv_Gain_ozfx3cxmrl , & rtP .
Kv1_Gain_otbflrw2my , & rtP . Kv_Gain , & rtP . Kv1_Gain , & rtP .
Kv_Gain_czwgps5mha , & rtP . Kv1_Gain_bfvq3500bp , & rtP .
RepeatingSequenceInterpolated6_OutValues [ 0 ] , & rtP .
RepeatingSequenceInterpolated6_TimeValues [ 0 ] , & rtP .
RepeatingSequenceInterpolated7_OutValues [ 0 ] , & rtP .
RepeatingSequenceInterpolated7_TimeValues [ 0 ] , & rtP .
RepeatingSequenceInterpolated8_OutValues [ 0 ] , & rtP .
RepeatingSequenceInterpolated8_TimeValues [ 0 ] , & rtP . Constant1_Value , &
rtP . Constant2_Value , & rtP . Constant6_Value , & rtP .
Switch2_Threshold_cpu03sarvk , & rtP . Switch3_Threshold_diazeczrov , & rtP .
Switch4_Threshold , & rtP . DieselEngineGovernor_K , & rtP .
DieselEngineGovernor_Td , & rtP . DieselEngineGovernor_Pm0 , & rtP .
Constant_Value , & rtP . Constant1_Value_ls0pawmfdq , & rtP . Vtrefpu_Value ,
& rtP . Switch1_Threshold_i5r3mlizx4 , & rtP .
DieselEngineGovernor_K_hsep1xrwii , & rtP .
DieselEngineGovernor_Td_khwtk020bh , & rtP .
DieselEngineGovernor_Pm0_kdo13i53e1 , & rtP . Constant_Value_fsy5hzupsd , &
rtP . Constant1_Value_gzdhx1y50h , & rtP . Vtrefpu_Value_dhu50coqb3 , & rtP .
Switch1_Threshold_fwfvkbu4fv , & rtP . DieselEngineGovernor_K_cl2ljmrvvx , &
rtP . DieselEngineGovernor_Td_bx2jkcsvfl , & rtP .
DieselEngineGovernor_Pm0_a40shkker5 , & rtP . Constant_Value_feo10nb4xc , &
rtP . Constant1_Value_p3y25qn4th , & rtP . Vtrefpu_Value_gqtbi3ry5p , & rtP .
Switch1_Threshold_bvrzjijffl , & rtP . puV_Gain_ff0r1eyugh , & rtP .
C4_Value_oedqg4szxm , & rtP . Constant5_Value_p3h5lbxhcf , & rtP .
Switch_Threshold , & rtP . Switch1_Threshold , & rtP . Switch2_Threshold , &
rtP . Switch3_Threshold_cusgrt5efp , & rtP . SineWaveA_Amp , & rtP .
SineWaveA_Bias , & rtP . SineWaveA_Phase , & rtP . SineWaveB_Amp , & rtP .
SineWaveB_Bias , & rtP . SineWaveB_Phase , & rtP . SineWaveC_Amp , & rtP .
SineWaveC_Bias , & rtP . SineWaveC_Phase , & rtP . u1_Y0 , & rtP . u2_Y0 , &
rtP . u3_Y0 , & rtP . LimitedCounter_uplimit , & rtP .
SampleTimeMath_WtEt_mn443d0ldo , & rtP . LimitedCounter_uplimit_hhtrkteiui ,
& rtP . SampleTimeMath_WtEt_oqoqay0dg0 , & rtP .
LimitedCounter_uplimit_gpv2tvmki5 , & rtP . SampleTimeMath_WtEt , & rtP .
Integrator_UpperSat_f4njfmemxq , & rtP . Integrator_LowerSat_dbtbuno0hm , &
rtP . CONTROLSYSTEM_A [ 0 ] , & rtP . CONTROLSYSTEM_C [ 0 ] , & rtP . TF1_A ,
& rtP . TF1_C , & rtP . TF1_D , & rtP . TF2_A , & rtP . TF2_C , & rtP .
puV_Gain_k4ukpfvde5 , & rtP . Integrator_UpperSat_gojjo5eoxp , & rtP .
Integrator_LowerSat_odmybcofvo , & rtP . CONTROLSYSTEM_A_oy0zvzwgbs [ 0 ] , &
rtP . CONTROLSYSTEM_C_aor5asjqzc [ 0 ] , & rtP . TF1_A_in4jblwda4 , & rtP .
TF1_C_p2k2li4nfg , & rtP . TF1_D_ctmvhklpop , & rtP . TF2_A_enodlnrioj , &
rtP . TF2_C_cttzu3ti0v , & rtP . puV_Gain , & rtP .
Integrator_UpperSat_g2nmqxfxgj , & rtP . Integrator_LowerSat_jpz1embdbj , &
rtP . CONTROLSYSTEM_A_fmcipdkw5g [ 0 ] , & rtP . CONTROLSYSTEM_C_bbvipdfxiw [
0 ] , & rtP . TF1_A_jog0zs3jsk , & rtP . TF1_C_enbbofzqoo , & rtP .
TF1_D_oklbobiarf , & rtP . TF2_A_nfpoakqhp5 , & rtP . TF2_C_b52pyf1de4 , &
rtP . puV_Gain_p1qhxv12dx , & rtP . StateSpace_P1 [ 0 ] , & rtP .
StateSpace_P2 [ 0 ] , & rtP . StateSpace_P3 [ 0 ] , & rtP . StateSpace_P4 [ 0
] , & rtP . StateSpace_P5 [ 0 ] , & rtP . StateSpace_P6 [ 0 ] , & rtP .
StateSpace_P7 [ 0 ] , & rtP . StateSpace_P8 [ 0 ] , & rtP . StateSpace_P9 , &
rtP . StateSpace_P10 , & rtP . donotdeletethisgain_Gain_en3nmrxgld , & rtP .
donotdeletethisgain_Gain_hsdfpbzlqb , & rtP .
donotdeletethisgain_Gain_by5bos33lx , & rtP .
donotdeletethisgain_Gain_cnnpmgyozm , & rtP .
donotdeletethisgain_Gain_l234soa3tf , & rtP .
donotdeletethisgain_Gain_lkyvqrwckq , & rtP .
donotdeletethisgain_Gain_jy0ly32qzq , & rtP .
donotdeletethisgain_Gain_b0gdocyoez , & rtP .
donotdeletethisgain_Gain_ablp5g31dp , & rtP .
donotdeletethisgain_Gain_lmtenwvpad , & rtP .
donotdeletethisgain_Gain_b4h4vrwez2 , & rtP .
donotdeletethisgain_Gain_hjafqzuqe3 , & rtP .
donotdeletethisgain_Gain_e2auf2j1rh , & rtP .
donotdeletethisgain_Gain_mshnmhldd3 , & rtP .
donotdeletethisgain_Gain_j0haq310r2 , & rtP . donotdeletethisgain_Gain , &
rtP . donotdeletethisgain_Gain_f1ifkvuqfs , & rtP .
donotdeletethisgain_Gain_kkqpn0enmg , & rtP .
donotdeletethisgain_Gain_ok2btrhuoi , & rtP .
donotdeletethisgain_Gain_jfb5zvz2in , & rtP .
donotdeletethisgain_Gain_agzp2l5xoj , & rtP .
donotdeletethisgain_Gain_gmp4pnrphh , & rtP .
donotdeletethisgain_Gain_bnawliqvik , & rtP .
donotdeletethisgain_Gain_ovofaqt3tg , & rtP .
Output_InitialCondition_koai1wfyjy , & rtP .
Output_InitialCondition_kgl5nejq40 , & rtP . Output_InitialCondition , & rtP
. AC1A_Kd , & rtP . AC1A_Kc , & rtP . Vkd0Vkq10Vkq20_Value [ 0 ] , & rtP .
N_Gain , & rtP . nomspeed_Value , & rtP . u_2H_Gain , & rtP . u_Pb_Gain , &
rtP . F1_Gain , & rtP . t_Gain , & rtP . units_Gain , & rtP . units1_Gain , &
rtP . units2_Gain , & rtP . web1_Gain , & rtP . web2_Gain_lxgspwzlqe , & rtP
. web3_Gain , & rtP . Rotorangledtheta_IC_jattgadt2d , & rtP .
Rotorspeeddeviationdw_IC , & rtP . theta_IC , & rtP . AC1A_Kd_dmbfzuvmau , &
rtP . AC1A_Kc_lp3kwbrdlq , & rtP . Vkd0Vkq10Vkq20_Value_nhzucgdnq4 [ 0 ] , &
rtP . N_Gain_be3jplttom , & rtP . nomspeed_Value_gur000lokn , & rtP .
u_2H_Gain_fy3z52hrui , & rtP . u_Pb_Gain_meqork31l1 , & rtP .
F1_Gain_ehi20lbmpl , & rtP . t_Gain_ocx2eejdk0 , & rtP .
units_Gain_iq4q232a3o , & rtP . units1_Gain_ck3oazuezb , & rtP .
units2_Gain_mdhlfy5yh3 , & rtP . web1_Gain_ntza1b0jr3 , & rtP .
web2_Gain_hafoo1lium , & rtP . web3_Gain_hkaiompgkf , & rtP .
Rotorangledtheta_IC_ino2tfu01n , & rtP . Rotorspeeddeviationdw_IC_o43mhwbr2s
, & rtP . theta_IC_dprjmrmwfq , & rtP . AC1A_Kd_jc2axpnc1z , & rtP .
AC1A_Kc_ey4gmz0v22 , & rtP . Vkd0Vkq10Vkq20_Value_ltjzacdd50 [ 0 ] , & rtP .
N_Gain_ibtzqi1ta5 , & rtP . nomspeed_Value_c4afvv0dzn , & rtP .
u_2H_Gain_pa0w4j2kxa , & rtP . u_Pb_Gain_cmlupu4lup , & rtP .
F1_Gain_fyk4vsqtoc , & rtP . t_Gain_dbtteubymo , & rtP .
units_Gain_knuawugzke , & rtP . units1_Gain_mjfpltedd3 , & rtP .
units2_Gain_lg4ftazuex , & rtP . web1_Gain_pvbmras4px , & rtP . web2_Gain , &
rtP . web3_Gain_frif05wfp3 , & rtP . Rotorangledtheta_IC , & rtP .
Rotorspeeddeviationdw_IC_mgh0oddmta , & rtP . theta_IC_nuqyp4ahc0 , & rtP .
C4_Value , & rtP . Switch3_Threshold_g4hlm5luuc , & rtP . C4_Value_j03cbj4w4t
, & rtP . Switch3_Threshold_au45uwgzmy , & rtP . C4_Value_d2dqb0vhdi , & rtP
. Switch3_Threshold_npd5pduwpp , & rtP . HitCrossing_Offset_fvwyzrflnb , &
rtP . LookUpTable_XData [ 0 ] , & rtP . LookUpTable_YData [ 0 ] , & rtP .
FixPtConstant_Value , & rtP . Constant_Value_d1po1vdd0l , & rtP .
FixPtConstant_Value_bhfbq2rm4w , & rtP . Constant_Value_lox41z13xd , & rtP .
FixPtConstant_Value_mqj2wqz1c5 , & rtP . Constant_Value_nhhzojlawr , & rtP .
Constant1_Value_fzwmfv0kgm , & rtP . Constant2_Value_epm55skuqn , & rtP .
outputformatting_Gain [ 0 ] , & rtP . Constant1_Value_iqgflwhd0e , & rtP .
Constant2_Value_aotbypyuon , & rtP . Constant3_Value_bcu1pnrcxc , & rtP .
Constant4_Value_f2c3xayuty [ 0 ] , & rtP . Constant5_Value_kqupx0gkxm , & rtP
. Constant6_Value_aag1qbkfgz [ 0 ] , & rtP . Constant8_Value , & rtP .
Laqd_nosat_Value [ 0 ] , & rtP . Lmqd_nosat_Value [ 0 ] , & rtP .
changeIqIdcurrentsigns_Gain_devnvm2504 [ 0 ] , & rtP .
Switch_Threshold_e2e0xrm3uu , & rtP . Switch1_Threshold_aftgfs3nnz , & rtP .
Switch2_Threshold_gl2dnbpcoc , & rtP . Switch3_Threshold , & rtP . u_Vb_Gain
, & rtP . ib_Gain_k0uiynd021 , & rtP . Constant1_Value_pwpdsgpubt , & rtP .
Constant2_Value_ie44msnx1e , & rtP . outputformatting_Gain_ghuljw3lhk [ 0 ] ,
& rtP . Constant1_Value_bhms2ohso1 , & rtP . Constant2_Value_pvyxnakeki , &
rtP . Constant3_Value_ekoy4aaewq , & rtP . Constant4_Value_a4umnvtiwg [ 0 ] ,
& rtP . Constant5_Value_owzacacl1u , & rtP . Constant6_Value_k5ippmioel [ 0 ]
, & rtP . Constant8_Value_erv12cit4q , & rtP . Laqd_nosat_Value_i2eposfmya [
0 ] , & rtP . Lmqd_nosat_Value_guprarme5m [ 0 ] , & rtP .
changeIqIdcurrentsigns_Gain_oeffjb2exf [ 0 ] , & rtP .
Switch_Threshold_i2gzs1aal3 , & rtP . Switch1_Threshold_fwxhhecccj , & rtP .
Switch2_Threshold_ouaxae3tuq , & rtP . Switch3_Threshold_pdefg51fln , & rtP .
u_Vb_Gain_fxx3jygcme , & rtP . ib_Gain_a5iu43yzxn , & rtP .
Constant1_Value_o4y4gj153l , & rtP . Constant2_Value_gn5n2cp44f , & rtP .
outputformatting_Gain_pp0gocueod [ 0 ] , & rtP . Constant1_Value_gju1j5culq ,
& rtP . Constant2_Value_pd52okrj2w , & rtP . Constant3_Value_ftweuv5hbb , &
rtP . Constant4_Value_kflxryerzb [ 0 ] , & rtP . Constant5_Value_avkreamlze ,
& rtP . Constant6_Value_ovz5lrokju [ 0 ] , & rtP . Constant8_Value_pcjxv32svc
, & rtP . Laqd_nosat_Value_fjpqaej0yv [ 0 ] , & rtP .
Lmqd_nosat_Value_kp0vqseud3 [ 0 ] , & rtP . changeIqIdcurrentsigns_Gain [ 0 ]
, & rtP . Switch_Threshold_es5p4ljhx5 , & rtP . Switch1_Threshold_eqdxhfdxlc
, & rtP . Switch2_Threshold_ihudfcdcgg , & rtP . Switch3_Threshold_njctu0jfwh
, & rtP . u_Vb_Gain_euntrylpur , & rtP . ib_Gain , & rtP . HitCrossing_Offset
, & rtP . LookUpTable_XData_mq1idq0nl4 [ 0 ] , & rtP .
LookUpTable_YData_ccvh5hrnif [ 0 ] , & rtP . HitCrossing_Offset_byy35c2pe2 ,
& rtP . LookUpTable_XData_eezqqd1gay [ 0 ] , & rtP .
LookUpTable_YData_hvy2xxeyp0 [ 0 ] , & rtP . HitCrossing_Offset_ckyjwcjlvs ,
& rtP . LookUpTable_XData_lgzoqpdmap [ 0 ] , & rtP .
LookUpTable_YData_iwdiswx02w [ 0 ] , & rtP . Vaminmax_Ka , & rtP .
Vaminmax_Ta , & rtP . Vfe0Ka_Value , & rtP . Gain_Gain_ffnxwopg3s , & rtP .
Gain3_Gain , & rtP . Integrator_IC_dwtmatqar4 , & rtP . Integrator_UpperSat ,
& rtP . Integrator_LowerSat , & rtP . VRmin_UpperSat , & rtP . VRmin_LowerSat
, & rtP . Gain_Gain_go11vj5gb1 , & rtP . Gain1_Gain , & rtP . u1_Gain [ 0 ] ,
& rtP . u1_Value [ 0 ] , & rtP . Gain1_Gain_moin2woj4i , & rtP . uLl_d_Gain [
0 ] , & rtP . uLl_q_Gain [ 0 ] , & rtP . gqdbtcmlhky . Linv_Y0 , & rtP .
gqdbtcmlhky . RLinv_Y0 , & rtP . gqdbtcmlhky . Lmqd_Y0 , & rtP . gqdbtcmlhky
. Laqd_Y0 , & rtP . gqdbtcmlhky . Constant1_Value_cjnzzjd4qz , & rtP .
gqdbtcmlhky . Constant2_Value , & rtP . gqdbtcmlhky . Constant3_Value , & rtP
. gqdbtcmlhky . u1_Value_gb2ffz550q [ 0 ] , & rtP . gqdbtcmlhky .
u2_Value_ofkq3wczs0 , & rtP . gqdbtcmlhky . u3_Value , & rtP . wbase_Gain , &
rtP . Integrator_IC_penjbqiku4 [ 0 ] , & rtP . Vaminmax_Ka_joioxdjv2b , & rtP
. Vaminmax_Ta_m25rkfya5x , & rtP . Vfe0Ka_Value_mornhw3ubx , & rtP .
Gain_Gain_obx54i1vu4 , & rtP . Gain3_Gain_l0wnsmveb4 , & rtP .
Integrator_IC_cbuanuvuvp , & rtP . Integrator_UpperSat_emevdxcfrg , & rtP .
Integrator_LowerSat_b2xzznseid , & rtP . VRmin_UpperSat_kemkgh34w4 , & rtP .
VRmin_LowerSat_jrg3s5kvpl , & rtP . Gain_Gain_kd3xkntxif , & rtP .
Gain1_Gain_lni3n3ja03 , & rtP . u1_Gain_h2t4ccjbjb [ 0 ] , & rtP .
u1_Value_jhomplmiue [ 0 ] , & rtP . Gain1_Gain_e30uvq0bg2 , & rtP .
uLl_d_Gain_ksdp1qfju0 [ 0 ] , & rtP . uLl_q_Gain_jh4fgceov2 [ 0 ] , & rtP .
puvrgymrfw . Linv_Y0 , & rtP . puvrgymrfw . RLinv_Y0 , & rtP . puvrgymrfw .
Lmqd_Y0 , & rtP . puvrgymrfw . Laqd_Y0 , & rtP . puvrgymrfw .
Constant1_Value_cjnzzjd4qz , & rtP . puvrgymrfw . Constant2_Value , & rtP .
puvrgymrfw . Constant3_Value , & rtP . puvrgymrfw . u1_Value_gb2ffz550q [ 0 ]
, & rtP . puvrgymrfw . u2_Value_ofkq3wczs0 , & rtP . puvrgymrfw . u3_Value ,
& rtP . wbase_Gain_ipvpfsncw4 , & rtP . Integrator_IC_hskzo4cis1 [ 0 ] , &
rtP . Vaminmax_Ka_fmvvzu1cvw , & rtP . Vaminmax_Ta_achztkg4yj , & rtP .
Vfe0Ka_Value_hmejnrjuz0 , & rtP . Gain_Gain_gns12i5e1p , & rtP .
Gain3_Gain_fuo2nhtpfo , & rtP . Integrator_IC_pyisyjlvgu , & rtP .
Integrator_UpperSat_m3couvae5u , & rtP . Integrator_LowerSat_cp3m3xxjrp , &
rtP . VRmin_UpperSat_k0uoo5f5gu , & rtP . VRmin_LowerSat_aseabweop3 , & rtP .
Gain_Gain_cvcbqyleda , & rtP . Gain1_Gain_l4eyt2f1nb , & rtP .
u1_Gain_i4dhglb1xx [ 0 ] , & rtP . u1_Value_kgi3v4joec [ 0 ] , & rtP .
Gain1_Gain_mh0xj2zmnv , & rtP . uLl_d_Gain_lwwmuggbe5 [ 0 ] , & rtP .
uLl_q_Gain_kecofhqc2m [ 0 ] , & rtP . cqi4cjmse0 . Linv_Y0 , & rtP .
cqi4cjmse0 . RLinv_Y0 , & rtP . cqi4cjmse0 . Lmqd_Y0 , & rtP . cqi4cjmse0 .
Laqd_Y0 , & rtP . cqi4cjmse0 . Constant1_Value_cjnzzjd4qz , & rtP .
cqi4cjmse0 . Constant2_Value , & rtP . cqi4cjmse0 . Constant3_Value , & rtP .
cqi4cjmse0 . u1_Value_gb2ffz550q [ 0 ] , & rtP . cqi4cjmse0 .
u2_Value_ofkq3wczs0 , & rtP . cqi4cjmse0 . u3_Value , & rtP .
wbase_Gain_okwmdlnvlt , & rtP . Integrator_IC [ 0 ] , & rtP . StateSpace_A ,
& rtP . StateSpace_B , & rtP . StateSpace_C , & rtP . StateSpace_D , & rtP .
StateSpace_InitialCondition , & rtP . StateSpace_A_pgmfa5yhzo , & rtP .
StateSpace_B_pl13jcfikc , & rtP . StateSpace_C_m5ukcmidnd , & rtP .
StateSpace_InitialCondition_dxz5ijbicj , & rtP . input_Value , & rtP .
input1_Value , & rtP . input2_Value , & rtP . Saturation_tableData [ 0 ] , &
rtP . Saturation_bp01Data [ 0 ] , & rtP . StateSpace_D_irddqmjpbm , & rtP .
Integrator_IC_pvpv3edcbn , & rtP . Integrator_UpperSat_drvyrbacf3 , & rtP .
Integrator_LowerSat_hx5r22dn01 , & rtP . Gain_Gain , & rtP . gqdbtcmlhky .
Constant1_Value_dvrakrgzwa , & rtP . gqdbtcmlhky . Lmd_Gain , & rtP .
gqdbtcmlhky . uDLookupTable_tableData_imh4jt4ucy [ 0 ] , & rtP . gqdbtcmlhky
. uDLookupTable_bp01Data_ksienufmbo [ 0 ] , & rtP . gqdbtcmlhky . Lmq_sat_Y0
, & rtP . gqdbtcmlhky . Laq_Y0 , & rtP . gqdbtcmlhky . Constant1_Value , &
rtP . gqdbtcmlhky . Lmq_Gain , & rtP . gqdbtcmlhky . uDLookupTable_tableData
[ 0 ] , & rtP . gqdbtcmlhky . uDLookupTable_bp01Data [ 0 ] , & rtP .
gqdbtcmlhky . u1_Value_kxgxvrotpn [ 0 ] , & rtP . gqdbtcmlhky . u5_Value [ 0
] , & rtP . StateSpace_A_egh3gfm2o1 , & rtP . StateSpace_B_ffyet4mzai , & rtP
. StateSpace_C_hoey44f3p1 , & rtP . StateSpace_D_fhquez5sfr , & rtP .
StateSpace_InitialCondition_huivxjzddm , & rtP . StateSpace_A_hz0n2nokjy , &
rtP . StateSpace_B_cies5b1jkk , & rtP . StateSpace_C_l2uehmt5xx , & rtP .
StateSpace_InitialCondition_o3b0kscpl2 , & rtP . input_Value_j4v0x1onoy , &
rtP . input1_Value_jwembzy4jc , & rtP . input2_Value_mfn5w3js4u , & rtP .
Saturation_tableData_bxpta2jp2k [ 0 ] , & rtP .
Saturation_bp01Data_cujbbzghha [ 0 ] , & rtP . StateSpace_D_ag504b3buu , &
rtP . Integrator_IC_h2sy3kxvaj , & rtP . Integrator_UpperSat_mx32ysi3tz , &
rtP . Integrator_LowerSat_pgmxfrs2lk , & rtP . Gain_Gain_n4b4vqpdms , & rtP .
puvrgymrfw . Constant1_Value_dvrakrgzwa , & rtP . puvrgymrfw . Lmd_Gain , &
rtP . puvrgymrfw . uDLookupTable_tableData_imh4jt4ucy [ 0 ] , & rtP .
puvrgymrfw . uDLookupTable_bp01Data_ksienufmbo [ 0 ] , & rtP . puvrgymrfw .
Lmq_sat_Y0 , & rtP . puvrgymrfw . Laq_Y0 , & rtP . puvrgymrfw .
Constant1_Value , & rtP . puvrgymrfw . Lmq_Gain , & rtP . puvrgymrfw .
uDLookupTable_tableData [ 0 ] , & rtP . puvrgymrfw . uDLookupTable_bp01Data [
0 ] , & rtP . puvrgymrfw . u1_Value_kxgxvrotpn [ 0 ] , & rtP . puvrgymrfw .
u5_Value [ 0 ] , & rtP . StateSpace_A_ggjpwot10c , & rtP .
StateSpace_B_k2dlv21nqs , & rtP . StateSpace_C_ixsu11uqcc , & rtP .
StateSpace_D_kgtr0kyhhc , & rtP . StateSpace_InitialCondition_ldzhin2tip , &
rtP . StateSpace_A_f04ittyphn , & rtP . StateSpace_B_oeqazzuglo , & rtP .
StateSpace_C_gsj3y0bvsj , & rtP . StateSpace_InitialCondition_bacyfv3a4h , &
rtP . input_Value_kgzybnfuyq , & rtP . input1_Value_lmbqbgulqv , & rtP .
input2_Value_damfqfxz2b , & rtP . Saturation_tableData_kxfwt3h3lg [ 0 ] , &
rtP . Saturation_bp01Data_en0rvvne43 [ 0 ] , & rtP . StateSpace_D_px4xwj4emx
, & rtP . Integrator_IC_jdcpelpvxo , & rtP . Integrator_UpperSat_awe5bjjzds ,
& rtP . Integrator_LowerSat_boizxptfju , & rtP . Gain_Gain_mlg03jqesr , & rtP
. cqi4cjmse0 . Constant1_Value_dvrakrgzwa , & rtP . cqi4cjmse0 . Lmd_Gain , &
rtP . cqi4cjmse0 . uDLookupTable_tableData_imh4jt4ucy [ 0 ] , & rtP .
cqi4cjmse0 . uDLookupTable_bp01Data_ksienufmbo [ 0 ] , & rtP . cqi4cjmse0 .
Lmq_sat_Y0 , & rtP . cqi4cjmse0 . Laq_Y0 , & rtP . cqi4cjmse0 .
Constant1_Value , & rtP . cqi4cjmse0 . Lmq_Gain , & rtP . cqi4cjmse0 .
uDLookupTable_tableData [ 0 ] , & rtP . cqi4cjmse0 . uDLookupTable_bp01Data [
0 ] , & rtP . cqi4cjmse0 . u1_Value_kxgxvrotpn [ 0 ] , & rtP . cqi4cjmse0 .
u5_Value [ 0 ] , & rtP . igmpp4jfdvg . input2_Value , & rtP . attmdly3nwd .
input2_Value , & rtP . attmdly3nwd . Gain_Gain , & rtP . e22kv3zqsq0 .
input2_Value , & rtP . e22kv3zqsq0 . Gain_Gain , & rtP . mfbj0yzfuo4 .
input2_Value , & rtP . gqdbtcmlhky . u1_Value [ 0 ] , & rtP . gqdbtcmlhky .
uTT1e6s_Gain_lrfifhs0hf , & rtP . gqdbtcmlhky . Integrator_IC_g1shtqvluy , &
rtP . gqdbtcmlhky . uLl_d_Gain [ 0 ] , & rtP . gqdbtcmlhky . u2_Value [ 0 ] ,
& rtP . gqdbtcmlhky . uTT1e6s_Gain , & rtP . gqdbtcmlhky . Integrator_IC , &
rtP . gqdbtcmlhky . uLl_q_Gain [ 0 ] , & rtP . a1ytfvhs5e . input2_Value , &
rtP . dslix2t5ne . input2_Value , & rtP . dslix2t5ne . Gain_Gain , & rtP .
clza3n5d4t . input2_Value , & rtP . clza3n5d4t . Gain_Gain , & rtP .
ghjqwoc3wx . input2_Value , & rtP . puvrgymrfw . u1_Value [ 0 ] , & rtP .
puvrgymrfw . uTT1e6s_Gain_lrfifhs0hf , & rtP . puvrgymrfw .
Integrator_IC_g1shtqvluy , & rtP . puvrgymrfw . uLl_d_Gain [ 0 ] , & rtP .
puvrgymrfw . u2_Value [ 0 ] , & rtP . puvrgymrfw . uTT1e6s_Gain , & rtP .
puvrgymrfw . Integrator_IC , & rtP . puvrgymrfw . uLl_q_Gain [ 0 ] , & rtP .
b0yuwkfotx . input2_Value , & rtP . plxey5q4z3 . input2_Value , & rtP .
plxey5q4z3 . Gain_Gain , & rtP . a12lwium4g . input2_Value , & rtP .
a12lwium4g . Gain_Gain , & rtP . ecdtivcszk . input2_Value , & rtP .
cqi4cjmse0 . u1_Value [ 0 ] , & rtP . cqi4cjmse0 . uTT1e6s_Gain_lrfifhs0hf ,
& rtP . cqi4cjmse0 . Integrator_IC_g1shtqvluy , & rtP . cqi4cjmse0 .
uLl_d_Gain [ 0 ] , & rtP . cqi4cjmse0 . u2_Value [ 0 ] , & rtP . cqi4cjmse0 .
uTT1e6s_Gain , & rtP . cqi4cjmse0 . Integrator_IC , & rtP . cqi4cjmse0 .
uLl_q_Gain [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , SS_UINT8 , 0 , 0 ,
0 } , { "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) ,
SS_BOOLEAN , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } , {
rtwCAPI_VECTOR , 16 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 18 , 2 , 0 } , {
rtwCAPI_VECTOR , 20 , 2 , 0 } , { rtwCAPI_VECTOR , 22 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 24 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 26 , 2
, 0 } , { rtwCAPI_VECTOR , 28 , 2 , 0 } , { rtwCAPI_VECTOR , 30 , 2 , 0 } , {
rtwCAPI_VECTOR , 32 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] =
{ 1 , 1 , 30 , 1 , 6 , 1 , 18 , 1 , 5 , 5 , 5 , 1 , 2 , 1 , 3 , 1 , 1 , 2 ,
81 , 45 , 1 , 4 , 12 , 1 , 81 , 57 , 2 , 3 , 1 , 3 , 1 , 18 , 1 , 5 } ;
static const real_T rtcapiStoredFloats [ ] = { 1.0 , 0.0 , 8.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 2 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , 3 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 1 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 437 , ( NULL
) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 498 , rtModelParameters , 0 }
, { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 1074908781U
, 319055505U , 3192287614U , 1810229351U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * testingV10_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void testingV10_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void testingV10_host_InitializeDataMapInfo ( testingV10_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
