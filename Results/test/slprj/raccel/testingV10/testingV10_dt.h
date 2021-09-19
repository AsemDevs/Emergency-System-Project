#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "struct_Hj9CrByDQJdvNo4enmKmZB" , 14 ,
24 } , { "struct_JScjpLSapONfBxIPyX8hSC" , 15 , 96 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( struct_Hj9CrByDQJdvNo4enmKmZB ) , sizeof
( struct_JScjpLSapONfBxIPyX8hSC ) } ; static const char_T * rtDataTypeNames [
] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "struct_Hj9CrByDQJdvNo4enmKmZB" ,
"struct_JScjpLSapONfBxIPyX8hSC" } ; static DataTypeTransition rtBTransitions
[ ] = { { ( char_T * ) ( & rtB . pgprp2j0mg ) , 0 , 0 , 918 } , { ( char_T *
) ( & rtB . egynfvvlbk ) , 3 , 0 , 3 } , { ( char_T * ) ( & rtB . cqi4cjmse0
. lzzeeexge0 [ 0 ] ) , 0 , 0 , 156 } , { ( char_T * ) ( & rtB . puvrgymrfw .
lzzeeexge0 [ 0 ] ) , 0 , 0 , 156 } , { ( char_T * ) ( & rtB . gqdbtcmlhky .
lzzeeexge0 [ 0 ] ) , 0 , 0 , 156 } , { ( char_T * ) ( & rtDW . k2gqgbs5d5 ) ,
0 , 0 , 21 } , { ( char_T * ) ( & rtDW . djqjasg2hy [ 0 ] ) , 11 , 0 , 54 } ,
{ ( char_T * ) ( & rtDW . gin5y5hus0 [ 0 ] ) , 10 , 0 , 42 } , { ( char_T * )
( & rtDW . nq0bdz3dwr ) , 3 , 0 , 3 } , { ( char_T * ) ( & rtDW . hinb1ade0f
) , 2 , 0 , 9 } , { ( char_T * ) ( & rtDW . c10lhed5jx ) , 8 , 0 , 9 } , { (
char_T * ) ( & rtDW . cqi4cjmse0 . mumkhlfn5t [ 0 ] ) , 0 , 0 , 25 } , { (
char_T * ) ( & rtDW . cqi4cjmse0 . izbjd0yomk ) , 7 , 0 , 2 } , { ( char_T *
) ( & rtDW . cqi4cjmse0 . fov0xqpu0p ) , 10 , 0 , 2 } , { ( char_T * ) ( &
rtDW . cqi4cjmse0 . ene3psc5eg ) , 2 , 0 , 2 } , { ( char_T * ) ( & rtDW .
cqi4cjmse0 . jmnuu5fkfj ) , 8 , 0 , 4 } , { ( char_T * ) ( & rtDW .
ecdtivcszk . iywpiqxv2q ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
a12lwium4g . g33nsvnzmn ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
b0yuwkfotx . pcotaqjtuk ) , 2 , 0 , 2 } , { ( char_T * ) ( & rtDW .
plxey5q4z3 . gxuxajwdt5 ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
puvrgymrfw . mumkhlfn5t [ 0 ] ) , 0 , 0 , 25 } , { ( char_T * ) ( & rtDW .
puvrgymrfw . izbjd0yomk ) , 7 , 0 , 2 } , { ( char_T * ) ( & rtDW .
puvrgymrfw . fov0xqpu0p ) , 10 , 0 , 2 } , { ( char_T * ) ( & rtDW .
puvrgymrfw . ene3psc5eg ) , 2 , 0 , 2 } , { ( char_T * ) ( & rtDW .
puvrgymrfw . jmnuu5fkfj ) , 8 , 0 , 4 } , { ( char_T * ) ( & rtDW .
ghjqwoc3wx . iywpiqxv2q ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
clza3n5d4t . g33nsvnzmn ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
a1ytfvhs5e . pcotaqjtuk ) , 2 , 0 , 2 } , { ( char_T * ) ( & rtDW .
dslix2t5ne . gxuxajwdt5 ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
gqdbtcmlhky . mumkhlfn5t [ 0 ] ) , 0 , 0 , 25 } , { ( char_T * ) ( & rtDW .
gqdbtcmlhky . izbjd0yomk ) , 7 , 0 , 2 } , { ( char_T * ) ( & rtDW .
gqdbtcmlhky . fov0xqpu0p ) , 10 , 0 , 2 } , { ( char_T * ) ( & rtDW .
gqdbtcmlhky . ene3psc5eg ) , 2 , 0 , 2 } , { ( char_T * ) ( & rtDW .
gqdbtcmlhky . jmnuu5fkfj ) , 8 , 0 , 4 } , { ( char_T * ) ( & rtDW .
mfbj0yzfuo4 . iywpiqxv2q ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
e22kv3zqsq0 . g33nsvnzmn ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
igmpp4jfdvg . pcotaqjtuk ) , 2 , 0 , 2 } , { ( char_T * ) ( & rtDW .
attmdly3nwd . gxuxajwdt5 ) , 2 , 0 , 1 } } ; static DataTypeTransitionTable
rtBTransTable = { 38U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . u00kV1000MVA_Frequency ) , 0
, 0 , 43 } , { ( char_T * ) ( & rtP . LimitedCounter_uplimit ) , 3 , 0 , 3 }
, { ( char_T * ) ( & rtP . u1_Y0 ) , 0 , 0 , 9009 } , { ( char_T * ) ( & rtP
. Constant1_Value_fzwmfv0kgm ) , 8 , 0 , 3 } , { ( char_T * ) ( & rtP .
Output_InitialCondition ) , 3 , 0 , 9 } , { ( char_T * ) ( & rtP . cqi4cjmse0
. Lmq_sat_Y0 ) , 0 , 0 , 109 } , { ( char_T * ) ( & rtP . cqi4cjmse0 .
Constant1_Value_cjnzzjd4qz ) , 8 , 0 , 3 } , { ( char_T * ) ( & rtP .
ecdtivcszk . input2_Value ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
a12lwium4g . Gain_Gain ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . b0yuwkfotx
. input2_Value ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP . plxey5q4z3 .
Gain_Gain ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . puvrgymrfw . Lmq_sat_Y0
) , 0 , 0 , 109 } , { ( char_T * ) ( & rtP . puvrgymrfw .
Constant1_Value_cjnzzjd4qz ) , 8 , 0 , 3 } , { ( char_T * ) ( & rtP .
ghjqwoc3wx . input2_Value ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
clza3n5d4t . Gain_Gain ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . a1ytfvhs5e
. input2_Value ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP . dslix2t5ne .
Gain_Gain ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . gqdbtcmlhky . Lmq_sat_Y0
) , 0 , 0 , 109 } , { ( char_T * ) ( & rtP . gqdbtcmlhky .
Constant1_Value_cjnzzjd4qz ) , 8 , 0 , 3 } , { ( char_T * ) ( & rtP .
mfbj0yzfuo4 . input2_Value ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
e22kv3zqsq0 . Gain_Gain ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP .
igmpp4jfdvg . input2_Value ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
attmdly3nwd . Gain_Gain ) , 0 , 0 , 2 } } ; static DataTypeTransitionTable
rtPTransTable = { 23U , rtPTransitions } ;
