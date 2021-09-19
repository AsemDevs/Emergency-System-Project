#include "rt_logging_mmi.h"
#include "testingV10_capi.h"
#include <math.h>
#include "testingV10.h"
#include "testingV10_private.h"
#include "testingV10_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 4 , & stopRequested ) ; }
rtExtModeShutdown ( 4 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "9.3 (R2020a) 18-Nov-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\testingV10\\testingV10_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * tBufPtr ; real_T *
xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer =
3 ; xBuf = * xBufPtr ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) :
0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
tBufPtr = tempT ; * uBufPtr = tempU ; if ( istransportdelay ) * xBufPtr =
tempX ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * tBuf ,
real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
real_T look1_pbinlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table
[ ] , uint32_T prevIndex [ ] , uint32_T maxIndex ) { real_T frac ; uint32_T
iRght ; uint32_T iLeft ; uint32_T bpIdx ; uint32_T found ; if ( u0 <= bp0 [
0U ] ) { bpIdx = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ]
) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = prevIndex [ 0U ] ; iLeft =
0U ; iRght = maxIndex ; found = 0U ; while ( found == 0U ) { if ( u0 < bp0 [
bpIdx ] ) { iRght = bpIdx - 1U ; bpIdx = ( iRght + iLeft ) >> 1U ; } else if
( u0 < bp0 [ bpIdx + 1U ] ) { found = 1U ; } else { iLeft = bpIdx + 1U ;
bpIdx = ( iRght + iLeft ) >> 1U ; } } frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [
bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx = maxIndex - 1U ; frac = ( u0
- bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; }
prevIndex [ 0U ] = bpIdx ; return ( table [ bpIdx + 1U ] - table [ bpIdx ] )
* frac + table [ bpIdx ] ; } real_T look1_binlcpw ( real_T u0 , const real_T
bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) { real_T frac ;
uint32_T iRght ; uint32_T iLeft ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) {
iLeft = 0U ; frac = 0.0 ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx =
maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght - iLeft > 1U )
{ if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; }
bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [
iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ; frac = 1.0
; } return ( table [ iLeft + 1U ] - table [ iLeft ] ) * frac + table [ iLeft
] ; } real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T
table [ ] , uint32_T maxIndex ) { real_T frac ; uint32_T iRght ; uint32_T
iLeft ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 -
bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex
] ) { bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght
- iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft =
bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) /
( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ;
frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex -
1U ] ) ; } return ( table [ iLeft + 1U ] - table [ iLeft ] ) * frac + table [
iLeft ] ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void mbwj5xxyv5 (
SimStruct * rtS_e ) { if ( ssGetTaskTime ( rtS_e , 1 ) != ssGetTStart ( rtS_e
) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_e ) ; } } void
julesvnt2d ( SimStruct * rtS_p ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS_p ) ; } void attmdly3nw ( SimStruct * rtS_i , real_T ayyzh10w3r ,
real_T * j0u5w4s5kd , d2o1h43yf5 * localP ) { if ( ssIsSampleHit ( rtS_i , 1
, 0 ) ) { * j0u5w4s5kd = ( localP -> input2_Value - ayyzh10w3r ) * localP ->
Gain_Gain ; } } void cmjweld2k1 ( SimStruct * rtS_i ) { if ( ssGetTaskTime (
rtS_i , 1 ) != ssGetTStart ( rtS_i ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; } } void ab0lumfo3e (
SimStruct * rtS_m ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_m ) ;
} void igmpp4jfdv ( SimStruct * rtS_e , real_T nozwu1f12r , real_T *
jkusnymiui , acuaihhzpu * localP ) { real_T nm3q0dg25l ; if ( ssIsSampleHit (
rtS_e , 1 , 0 ) ) { nm3q0dg25l = localP -> input2_Value - nozwu1f12r *
nozwu1f12r ; if ( nm3q0dg25l < 0.0 ) { * jkusnymiui = - muDoubleScalarSqrt (
muDoubleScalarAbs ( nm3q0dg25l ) ) ; } else { * jkusnymiui =
muDoubleScalarSqrt ( nm3q0dg25l ) ; } } } void a5me1li4az ( SimStruct * rtS_p
) { if ( ssGetTaskTime ( rtS_p , 1 ) != ssGetTStart ( rtS_p ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_p ) ; } } void fwicy1bcaz (
SimStruct * rtS_g ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_g ) ;
} void e22kv3zqsq ( SimStruct * rtS_j , real_T gp5wlbp5k2 , real_T *
d4vsegz52q , bek1yqg5mv * localP ) { if ( ssIsSampleHit ( rtS_j , 1 , 0 ) ) {
* d4vsegz52q = localP -> input2_Value - localP -> Gain_Gain * gp5wlbp5k2 ; }
} void doisemfibt ( SimStruct * rtS_m ) { if ( ssGetTaskTime ( rtS_m , 1 ) !=
ssGetTStart ( rtS_m ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_m
) ; } } void j34hurn5mj ( SimStruct * rtS_f ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_f ) ; } void mfbj0yzfuo (
SimStruct * rtS_c , real_T * biep1lmlsg , ozd4wyfuvi * localP ) { if (
ssIsSampleHit ( rtS_c , 1 , 0 ) ) { * biep1lmlsg = localP -> input2_Value ; }
} void rt_invd5x5_snf ( const real_T u [ 25 ] , real_T y [ 25 ] ) { int8_T p
[ 5 ] ; real_T A [ 25 ] ; int8_T ipiv [ 5 ] ; int32_T pipk ; int32_T jj ;
int32_T jp1j ; int32_T jBcol ; int32_T c ; int32_T ix ; real_T smax ; real_T
s ; int32_T iy ; int32_T jA ; int32_T ijA ; for ( iy = 0 ; iy < 25 ; iy ++ )
{ y [ iy ] = 0.0 ; A [ iy ] = u [ iy ] ; } for ( iy = 0 ; iy < 5 ; iy ++ ) {
ipiv [ iy ] = ( int8_T ) ( iy + 1 ) ; } for ( pipk = 0 ; pipk < 4 ; pipk ++ )
{ jBcol = pipk * 6 + 2 ; jj = pipk * 6 ; c = 5 - pipk ; iy = 1 ; ix = jBcol -
2 ; smax = muDoubleScalarAbs ( A [ jj ] ) ; for ( jA = 2 ; jA <= c ; jA ++ )
{ ix ++ ; s = muDoubleScalarAbs ( A [ ix ] ) ; if ( s > smax ) { iy = jA ;
smax = s ; } } if ( A [ ( jBcol + iy ) - 3 ] != 0.0 ) { if ( iy - 1 != 0 ) {
ipiv [ pipk ] = ( int8_T ) ( pipk + iy ) ; ix = pipk ; iy = ( pipk + iy ) - 1
; for ( jA = 0 ; jA < 5 ; jA ++ ) { smax = A [ ix ] ; A [ ix ] = A [ iy ] ; A
[ iy ] = smax ; ix += 5 ; iy += 5 ; } } iy = jBcol - pipk ; for ( ix = jBcol
; ix <= iy + 3 ; ix ++ ) { A [ ix - 1 ] /= A [ jj ] ; } } c = 3 - pipk ; jA =
jj ; jj += 5 ; for ( jp1j = 0 ; jp1j <= c ; jp1j ++ ) { if ( A [ jj ] != 0.0
) { smax = - A [ jj ] ; ix = jBcol - 1 ; iy = jA - pipk ; for ( ijA = jA + 7
; ijA <= iy + 10 ; ijA ++ ) { A [ ijA - 1 ] += A [ ix ] * smax ; ix ++ ; } }
jj += 5 ; jA += 5 ; } } for ( iy = 0 ; iy < 5 ; iy ++ ) { p [ iy ] = ( int8_T
) ( iy + 1 ) ; } if ( ipiv [ 0 ] > 1 ) { pipk = p [ ipiv [ 0 ] - 1 ] ; p [
ipiv [ 0 ] - 1 ] = p [ 0 ] ; p [ 0 ] = ( int8_T ) pipk ; } if ( ipiv [ 1 ] >
2 ) { pipk = p [ ipiv [ 1 ] - 1 ] ; p [ ipiv [ 1 ] - 1 ] = p [ 1 ] ; p [ 1 ]
= ( int8_T ) pipk ; } if ( ipiv [ 2 ] > 3 ) { pipk = p [ ipiv [ 2 ] - 1 ] ; p
[ ipiv [ 2 ] - 1 ] = p [ 2 ] ; p [ 2 ] = ( int8_T ) pipk ; } if ( ipiv [ 3 ]
> 4 ) { pipk = p [ ipiv [ 3 ] - 1 ] ; p [ ipiv [ 3 ] - 1 ] = p [ 3 ] ; p [ 3
] = ( int8_T ) pipk ; } for ( jA = 0 ; jA < 5 ; jA ++ ) { jBcol = p [ jA ] -
1 ; y [ jA + 5 * ( p [ jA ] - 1 ) ] = 1.0 ; for ( pipk = jA + 1 ; pipk < 6 ;
pipk ++ ) { if ( y [ ( 5 * jBcol + pipk ) - 1 ] != 0.0 ) { for ( ix = pipk +
1 ; ix < 6 ; ix ++ ) { y [ ( ix + 5 * jBcol ) - 1 ] -= A [ ( ( pipk - 1 ) * 5
+ ix ) - 1 ] * y [ ( 5 * jBcol + pipk ) - 1 ] ; } } } } for ( pipk = 0 ; pipk
< 5 ; pipk ++ ) { jBcol = 5 * pipk ; for ( jA = 4 ; jA >= 0 ; jA -- ) { jj =
5 * jA ; if ( y [ jA + jBcol ] != 0.0 ) { y [ jA + jBcol ] /= A [ jA + jj ] ;
iy = jA - 1 ; for ( ix = 0 ; ix <= iy ; ix ++ ) { y [ ix + jBcol ] -= y [ jA
+ jBcol ] * A [ ix + jj ] ; } } } } } void f3adcfr20z ( hy4g22ft5l * localB ,
chh2ehjaxn * localP , pb1p3lro1p * localX ) { int32_T i ; localX ->
k0qcscyfkp = localP -> Integrator_IC_g1shtqvluy ; localX -> fj3dlbq3k3 =
localP -> Integrator_IC ; localB -> privppgr4h = localP -> Lmq_sat_Y0 ;
localB -> b3l11gphfb = localP -> Laq_Y0 ; for ( i = 0 ; i < 25 ; i ++ ) {
localB -> anumpx44cp [ i ] = localP -> Linv_Y0 ; localB -> nyt32tufuy [ i ] =
localP -> RLinv_Y0 ; } localB -> kguc1xjgtq = localP -> Lmqd_Y0 ; localB ->
k33sqomjhg = localP -> Lmqd_Y0 ; localB -> fbja1wrd5n = localP -> Laqd_Y0 ;
localB -> dknardu53j = localP -> Laqd_Y0 ; } void gz4umw2aaz ( ixnicbdqnf *
localDW ) { localDW -> axnuixsnfy = false ; localDW -> d4fx2pljzn = false ; }
void mner3hbxuo ( SimStruct * rtS_k , ixnicbdqnf * localDW , p4cqd5zcze *
localXdis ) { localDW -> d4fx2pljzn = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_k ) ; ( void ) memset ( & (
localXdis -> k0qcscyfkp ) , 1 , 2 * sizeof ( boolean_T ) ) ; localDW ->
axnuixsnfy = false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS_k ) ;
localXdis -> fj3dlbq3k3 = 1 ; } void gqdbtcmlhk ( SimStruct * rtS_b , real_T
ihtr2n3nur , const real_T brkujkabcz [ 5 ] , hy4g22ft5l * localB , ixnicbdqnf
* localDW , chh2ehjaxn * localP , pb1p3lro1p * localX , p4cqd5zcze *
localXdis ) { int32_T i ; int32_T i_p ; int32_T i_e ; if ( ssIsSampleHit (
rtS_b , 1 , 0 ) && ssIsMajorTimeStep ( rtS_b ) ) { if ( ihtr2n3nur > 0.0 ) {
if ( ! localDW -> d4fx2pljzn ) { if ( ssGetTaskTime ( rtS_b , 1 ) !=
ssGetTStart ( rtS_b ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_b
) ; } ( void ) memset ( & ( localXdis -> k0qcscyfkp ) , 0 , 2 * sizeof (
boolean_T ) ) ; localDW -> d4fx2pljzn = true ; } } else { if ( localDW ->
d4fx2pljzn ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_b ) ; ( void
) memset ( & ( localXdis -> k0qcscyfkp ) , 1 , 2 * sizeof ( boolean_T ) ) ;
gz4umw2aaz ( localDW ) ; } } } if ( localDW -> d4fx2pljzn ) { localB ->
lzzeeexge0 [ 0 ] = localP -> uLl_d_Gain [ 0 ] * brkujkabcz [ 1 ] ; localB ->
lzzeeexge0 [ 1 ] = localP -> uLl_d_Gain [ 1 ] * brkujkabcz [ 2 ] ; localB ->
lzzeeexge0 [ 2 ] = localP -> uLl_d_Gain [ 2 ] * brkujkabcz [ 3 ] ; localB ->
iwuvpqmdqd = ( localB -> lzzeeexge0 [ 0 ] + localB -> lzzeeexge0 [ 1 ] ) +
localB -> lzzeeexge0 [ 2 ] ; localB -> m0j312cexm = localX -> k0qcscyfkp ;
localB -> dgj2vlo3ae = ( localP -> u1_Value [ 0 ] + localP -> u1_Value [ 1 ]
) + 1.0 / localB -> m0j312cexm ; localB -> dknardu53j = 1.0 / localB ->
dgj2vlo3ae ; localB -> bqfae1z4xm = localB -> iwuvpqmdqd * localB ->
dknardu53j ; if ( ssIsMajorTimeStep ( rtS_b ) ) { localDW -> fov0xqpu0p = (
localB -> bqfae1z4xm >= 0.0 ) ; } localB -> kkho4m250n = localDW ->
fov0xqpu0p > 0 ? localB -> bqfae1z4xm : - localB -> bqfae1z4xm ; localB ->
ebabsrxrur = look1_pbinlxpw ( localB -> kkho4m250n , localP ->
uDLookupTable_bp01Data_ksienufmbo , localP ->
uDLookupTable_tableData_imh4jt4ucy , & localDW -> izbjd0yomk , 1U ) ; if (
ssIsMajorTimeStep ( rtS_b ) ) { localDW -> jmnuu5fkfj = ( localB ->
ebabsrxrur != 0.0 ) ; } if ( localDW -> jmnuu5fkfj ) { localB -> mc0nzpa2g2 =
localB -> kkho4m250n / localB -> ebabsrxrur ; localB -> iytz0y3ucg = localB
-> mc0nzpa2g2 ; } else { localB -> iytz0y3ucg = localP ->
Constant1_Value_dvrakrgzwa ; } localB -> k33sqomjhg = localP -> Lmd_Gain *
localB -> iytz0y3ucg ; localB -> jtahvktmal = localB -> k33sqomjhg - localB
-> m0j312cexm ; localB -> okkine1bpp = localP -> uTT1e6s_Gain_lrfifhs0hf *
localB -> jtahvktmal ; if ( ssIsSampleHit ( rtS_b , 1 , 0 ) &&
ssIsMajorTimeStep ( rtS_b ) ) { if ( localP -> Constant1_Value_cjnzzjd4qz ) {
if ( ! localDW -> axnuixsnfy ) { if ( ssGetTaskTime ( rtS_b , 1 ) !=
ssGetTStart ( rtS_b ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_b
) ; } localXdis -> fj3dlbq3k3 = 0 ; localDW -> axnuixsnfy = true ; } } else {
if ( localDW -> axnuixsnfy ) { ssSetBlockStateForSolverChangedAtMajorStep (
rtS_b ) ; localXdis -> fj3dlbq3k3 = 1 ; localDW -> axnuixsnfy = false ; } } }
if ( localDW -> axnuixsnfy ) { localB -> hcoloefwbj [ 0 ] = localP ->
uLl_q_Gain [ 0 ] * brkujkabcz [ 0 ] ; localB -> hcoloefwbj [ 1 ] = localP ->
uLl_q_Gain [ 1 ] * brkujkabcz [ 4 ] ; localB -> igfp3wt3zj = localB ->
hcoloefwbj [ 0 ] + localB -> hcoloefwbj [ 1 ] ; localB -> kdysf2sgiq = localX
-> fj3dlbq3k3 ; localB -> hyzrfwdn0b = ( ( localP -> u2_Value [ 0 ] + localP
-> u2_Value [ 1 ] ) + localP -> u2_Value [ 2 ] ) + 1.0 / localB -> kdysf2sgiq
; localB -> b3l11gphfb = 1.0 / localB -> hyzrfwdn0b ; localB -> ahmbzjodez =
localB -> igfp3wt3zj * localB -> b3l11gphfb ; if ( ssIsMajorTimeStep ( rtS_b
) ) { localDW -> mw1c4diklt = ( localB -> ahmbzjodez >= 0.0 ) ; } localB ->
f2a01aevzv = localDW -> mw1c4diklt > 0 ? localB -> ahmbzjodez : - localB ->
ahmbzjodez ; localB -> ifyloqp5tf = look1_pbinlxpw ( localB -> f2a01aevzv ,
localP -> uDLookupTable_bp01Data , localP -> uDLookupTable_tableData , &
localDW -> pjr2nuseh4 , 1U ) ; if ( ssIsMajorTimeStep ( rtS_b ) ) { localDW
-> itnod251z1 = ( localB -> ifyloqp5tf != 0.0 ) ; } if ( localDW ->
itnod251z1 ) { localB -> j5vjugftgu = localB -> f2a01aevzv / localB ->
ifyloqp5tf ; localB -> ihs5uzpoqs = localB -> j5vjugftgu ; } else { localB ->
ihs5uzpoqs = localP -> Constant1_Value ; } localB -> privppgr4h = localP ->
Lmq_Gain * localB -> ihs5uzpoqs ; localB -> i2v1etu5n3 = localB -> privppgr4h
- localB -> kdysf2sgiq ; localB -> oelb25yqch = localP -> uTT1e6s_Gain *
localB -> i2v1etu5n3 ; if ( ssIsMajorTimeStep ( rtS_b ) ) { srUpdateBC (
localDW -> lwv41vwpbg ) ; } } if ( localP -> Constant2_Value ) { localB ->
kguc1xjgtq = localB -> privppgr4h ; } else { localB -> kguc1xjgtq = localP ->
u3_Value ; } memcpy ( & localB -> e4eaoc3n4j [ 0 ] , & localP ->
u1_Value_kxgxvrotpn [ 0 ] , 25U * sizeof ( real_T ) ) ; localB -> e4eaoc3n4j
[ 0 ] = localB -> kguc1xjgtq ; localB -> e4eaoc3n4j [ 4 ] = localB ->
kguc1xjgtq ; localB -> e4eaoc3n4j [ 20 ] = localB -> kguc1xjgtq ; localB ->
e4eaoc3n4j [ 24 ] = localB -> kguc1xjgtq ; memcpy ( & localB -> dos2ao4wzk [
0 ] , & localB -> e4eaoc3n4j [ 0 ] , 25U * sizeof ( real_T ) ) ; for ( i = 0
; i < 3 ; i ++ ) { localB -> dos2ao4wzk [ 5 * ( i + 1 ) + 1 ] = localB ->
k33sqomjhg ; localB -> dos2ao4wzk [ 5 * ( i + 1 ) + 2 ] = localB ->
k33sqomjhg ; localB -> dos2ao4wzk [ 5 * ( i + 1 ) + 3 ] = localB ->
k33sqomjhg ; } for ( i = 0 ; i < 25 ; i ++ ) { localB -> akb1ib2amz [ i ] =
localB -> dos2ao4wzk [ i ] + localP -> u5_Value [ i ] ; } rt_invd5x5_snf (
localB -> akb1ib2amz , localB -> anumpx44cp ) ; for ( i = 0 ; i < 5 ; i ++ )
{ for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { localB -> nyt32tufuy [ i_p + 5 * i ] =
0.0 ; for ( i_e = 0 ; i_e < 5 ; i_e ++ ) { localB -> nyt32tufuy [ i_p + 5 * i
] += localP -> u1_Value_gb2ffz550q [ 5 * i_e + i_p ] * localB -> anumpx44cp [
5 * i + i_e ] ; } } } if ( localP -> Constant3_Value ) { localB -> fbja1wrd5n
= localB -> b3l11gphfb ; } else { localB -> fbja1wrd5n = localP ->
u2_Value_ofkq3wczs0 ; } if ( ssIsMajorTimeStep ( rtS_b ) ) { srUpdateBC (
localDW -> ene3psc5eg ) ; } } } void gqdbtcmlhkTID4 ( SimStruct * rtS_p ,
ixnicbdqnf * localDW ) { if ( ssIsMajorTimeStep ( rtS_p ) ) { srUpdateBC (
localDW -> lwv41vwpbg ) ; srUpdateBC ( localDW -> ene3psc5eg ) ; } } void
gh4mkhetsb ( hy4g22ft5l * localB , ixnicbdqnf * localDW , gawmg1mpfd *
localXdot ) { if ( localDW -> d4fx2pljzn ) { localXdot -> k0qcscyfkp = localB
-> okkine1bpp ; if ( localDW -> axnuixsnfy ) { localXdot -> fj3dlbq3k3 =
localB -> oelb25yqch ; } else { localXdot -> fj3dlbq3k3 = 0.0 ; } } else { {
real_T * dx ; int_T i ; dx = & ( localXdot -> k0qcscyfkp ) ; for ( i = 0 ; i
< 2 ; i ++ ) { dx [ i ] = 0.0 ; } } } } void nlzkrjo2aq ( hy4g22ft5l * localB
, ixnicbdqnf * localDW , j4bdse2byj * localZCSV ) { if ( localDW ->
d4fx2pljzn ) { localZCSV -> nazqzeqojt = localB -> bqfae1z4xm ; localZCSV ->
cq0bpaoclk = localB -> ebabsrxrur ; if ( localDW -> axnuixsnfy ) { localZCSV
-> lbgqimsikx = localB -> ahmbzjodez ; localZCSV -> i5mzhw5zf3 = localB ->
ifyloqp5tf ; } else { { real_T * zcsv = & ( localZCSV -> lbgqimsikx ) ; int_T
i ; for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i ] = 0.0 ; } } } } else { { real_T
* zcsv = & ( localZCSV -> nazqzeqojt ) ; int_T i ; for ( i = 0 ; i < 4 ; i ++
) { zcsv [ i ] = 0.0 ; } } } } void MdlInitialize ( void ) { int32_T i ; rtX
. dxcqn52y0j = rtP . Rotorangledtheta_IC ; rtX . ftxl3ve1we = rtP .
Rotorangledtheta_IC_jattgadt2d ; rtX . pbf0mwqvxu = rtP .
Rotorangledtheta_IC_ino2tfu01n ; for ( i = 0 ; i < 5 ; i ++ ) { rtX .
prvbwmxe5d [ i ] = rtP . Integrator_IC [ i ] ; rtX . cqlekexsf4 [ i ] = rtP .
Integrator_IC_penjbqiku4 [ i ] ; rtX . ezu3nw0jme [ i ] = rtP .
Integrator_IC_hskzo4cis1 [ i ] ; } { SimStruct * rts = ssGetSFunction ( rtS ,
0 ) ; sfcnInitializeConditions ( rts ) ; if ( ssGetErrorStatus ( rts ) != (
NULL ) ) return ; } rtX . ipldudc4jc = rtP . Rotorspeeddeviationdw_IC ; rtX .
i5wyejvw00 = rtP . Integrator_IC_dwtmatqar4 ; rtDW . nq0bdz3dwr = rtP .
Output_InitialCondition ; rtX . jzaacseaxt = rtP . theta_IC ; rtX .
ir2k1m2xef [ 0 ] = 0.0 ; rtX . ir2k1m2xef [ 1 ] = 0.0 ; rtX . ccho5ckvhr =
rtP . DieselEngineGovernor_Pm0 ; rtX . oq42ze3zlo = 0.0 ; rtX . jlygjdr5nw =
0.0 ; rtX . fo31vd32p4 = rtP . StateSpace_InitialCondition ; rtX . mir041liby
= rtP . Integrator_IC_pvpv3edcbn ; rtX . jz4lzneeo1 = rtP .
StateSpace_InitialCondition_dxz5ijbicj ; rtX . ebee4njyij = rtP .
Rotorspeeddeviationdw_IC_o43mhwbr2s ; rtX . i302uyv4ub = rtP .
Integrator_IC_cbuanuvuvp ; rtDW . dntwmboj5l = rtP .
Output_InitialCondition_kgl5nejq40 ; rtX . cvoatslkxn = rtP .
theta_IC_dprjmrmwfq ; rtX . ozdje1tbeq [ 0 ] = 0.0 ; rtX . ozdje1tbeq [ 1 ] =
0.0 ; rtX . c3odb1pgdi = rtP . DieselEngineGovernor_Pm0_kdo13i53e1 ; rtX .
dumyo0mi3u = 0.0 ; rtX . mjljeeps1u = 0.0 ; rtX . e32unymcc4 = rtP .
StateSpace_InitialCondition_huivxjzddm ; rtX . om4zueiy1s = rtP .
Integrator_IC_h2sy3kxvaj ; rtX . nafgdh5awp = rtP .
StateSpace_InitialCondition_o3b0kscpl2 ; rtX . pvsfs5bviq = rtP .
Rotorspeeddeviationdw_IC_mgh0oddmta ; rtX . oh1bpz4njz = rtP .
Integrator_IC_pyisyjlvgu ; rtDW . hdwuwozgch = rtP .
Output_InitialCondition_koai1wfyjy ; rtX . mtfzfgh35r = rtP .
theta_IC_nuqyp4ahc0 ; rtX . kvt4cjhlrh [ 0 ] = 0.0 ; rtX . kvt4cjhlrh [ 1 ] =
0.0 ; rtX . nk334zxlzp = rtP . DieselEngineGovernor_Pm0_a40shkker5 ; rtX .
geip5cv4tr = 0.0 ; rtX . j51tfhhdgm = 0.0 ; rtX . icyr0u0hwc = rtP .
StateSpace_InitialCondition_ldzhin2tip ; rtX . b0v4jzhvdz = rtP .
Integrator_IC_jdcpelpvxo ; rtX . mia0akgecm = rtP .
StateSpace_InitialCondition_bacyfv3a4h ; rtDW . k2gqgbs5d5 = ( rtInf ) ; rtDW
. mgitsq1y4c = ( rtInf ) ; rtDW . kydy0dzs4q = ( rtInf ) ; rtDW . ix3txx30gm
= ( rtInf ) ; rtDW . dfk5fcernw = ( rtInf ) ; rtDW . excno4hjxp = ( rtInf ) ;
rtDW . g0ztsagyor = ( rtInf ) ; rtDW . fetl5keei4 = ( rtInf ) ; f3adcfr20z (
& rtB . cqi4cjmse0 , & rtP . cqi4cjmse0 , & rtX . cqi4cjmse0 ) ; f3adcfr20z (
& rtB . gqdbtcmlhky , & rtP . gqdbtcmlhky , & rtX . gqdbtcmlhky ) ;
f3adcfr20z ( & rtB . puvrgymrfw , & rtP . puvrgymrfw , & rtX . puvrgymrfw ) ;
rtB . obphrpkole = rtP . u1_Y0 ; rtB . opow2w1mi1 = rtP . u2_Y0 ; rtB .
npyj2l24ut = rtP . u3_Y0 ; } void MdlStart ( void ) { { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void *
* pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } mner3hbxuo ( rtS , & rtDW .
gqdbtcmlhky , & ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) -> gqdbtcmlhky
) ; mner3hbxuo ( rtS , & rtDW . puvrgymrfw , & ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> puvrgymrfw ) ; mner3hbxuo ( rtS , & rtDW
. cqi4cjmse0 , & ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) -> cqi4cjmse0
) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnStart ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } rtDW . pom54x2oll . Tail = 0 ; rtDW . pom54x2oll . Head = 0 ; rtDW
. pom54x2oll . Last = 0 ; rtDW . pom54x2oll . CircularBufSize = 1024 ;
pBuffer [ 0 ] = rtP . DieselEngineGovernor_Pm0 ; pBuffer [ 1024 ] = ssGetT (
rtS ) ; rtDW . d2mee5ywuy . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ;
rtDW . d2mee5ywuy . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } }
rtDW . hinb1ade0f = - 1 ; rtDW . lzjsd04kej = - 1 ; { { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ;
return ; } rtDW . g35ini334z . Tail = 0 ; rtDW . g35ini334z . Head = 0 ; rtDW
. g35ini334z . Last = 0 ; rtDW . g35ini334z . CircularBufSize = 1024 ;
pBuffer [ 0 ] = rtP . DieselEngineGovernor_Pm0_kdo13i53e1 ; pBuffer [ 1024 ]
= ssGetT ( rtS ) ; rtDW . iin0a1rkif . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; rtDW . iin0a1rkif . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer
[ 1024 ] ; } } rtDW . hz40ksez24 = - 1 ; rtDW . a20bqbbboc = - 1 ; { { real_T
* pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) )
; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . aexlfdwpio . Tail = 0
; rtDW . aexlfdwpio . Head = 0 ; rtDW . aexlfdwpio . Last = 0 ; rtDW .
aexlfdwpio . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
DieselEngineGovernor_Pm0_a40shkker5 ; pBuffer [ 1024 ] = ssGetT ( rtS ) ;
rtDW . abwpuwwzkr . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
abwpuwwzkr . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } rtDW .
ajv3iwzytl = - 1 ; rtDW . jdvbg1vzm5 = - 1 ; MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T * lastU ; real_T glrhaqk1if ; real_T
jglko44zhq ; real_T lrfvawl2h3 ; real_T oo0vu2anpb ; real_T cq5g3ezsl5 ;
real_T msgortbjk0 ; real_T fst0n4qoax ; real_T bouhabhtxj ; real_T dziq0k4vk2
; real_T n0hkaqfprr ; real_T fxg223krhh ; real_T bvtlrzy045 ; real_T
mzxkqyo0ez ; int8_T rtPrevAction ; int8_T rtAction ; uint8_T dqp2jl35hv ;
real_T dqu31pvks0 ; uint8_T e1b3j5bavz ; uint8_T cpkdq1wvkh ; int32_T i ;
int32_T i_p ; srClearBC ( rtDW . fkvhgnbbpt ) ; srClearBC ( rtDW . ewfusfxrh1
) ; srClearBC ( rtDW . msqb4sdl5r ) ; srClearBC ( rtDW . attmdly3nwd .
gxuxajwdt5 ) ; srClearBC ( rtDW . igmpp4jfdvg . pcotaqjtuk ) ; srClearBC (
rtDW . e22kv3zqsq0 . g33nsvnzmn ) ; srClearBC ( rtDW . mfbj0yzfuo4 .
iywpiqxv2q ) ; srClearBC ( rtDW . gqdbtcmlhky . lwv41vwpbg ) ; srClearBC (
rtDW . gqdbtcmlhky . ene3psc5eg ) ; rtB . pgprp2j0mg = rtX . dxcqn52y0j ; rtB
. kckr1rsmi3 = rtP . web2_Gain * ssGetT ( rtS ) ; rtB . owqdlcfz5i = rtB .
pgprp2j0mg + rtB . kckr1rsmi3 ; muDoubleScalarSinCos ( rtB . owqdlcfz5i , &
glrhaqk1if , & jglko44zhq ) ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . j2hq00la3s
[ i ] = rtX . prvbwmxe5d [ i ] ; } gqdbtcmlhk ( rtS , rtP .
Constant1_Value_gju1j5culq , rtB . j2hq00la3s , & rtB . cqi4cjmse0 , & rtDW .
cqi4cjmse0 , & rtP . cqi4cjmse0 , & rtX . cqi4cjmse0 , & ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> cqi4cjmse0 ) ; if ( rtP .
Constant3_Value_ftweuv5hbb >= rtP . Switch_Threshold_es5p4ljhx5 ) { memcpy (
& rtB . kxg24koyh2 [ 0 ] , & rtB . cqi4cjmse0 . anumpx44cp [ 0 ] , 25U *
sizeof ( real_T ) ) ; } else { memcpy ( & rtB . kxg24koyh2 [ 0 ] , & rtP .
Constant4_Value_kflxryerzb [ 0 ] , 25U * sizeof ( real_T ) ) ; } for ( i = 0
; i < 5 ; i ++ ) { rtB . p2ppvvojae [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 5 ;
i_p ++ ) { rtB . p2ppvvojae [ i ] += rtB . kxg24koyh2 [ 5 * i_p + i ] * rtB .
j2hq00la3s [ i_p ] ; } rtB . dk1omp4wet [ i ] = rtP .
changeIqIdcurrentsigns_Gain [ i ] * rtB . p2ppvvojae [ i ] ; } bouhabhtxj =
rtB . dk1omp4wet [ 0 ] * jglko44zhq + rtB . dk1omp4wet [ 1 ] * glrhaqk1if ;
dziq0k4vk2 = ( ( - rtB . dk1omp4wet [ 0 ] - 1.7320508075688772 * rtB .
dk1omp4wet [ 1 ] ) * jglko44zhq + ( 1.7320508075688772 * rtB . dk1omp4wet [ 0
] - rtB . dk1omp4wet [ 1 ] ) * glrhaqk1if ) * 0.5 ; rtB . pq54vjdlkq = ( 0.0
- bouhabhtxj ) - dziq0k4vk2 ; rtB . mhvoaxr3ny [ 0 ] = rtP . ib_Gain *
bouhabhtxj ; rtB . mhvoaxr3ny [ 1 ] = rtP . ib_Gain * dziq0k4vk2 ; rtB .
mhvoaxr3ny [ 2 ] = rtP . ib_Gain * rtB . pq54vjdlkq ; rtB . dymy5fczgx = rtX
. ftxl3ve1we ; rtB . ndv1chiwse = rtP . web2_Gain_lxgspwzlqe * ssGetT ( rtS )
; rtB . danklhdtjg = rtB . dymy5fczgx + rtB . ndv1chiwse ;
muDoubleScalarSinCos ( rtB . danklhdtjg , & lrfvawl2h3 , & oo0vu2anpb ) ; for
( i = 0 ; i < 5 ; i ++ ) { rtB . nyuxeims25 [ i ] = rtX . cqlekexsf4 [ i ] ;
} gqdbtcmlhk ( rtS , rtP . Constant1_Value_iqgflwhd0e , rtB . nyuxeims25 , &
rtB . gqdbtcmlhky , & rtDW . gqdbtcmlhky , & rtP . gqdbtcmlhky , & rtX .
gqdbtcmlhky , & ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) -> gqdbtcmlhky
) ; if ( rtP . Constant3_Value_bcu1pnrcxc >= rtP .
Switch_Threshold_e2e0xrm3uu ) { memcpy ( & rtB . my41lqaa3e [ 0 ] , & rtB .
gqdbtcmlhky . anumpx44cp [ 0 ] , 25U * sizeof ( real_T ) ) ; } else { memcpy
( & rtB . my41lqaa3e [ 0 ] , & rtP . Constant4_Value_f2c3xayuty [ 0 ] , 25U *
sizeof ( real_T ) ) ; } for ( i = 0 ; i < 5 ; i ++ ) { rtB . axuxlimqfo [ i ]
= 0.0 ; for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { rtB . axuxlimqfo [ i ] += rtB .
my41lqaa3e [ 5 * i_p + i ] * rtB . nyuxeims25 [ i_p ] ; } rtB . d51r4ddhlp [
i ] = rtP . changeIqIdcurrentsigns_Gain_devnvm2504 [ i ] * rtB . axuxlimqfo [
i ] ; } n0hkaqfprr = rtB . d51r4ddhlp [ 0 ] * oo0vu2anpb + rtB . d51r4ddhlp [
1 ] * lrfvawl2h3 ; fxg223krhh = ( ( - rtB . d51r4ddhlp [ 0 ] -
1.7320508075688772 * rtB . d51r4ddhlp [ 1 ] ) * oo0vu2anpb + (
1.7320508075688772 * rtB . d51r4ddhlp [ 0 ] - rtB . d51r4ddhlp [ 1 ] ) *
lrfvawl2h3 ) * 0.5 ; rtB . mhlj2wouuq = ( 0.0 - n0hkaqfprr ) - fxg223krhh ;
rtB . oyz4fl5tkc [ 0 ] = rtP . ib_Gain_k0uiynd021 * n0hkaqfprr ; rtB .
oyz4fl5tkc [ 1 ] = rtP . ib_Gain_k0uiynd021 * fxg223krhh ; rtB . oyz4fl5tkc [
2 ] = rtP . ib_Gain_k0uiynd021 * rtB . mhlj2wouuq ; rtB . cqvzl34lfs = rtX .
pbf0mwqvxu ; rtB . ds252cwh3s = rtP . web2_Gain_hafoo1lium * ssGetT ( rtS ) ;
rtB . jrbkd00tcm = rtB . cqvzl34lfs + rtB . ds252cwh3s ; muDoubleScalarSinCos
( rtB . jrbkd00tcm , & cq5g3ezsl5 , & msgortbjk0 ) ; for ( i = 0 ; i < 5 ; i
++ ) { rtB . p2ubfcpe4u [ i ] = rtX . ezu3nw0jme [ i ] ; } gqdbtcmlhk ( rtS ,
rtP . Constant1_Value_bhms2ohso1 , rtB . p2ubfcpe4u , & rtB . puvrgymrfw , &
rtDW . puvrgymrfw , & rtP . puvrgymrfw , & rtX . puvrgymrfw , & ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> puvrgymrfw ) ; if ( rtP .
Constant3_Value_ekoy4aaewq >= rtP . Switch_Threshold_i2gzs1aal3 ) { memcpy (
& rtB . jt2zr3xuyu [ 0 ] , & rtB . puvrgymrfw . anumpx44cp [ 0 ] , 25U *
sizeof ( real_T ) ) ; } else { memcpy ( & rtB . jt2zr3xuyu [ 0 ] , & rtP .
Constant4_Value_a4umnvtiwg [ 0 ] , 25U * sizeof ( real_T ) ) ; } for ( i = 0
; i < 5 ; i ++ ) { rtB . i3xfrtnhpx [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 5 ;
i_p ++ ) { rtB . i3xfrtnhpx [ i ] += rtB . jt2zr3xuyu [ 5 * i_p + i ] * rtB .
p2ubfcpe4u [ i_p ] ; } rtB . ivbwlhlxla [ i ] = rtP .
changeIqIdcurrentsigns_Gain_oeffjb2exf [ i ] * rtB . i3xfrtnhpx [ i ] ; }
bvtlrzy045 = rtB . ivbwlhlxla [ 0 ] * msgortbjk0 + rtB . ivbwlhlxla [ 1 ] *
cq5g3ezsl5 ; mzxkqyo0ez = ( ( - rtB . ivbwlhlxla [ 0 ] - 1.7320508075688772 *
rtB . ivbwlhlxla [ 1 ] ) * msgortbjk0 + ( 1.7320508075688772 * rtB .
ivbwlhlxla [ 0 ] - rtB . ivbwlhlxla [ 1 ] ) * cq5g3ezsl5 ) * 0.5 ; rtB .
ncljwqtey4 = ( 0.0 - bvtlrzy045 ) - mzxkqyo0ez ; rtB . h2jybzg354 [ 0 ] = rtP
. ib_Gain_a5iu43yzxn * bvtlrzy045 ; rtB . h2jybzg354 [ 1 ] = rtP .
ib_Gain_a5iu43yzxn * mzxkqyo0ez ; rtB . h2jybzg354 [ 2 ] = rtP .
ib_Gain_a5iu43yzxn * rtB . ncljwqtey4 ; rtB . d5bucyfqa0 = muDoubleScalarSin
( 6.2831853071795862 * rtP . u00kV1000MVA_Frequency * ssGetTaskTime ( rtS , 0
) + rtP . SineWaveA_Phase ) * rtP . SineWaveA_Amp + rtP . SineWaveA_Bias ;
rtB . icdvip4qf2 = muDoubleScalarSin ( 6.2831853071795862 * rtP .
u00kV1000MVA_Frequency * ssGetTaskTime ( rtS , 0 ) + rtP . SineWaveB_Phase )
* rtP . SineWaveB_Amp + rtP . SineWaveB_Bias ; rtB . ltfwzxychx =
muDoubleScalarSin ( 6.2831853071795862 * rtP . u00kV1000MVA_Frequency *
ssGetTaskTime ( rtS , 0 ) + rtP . SineWaveC_Phase ) * rtP . SineWaveC_Amp +
rtP . SineWaveC_Bias ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnOutputs ( rts , 0 ) ; } rtB . byg1ydrnj5 = rtX . ipldudc4jc ; rtB .
ebqjy0h1vz = rtP . nomspeed_Value + rtB . byg1ydrnj5 ; rtB . fhocpb4rlk = rtP
. units_Gain * rtB . ebqjy0h1vz ; { real_T * * uBuffer = ( real_T * * ) &
rtDW . d2mee5ywuy . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& rtDW . d2mee5ywuy . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T tMinusDelay = simTime - rtP . DieselEngineGovernor_Td ; rtB .
ogontexkwa = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer
, rtDW . pom54x2oll . CircularBufSize , & rtDW . pom54x2oll . Last , rtDW .
pom54x2oll . Tail , rtDW . pom54x2oll . Head , rtP . DieselEngineGovernor_Pm0
, 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput (
rtS ) == ssGetT ( rtS ) ) ) ) ; } rtB . bzmzsahkz0 = rtB . ogontexkwa * rtB .
fhocpb4rlk ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtX . i5wyejvw00 >= rtP
. Integrator_UpperSat ) { if ( rtX . i5wyejvw00 > rtP . Integrator_UpperSat )
{ ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . i5wyejvw00 =
rtP . Integrator_UpperSat ; } else { if ( rtX . i5wyejvw00 <= rtP .
Integrator_LowerSat ) { if ( rtX . i5wyejvw00 < rtP . Integrator_LowerSat ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . i5wyejvw00 = rtP
. Integrator_LowerSat ; } } } rtB . bqh4htctpf = rtX . i5wyejvw00 ; if ( rtP
. Constant1_Value_fzwmfv0kgm ) { rtB . npdbafvddp = rtB . d51r4ddhlp [ 0 ] ;
} else { rtB . npdbafvddp = rtP . Constant2_Value_epm55skuqn ; } rtB .
lnfeerzdwl [ 0 ] = rtP . uLl_q_Gain [ 0 ] * rtB . nyuxeims25 [ 0 ] ; rtB .
lnfeerzdwl [ 1 ] = rtP . uLl_q_Gain [ 1 ] * rtB . nyuxeims25 [ 4 ] ; if ( rtP
. Constant8_Value >= rtP . Switch3_Threshold ) { rtB . ll5lhtaahm [ 0 ] = rtB
. gqdbtcmlhky . fbja1wrd5n ; rtB . ll5lhtaahm [ 1 ] = rtB . gqdbtcmlhky .
dknardu53j ; } else { rtB . ll5lhtaahm [ 0 ] = rtP . Laqd_nosat_Value [ 0 ] ;
rtB . ll5lhtaahm [ 1 ] = rtP . Laqd_nosat_Value [ 1 ] ; } rtB . omolj25xda [
0 ] = rtB . lnfeerzdwl [ 0 ] * rtB . ll5lhtaahm [ 0 ] ; rtB . omolj25xda [ 1
] = rtB . lnfeerzdwl [ 1 ] * rtB . ll5lhtaahm [ 0 ] ; rtB . e3cyuxmtad = rtB
. omolj25xda [ 0 ] + rtB . omolj25xda [ 1 ] ; rtB . n5u3z30051 [ 0 ] = rtP .
uLl_d_Gain [ 0 ] * rtB . nyuxeims25 [ 1 ] ; rtB . h0135r1dh0 [ 0 ] = rtB .
n5u3z30051 [ 0 ] * rtB . ll5lhtaahm [ 1 ] ; rtB . n5u3z30051 [ 1 ] = rtP .
uLl_d_Gain [ 1 ] * rtB . nyuxeims25 [ 2 ] ; rtB . h0135r1dh0 [ 1 ] = rtB .
n5u3z30051 [ 1 ] * rtB . ll5lhtaahm [ 1 ] ; rtB . n5u3z30051 [ 2 ] = rtP .
uLl_d_Gain [ 2 ] * rtB . nyuxeims25 [ 3 ] ; rtB . h0135r1dh0 [ 2 ] = rtB .
n5u3z30051 [ 2 ] * rtB . ll5lhtaahm [ 1 ] ; rtB . hn1104ars0 = ( rtB .
h0135r1dh0 [ 0 ] + rtB . h0135r1dh0 [ 1 ] ) + rtB . h0135r1dh0 [ 2 ] ; rtB .
fbmjaug21p [ 0 ] = rtP . u_Vb_Gain * rtB . bx1vifjqa5 [ 2 ] ; rtB .
fbmjaug21p [ 1 ] = rtP . u_Vb_Gain * rtB . bx1vifjqa5 [ 3 ] ; fst0n4qoax = (
( 2.0 * rtB . fbmjaug21p [ 0 ] + rtB . fbmjaug21p [ 1 ] ) * oo0vu2anpb +
1.7320508075688772 * rtB . fbmjaug21p [ 1 ] * lrfvawl2h3 ) *
0.33333333333333331 ; lrfvawl2h3 = ( ( 2.0 * rtB . fbmjaug21p [ 0 ] + rtB .
fbmjaug21p [ 1 ] ) * lrfvawl2h3 + - 1.7320508075688772 * rtB . fbmjaug21p [ 1
] * oo0vu2anpb ) * 0.33333333333333331 ; if ( rtP .
Constant5_Value_kqupx0gkxm >= rtP . Switch2_Threshold_gl2dnbpcoc ) { rtB .
ml5evcnodk [ 0 ] = rtB . gqdbtcmlhky . kguc1xjgtq ; rtB . ml5evcnodk [ 1 ] =
rtB . gqdbtcmlhky . k33sqomjhg ; } else { rtB . ml5evcnodk [ 0 ] = rtP .
Lmqd_nosat_Value [ 0 ] ; rtB . ml5evcnodk [ 1 ] = rtP . Lmqd_nosat_Value [ 1
] ; } rtB . ifzgu2ee1l = rtP . Gain_Gain * muDoubleScalarAtan2 ( lrfvawl2h3 ,
fst0n4qoax ) ; rtB . m5o0jbgvyx = fst0n4qoax * rtB . d51r4ddhlp [ 0 ] ; rtB .
pizp5zm00a = lrfvawl2h3 * rtB . d51r4ddhlp [ 1 ] ; rtB . nhjs51s1ph = rtB .
m5o0jbgvyx + rtB . pizp5zm00a ; rtB . kql5exxrek = rtP . Gain_Gain_go11vj5gb1
* rtB . nhjs51s1ph ; rtB . od1v53lcod = fst0n4qoax * rtB . d51r4ddhlp [ 1 ] ;
rtB . iucqalgajz = lrfvawl2h3 * rtB . d51r4ddhlp [ 0 ] ; rtB . pfuip4apkg =
rtB . od1v53lcod - rtB . iucqalgajz ; rtB . oeedo4set2 = rtP . Gain1_Gain *
rtB . pfuip4apkg ; rtB . axj0g1at3l [ 0 ] = rtP . outputformatting_Gain [ 0 ]
* n0hkaqfprr ; rtB . axj0g1at3l [ 1 ] = rtP . outputformatting_Gain [ 1 ] *
fxg223krhh ; rtB . axj0g1at3l [ 2 ] = rtP . outputformatting_Gain [ 2 ] * rtB
. mhlj2wouuq ; rtB . axj0g1at3l [ 3 ] = rtP . outputformatting_Gain [ 3 ] *
rtB . d51r4ddhlp [ 0 ] ; rtB . axj0g1at3l [ 4 ] = rtP . outputformatting_Gain
[ 4 ] * rtB . d51r4ddhlp [ 1 ] ; rtB . axj0g1at3l [ 5 ] = rtP .
outputformatting_Gain [ 5 ] * rtB . d51r4ddhlp [ 2 ] ; rtB . axj0g1at3l [ 6 ]
= rtP . outputformatting_Gain [ 6 ] * rtB . d51r4ddhlp [ 4 ] ; rtB .
axj0g1at3l [ 7 ] = rtP . outputformatting_Gain [ 7 ] * rtB . npdbafvddp ; rtB
. axj0g1at3l [ 8 ] = rtP . outputformatting_Gain [ 8 ] * rtB . d51r4ddhlp [ 3
] ; rtB . axj0g1at3l [ 9 ] = rtP . outputformatting_Gain [ 9 ] * rtB .
e3cyuxmtad ; rtB . axj0g1at3l [ 10 ] = rtP . outputformatting_Gain [ 10 ] *
rtB . hn1104ars0 ; rtB . axj0g1at3l [ 11 ] = rtP . outputformatting_Gain [ 11
] * fst0n4qoax ; rtB . axj0g1at3l [ 12 ] = rtP . outputformatting_Gain [ 12 ]
* lrfvawl2h3 ; rtB . axj0g1at3l [ 13 ] = rtP . outputformatting_Gain [ 13 ] *
rtB . ml5evcnodk [ 0 ] ; rtB . axj0g1at3l [ 14 ] = rtP .
outputformatting_Gain [ 14 ] * rtB . ml5evcnodk [ 1 ] ; rtB . axj0g1at3l [ 15
] = rtP . outputformatting_Gain [ 15 ] * rtB . ifzgu2ee1l ; rtB . axj0g1at3l
[ 16 ] = rtP . outputformatting_Gain [ 16 ] * rtB . kql5exxrek ; rtB .
axj0g1at3l [ 17 ] = rtP . outputformatting_Gain [ 17 ] * rtB . oeedo4set2 ;
rtB . eiwmp0uix0 = rtB . axj0g1at3l [ 5 ] / ( ( real_T ) ( rtB . bqh4htctpf
== 0.0 ) * 2.2204460492503131e-16 + rtB . bqh4htctpf ) * rtP . AC1A_Kc ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtPrevAction = rtDW . hinb1ade0f ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . c10lhed5jx = ( rtB . eiwmp0uix0 <= rtP .
input_Value ) ; rtDW . jyij4nxr4z = ( rtB . eiwmp0uix0 < rtP . input1_Value )
; rtDW . ohi2tzs1ww = ( rtB . eiwmp0uix0 <= rtP . input2_Value ) ; switch ( (
rtDW . c10lhed5jx + rtDW . jyij4nxr4z ) + rtDW . ohi2tzs1ww ) { case 1 :
rtAction = 0 ; break ; case 2 : rtAction = 1 ; break ; case 3 : rtAction = 2
; break ; default : rtAction = 3 ; break ; } rtDW . hinb1ade0f = rtAction ; }
else { rtAction = rtDW . hinb1ade0f ; } if ( rtPrevAction != rtAction ) {
switch ( rtPrevAction ) { case 0 : julesvnt2d ( rtS ) ; break ; case 1 :
ab0lumfo3e ( rtS ) ; break ; case 2 : fwicy1bcaz ( rtS ) ; break ; case 3 :
j34hurn5mj ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction
!= rtPrevAction ) { mbwj5xxyv5 ( rtS ) ; } attmdly3nw ( rtS , rtB .
eiwmp0uix0 , & rtB . amufqu02uc , & rtP . attmdly3nwd ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . attmdly3nwd . gxuxajwdt5 )
; } break ; case 1 : if ( rtAction != rtPrevAction ) { cmjweld2k1 ( rtS ) ; }
igmpp4jfdv ( rtS , rtB . eiwmp0uix0 , & rtB . amufqu02uc , & rtP .
igmpp4jfdvg ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
igmpp4jfdvg . pcotaqjtuk ) ; } break ; case 2 : if ( rtAction != rtPrevAction
) { a5me1li4az ( rtS ) ; } e22kv3zqsq ( rtS , rtB . eiwmp0uix0 , & rtB .
amufqu02uc , & rtP . e22kv3zqsq0 ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . e22kv3zqsq0 . g33nsvnzmn ) ; } break ; case 3 : if (
rtAction != rtPrevAction ) { doisemfibt ( rtS ) ; } mfbj0yzfuo ( rtS , & rtB
. amufqu02uc , & rtP . mfbj0yzfuo4 ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . mfbj0yzfuo4 . iywpiqxv2q ) ; } break ; } } rtB .
hvcpcic14r = rtB . bqh4htctpf * rtB . amufqu02uc ; oo0vu2anpb =
muDoubleScalarPower ( rtB . axj0g1at3l [ 12 ] , 2.0 ) + muDoubleScalarPower (
rtB . axj0g1at3l [ 11 ] , 2.0 ) ; if ( oo0vu2anpb < 0.0 ) { rtB . npq14v1sxw
= - muDoubleScalarSqrt ( - oo0vu2anpb ) ; } else { rtB . npq14v1sxw =
muDoubleScalarSqrt ( oo0vu2anpb ) ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) {
dqp2jl35hv = rtDW . nq0bdz3dwr ; rtB . pkqtmwmhph = look1_binlcpw ( ( real_T
) rtDW . nq0bdz3dwr * rtP . SampleTimeMath_WtEt , rtP .
RepeatingSequenceInterpolated8_TimeValues , rtP .
RepeatingSequenceInterpolated8_OutValues , 2U ) ; } if ( ssIsSampleHit ( rtS
, 2 , 0 ) ) { rtB . e02gvifuul = rtP . Constant3_Value ; if ( rtB .
e02gvifuul > rtP . Switch1_Threshold_nhwesj444w ) { dqu31pvks0 = rtP .
Constant4_Value ; } else { dqu31pvks0 = rtP . Constant5_Value ; }
rtPrevAction = rtDW . lzjsd04kej ; rtAction = - 1 ; if ( ssIsMajorTimeStep (
rtS ) ) { if ( dqu31pvks0 == 1.0 ) { rtAction = 0 ; } rtDW . lzjsd04kej =
rtAction ; } else { rtAction = rtDW . lzjsd04kej ; } if ( ( rtPrevAction !=
rtAction ) && ( rtPrevAction == 0 ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } if ( rtAction == 0 ) {
if ( 0 != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 2 ) != ssGetTStart (
rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB .
obphrpkole = rtB . pkqtmwmhph ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC
( rtDW . fkvhgnbbpt ) ; } } if ( dqu31pvks0 > rtP .
Switch2_Threshold_cpu03sarvk ) { oo0vu2anpb = rtB . obphrpkole ; } else {
oo0vu2anpb = rtP . Constant1_Value ; } if ( oo0vu2anpb > rtP .
Switch1_Threshold_i5r3mlizx4 ) { rtB . cpqapklze4 = rtP .
Constant1_Value_ls0pawmfdq ; } else { rtB . cpqapklze4 = rtP . Constant_Value
; } } rtB . mtaotlu3kj [ 0 ] = rtP . u1_Gain [ 0 ] * rtB . d51r4ddhlp [ 0 ] ;
rtB . mtaotlu3kj [ 1 ] = rtP . u1_Gain [ 1 ] * rtB . d51r4ddhlp [ 1 ] ; rtB .
iodshzwwqj [ 0 ] = rtB . nyuxeims25 [ 1 ] * rtB . mtaotlu3kj [ 0 ] ; rtB .
iodshzwwqj [ 1 ] = rtB . nyuxeims25 [ 0 ] * rtB . mtaotlu3kj [ 1 ] ; rtB .
d2i2d0pjwa = rtB . iodshzwwqj [ 0 ] + rtB . iodshzwwqj [ 1 ] ; rtB .
k3g1mw2mb1 = rtB . ebqjy0h1vz * rtB . d2i2d0pjwa * rtP . units1_Gain ; rtB .
ms5yftyqp5 = rtX . jzaacseaxt ; rtB . icpch50dox = rtP . t_Gain *
muDoubleScalarRem ( rtB . ms5yftyqp5 , 6.2831853071795862 ) ; rtB .
ou5as25oqf = rtP . units2_Gain * rtB . d2i2d0pjwa ; rtB . ckbwyd51fw = 0.0 ;
rtB . ckbwyd51fw += rtP . CONTROLSYSTEM_C [ 0 ] * rtX . ir2k1m2xef [ 0 ] ;
rtB . ckbwyd51fw += rtP . CONTROLSYSTEM_C [ 1 ] * rtX . ir2k1m2xef [ 1 ] ;
rtB . g3tr54e0gh = rtP . DieselEngineGovernor_K * rtB . ckbwyd51fw ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtX . ccho5ckvhr >= rtP .
Integrator_UpperSat_f4njfmemxq ) { if ( rtX . ccho5ckvhr > rtP .
Integrator_UpperSat_f4njfmemxq ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } rtX . ccho5ckvhr = rtP . Integrator_UpperSat_f4njfmemxq ; } else
{ if ( rtX . ccho5ckvhr <= rtP . Integrator_LowerSat_dbtbuno0hm ) { if ( rtX
. ccho5ckvhr < rtP . Integrator_LowerSat_dbtbuno0hm ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . ccho5ckvhr = rtP
. Integrator_LowerSat_dbtbuno0hm ; } } } rtB . ajb0jd1wax = rtX . ccho5ckvhr
; rtB . lmjgudxydq = rtB . cpqapklze4 - rtB . fhocpb4rlk ; rtB . mgwenfy132 =
0.0 ; rtB . mgwenfy132 += rtP . TF1_C * rtX . oq42ze3zlo ; rtB . mgwenfy132
+= rtP . TF1_D * rtB . g3tr54e0gh ; rtB . edtnmnr3vm = 0.0 ; rtB . edtnmnr3vm
+= rtP . TF2_C * rtX . jlygjdr5nw ; rtB . kb4mvzq0n3 = rtB . bqh4htctpf *
look1_binlxpw ( rtB . bqh4htctpf , rtP . Saturation_bp01Data , rtP .
Saturation_tableData , 2U ) ; rtB . i45iq1kx0r = rtP . Gain3_Gain * rtB .
bqh4htctpf ; rtB . p4byd4k51j = rtB . kb4mvzq0n3 + rtB . i45iq1kx0r ; rtB .
gz2qcnyb1c = rtP . AC1A_Kd * rtB . axj0g1at3l [ 5 ] ; rtB . d3prvaxezv = rtB
. p4byd4k51j + rtB . gz2qcnyb1c ; rtB . emn13j4iq4 = 0.0 ; rtB . emn13j4iq4
+= rtP . StateSpace_C * rtX . fo31vd32p4 ; rtB . emn13j4iq4 += rtP .
StateSpace_D * rtB . d3prvaxezv ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtX
. mir041liby >= rtP . Integrator_UpperSat_drvyrbacf3 ) { if ( rtX .
mir041liby > rtP . Integrator_UpperSat_drvyrbacf3 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . mir041liby = rtP
. Integrator_UpperSat_drvyrbacf3 ; } else { if ( rtX . mir041liby <= rtP .
Integrator_LowerSat_hx5r22dn01 ) { if ( rtX . mir041liby < rtP .
Integrator_LowerSat_hx5r22dn01 ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } rtX . mir041liby = rtP . Integrator_LowerSat_hx5r22dn01 ; } } }
rtB . k2ed141a0b = rtX . mir041liby ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW
. g4jaeoabjw = rtB . k2ed141a0b >= rtP . VRmin_UpperSat ? 1 : rtB .
k2ed141a0b > rtP . VRmin_LowerSat ? 0 : - 1 ; } rtB . l5tveyumnb = rtDW .
g4jaeoabjw == 1 ? rtP . VRmin_UpperSat : rtDW . g4jaeoabjw == - 1 ? rtP .
VRmin_LowerSat : rtB . k2ed141a0b ; rtB . fsbjhr5dz0 = rtB . l5tveyumnb - rtB
. d3prvaxezv ; rtB . asp4dkpswc = rtP . Gain_Gain_ffnxwopg3s * rtB .
fsbjhr5dz0 ; rtB . b1zkykkz5k = 0.0 ; rtB . b1zkykkz5k += rtP .
StateSpace_C_m5ukcmidnd * rtX . jz4lzneeo1 ; rtB . fg4jwggqvs = ( ( rtP .
Vtrefpu_Value + rtP . Vfe0Ka_Value ) - rtB . b1zkykkz5k ) - rtB . emn13j4iq4
; rtB . di4ji05v0o = 0.0 ; rtB . di4ji05v0o += rtP . StateSpace_D_irddqmjpbm
* rtB . fg4jwggqvs ; rtB . my43lbhgf2 = rtP . Vaminmax_Ka * rtB . di4ji05v0o
; rtB . pm0bgbsy3o = rtB . my43lbhgf2 - rtB . k2ed141a0b ; rtB . kkwarc0rc1 =
1.0 / rtP . Vaminmax_Ta * rtB . pm0bgbsy3o ; rtB . bwynwxckua = rtP . N_Gain
* rtB . hvcpcic14r ; rtB . lh3hq5cwil = rtP . Gain1_Gain_moin2woj4i * rtB .
ebqjy0h1vz ; for ( i = 0 ; i < 25 ; i ++ ) { rtB . k2cexfls20 [ i ] = rtP .
u1_Value [ i ] ; rtB . lo2ggdoibh [ i ] = rtB . k2cexfls20 [ i ] ; } rtB .
lo2ggdoibh [ 5 ] = rtB . ebqjy0h1vz ; memcpy ( & rtB . oydhroyllb [ 0 ] , &
rtB . lo2ggdoibh [ 0 ] , 25U * sizeof ( real_T ) ) ; rtB . oydhroyllb [ 1 ] =
rtB . lh3hq5cwil ; if ( rtP . Constant2_Value_aotbypyuon >= rtP .
Switch1_Threshold_aftgfs3nnz ) { memcpy ( & rtB . bzuabr4dvk [ 0 ] , & rtB .
gqdbtcmlhky . nyt32tufuy [ 0 ] , 25U * sizeof ( real_T ) ) ; } else { memcpy
( & rtB . bzuabr4dvk [ 0 ] , & rtP . Constant6_Value_aag1qbkfgz [ 0 ] , 25U *
sizeof ( real_T ) ) ; } for ( i = 0 ; i < 25 ; i ++ ) { rtB . muljazi4vt [ i
] = ( 0.0 - rtB . oydhroyllb [ i ] ) - rtB . bzuabr4dvk [ i ] ; } for ( i_p =
0 ; i_p < 5 ; i_p ++ ) { rtB . haa5p2ptdq [ i_p ] = 0.0 ; for ( i = 0 ; i < 5
; i ++ ) { rtB . haa5p2ptdq [ i_p ] += rtB . muljazi4vt [ 5 * i + i_p ] * rtB
. nyuxeims25 [ i ] ; } } rtB . gtamjmvbh0 [ 0 ] = fst0n4qoax + rtB .
haa5p2ptdq [ 0 ] ; rtB . gtamjmvbh0 [ 1 ] = lrfvawl2h3 + rtB . haa5p2ptdq [ 1
] ; rtB . gtamjmvbh0 [ 2 ] = rtB . bwynwxckua + rtB . haa5p2ptdq [ 2 ] ; rtB
. gtamjmvbh0 [ 3 ] = rtP . Vkd0Vkq10Vkq20_Value [ 0 ] + rtB . haa5p2ptdq [ 3
] ; rtB . gtamjmvbh0 [ 4 ] = rtP . Vkd0Vkq10Vkq20_Value [ 1 ] + rtB .
haa5p2ptdq [ 4 ] ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . grwocktd5q [ i ] =
rtP . wbase_Gain * rtB . gtamjmvbh0 [ i ] ; } rtB . ljw0dnybdy = rtP .
u_Pb_Gain * rtB . bzmzsahkz0 ; rtB . ay3br3a3hq = rtP . F1_Gain * rtB .
ebqjy0h1vz ; rtB . pqzx0wtulf = ( rtB . ljw0dnybdy / ( rtB . ebqjy0h1vz +
2.2204460492503131e-16 ) - rtB . d2i2d0pjwa ) - rtB . ay3br3a3hq ; rtB .
ol0nkdk5rw = rtP . u_2H_Gain * rtB . pqzx0wtulf ; rtB . brvzzfgdkk = rtP .
web1_Gain * rtB . byg1ydrnj5 ; rtB . ljxtwfbyom = rtP . web3_Gain * rtB .
ebqjy0h1vz ; rtB . jbq05nhwpa = rtX . ebee4njyij ; rtB . npvosve4cu = rtP .
nomspeed_Value_gur000lokn + rtB . jbq05nhwpa ; rtB . lcbyglc5pf = rtP .
units_Gain_iq4q232a3o * rtB . npvosve4cu ; { real_T * * uBuffer = ( real_T *
* ) & rtDW . iin0a1rkif . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & rtDW . iin0a1rkif . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT (
rtS ) ; real_T tMinusDelay = simTime - rtP .
DieselEngineGovernor_Td_khwtk020bh ; rtB . jbvbomnw2p = rt_TDelayInterpolate
( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . g35ini334z .
CircularBufSize , & rtDW . g35ini334z . Last , rtDW . g35ini334z . Tail ,
rtDW . g35ini334z . Head , rtP . DieselEngineGovernor_Pm0_kdo13i53e1 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) ==
ssGetT ( rtS ) ) ) ) ; } rtB . p0ztjxbfsc = rtB . jbvbomnw2p * rtB .
lcbyglc5pf ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtX . i302uyv4ub >= rtP
. Integrator_UpperSat_emevdxcfrg ) { if ( rtX . i302uyv4ub > rtP .
Integrator_UpperSat_emevdxcfrg ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } rtX . i302uyv4ub = rtP . Integrator_UpperSat_emevdxcfrg ; } else
{ if ( rtX . i302uyv4ub <= rtP . Integrator_LowerSat_b2xzznseid ) { if ( rtX
. i302uyv4ub < rtP . Integrator_LowerSat_b2xzznseid ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . i302uyv4ub = rtP
. Integrator_LowerSat_b2xzznseid ; } } } rtB . leh2oxynn2 = rtX . i302uyv4ub
; if ( rtP . Constant1_Value_pwpdsgpubt ) { rtB . e3mykpbvxu = rtB .
ivbwlhlxla [ 0 ] ; } else { rtB . e3mykpbvxu = rtP .
Constant2_Value_ie44msnx1e ; } rtB . cbo535uscm [ 0 ] = rtP .
uLl_q_Gain_jh4fgceov2 [ 0 ] * rtB . p2ubfcpe4u [ 0 ] ; rtB . cbo535uscm [ 1 ]
= rtP . uLl_q_Gain_jh4fgceov2 [ 1 ] * rtB . p2ubfcpe4u [ 4 ] ; if ( rtP .
Constant8_Value_erv12cit4q >= rtP . Switch3_Threshold_pdefg51fln ) { rtB .
nwlcni0prp [ 0 ] = rtB . puvrgymrfw . fbja1wrd5n ; rtB . nwlcni0prp [ 1 ] =
rtB . puvrgymrfw . dknardu53j ; } else { rtB . nwlcni0prp [ 0 ] = rtP .
Laqd_nosat_Value_i2eposfmya [ 0 ] ; rtB . nwlcni0prp [ 1 ] = rtP .
Laqd_nosat_Value_i2eposfmya [ 1 ] ; } rtB . ezhs2i41dg [ 0 ] = rtB .
cbo535uscm [ 0 ] * rtB . nwlcni0prp [ 0 ] ; rtB . ezhs2i41dg [ 1 ] = rtB .
cbo535uscm [ 1 ] * rtB . nwlcni0prp [ 0 ] ; rtB . k1bgn3kbs2 = rtB .
ezhs2i41dg [ 0 ] + rtB . ezhs2i41dg [ 1 ] ; rtB . gwqqhvgmz0 [ 0 ] = rtP .
uLl_d_Gain_ksdp1qfju0 [ 0 ] * rtB . p2ubfcpe4u [ 1 ] ; rtB . mrhppm5nnj [ 0 ]
= rtB . gwqqhvgmz0 [ 0 ] * rtB . nwlcni0prp [ 1 ] ; rtB . gwqqhvgmz0 [ 1 ] =
rtP . uLl_d_Gain_ksdp1qfju0 [ 1 ] * rtB . p2ubfcpe4u [ 2 ] ; rtB . mrhppm5nnj
[ 1 ] = rtB . gwqqhvgmz0 [ 1 ] * rtB . nwlcni0prp [ 1 ] ; rtB . gwqqhvgmz0 [
2 ] = rtP . uLl_d_Gain_ksdp1qfju0 [ 2 ] * rtB . p2ubfcpe4u [ 3 ] ; rtB .
mrhppm5nnj [ 2 ] = rtB . gwqqhvgmz0 [ 2 ] * rtB . nwlcni0prp [ 1 ] ; rtB .
effezdjmri = ( rtB . mrhppm5nnj [ 0 ] + rtB . mrhppm5nnj [ 1 ] ) + rtB .
mrhppm5nnj [ 2 ] ; rtB . n34rsgjlm4 [ 0 ] = rtP . u_Vb_Gain_fxx3jygcme * rtB
. bx1vifjqa5 [ 4 ] ; rtB . n34rsgjlm4 [ 1 ] = rtP . u_Vb_Gain_fxx3jygcme *
rtB . bx1vifjqa5 [ 5 ] ; n0hkaqfprr = ( ( 2.0 * rtB . n34rsgjlm4 [ 0 ] + rtB
. n34rsgjlm4 [ 1 ] ) * msgortbjk0 + 1.7320508075688772 * rtB . n34rsgjlm4 [ 1
] * cq5g3ezsl5 ) * 0.33333333333333331 ; cq5g3ezsl5 = ( ( 2.0 * rtB .
n34rsgjlm4 [ 0 ] + rtB . n34rsgjlm4 [ 1 ] ) * cq5g3ezsl5 + -
1.7320508075688772 * rtB . n34rsgjlm4 [ 1 ] * msgortbjk0 ) *
0.33333333333333331 ; if ( rtP . Constant5_Value_owzacacl1u >= rtP .
Switch2_Threshold_ouaxae3tuq ) { rtB . keaofkpcfk [ 0 ] = rtB . puvrgymrfw .
kguc1xjgtq ; rtB . keaofkpcfk [ 1 ] = rtB . puvrgymrfw . k33sqomjhg ; } else
{ rtB . keaofkpcfk [ 0 ] = rtP . Lmqd_nosat_Value_guprarme5m [ 0 ] ; rtB .
keaofkpcfk [ 1 ] = rtP . Lmqd_nosat_Value_guprarme5m [ 1 ] ; } rtB .
ibx54rryug = rtP . Gain_Gain_n4b4vqpdms * muDoubleScalarAtan2 ( cq5g3ezsl5 ,
n0hkaqfprr ) ; rtB . b3cqfd55dr = n0hkaqfprr * rtB . ivbwlhlxla [ 0 ] ; rtB .
cbome3ugdq = cq5g3ezsl5 * rtB . ivbwlhlxla [ 1 ] ; rtB . hjjlvvkayj = rtB .
b3cqfd55dr + rtB . cbome3ugdq ; rtB . meaoaylidx = rtP . Gain_Gain_kd3xkntxif
* rtB . hjjlvvkayj ; rtB . aacdpemjnp = n0hkaqfprr * rtB . ivbwlhlxla [ 1 ] ;
rtB . jtkc3lsddk = cq5g3ezsl5 * rtB . ivbwlhlxla [ 0 ] ; rtB . o03eqw4qg4 =
rtB . aacdpemjnp - rtB . jtkc3lsddk ; rtB . hnovtssll3 = rtP .
Gain1_Gain_lni3n3ja03 * rtB . o03eqw4qg4 ; rtB . fsskatoni2 [ 0 ] = rtP .
outputformatting_Gain_ghuljw3lhk [ 0 ] * bvtlrzy045 ; rtB . fsskatoni2 [ 1 ]
= rtP . outputformatting_Gain_ghuljw3lhk [ 1 ] * mzxkqyo0ez ; rtB .
fsskatoni2 [ 2 ] = rtP . outputformatting_Gain_ghuljw3lhk [ 2 ] * rtB .
ncljwqtey4 ; rtB . fsskatoni2 [ 3 ] = rtP . outputformatting_Gain_ghuljw3lhk
[ 3 ] * rtB . ivbwlhlxla [ 0 ] ; rtB . fsskatoni2 [ 4 ] = rtP .
outputformatting_Gain_ghuljw3lhk [ 4 ] * rtB . ivbwlhlxla [ 1 ] ; rtB .
fsskatoni2 [ 5 ] = rtP . outputformatting_Gain_ghuljw3lhk [ 5 ] * rtB .
ivbwlhlxla [ 2 ] ; rtB . fsskatoni2 [ 6 ] = rtP .
outputformatting_Gain_ghuljw3lhk [ 6 ] * rtB . ivbwlhlxla [ 4 ] ; rtB .
fsskatoni2 [ 7 ] = rtP . outputformatting_Gain_ghuljw3lhk [ 7 ] * rtB .
e3mykpbvxu ; rtB . fsskatoni2 [ 8 ] = rtP . outputformatting_Gain_ghuljw3lhk
[ 8 ] * rtB . ivbwlhlxla [ 3 ] ; rtB . fsskatoni2 [ 9 ] = rtP .
outputformatting_Gain_ghuljw3lhk [ 9 ] * rtB . k1bgn3kbs2 ; rtB . fsskatoni2
[ 10 ] = rtP . outputformatting_Gain_ghuljw3lhk [ 10 ] * rtB . effezdjmri ;
rtB . fsskatoni2 [ 11 ] = rtP . outputformatting_Gain_ghuljw3lhk [ 11 ] *
n0hkaqfprr ; rtB . fsskatoni2 [ 12 ] = rtP . outputformatting_Gain_ghuljw3lhk
[ 12 ] * cq5g3ezsl5 ; rtB . fsskatoni2 [ 13 ] = rtP .
outputformatting_Gain_ghuljw3lhk [ 13 ] * rtB . keaofkpcfk [ 0 ] ; rtB .
fsskatoni2 [ 14 ] = rtP . outputformatting_Gain_ghuljw3lhk [ 14 ] * rtB .
keaofkpcfk [ 1 ] ; rtB . fsskatoni2 [ 15 ] = rtP .
outputformatting_Gain_ghuljw3lhk [ 15 ] * rtB . ibx54rryug ; rtB . fsskatoni2
[ 16 ] = rtP . outputformatting_Gain_ghuljw3lhk [ 16 ] * rtB . meaoaylidx ;
rtB . fsskatoni2 [ 17 ] = rtP . outputformatting_Gain_ghuljw3lhk [ 17 ] * rtB
. hnovtssll3 ; rtB . lds45me1tz = rtB . fsskatoni2 [ 5 ] / ( ( real_T ) ( rtB
. leh2oxynn2 == 0.0 ) * 2.2204460492503131e-16 + rtB . leh2oxynn2 ) * rtP .
AC1A_Kc_lp3kwbrdlq ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtPrevAction =
rtDW . hz40ksez24 ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . dpd2hvdwgh = (
rtB . lds45me1tz <= rtP . input_Value_j4v0x1onoy ) ; rtDW . ayvci0hmjr = (
rtB . lds45me1tz < rtP . input1_Value_jwembzy4jc ) ; rtDW . pzm1pkcrzf = (
rtB . lds45me1tz <= rtP . input2_Value_mfn5w3js4u ) ; switch ( ( rtDW .
dpd2hvdwgh + rtDW . ayvci0hmjr ) + rtDW . pzm1pkcrzf ) { case 1 : rtAction =
0 ; break ; case 2 : rtAction = 1 ; break ; case 3 : rtAction = 2 ; break ;
default : rtAction = 3 ; break ; } rtDW . hz40ksez24 = rtAction ; } else {
rtAction = rtDW . hz40ksez24 ; } if ( rtPrevAction != rtAction ) { switch (
rtPrevAction ) { case 0 : julesvnt2d ( rtS ) ; break ; case 1 : ab0lumfo3e (
rtS ) ; break ; case 2 : fwicy1bcaz ( rtS ) ; break ; case 3 : j34hurn5mj (
rtS ) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction !=
rtPrevAction ) { mbwj5xxyv5 ( rtS ) ; } attmdly3nw ( rtS , rtB . lds45me1tz ,
& rtB . ipenwii4hv , & rtP . dslix2t5ne ) ; if ( ssIsMajorTimeStep ( rtS ) )
{ srUpdateBC ( rtDW . dslix2t5ne . gxuxajwdt5 ) ; } break ; case 1 : if (
rtAction != rtPrevAction ) { cmjweld2k1 ( rtS ) ; } igmpp4jfdv ( rtS , rtB .
lds45me1tz , & rtB . ipenwii4hv , & rtP . a1ytfvhs5e ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . a1ytfvhs5e . pcotaqjtuk ) ;
} break ; case 2 : if ( rtAction != rtPrevAction ) { a5me1li4az ( rtS ) ; }
e22kv3zqsq ( rtS , rtB . lds45me1tz , & rtB . ipenwii4hv , & rtP . clza3n5d4t
) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . clza3n5d4t .
g33nsvnzmn ) ; } break ; case 3 : if ( rtAction != rtPrevAction ) {
doisemfibt ( rtS ) ; } mfbj0yzfuo ( rtS , & rtB . ipenwii4hv , & rtP .
ghjqwoc3wx ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
ghjqwoc3wx . iywpiqxv2q ) ; } break ; } } rtB . eeez5exivc = rtB . leh2oxynn2
* rtB . ipenwii4hv ; oo0vu2anpb = muDoubleScalarPower ( rtB . fsskatoni2 [ 12
] , 2.0 ) + muDoubleScalarPower ( rtB . fsskatoni2 [ 11 ] , 2.0 ) ; if (
oo0vu2anpb < 0.0 ) { rtB . f1xtfhhhqv = - muDoubleScalarSqrt ( - oo0vu2anpb )
; } else { rtB . f1xtfhhhqv = muDoubleScalarSqrt ( oo0vu2anpb ) ; } if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { e1b3j5bavz = rtDW . dntwmboj5l ; rtB .
oftl5xnv1o = look1_binlcpw ( ( real_T ) rtDW . dntwmboj5l * rtP .
SampleTimeMath_WtEt_oqoqay0dg0 , rtP .
RepeatingSequenceInterpolated7_TimeValues , rtP .
RepeatingSequenceInterpolated7_OutValues , 2U ) ; } if ( ssIsSampleHit ( rtS
, 2 , 0 ) ) { rtPrevAction = rtDW . a20bqbbboc ; rtAction = - 1 ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( dqu31pvks0 == 1.0 ) { rtAction = 0 ; }
rtDW . a20bqbbboc = rtAction ; } else { rtAction = rtDW . a20bqbbboc ; } if (
( rtPrevAction != rtAction ) && ( rtPrevAction == 0 ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } if ( rtAction == 0 ) {
if ( 0 != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 2 ) != ssGetTStart (
rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB .
opow2w1mi1 = rtB . oftl5xnv1o ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC
( rtDW . ewfusfxrh1 ) ; } } if ( dqu31pvks0 > rtP .
Switch3_Threshold_diazeczrov ) { oo0vu2anpb = rtB . opow2w1mi1 ; } else {
oo0vu2anpb = rtP . Constant2_Value ; } if ( oo0vu2anpb > rtP .
Switch1_Threshold_fwfvkbu4fv ) { rtB . brcsbdnmx5 = rtP .
Constant1_Value_gzdhx1y50h ; } else { rtB . brcsbdnmx5 = rtP .
Constant_Value_fsy5hzupsd ; } } rtB . ksrhlo5pxw [ 0 ] = rtP .
u1_Gain_h2t4ccjbjb [ 0 ] * rtB . ivbwlhlxla [ 0 ] ; rtB . ksrhlo5pxw [ 1 ] =
rtP . u1_Gain_h2t4ccjbjb [ 1 ] * rtB . ivbwlhlxla [ 1 ] ; rtB . bqhwxr5qcc [
0 ] = rtB . p2ubfcpe4u [ 1 ] * rtB . ksrhlo5pxw [ 0 ] ; rtB . bqhwxr5qcc [ 1
] = rtB . p2ubfcpe4u [ 0 ] * rtB . ksrhlo5pxw [ 1 ] ; rtB . i025vm1xpp = rtB
. bqhwxr5qcc [ 0 ] + rtB . bqhwxr5qcc [ 1 ] ; rtB . kquxrsdq3f = rtB .
npvosve4cu * rtB . i025vm1xpp * rtP . units1_Gain_ck3oazuezb ; rtB .
muz5hrtqty = rtX . cvoatslkxn ; rtB . ialymydhnj = rtP . t_Gain_ocx2eejdk0 *
muDoubleScalarRem ( rtB . muz5hrtqty , 6.2831853071795862 ) ; rtB .
m1ycajq1qq = rtP . units2_Gain_mdhlfy5yh3 * rtB . i025vm1xpp ; rtB .
pucoihkeei = 0.0 ; rtB . pucoihkeei += rtP . CONTROLSYSTEM_C_aor5asjqzc [ 0 ]
* rtX . ozdje1tbeq [ 0 ] ; rtB . pucoihkeei += rtP .
CONTROLSYSTEM_C_aor5asjqzc [ 1 ] * rtX . ozdje1tbeq [ 1 ] ; rtB . lrb3pzyxyo
= rtP . DieselEngineGovernor_K_hsep1xrwii * rtB . pucoihkeei ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtX . c3odb1pgdi >= rtP .
Integrator_UpperSat_gojjo5eoxp ) { if ( rtX . c3odb1pgdi > rtP .
Integrator_UpperSat_gojjo5eoxp ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } rtX . c3odb1pgdi = rtP . Integrator_UpperSat_gojjo5eoxp ; } else
{ if ( rtX . c3odb1pgdi <= rtP . Integrator_LowerSat_odmybcofvo ) { if ( rtX
. c3odb1pgdi < rtP . Integrator_LowerSat_odmybcofvo ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . c3odb1pgdi = rtP
. Integrator_LowerSat_odmybcofvo ; } } } rtB . is1htqzogm = rtX . c3odb1pgdi
; rtB . dg5y4n2fx5 = rtB . brcsbdnmx5 - rtB . lcbyglc5pf ; rtB . kdezj5zhgl =
0.0 ; rtB . kdezj5zhgl += rtP . TF1_C_p2k2li4nfg * rtX . dumyo0mi3u ; rtB .
kdezj5zhgl += rtP . TF1_D_ctmvhklpop * rtB . lrb3pzyxyo ; rtB . k5vss3m212 =
0.0 ; rtB . k5vss3m212 += rtP . TF2_C_cttzu3ti0v * rtX . mjljeeps1u ; rtB .
fxujfy1naf = rtB . leh2oxynn2 * look1_binlxpw ( rtB . leh2oxynn2 , rtP .
Saturation_bp01Data_cujbbzghha , rtP . Saturation_tableData_bxpta2jp2k , 2U )
; rtB . bltflfqi2c = rtP . Gain3_Gain_l0wnsmveb4 * rtB . leh2oxynn2 ; rtB .
lmqrmcycfr = rtB . fxujfy1naf + rtB . bltflfqi2c ; rtB . d54dp4nzot = rtP .
AC1A_Kd_dmbfzuvmau * rtB . fsskatoni2 [ 5 ] ; rtB . jgmqqelntj = rtB .
lmqrmcycfr + rtB . d54dp4nzot ; rtB . nqfjt0wu52 = 0.0 ; rtB . nqfjt0wu52 +=
rtP . StateSpace_C_hoey44f3p1 * rtX . e32unymcc4 ; rtB . nqfjt0wu52 += rtP .
StateSpace_D_fhquez5sfr * rtB . jgmqqelntj ; if ( ssIsMajorTimeStep ( rtS ) )
{ if ( rtX . om4zueiy1s >= rtP . Integrator_UpperSat_mx32ysi3tz ) { if ( rtX
. om4zueiy1s > rtP . Integrator_UpperSat_mx32ysi3tz ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . om4zueiy1s = rtP
. Integrator_UpperSat_mx32ysi3tz ; } else { if ( rtX . om4zueiy1s <= rtP .
Integrator_LowerSat_pgmxfrs2lk ) { if ( rtX . om4zueiy1s < rtP .
Integrator_LowerSat_pgmxfrs2lk ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } rtX . om4zueiy1s = rtP . Integrator_LowerSat_pgmxfrs2lk ; } } }
rtB . bbuesupjvr = rtX . om4zueiy1s ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW
. fiaucjz2wl = rtB . bbuesupjvr >= rtP . VRmin_UpperSat_kemkgh34w4 ? 1 : rtB
. bbuesupjvr > rtP . VRmin_LowerSat_jrg3s5kvpl ? 0 : - 1 ; } rtB . in55bj1rrn
= rtDW . fiaucjz2wl == 1 ? rtP . VRmin_UpperSat_kemkgh34w4 : rtDW .
fiaucjz2wl == - 1 ? rtP . VRmin_LowerSat_jrg3s5kvpl : rtB . bbuesupjvr ; rtB
. lfna3t2vnq = rtB . in55bj1rrn - rtB . jgmqqelntj ; rtB . czljrbrypr = rtP .
Gain_Gain_obx54i1vu4 * rtB . lfna3t2vnq ; rtB . olxkln2vrn = 0.0 ; rtB .
olxkln2vrn += rtP . StateSpace_C_l2uehmt5xx * rtX . nafgdh5awp ; rtB .
n5pczeolzc = ( ( rtP . Vtrefpu_Value_dhu50coqb3 + rtP .
Vfe0Ka_Value_mornhw3ubx ) - rtB . olxkln2vrn ) - rtB . nqfjt0wu52 ; rtB .
pd4pkxomth = 0.0 ; rtB . pd4pkxomth += rtP . StateSpace_D_ag504b3buu * rtB .
n5pczeolzc ; rtB . bfl0othxdw = rtP . Vaminmax_Ka_joioxdjv2b * rtB .
pd4pkxomth ; rtB . geqf1klp5b = rtB . bfl0othxdw - rtB . bbuesupjvr ; rtB .
k0htkyngm1 = 1.0 / rtP . Vaminmax_Ta_m25rkfya5x * rtB . geqf1klp5b ; rtB .
juqlwmzilg = rtP . N_Gain_be3jplttom * rtB . eeez5exivc ; rtB . cl2yrd4l20 =
rtP . Gain1_Gain_e30uvq0bg2 * rtB . npvosve4cu ; for ( i = 0 ; i < 25 ; i ++
) { rtB . cx2nl0uoty [ i ] = rtP . u1_Value_jhomplmiue [ i ] ; rtB .
ojbcjx0grt [ i ] = rtB . cx2nl0uoty [ i ] ; } rtB . ojbcjx0grt [ 5 ] = rtB .
npvosve4cu ; memcpy ( & rtB . okrtsi5dua [ 0 ] , & rtB . ojbcjx0grt [ 0 ] ,
25U * sizeof ( real_T ) ) ; rtB . okrtsi5dua [ 1 ] = rtB . cl2yrd4l20 ; if (
rtP . Constant2_Value_pvyxnakeki >= rtP . Switch1_Threshold_fwxhhecccj ) {
memcpy ( & rtB . liak5gzlbs [ 0 ] , & rtB . puvrgymrfw . nyt32tufuy [ 0 ] ,
25U * sizeof ( real_T ) ) ; } else { memcpy ( & rtB . liak5gzlbs [ 0 ] , &
rtP . Constant6_Value_k5ippmioel [ 0 ] , 25U * sizeof ( real_T ) ) ; } for (
i = 0 ; i < 25 ; i ++ ) { rtB . kj5c5ay2lr [ i ] = ( 0.0 - rtB . okrtsi5dua [
i ] ) - rtB . liak5gzlbs [ i ] ; } for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { rtB .
nthau0fysn [ i_p ] = 0.0 ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . nthau0fysn [
i_p ] += rtB . kj5c5ay2lr [ 5 * i + i_p ] * rtB . p2ubfcpe4u [ i ] ; } } rtB
. mh1p4xc2nf [ 0 ] = n0hkaqfprr + rtB . nthau0fysn [ 0 ] ; rtB . mh1p4xc2nf [
1 ] = cq5g3ezsl5 + rtB . nthau0fysn [ 1 ] ; rtB . mh1p4xc2nf [ 2 ] = rtB .
juqlwmzilg + rtB . nthau0fysn [ 2 ] ; rtB . mh1p4xc2nf [ 3 ] = rtP .
Vkd0Vkq10Vkq20_Value_nhzucgdnq4 [ 0 ] + rtB . nthau0fysn [ 3 ] ; rtB .
mh1p4xc2nf [ 4 ] = rtP . Vkd0Vkq10Vkq20_Value_nhzucgdnq4 [ 1 ] + rtB .
nthau0fysn [ 4 ] ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . aaxc40oml0 [ i ] =
rtP . wbase_Gain_ipvpfsncw4 * rtB . mh1p4xc2nf [ i ] ; } rtB . izbaih23wf =
rtP . u_Pb_Gain_meqork31l1 * rtB . p0ztjxbfsc ; rtB . nm1zt5o0wf = rtP .
F1_Gain_ehi20lbmpl * rtB . npvosve4cu ; rtB . fpw2bhibof = ( rtB . izbaih23wf
/ ( rtB . npvosve4cu + 2.2204460492503131e-16 ) - rtB . i025vm1xpp ) - rtB .
nm1zt5o0wf ; rtB . dg4rfafxi2 = rtP . u_2H_Gain_fy3z52hrui * rtB . fpw2bhibof
; rtB . fr3yekodlk = rtP . web1_Gain_ntza1b0jr3 * rtB . jbq05nhwpa ; rtB .
feadnsrfon = rtP . web3_Gain_hkaiompgkf * rtB . npvosve4cu ; rtB . cjhy3wufru
= rtX . pvsfs5bviq ; rtB . gz4h1n4arf = rtP . nomspeed_Value_c4afvv0dzn + rtB
. cjhy3wufru ; rtB . mjcpwqdoim = rtP . units_Gain_knuawugzke * rtB .
gz4h1n4arf ; { real_T * * uBuffer = ( real_T * * ) & rtDW . abwpuwwzkr .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . abwpuwwzkr
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay =
simTime - rtP . DieselEngineGovernor_Td_bx2jkcsvfl ; rtB . lpzstbvwnw =
rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW .
aexlfdwpio . CircularBufSize , & rtDW . aexlfdwpio . Last , rtDW . aexlfdwpio
. Tail , rtDW . aexlfdwpio . Head , rtP . DieselEngineGovernor_Pm0_a40shkker5
, 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput (
rtS ) == ssGetT ( rtS ) ) ) ) ; } rtB . kosf4p4xvo = rtB . lpzstbvwnw * rtB .
mjcpwqdoim ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtX . oh1bpz4njz >= rtP
. Integrator_UpperSat_m3couvae5u ) { if ( rtX . oh1bpz4njz > rtP .
Integrator_UpperSat_m3couvae5u ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } rtX . oh1bpz4njz = rtP . Integrator_UpperSat_m3couvae5u ; } else
{ if ( rtX . oh1bpz4njz <= rtP . Integrator_LowerSat_cp3m3xxjrp ) { if ( rtX
. oh1bpz4njz < rtP . Integrator_LowerSat_cp3m3xxjrp ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . oh1bpz4njz = rtP
. Integrator_LowerSat_cp3m3xxjrp ; } } } rtB . dddvo3hq1e = rtX . oh1bpz4njz
; if ( rtP . Constant1_Value_o4y4gj153l ) { rtB . eilem0zhx5 = rtB .
dk1omp4wet [ 0 ] ; } else { rtB . eilem0zhx5 = rtP .
Constant2_Value_gn5n2cp44f ; } rtB . e2xvdcfwjv [ 0 ] = rtP .
uLl_q_Gain_kecofhqc2m [ 0 ] * rtB . j2hq00la3s [ 0 ] ; rtB . e2xvdcfwjv [ 1 ]
= rtP . uLl_q_Gain_kecofhqc2m [ 1 ] * rtB . j2hq00la3s [ 4 ] ; if ( rtP .
Constant8_Value_pcjxv32svc >= rtP . Switch3_Threshold_njctu0jfwh ) { rtB .
hyw4ezm3jt [ 0 ] = rtB . cqi4cjmse0 . fbja1wrd5n ; rtB . hyw4ezm3jt [ 1 ] =
rtB . cqi4cjmse0 . dknardu53j ; } else { rtB . hyw4ezm3jt [ 0 ] = rtP .
Laqd_nosat_Value_fjpqaej0yv [ 0 ] ; rtB . hyw4ezm3jt [ 1 ] = rtP .
Laqd_nosat_Value_fjpqaej0yv [ 1 ] ; } rtB . nkurjvw04v [ 0 ] = rtB .
e2xvdcfwjv [ 0 ] * rtB . hyw4ezm3jt [ 0 ] ; rtB . nkurjvw04v [ 1 ] = rtB .
e2xvdcfwjv [ 1 ] * rtB . hyw4ezm3jt [ 0 ] ; rtB . dddbntcjoq = rtB .
nkurjvw04v [ 0 ] + rtB . nkurjvw04v [ 1 ] ; rtB . b3aww42o13 [ 0 ] = rtP .
uLl_d_Gain_lwwmuggbe5 [ 0 ] * rtB . j2hq00la3s [ 1 ] ; rtB . nqquna1krn [ 0 ]
= rtB . b3aww42o13 [ 0 ] * rtB . hyw4ezm3jt [ 1 ] ; rtB . b3aww42o13 [ 1 ] =
rtP . uLl_d_Gain_lwwmuggbe5 [ 1 ] * rtB . j2hq00la3s [ 2 ] ; rtB . nqquna1krn
[ 1 ] = rtB . b3aww42o13 [ 1 ] * rtB . hyw4ezm3jt [ 1 ] ; rtB . b3aww42o13 [
2 ] = rtP . uLl_d_Gain_lwwmuggbe5 [ 2 ] * rtB . j2hq00la3s [ 3 ] ; rtB .
nqquna1krn [ 2 ] = rtB . b3aww42o13 [ 2 ] * rtB . hyw4ezm3jt [ 1 ] ; rtB .
f0m4fsml1k = ( rtB . nqquna1krn [ 0 ] + rtB . nqquna1krn [ 1 ] ) + rtB .
nqquna1krn [ 2 ] ; rtB . p2gohtwhoy [ 0 ] = rtP . u_Vb_Gain_euntrylpur * rtB
. bx1vifjqa5 [ 0 ] ; rtB . p2gohtwhoy [ 1 ] = rtP . u_Vb_Gain_euntrylpur *
rtB . bx1vifjqa5 [ 1 ] ; bvtlrzy045 = ( ( 2.0 * rtB . p2gohtwhoy [ 0 ] + rtB
. p2gohtwhoy [ 1 ] ) * jglko44zhq + 1.7320508075688772 * rtB . p2gohtwhoy [ 1
] * glrhaqk1if ) * 0.33333333333333331 ; glrhaqk1if = ( ( 2.0 * rtB .
p2gohtwhoy [ 0 ] + rtB . p2gohtwhoy [ 1 ] ) * glrhaqk1if + -
1.7320508075688772 * rtB . p2gohtwhoy [ 1 ] * jglko44zhq ) *
0.33333333333333331 ; if ( rtP . Constant5_Value_avkreamlze >= rtP .
Switch2_Threshold_ihudfcdcgg ) { rtB . echinzwblw [ 0 ] = rtB . cqi4cjmse0 .
kguc1xjgtq ; rtB . echinzwblw [ 1 ] = rtB . cqi4cjmse0 . k33sqomjhg ; } else
{ rtB . echinzwblw [ 0 ] = rtP . Lmqd_nosat_Value_kp0vqseud3 [ 0 ] ; rtB .
echinzwblw [ 1 ] = rtP . Lmqd_nosat_Value_kp0vqseud3 [ 1 ] ; } rtB .
ora01btyv5 = rtP . Gain_Gain_mlg03jqesr * muDoubleScalarAtan2 ( glrhaqk1if ,
bvtlrzy045 ) ; rtB . m1pbevt2be = bvtlrzy045 * rtB . dk1omp4wet [ 0 ] ; rtB .
jvrusqmyep = glrhaqk1if * rtB . dk1omp4wet [ 1 ] ; rtB . bzvubtagmj = rtB .
m1pbevt2be + rtB . jvrusqmyep ; rtB . hyvvo1s5f2 = rtP . Gain_Gain_cvcbqyleda
* rtB . bzvubtagmj ; rtB . hz5ux0snkr = bvtlrzy045 * rtB . dk1omp4wet [ 1 ] ;
rtB . faanufcllo = glrhaqk1if * rtB . dk1omp4wet [ 0 ] ; rtB . inwdxaza5z =
rtB . hz5ux0snkr - rtB . faanufcllo ; rtB . a0qycmun3l = rtP .
Gain1_Gain_l4eyt2f1nb * rtB . inwdxaza5z ; rtB . hxglkl2bua [ 0 ] = rtP .
outputformatting_Gain_pp0gocueod [ 0 ] * bouhabhtxj ; rtB . hxglkl2bua [ 1 ]
= rtP . outputformatting_Gain_pp0gocueod [ 1 ] * dziq0k4vk2 ; rtB .
hxglkl2bua [ 2 ] = rtP . outputformatting_Gain_pp0gocueod [ 2 ] * rtB .
pq54vjdlkq ; rtB . hxglkl2bua [ 3 ] = rtP . outputformatting_Gain_pp0gocueod
[ 3 ] * rtB . dk1omp4wet [ 0 ] ; rtB . hxglkl2bua [ 4 ] = rtP .
outputformatting_Gain_pp0gocueod [ 4 ] * rtB . dk1omp4wet [ 1 ] ; rtB .
hxglkl2bua [ 5 ] = rtP . outputformatting_Gain_pp0gocueod [ 5 ] * rtB .
dk1omp4wet [ 2 ] ; rtB . hxglkl2bua [ 6 ] = rtP .
outputformatting_Gain_pp0gocueod [ 6 ] * rtB . dk1omp4wet [ 4 ] ; rtB .
hxglkl2bua [ 7 ] = rtP . outputformatting_Gain_pp0gocueod [ 7 ] * rtB .
eilem0zhx5 ; rtB . hxglkl2bua [ 8 ] = rtP . outputformatting_Gain_pp0gocueod
[ 8 ] * rtB . dk1omp4wet [ 3 ] ; rtB . hxglkl2bua [ 9 ] = rtP .
outputformatting_Gain_pp0gocueod [ 9 ] * rtB . dddbntcjoq ; rtB . hxglkl2bua
[ 10 ] = rtP . outputformatting_Gain_pp0gocueod [ 10 ] * rtB . f0m4fsml1k ;
rtB . hxglkl2bua [ 11 ] = rtP . outputformatting_Gain_pp0gocueod [ 11 ] *
bvtlrzy045 ; rtB . hxglkl2bua [ 12 ] = rtP . outputformatting_Gain_pp0gocueod
[ 12 ] * glrhaqk1if ; rtB . hxglkl2bua [ 13 ] = rtP .
outputformatting_Gain_pp0gocueod [ 13 ] * rtB . echinzwblw [ 0 ] ; rtB .
hxglkl2bua [ 14 ] = rtP . outputformatting_Gain_pp0gocueod [ 14 ] * rtB .
echinzwblw [ 1 ] ; rtB . hxglkl2bua [ 15 ] = rtP .
outputformatting_Gain_pp0gocueod [ 15 ] * rtB . ora01btyv5 ; rtB . hxglkl2bua
[ 16 ] = rtP . outputformatting_Gain_pp0gocueod [ 16 ] * rtB . hyvvo1s5f2 ;
rtB . hxglkl2bua [ 17 ] = rtP . outputformatting_Gain_pp0gocueod [ 17 ] * rtB
. a0qycmun3l ; rtB . jsjdhroynv = rtB . hxglkl2bua [ 5 ] / ( ( real_T ) ( rtB
. dddvo3hq1e == 0.0 ) * 2.2204460492503131e-16 + rtB . dddvo3hq1e ) * rtP .
AC1A_Kc_ey4gmz0v22 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtPrevAction =
rtDW . ajv3iwzytl ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . gqcabwkprt = (
rtB . jsjdhroynv <= rtP . input_Value_kgzybnfuyq ) ; rtDW . bbl2l4op42 = (
rtB . jsjdhroynv < rtP . input1_Value_lmbqbgulqv ) ; rtDW . mo2lkhaep1 = (
rtB . jsjdhroynv <= rtP . input2_Value_damfqfxz2b ) ; switch ( ( rtDW .
gqcabwkprt + rtDW . bbl2l4op42 ) + rtDW . mo2lkhaep1 ) { case 1 : rtAction =
0 ; break ; case 2 : rtAction = 1 ; break ; case 3 : rtAction = 2 ; break ;
default : rtAction = 3 ; break ; } rtDW . ajv3iwzytl = rtAction ; } else {
rtAction = rtDW . ajv3iwzytl ; } if ( rtPrevAction != rtAction ) { switch (
rtPrevAction ) { case 0 : julesvnt2d ( rtS ) ; break ; case 1 : ab0lumfo3e (
rtS ) ; break ; case 2 : fwicy1bcaz ( rtS ) ; break ; case 3 : j34hurn5mj (
rtS ) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction !=
rtPrevAction ) { mbwj5xxyv5 ( rtS ) ; } attmdly3nw ( rtS , rtB . jsjdhroynv ,
& rtB . i0iyh4zr0m , & rtP . plxey5q4z3 ) ; if ( ssIsMajorTimeStep ( rtS ) )
{ srUpdateBC ( rtDW . plxey5q4z3 . gxuxajwdt5 ) ; } break ; case 1 : if (
rtAction != rtPrevAction ) { cmjweld2k1 ( rtS ) ; } igmpp4jfdv ( rtS , rtB .
jsjdhroynv , & rtB . i0iyh4zr0m , & rtP . b0yuwkfotx ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . b0yuwkfotx . pcotaqjtuk ) ;
} break ; case 2 : if ( rtAction != rtPrevAction ) { a5me1li4az ( rtS ) ; }
e22kv3zqsq ( rtS , rtB . jsjdhroynv , & rtB . i0iyh4zr0m , & rtP . a12lwium4g
) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . a12lwium4g .
g33nsvnzmn ) ; } break ; case 3 : if ( rtAction != rtPrevAction ) {
doisemfibt ( rtS ) ; } mfbj0yzfuo ( rtS , & rtB . i0iyh4zr0m , & rtP .
ecdtivcszk ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
ecdtivcszk . iywpiqxv2q ) ; } break ; } } rtB . kxi0hiouf4 = rtB . dddvo3hq1e
* rtB . i0iyh4zr0m ; oo0vu2anpb = muDoubleScalarPower ( rtB . hxglkl2bua [ 12
] , 2.0 ) + muDoubleScalarPower ( rtB . hxglkl2bua [ 11 ] , 2.0 ) ; if (
oo0vu2anpb < 0.0 ) { rtB . eyy42dwotr = - muDoubleScalarSqrt ( - oo0vu2anpb )
; } else { rtB . eyy42dwotr = muDoubleScalarSqrt ( oo0vu2anpb ) ; } if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { cpkdq1wvkh = rtDW . hdwuwozgch ; rtB .
izwovv53aq = look1_binlcpw ( ( real_T ) rtDW . hdwuwozgch * rtP .
SampleTimeMath_WtEt_mn443d0ldo , rtP .
RepeatingSequenceInterpolated6_TimeValues , rtP .
RepeatingSequenceInterpolated6_OutValues , 2U ) ; } if ( ssIsSampleHit ( rtS
, 2 , 0 ) ) { rtPrevAction = rtDW . jdvbg1vzm5 ; rtAction = - 1 ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( dqu31pvks0 == 1.0 ) { rtAction = 0 ; }
rtDW . jdvbg1vzm5 = rtAction ; } else { rtAction = rtDW . jdvbg1vzm5 ; } if (
( rtPrevAction != rtAction ) && ( rtPrevAction == 0 ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } if ( rtAction == 0 ) {
if ( 0 != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 2 ) != ssGetTStart (
rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB .
npyj2l24ut = rtB . izwovv53aq ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC
( rtDW . msqb4sdl5r ) ; } } if ( dqu31pvks0 > rtP . Switch4_Threshold ) {
dqu31pvks0 = rtB . npyj2l24ut ; } else { dqu31pvks0 = rtP . Constant6_Value ;
} if ( dqu31pvks0 > rtP . Switch1_Threshold_bvrzjijffl ) { rtB . j4zpdoh2yb =
rtP . Constant1_Value_p3y25qn4th ; } else { rtB . j4zpdoh2yb = rtP .
Constant_Value_feo10nb4xc ; } } rtB . kgd55h5ywl [ 0 ] = rtP .
u1_Gain_i4dhglb1xx [ 0 ] * rtB . dk1omp4wet [ 0 ] ; rtB . kgd55h5ywl [ 1 ] =
rtP . u1_Gain_i4dhglb1xx [ 1 ] * rtB . dk1omp4wet [ 1 ] ; rtB . ilnl1lw0qf [
0 ] = rtB . j2hq00la3s [ 1 ] * rtB . kgd55h5ywl [ 0 ] ; rtB . ilnl1lw0qf [ 1
] = rtB . j2hq00la3s [ 0 ] * rtB . kgd55h5ywl [ 1 ] ; rtB . om3gsb2wta = rtB
. ilnl1lw0qf [ 0 ] + rtB . ilnl1lw0qf [ 1 ] ; rtB . hbasv1e1li = rtB .
gz4h1n4arf * rtB . om3gsb2wta * rtP . units1_Gain_mjfpltedd3 ; rtB .
gveciz5cnx = rtX . mtfzfgh35r ; rtB . l5jnvhxa3g = rtP . t_Gain_dbtteubymo *
muDoubleScalarRem ( rtB . gveciz5cnx , 6.2831853071795862 ) ; rtB .
mjgxqzxhn4 = rtP . units2_Gain_lg4ftazuex * rtB . om3gsb2wta ; rtB .
gecgjcwxl2 = 0.0 ; rtB . gecgjcwxl2 += rtP . CONTROLSYSTEM_C_bbvipdfxiw [ 0 ]
* rtX . kvt4cjhlrh [ 0 ] ; rtB . gecgjcwxl2 += rtP .
CONTROLSYSTEM_C_bbvipdfxiw [ 1 ] * rtX . kvt4cjhlrh [ 1 ] ; rtB . nwxyngwvoo
= rtP . DieselEngineGovernor_K_cl2ljmrvvx * rtB . gecgjcwxl2 ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtX . nk334zxlzp >= rtP .
Integrator_UpperSat_g2nmqxfxgj ) { if ( rtX . nk334zxlzp > rtP .
Integrator_UpperSat_g2nmqxfxgj ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } rtX . nk334zxlzp = rtP . Integrator_UpperSat_g2nmqxfxgj ; } else
{ if ( rtX . nk334zxlzp <= rtP . Integrator_LowerSat_jpz1embdbj ) { if ( rtX
. nk334zxlzp < rtP . Integrator_LowerSat_jpz1embdbj ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . nk334zxlzp = rtP
. Integrator_LowerSat_jpz1embdbj ; } } } rtB . hwewg0ullm = rtX . nk334zxlzp
; rtB . prgl4v4rcs = rtB . j4zpdoh2yb - rtB . mjcpwqdoim ; rtB . h2f5ohv0un =
0.0 ; rtB . h2f5ohv0un += rtP . TF1_C_enbbofzqoo * rtX . geip5cv4tr ; rtB .
h2f5ohv0un += rtP . TF1_D_oklbobiarf * rtB . nwxyngwvoo ; rtB . kfay54rwhc =
0.0 ; rtB . kfay54rwhc += rtP . TF2_C_b52pyf1de4 * rtX . j51tfhhdgm ; rtB .
l4qzjl15fy = rtB . dddvo3hq1e * look1_binlxpw ( rtB . dddvo3hq1e , rtP .
Saturation_bp01Data_en0rvvne43 , rtP . Saturation_tableData_kxfwt3h3lg , 2U )
; rtB . lnyirkbasi = rtP . Gain3_Gain_fuo2nhtpfo * rtB . dddvo3hq1e ; rtB .
evrpjg415a = rtB . l4qzjl15fy + rtB . lnyirkbasi ; rtB . fyneqtq03a = rtP .
AC1A_Kd_jc2axpnc1z * rtB . hxglkl2bua [ 5 ] ; rtB . o5yahrnyq3 = rtB .
evrpjg415a + rtB . fyneqtq03a ; rtB . dphvgbxieu = 0.0 ; rtB . dphvgbxieu +=
rtP . StateSpace_C_ixsu11uqcc * rtX . icyr0u0hwc ; rtB . dphvgbxieu += rtP .
StateSpace_D_kgtr0kyhhc * rtB . o5yahrnyq3 ; if ( ssIsMajorTimeStep ( rtS ) )
{ if ( rtX . b0v4jzhvdz >= rtP . Integrator_UpperSat_awe5bjjzds ) { if ( rtX
. b0v4jzhvdz > rtP . Integrator_UpperSat_awe5bjjzds ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . b0v4jzhvdz = rtP
. Integrator_UpperSat_awe5bjjzds ; } else { if ( rtX . b0v4jzhvdz <= rtP .
Integrator_LowerSat_boizxptfju ) { if ( rtX . b0v4jzhvdz < rtP .
Integrator_LowerSat_boizxptfju ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } rtX . b0v4jzhvdz = rtP . Integrator_LowerSat_boizxptfju ; } } }
rtB . e4g0rxt1yl = rtX . b0v4jzhvdz ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW
. nazzdgbbki = rtB . e4g0rxt1yl >= rtP . VRmin_UpperSat_k0uoo5f5gu ? 1 : rtB
. e4g0rxt1yl > rtP . VRmin_LowerSat_aseabweop3 ? 0 : - 1 ; } rtB . i2y4p2vw1k
= rtDW . nazzdgbbki == 1 ? rtP . VRmin_UpperSat_k0uoo5f5gu : rtDW .
nazzdgbbki == - 1 ? rtP . VRmin_LowerSat_aseabweop3 : rtB . e4g0rxt1yl ; rtB
. imbchlh21y = rtB . i2y4p2vw1k - rtB . o5yahrnyq3 ; rtB . o2yzakmz1p = rtP .
Gain_Gain_gns12i5e1p * rtB . imbchlh21y ; rtB . biqautq04w = 0.0 ; rtB .
biqautq04w += rtP . StateSpace_C_gsj3y0bvsj * rtX . mia0akgecm ; rtB .
f4wm3ijjcw = ( ( rtP . Vtrefpu_Value_gqtbi3ry5p + rtP .
Vfe0Ka_Value_hmejnrjuz0 ) - rtB . biqautq04w ) - rtB . dphvgbxieu ; rtB .
pyb5nlfcal = 0.0 ; rtB . pyb5nlfcal += rtP . StateSpace_D_px4xwj4emx * rtB .
f4wm3ijjcw ; rtB . fv5a4vo3xg = rtP . Vaminmax_Ka_fmvvzu1cvw * rtB .
pyb5nlfcal ; rtB . kjdjn4pvtg = rtB . fv5a4vo3xg - rtB . e4g0rxt1yl ; rtB .
jx22a2iggv = 1.0 / rtP . Vaminmax_Ta_achztkg4yj * rtB . kjdjn4pvtg ; rtB .
cgkgxwy5lm = rtP . N_Gain_ibtzqi1ta5 * rtB . kxi0hiouf4 ; rtB . d2o4vcwr4t =
rtP . Gain1_Gain_mh0xj2zmnv * rtB . gz4h1n4arf ; for ( i = 0 ; i < 25 ; i ++
) { rtB . g4jauwnx0y [ i ] = rtP . u1_Value_kgi3v4joec [ i ] ; rtB .
j1s3mphmsm [ i ] = rtB . g4jauwnx0y [ i ] ; } rtB . j1s3mphmsm [ 5 ] = rtB .
gz4h1n4arf ; memcpy ( & rtB . j21pixwogm [ 0 ] , & rtB . j1s3mphmsm [ 0 ] ,
25U * sizeof ( real_T ) ) ; rtB . j21pixwogm [ 1 ] = rtB . d2o4vcwr4t ; if (
rtP . Constant2_Value_pd52okrj2w >= rtP . Switch1_Threshold_eqdxhfdxlc ) {
memcpy ( & rtB . btni35uwov [ 0 ] , & rtB . cqi4cjmse0 . nyt32tufuy [ 0 ] ,
25U * sizeof ( real_T ) ) ; } else { memcpy ( & rtB . btni35uwov [ 0 ] , &
rtP . Constant6_Value_ovz5lrokju [ 0 ] , 25U * sizeof ( real_T ) ) ; } for (
i = 0 ; i < 25 ; i ++ ) { rtB . pszjudozhd [ i ] = ( 0.0 - rtB . j21pixwogm [
i ] ) - rtB . btni35uwov [ i ] ; } for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { rtB .
dfgsexyfsz [ i_p ] = 0.0 ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . dfgsexyfsz [
i_p ] += rtB . pszjudozhd [ 5 * i + i_p ] * rtB . j2hq00la3s [ i ] ; } } rtB
. ikmi0yu0r4 [ 0 ] = bvtlrzy045 + rtB . dfgsexyfsz [ 0 ] ; rtB . ikmi0yu0r4 [
1 ] = glrhaqk1if + rtB . dfgsexyfsz [ 1 ] ; rtB . ikmi0yu0r4 [ 2 ] = rtB .
cgkgxwy5lm + rtB . dfgsexyfsz [ 2 ] ; rtB . ikmi0yu0r4 [ 3 ] = rtP .
Vkd0Vkq10Vkq20_Value_ltjzacdd50 [ 0 ] + rtB . dfgsexyfsz [ 3 ] ; rtB .
ikmi0yu0r4 [ 4 ] = rtP . Vkd0Vkq10Vkq20_Value_ltjzacdd50 [ 1 ] + rtB .
dfgsexyfsz [ 4 ] ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . djoydjgvbg [ i ] =
rtP . wbase_Gain_okwmdlnvlt * rtB . ikmi0yu0r4 [ i ] ; } rtB . e4dpd1hqdn =
rtP . u_Pb_Gain_cmlupu4lup * rtB . kosf4p4xvo ; rtB . k43sb00nmf = rtP .
F1_Gain_fyk4vsqtoc * rtB . gz4h1n4arf ; rtB . gewuongkab = ( rtB . e4dpd1hqdn
/ ( rtB . gz4h1n4arf + 2.2204460492503131e-16 ) - rtB . om3gsb2wta ) - rtB .
k43sb00nmf ; rtB . iwhl53vsbp = rtP . u_2H_Gain_pa0w4j2kxa * rtB . gewuongkab
; rtB . n0ctdpimv4 = rtP . web1_Gain_pvbmras4px * rtB . cjhy3wufru ; rtB .
nvzgkwwurg = rtP . web3_Gain_frif05wfp3 * rtB . gz4h1n4arf ; rtB . pkizjdds0x
= rt_Lookup ( rtP . LookUpTable_XData , 4 , ssGetT ( rtS ) , rtP .
LookUpTable_YData ) ; if ( rtP . C4_Value_oedqg4szxm >= rtP .
Switch3_Threshold_cusgrt5efp ) { rtB . aipd2mmrrr = rtB . e02gvifuul ; } else
{ rtB . aipd2mmrrr = rtB . pkizjdds0x ; } rtB . e2b1dnuz0z = rt_Lookup ( rtP
. LookUpTable_XData_mq1idq0nl4 , 5 , ssGetT ( rtS ) , rtP .
LookUpTable_YData_ccvh5hrnif ) ; if ( rtP . C4_Value >= rtP .
Switch3_Threshold_g4hlm5luuc ) { if ( rtP . ThreePhaseBreaker_SwitchA >= rtP
. Switch_Threshold ) { rtB . h20osj2hz4 = rtB . aipd2mmrrr ; } else { rtB .
h20osj2hz4 = rtP . Constant5_Value_p3h5lbxhcf ; } rtB . bt3z4wm1qx = rtB .
h20osj2hz4 ; } else { rtB . bt3z4wm1qx = rtB . e2b1dnuz0z ; } if ( ( rtDW .
k2gqgbs5d5 >= ssGetT ( rtS ) ) && ( rtDW . mgitsq1y4c >= ssGetT ( rtS ) ) ) {
rtB . ehtl4hikfh = 0.0 ; } else { bouhabhtxj = rtDW . k2gqgbs5d5 ; lastU = &
rtDW . hgooub1kfm ; if ( rtDW . k2gqgbs5d5 < rtDW . mgitsq1y4c ) { if ( rtDW
. mgitsq1y4c < ssGetT ( rtS ) ) { bouhabhtxj = rtDW . mgitsq1y4c ; lastU = &
rtDW . ielhf2atex ; } } else { if ( rtDW . k2gqgbs5d5 >= ssGetT ( rtS ) ) {
bouhabhtxj = rtDW . mgitsq1y4c ; lastU = & rtDW . ielhf2atex ; } } rtB .
ehtl4hikfh = ( rtB . e2b1dnuz0z - * lastU ) / ( ssGetT ( rtS ) - bouhabhtxj )
; } rtB . e4wb3lihdw = rt_Lookup ( rtP . LookUpTable_XData_eezqqd1gay , 5 ,
ssGetT ( rtS ) , rtP . LookUpTable_YData_hvy2xxeyp0 ) ; if ( rtP .
C4_Value_j03cbj4w4t >= rtP . Switch3_Threshold_au45uwgzmy ) { if ( rtP .
ThreePhaseBreaker_SwitchB >= rtP . Switch1_Threshold ) { rtB . aex4uyx51s =
rtB . aipd2mmrrr ; } else { rtB . aex4uyx51s = rtP .
Constant5_Value_p3h5lbxhcf ; } rtB . l3hudrc3jb = rtB . aex4uyx51s ; } else {
rtB . l3hudrc3jb = rtB . e4wb3lihdw ; } if ( ( rtDW . kydy0dzs4q >= ssGetT (
rtS ) ) && ( rtDW . ix3txx30gm >= ssGetT ( rtS ) ) ) { rtB . d3d4jc4vne = 0.0
; } else { bouhabhtxj = rtDW . kydy0dzs4q ; lastU = & rtDW . gpk14zbdx0 ; if
( rtDW . kydy0dzs4q < rtDW . ix3txx30gm ) { if ( rtDW . ix3txx30gm < ssGetT (
rtS ) ) { bouhabhtxj = rtDW . ix3txx30gm ; lastU = & rtDW . l1uw3rg2qt ; } }
else { if ( rtDW . kydy0dzs4q >= ssGetT ( rtS ) ) { bouhabhtxj = rtDW .
ix3txx30gm ; lastU = & rtDW . l1uw3rg2qt ; } } rtB . d3d4jc4vne = ( rtB .
e4wb3lihdw - * lastU ) / ( ssGetT ( rtS ) - bouhabhtxj ) ; } rtB . h4uex5jljn
= rt_Lookup ( rtP . LookUpTable_XData_lgzoqpdmap , 5 , ssGetT ( rtS ) , rtP .
LookUpTable_YData_iwdiswx02w ) ; if ( rtP . C4_Value_d2dqb0vhdi >= rtP .
Switch3_Threshold_npd5pduwpp ) { if ( rtP . ThreePhaseBreaker_SwitchC >= rtP
. Switch2_Threshold ) { rtB . enckxhfxqr = rtB . aipd2mmrrr ; } else { rtB .
enckxhfxqr = rtP . Constant5_Value_p3h5lbxhcf ; } rtB . gm2c3kojd1 = rtB .
enckxhfxqr ; } else { rtB . gm2c3kojd1 = rtB . h4uex5jljn ; } if ( ( rtDW .
dfk5fcernw >= ssGetT ( rtS ) ) && ( rtDW . excno4hjxp >= ssGetT ( rtS ) ) ) {
rtB . nvwpe0rwjl = 0.0 ; } else { bouhabhtxj = rtDW . dfk5fcernw ; lastU = &
rtDW . isywftekv1 ; if ( rtDW . dfk5fcernw < rtDW . excno4hjxp ) { if ( rtDW
. excno4hjxp < ssGetT ( rtS ) ) { bouhabhtxj = rtDW . excno4hjxp ; lastU = &
rtDW . ndirfsq4jw ; } } else { if ( rtDW . dfk5fcernw >= ssGetT ( rtS ) ) {
bouhabhtxj = rtDW . excno4hjxp ; lastU = & rtDW . ndirfsq4jw ; } } rtB .
nvwpe0rwjl = ( rtB . h4uex5jljn - * lastU ) / ( ssGetT ( rtS ) - bouhabhtxj )
; } if ( ( rtDW . g0ztsagyor >= ssGetT ( rtS ) ) && ( rtDW . fetl5keei4 >=
ssGetT ( rtS ) ) ) { rtB . brtuqherkv = 0.0 ; } else { bouhabhtxj = rtDW .
g0ztsagyor ; lastU = & rtDW . hs0fo3ig54 ; if ( rtDW . g0ztsagyor < rtDW .
fetl5keei4 ) { if ( rtDW . fetl5keei4 < ssGetT ( rtS ) ) { bouhabhtxj = rtDW
. fetl5keei4 ; lastU = & rtDW . nnbixcnsch ; } } else { if ( rtDW .
g0ztsagyor >= ssGetT ( rtS ) ) { bouhabhtxj = rtDW . fetl5keei4 ; lastU = &
rtDW . nnbixcnsch ; } } rtB . brtuqherkv = ( rtB . pkizjdds0x - * lastU ) / (
ssGetT ( rtS ) - bouhabhtxj ) ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) {
cpkdq1wvkh = ( uint8_T ) ( ( uint32_T ) cpkdq1wvkh + rtP .
FixPtConstant_Value ) ; if ( cpkdq1wvkh > rtP . LimitedCounter_uplimit ) {
rtB . egynfvvlbk = rtP . Constant_Value_d1po1vdd0l ; } else { rtB .
egynfvvlbk = cpkdq1wvkh ; } e1b3j5bavz = ( uint8_T ) ( ( uint32_T )
e1b3j5bavz + rtP . FixPtConstant_Value_bhfbq2rm4w ) ; if ( e1b3j5bavz > rtP .
LimitedCounter_uplimit_hhtrkteiui ) { rtB . ng0qeau1ay = rtP .
Constant_Value_lox41z13xd ; } else { rtB . ng0qeau1ay = e1b3j5bavz ; }
dqp2jl35hv = ( uint8_T ) ( ( uint32_T ) dqp2jl35hv + rtP .
FixPtConstant_Value_mqj2wqz1c5 ) ; if ( dqp2jl35hv > rtP .
LimitedCounter_uplimit_gpv2tvmki5 ) { rtB . onvs14ppyq = rtP .
Constant_Value_nhhzojlawr ; } else { rtB . onvs14ppyq = dqp2jl35hv ; } }
glrhaqk1if = rtP . donotdeletethisgain_Gain * rtB . bx1vifjqa5 [ 9 ] * rtP .
Kv1_Gain ; jglko44zhq = rtP . donotdeletethisgain_Gain_f1ifkvuqfs * rtB .
bx1vifjqa5 [ 10 ] * rtP . Kv1_Gain ; dqu31pvks0 = rtP .
donotdeletethisgain_Gain_kkqpn0enmg * rtB . bx1vifjqa5 [ 11 ] * rtP .
Kv1_Gain ; bouhabhtxj = rtP . donotdeletethisgain_Gain_e2auf2j1rh * rtB .
bx1vifjqa5 [ 21 ] * rtP . Kv_Gain ; dziq0k4vk2 = rtP .
donotdeletethisgain_Gain_mshnmhldd3 * rtB . bx1vifjqa5 [ 22 ] * rtP . Kv_Gain
; lrfvawl2h3 = rtP . donotdeletethisgain_Gain_j0haq310r2 * rtB . bx1vifjqa5 [
23 ] * rtP . Kv_Gain ; rtB . a30jmyeur3 = ( glrhaqk1if * bouhabhtxj +
jglko44zhq * dziq0k4vk2 ) + dqu31pvks0 * lrfvawl2h3 ; bouhabhtxj *=
jglko44zhq - dqu31pvks0 ; dziq0k4vk2 *= dqu31pvks0 - glrhaqk1if ; lrfvawl2h3
*= glrhaqk1if - jglko44zhq ; rtB . hghs1t20yw = ( ( bouhabhtxj + dziq0k4vk2 )
+ lrfvawl2h3 ) * rtP . puV_Gain ; bouhabhtxj = rtP .
donotdeletethisgain_Gain_gmp4pnrphh * rtB . bx1vifjqa5 [ 12 ] * rtP .
Kv1_Gain_bfvq3500bp ; dziq0k4vk2 = rtP . donotdeletethisgain_Gain_bnawliqvik
* rtB . bx1vifjqa5 [ 13 ] * rtP . Kv1_Gain_bfvq3500bp ; lrfvawl2h3 = rtP .
donotdeletethisgain_Gain_ovofaqt3tg * rtB . bx1vifjqa5 [ 14 ] * rtP .
Kv1_Gain_bfvq3500bp ; glrhaqk1if = rtP . donotdeletethisgain_Gain_ok2btrhuoi
* rtB . bx1vifjqa5 [ 24 ] * rtP . Kv_Gain_czwgps5mha ; jglko44zhq = rtP .
donotdeletethisgain_Gain_jfb5zvz2in * rtB . bx1vifjqa5 [ 25 ] * rtP .
Kv_Gain_czwgps5mha ; dqu31pvks0 = rtP . donotdeletethisgain_Gain_agzp2l5xoj *
rtB . bx1vifjqa5 [ 26 ] * rtP . Kv_Gain_czwgps5mha ; rtB . mwbvfjvdmp = (
bouhabhtxj * glrhaqk1if + dziq0k4vk2 * jglko44zhq ) + lrfvawl2h3 * dqu31pvks0
; glrhaqk1if *= dziq0k4vk2 - lrfvawl2h3 ; jglko44zhq *= lrfvawl2h3 -
bouhabhtxj ; dqu31pvks0 *= bouhabhtxj - dziq0k4vk2 ; rtB . kkekcv3h3x = ( (
glrhaqk1if + jglko44zhq ) + dqu31pvks0 ) * rtP . puV_Gain_p1qhxv12dx ;
bouhabhtxj = rtP . donotdeletethisgain_Gain_lmtenwvpad * rtB . bx1vifjqa5 [ 6
] * rtP . Kv1_Gain_otbflrw2my ; dziq0k4vk2 = rtP .
donotdeletethisgain_Gain_b4h4vrwez2 * rtB . bx1vifjqa5 [ 7 ] * rtP .
Kv1_Gain_otbflrw2my ; lrfvawl2h3 = rtP . donotdeletethisgain_Gain_hjafqzuqe3
* rtB . bx1vifjqa5 [ 8 ] * rtP . Kv1_Gain_otbflrw2my ; glrhaqk1if = rtP .
donotdeletethisgain_Gain_jy0ly32qzq * rtB . bx1vifjqa5 [ 18 ] * rtP .
Kv_Gain_ozfx3cxmrl ; jglko44zhq = rtP . donotdeletethisgain_Gain_b0gdocyoez *
rtB . bx1vifjqa5 [ 19 ] * rtP . Kv_Gain_ozfx3cxmrl ; dqu31pvks0 = rtP .
donotdeletethisgain_Gain_ablp5g31dp * rtB . bx1vifjqa5 [ 20 ] * rtP .
Kv_Gain_ozfx3cxmrl ; rtB . lau2uwvqvd = ( bouhabhtxj * glrhaqk1if +
dziq0k4vk2 * jglko44zhq ) + lrfvawl2h3 * dqu31pvks0 ; glrhaqk1if *=
dziq0k4vk2 - lrfvawl2h3 ; jglko44zhq *= lrfvawl2h3 - bouhabhtxj ; dqu31pvks0
*= bouhabhtxj - dziq0k4vk2 ; rtB . phjkba00rh = ( ( glrhaqk1if + jglko44zhq )
+ dqu31pvks0 ) * rtP . puV_Gain_k4ukpfvde5 ; bouhabhtxj = rtP .
donotdeletethisgain_Gain_cnnpmgyozm * rtB . bx1vifjqa5 [ 15 ] * rtP .
Kv1_Gain_fxnn3aho5e ; dziq0k4vk2 = rtP . donotdeletethisgain_Gain_l234soa3tf
* rtB . bx1vifjqa5 [ 16 ] * rtP . Kv1_Gain_fxnn3aho5e ; lrfvawl2h3 = rtP .
donotdeletethisgain_Gain_lkyvqrwckq * rtB . bx1vifjqa5 [ 17 ] * rtP .
Kv1_Gain_fxnn3aho5e ; glrhaqk1if = rtP . donotdeletethisgain_Gain_en3nmrxgld
* rtB . bx1vifjqa5 [ 27 ] * rtP . Kv_Gain_nftr42q2lb ; jglko44zhq = rtP .
donotdeletethisgain_Gain_hsdfpbzlqb * rtB . bx1vifjqa5 [ 28 ] * rtP .
Kv_Gain_nftr42q2lb ; dqu31pvks0 = rtP . donotdeletethisgain_Gain_by5bos33lx *
rtB . bx1vifjqa5 [ 29 ] * rtP . Kv_Gain_nftr42q2lb ; rtB . bgdmyntavi = (
bouhabhtxj * glrhaqk1if + dziq0k4vk2 * jglko44zhq ) + lrfvawl2h3 * dqu31pvks0
; glrhaqk1if *= dziq0k4vk2 - lrfvawl2h3 ; jglko44zhq *= lrfvawl2h3 -
bouhabhtxj ; dqu31pvks0 *= bouhabhtxj - dziq0k4vk2 ; rtB . m3mvlja3vc = ( (
glrhaqk1if + jglko44zhq ) + dqu31pvks0 ) * rtP . puV_Gain_ff0r1eyugh ;
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID4 ( int_T tid ) {
gqdbtcmlhkTID4 ( rtS , & rtDW . gqdbtcmlhky ) ; gqdbtcmlhkTID4 ( rtS , & rtDW
. puvrgymrfw ) ; gqdbtcmlhkTID4 ( rtS , & rtDW . cqi4cjmse0 ) ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { real_T * lastU ;
{ SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnUpdate ( rts , 0 ) ; if
( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { real_T * * uBuffer = (
real_T * * ) & rtDW . d2mee5ywuy . TUbufferPtrs [ 0 ] ; real_T * * tBuffer =
( real_T * * ) & rtDW . d2mee5ywuy . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( rtS ) ; rtDW . pom54x2oll . Head = ( ( rtDW . pom54x2oll . Head < (
rtDW . pom54x2oll . CircularBufSize - 1 ) ) ? ( rtDW . pom54x2oll . Head + 1
) : 0 ) ; if ( rtDW . pom54x2oll . Head == rtDW . pom54x2oll . Tail ) { if (
! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . pom54x2oll . CircularBufSize , &
rtDW . pom54x2oll . Tail , & rtDW . pom54x2oll . Head , & rtDW . pom54x2oll .
Last , simTime - rtP . DieselEngineGovernor_Td , tBuffer , uBuffer , ( NULL )
, ( boolean_T ) 0 , false , & rtDW . pom54x2oll . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . pom54x2oll . Head ] = simTime ; ( * uBuffer ) [ rtDW .
pom54x2oll . Head ] = rtB . ajb0jd1wax ; } if ( rtX . i5wyejvw00 == rtP .
Integrator_UpperSat ) { switch ( rtDW . dxzyqf5nmc ) { case 3 : if ( rtB .
asp4dkpswc < 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
rtDW . dxzyqf5nmc = 1 ; } break ; case 1 : if ( rtB . asp4dkpswc >= 0.0 ) {
rtDW . dxzyqf5nmc = 3 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
} break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if (
rtB . asp4dkpswc < 0.0 ) { rtDW . dxzyqf5nmc = 1 ; } else { rtDW . dxzyqf5nmc
= 3 ; } break ; } } else if ( rtX . i5wyejvw00 == rtP . Integrator_LowerSat )
{ switch ( rtDW . dxzyqf5nmc ) { case 4 : if ( rtB . asp4dkpswc > 0.0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . dxzyqf5nmc = 2 ;
} break ; case 2 : if ( rtB . asp4dkpswc <= 0.0 ) { rtDW . dxzyqf5nmc = 4 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; default :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( rtB . asp4dkpswc >
0.0 ) { rtDW . dxzyqf5nmc = 2 ; } else { rtDW . dxzyqf5nmc = 4 ; } break ; }
} else { rtDW . dxzyqf5nmc = 0 ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) {
rtDW . nq0bdz3dwr = rtB . onvs14ppyq ; } if ( rtX . ccho5ckvhr == rtP .
Integrator_UpperSat_f4njfmemxq ) { switch ( rtDW . kds0u3jlha ) { case 3 : if
( rtB . edtnmnr3vm < 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . kds0u3jlha = 1 ; } break ; case 1 : if ( rtB . edtnmnr3vm >= 0.0 )
{ rtDW . kds0u3jlha = 3 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if
( rtB . edtnmnr3vm < 0.0 ) { rtDW . kds0u3jlha = 1 ; } else { rtDW .
kds0u3jlha = 3 ; } break ; } } else if ( rtX . ccho5ckvhr == rtP .
Integrator_LowerSat_dbtbuno0hm ) { switch ( rtDW . kds0u3jlha ) { case 4 : if
( rtB . edtnmnr3vm > 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . kds0u3jlha = 2 ; } break ; case 2 : if ( rtB . edtnmnr3vm <= 0.0 )
{ rtDW . kds0u3jlha = 4 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if
( rtB . edtnmnr3vm > 0.0 ) { rtDW . kds0u3jlha = 2 ; } else { rtDW .
kds0u3jlha = 4 ; } break ; } } else { rtDW . kds0u3jlha = 0 ; } if ( rtX .
mir041liby == rtP . Integrator_UpperSat_drvyrbacf3 ) { switch ( rtDW .
ktwxy2gk4t ) { case 3 : if ( rtB . kkwarc0rc1 < 0.0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . ktwxy2gk4t = 1 ;
} break ; case 1 : if ( rtB . kkwarc0rc1 >= 0.0 ) { rtDW . ktwxy2gk4t = 3 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; default :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( rtB . kkwarc0rc1 <
0.0 ) { rtDW . ktwxy2gk4t = 1 ; } else { rtDW . ktwxy2gk4t = 3 ; } break ; }
} else if ( rtX . mir041liby == rtP . Integrator_LowerSat_hx5r22dn01 ) {
switch ( rtDW . ktwxy2gk4t ) { case 4 : if ( rtB . kkwarc0rc1 > 0.0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . ktwxy2gk4t = 2 ;
} break ; case 2 : if ( rtB . kkwarc0rc1 <= 0.0 ) { rtDW . ktwxy2gk4t = 4 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; default :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( rtB . kkwarc0rc1 >
0.0 ) { rtDW . ktwxy2gk4t = 2 ; } else { rtDW . ktwxy2gk4t = 4 ; } break ; }
} else { rtDW . ktwxy2gk4t = 0 ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . iin0a1rkif . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * )
& rtDW . iin0a1rkif . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ;
rtDW . g35ini334z . Head = ( ( rtDW . g35ini334z . Head < ( rtDW . g35ini334z
. CircularBufSize - 1 ) ) ? ( rtDW . g35ini334z . Head + 1 ) : 0 ) ; if (
rtDW . g35ini334z . Head == rtDW . g35ini334z . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . g35ini334z . CircularBufSize , & rtDW
. g35ini334z . Tail , & rtDW . g35ini334z . Head , & rtDW . g35ini334z . Last
, simTime - rtP . DieselEngineGovernor_Td_khwtk020bh , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & rtDW . g35ini334z . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "tdelay memory allocation error" ) ; return ; } } (
* tBuffer ) [ rtDW . g35ini334z . Head ] = simTime ; ( * uBuffer ) [ rtDW .
g35ini334z . Head ] = rtB . is1htqzogm ; } if ( rtX . i302uyv4ub == rtP .
Integrator_UpperSat_emevdxcfrg ) { switch ( rtDW . da1gnnba33 ) { case 3 : if
( rtB . czljrbrypr < 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . da1gnnba33 = 1 ; } break ; case 1 : if ( rtB . czljrbrypr >= 0.0 )
{ rtDW . da1gnnba33 = 3 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if
( rtB . czljrbrypr < 0.0 ) { rtDW . da1gnnba33 = 1 ; } else { rtDW .
da1gnnba33 = 3 ; } break ; } } else if ( rtX . i302uyv4ub == rtP .
Integrator_LowerSat_b2xzznseid ) { switch ( rtDW . da1gnnba33 ) { case 4 : if
( rtB . czljrbrypr > 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . da1gnnba33 = 2 ; } break ; case 2 : if ( rtB . czljrbrypr <= 0.0 )
{ rtDW . da1gnnba33 = 4 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if
( rtB . czljrbrypr > 0.0 ) { rtDW . da1gnnba33 = 2 ; } else { rtDW .
da1gnnba33 = 4 ; } break ; } } else { rtDW . da1gnnba33 = 0 ; } if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtDW . dntwmboj5l = rtB . ng0qeau1ay ; } if
( rtX . c3odb1pgdi == rtP . Integrator_UpperSat_gojjo5eoxp ) { switch ( rtDW
. kb03ykgabx ) { case 3 : if ( rtB . k5vss3m212 < 0.0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . kb03ykgabx = 1 ;
} break ; case 1 : if ( rtB . k5vss3m212 >= 0.0 ) { rtDW . kb03ykgabx = 3 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; default :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( rtB . k5vss3m212 <
0.0 ) { rtDW . kb03ykgabx = 1 ; } else { rtDW . kb03ykgabx = 3 ; } break ; }
} else if ( rtX . c3odb1pgdi == rtP . Integrator_LowerSat_odmybcofvo ) {
switch ( rtDW . kb03ykgabx ) { case 4 : if ( rtB . k5vss3m212 > 0.0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . kb03ykgabx = 2 ;
} break ; case 2 : if ( rtB . k5vss3m212 <= 0.0 ) { rtDW . kb03ykgabx = 4 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; default :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( rtB . k5vss3m212 >
0.0 ) { rtDW . kb03ykgabx = 2 ; } else { rtDW . kb03ykgabx = 4 ; } break ; }
} else { rtDW . kb03ykgabx = 0 ; } if ( rtX . om4zueiy1s == rtP .
Integrator_UpperSat_mx32ysi3tz ) { switch ( rtDW . phi4pfmr53 ) { case 3 : if
( rtB . k0htkyngm1 < 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . phi4pfmr53 = 1 ; } break ; case 1 : if ( rtB . k0htkyngm1 >= 0.0 )
{ rtDW . phi4pfmr53 = 3 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if
( rtB . k0htkyngm1 < 0.0 ) { rtDW . phi4pfmr53 = 1 ; } else { rtDW .
phi4pfmr53 = 3 ; } break ; } } else if ( rtX . om4zueiy1s == rtP .
Integrator_LowerSat_pgmxfrs2lk ) { switch ( rtDW . phi4pfmr53 ) { case 4 : if
( rtB . k0htkyngm1 > 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . phi4pfmr53 = 2 ; } break ; case 2 : if ( rtB . k0htkyngm1 <= 0.0 )
{ rtDW . phi4pfmr53 = 4 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if
( rtB . k0htkyngm1 > 0.0 ) { rtDW . phi4pfmr53 = 2 ; } else { rtDW .
phi4pfmr53 = 4 ; } break ; } } else { rtDW . phi4pfmr53 = 0 ; } { real_T * *
uBuffer = ( real_T * * ) & rtDW . abwpuwwzkr . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . abwpuwwzkr . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . aexlfdwpio . Head = ( ( rtDW . aexlfdwpio .
Head < ( rtDW . aexlfdwpio . CircularBufSize - 1 ) ) ? ( rtDW . aexlfdwpio .
Head + 1 ) : 0 ) ; if ( rtDW . aexlfdwpio . Head == rtDW . aexlfdwpio . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . aexlfdwpio .
CircularBufSize , & rtDW . aexlfdwpio . Tail , & rtDW . aexlfdwpio . Head , &
rtDW . aexlfdwpio . Last , simTime - rtP . DieselEngineGovernor_Td_bx2jkcsvfl
, tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW .
aexlfdwpio . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
aexlfdwpio . Head ] = simTime ; ( * uBuffer ) [ rtDW . aexlfdwpio . Head ] =
rtB . hwewg0ullm ; } if ( rtX . oh1bpz4njz == rtP .
Integrator_UpperSat_m3couvae5u ) { switch ( rtDW . nopy54tklg ) { case 3 : if
( rtB . o2yzakmz1p < 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . nopy54tklg = 1 ; } break ; case 1 : if ( rtB . o2yzakmz1p >= 0.0 )
{ rtDW . nopy54tklg = 3 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if
( rtB . o2yzakmz1p < 0.0 ) { rtDW . nopy54tklg = 1 ; } else { rtDW .
nopy54tklg = 3 ; } break ; } } else if ( rtX . oh1bpz4njz == rtP .
Integrator_LowerSat_cp3m3xxjrp ) { switch ( rtDW . nopy54tklg ) { case 4 : if
( rtB . o2yzakmz1p > 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . nopy54tklg = 2 ; } break ; case 2 : if ( rtB . o2yzakmz1p <= 0.0 )
{ rtDW . nopy54tklg = 4 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if
( rtB . o2yzakmz1p > 0.0 ) { rtDW . nopy54tklg = 2 ; } else { rtDW .
nopy54tklg = 4 ; } break ; } } else { rtDW . nopy54tklg = 0 ; } if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtDW . hdwuwozgch = rtB . egynfvvlbk ; } if
( rtX . nk334zxlzp == rtP . Integrator_UpperSat_g2nmqxfxgj ) { switch ( rtDW
. kpe5ac43ty ) { case 3 : if ( rtB . kfay54rwhc < 0.0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . kpe5ac43ty = 1 ;
} break ; case 1 : if ( rtB . kfay54rwhc >= 0.0 ) { rtDW . kpe5ac43ty = 3 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; default :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( rtB . kfay54rwhc <
0.0 ) { rtDW . kpe5ac43ty = 1 ; } else { rtDW . kpe5ac43ty = 3 ; } break ; }
} else if ( rtX . nk334zxlzp == rtP . Integrator_LowerSat_jpz1embdbj ) {
switch ( rtDW . kpe5ac43ty ) { case 4 : if ( rtB . kfay54rwhc > 0.0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . kpe5ac43ty = 2 ;
} break ; case 2 : if ( rtB . kfay54rwhc <= 0.0 ) { rtDW . kpe5ac43ty = 4 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; default :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( rtB . kfay54rwhc >
0.0 ) { rtDW . kpe5ac43ty = 2 ; } else { rtDW . kpe5ac43ty = 4 ; } break ; }
} else { rtDW . kpe5ac43ty = 0 ; } if ( rtX . b0v4jzhvdz == rtP .
Integrator_UpperSat_awe5bjjzds ) { switch ( rtDW . pxa1vgfiln ) { case 3 : if
( rtB . jx22a2iggv < 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . pxa1vgfiln = 1 ; } break ; case 1 : if ( rtB . jx22a2iggv >= 0.0 )
{ rtDW . pxa1vgfiln = 3 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if
( rtB . jx22a2iggv < 0.0 ) { rtDW . pxa1vgfiln = 1 ; } else { rtDW .
pxa1vgfiln = 3 ; } break ; } } else if ( rtX . b0v4jzhvdz == rtP .
Integrator_LowerSat_boizxptfju ) { switch ( rtDW . pxa1vgfiln ) { case 4 : if
( rtB . jx22a2iggv > 0.0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . pxa1vgfiln = 2 ; } break ; case 2 : if ( rtB . jx22a2iggv <= 0.0 )
{ rtDW . pxa1vgfiln = 4 ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } break ; default : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if
( rtB . jx22a2iggv > 0.0 ) { rtDW . pxa1vgfiln = 2 ; } else { rtDW .
pxa1vgfiln = 4 ; } break ; } } else { rtDW . pxa1vgfiln = 0 ; } if ( rtDW .
k2gqgbs5d5 == ( rtInf ) ) { rtDW . k2gqgbs5d5 = ssGetT ( rtS ) ; lastU = &
rtDW . hgooub1kfm ; } else if ( rtDW . mgitsq1y4c == ( rtInf ) ) { rtDW .
mgitsq1y4c = ssGetT ( rtS ) ; lastU = & rtDW . ielhf2atex ; } else if ( rtDW
. k2gqgbs5d5 < rtDW . mgitsq1y4c ) { rtDW . k2gqgbs5d5 = ssGetT ( rtS ) ;
lastU = & rtDW . hgooub1kfm ; } else { rtDW . mgitsq1y4c = ssGetT ( rtS ) ;
lastU = & rtDW . ielhf2atex ; } * lastU = rtB . e2b1dnuz0z ; if ( rtDW .
kydy0dzs4q == ( rtInf ) ) { rtDW . kydy0dzs4q = ssGetT ( rtS ) ; lastU = &
rtDW . gpk14zbdx0 ; } else if ( rtDW . ix3txx30gm == ( rtInf ) ) { rtDW .
ix3txx30gm = ssGetT ( rtS ) ; lastU = & rtDW . l1uw3rg2qt ; } else if ( rtDW
. kydy0dzs4q < rtDW . ix3txx30gm ) { rtDW . kydy0dzs4q = ssGetT ( rtS ) ;
lastU = & rtDW . gpk14zbdx0 ; } else { rtDW . ix3txx30gm = ssGetT ( rtS ) ;
lastU = & rtDW . l1uw3rg2qt ; } * lastU = rtB . e4wb3lihdw ; if ( rtDW .
dfk5fcernw == ( rtInf ) ) { rtDW . dfk5fcernw = ssGetT ( rtS ) ; lastU = &
rtDW . isywftekv1 ; } else if ( rtDW . excno4hjxp == ( rtInf ) ) { rtDW .
excno4hjxp = ssGetT ( rtS ) ; lastU = & rtDW . ndirfsq4jw ; } else if ( rtDW
. dfk5fcernw < rtDW . excno4hjxp ) { rtDW . dfk5fcernw = ssGetT ( rtS ) ;
lastU = & rtDW . isywftekv1 ; } else { rtDW . excno4hjxp = ssGetT ( rtS ) ;
lastU = & rtDW . ndirfsq4jw ; } * lastU = rtB . h4uex5jljn ; if ( rtDW .
g0ztsagyor == ( rtInf ) ) { rtDW . g0ztsagyor = ssGetT ( rtS ) ; lastU = &
rtDW . hs0fo3ig54 ; } else if ( rtDW . fetl5keei4 == ( rtInf ) ) { rtDW .
fetl5keei4 = ssGetT ( rtS ) ; lastU = & rtDW . nnbixcnsch ; } else if ( rtDW
. g0ztsagyor < rtDW . fetl5keei4 ) { rtDW . g0ztsagyor = ssGetT ( rtS ) ;
lastU = & rtDW . hs0fo3ig54 ; } else { rtDW . fetl5keei4 = ssGetT ( rtS ) ;
lastU = & rtDW . nnbixcnsch ; } * lastU = rtB . pkizjdds0x ; UNUSED_PARAMETER
( tid ) ; } void MdlUpdateTID4 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlDerivatives ( void ) { int32_T i ; XDot * _rtXdot ; XDis * _rtXdis ;
_rtXdis = ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ; _rtXdot = ( ( XDot
* ) ssGetdX ( rtS ) ) ; _rtXdot -> dxcqn52y0j = rtB . n0ctdpimv4 ; for ( i =
0 ; i < 5 ; i ++ ) { _rtXdot -> prvbwmxe5d [ i ] = rtB . djoydjgvbg [ i ] ; }
gh4mkhetsb ( & rtB . cqi4cjmse0 , & rtDW . cqi4cjmse0 , & _rtXdot ->
cqi4cjmse0 ) ; _rtXdot -> ftxl3ve1we = rtB . brvzzfgdkk ; for ( i = 0 ; i < 5
; i ++ ) { _rtXdot -> cqlekexsf4 [ i ] = rtB . grwocktd5q [ i ] ; }
gh4mkhetsb ( & rtB . gqdbtcmlhky , & rtDW . gqdbtcmlhky , & _rtXdot ->
gqdbtcmlhky ) ; _rtXdot -> pbf0mwqvxu = rtB . fr3yekodlk ; for ( i = 0 ; i <
5 ; i ++ ) { _rtXdot -> ezu3nw0jme [ i ] = rtB . aaxc40oml0 [ i ] ; }
gh4mkhetsb ( & rtB . puvrgymrfw , & rtDW . puvrgymrfw , & _rtXdot ->
puvrgymrfw ) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; real_T *
sfcndX_fx = ( real_T * ) & ( ( XDot * ) ssGetdX ( rtS ) ) -> mpaduaczra [ 0 ]
; ssSetdX ( rts , sfcndX_fx ) ; sfcnDerivatives ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } _rtXdot -> ipldudc4jc = rtB
. ol0nkdk5rw ; if ( ( rtDW . dxzyqf5nmc != 3 ) && ( rtDW . dxzyqf5nmc != 4 )
) { _rtXdot -> i5wyejvw00 = rtB . asp4dkpswc ; _rtXdis -> i5wyejvw00 = false
; } else { _rtXdot -> i5wyejvw00 = 0.0 ; _rtXdis -> i5wyejvw00 = ( ( rtDW .
dxzyqf5nmc == 3 ) || ( rtDW . dxzyqf5nmc == 4 ) || _rtXdis -> i5wyejvw00 ) ;
} _rtXdot -> jzaacseaxt = rtB . ljxtwfbyom ; _rtXdot -> ir2k1m2xef [ 0 ] =
0.0 ; _rtXdot -> ir2k1m2xef [ 0 ] += rtP . CONTROLSYSTEM_A [ 0 ] * rtX .
ir2k1m2xef [ 0 ] ; _rtXdot -> ir2k1m2xef [ 1 ] = 0.0 ; _rtXdot -> ir2k1m2xef
[ 0 ] += rtP . CONTROLSYSTEM_A [ 1 ] * rtX . ir2k1m2xef [ 1 ] ; _rtXdot ->
ir2k1m2xef [ 1 ] += rtX . ir2k1m2xef [ 0 ] ; _rtXdot -> ir2k1m2xef [ 0 ] +=
rtB . lmjgudxydq ; if ( ( rtDW . kds0u3jlha != 3 ) && ( rtDW . kds0u3jlha !=
4 ) ) { _rtXdot -> ccho5ckvhr = rtB . edtnmnr3vm ; _rtXdis -> ccho5ckvhr =
false ; } else { _rtXdot -> ccho5ckvhr = 0.0 ; _rtXdis -> ccho5ckvhr = ( (
rtDW . kds0u3jlha == 3 ) || ( rtDW . kds0u3jlha == 4 ) || _rtXdis ->
ccho5ckvhr ) ; } _rtXdot -> oq42ze3zlo = 0.0 ; _rtXdot -> oq42ze3zlo += rtP .
TF1_A * rtX . oq42ze3zlo ; _rtXdot -> oq42ze3zlo += rtB . g3tr54e0gh ;
_rtXdot -> jlygjdr5nw = 0.0 ; _rtXdot -> jlygjdr5nw += rtP . TF2_A * rtX .
jlygjdr5nw ; _rtXdot -> jlygjdr5nw += rtB . mgwenfy132 ; _rtXdot ->
fo31vd32p4 = 0.0 ; _rtXdot -> fo31vd32p4 += rtP . StateSpace_A * rtX .
fo31vd32p4 ; _rtXdot -> fo31vd32p4 += rtP . StateSpace_B * rtB . d3prvaxezv ;
if ( ( rtDW . ktwxy2gk4t != 3 ) && ( rtDW . ktwxy2gk4t != 4 ) ) { _rtXdot ->
mir041liby = rtB . kkwarc0rc1 ; _rtXdis -> mir041liby = false ; } else {
_rtXdot -> mir041liby = 0.0 ; _rtXdis -> mir041liby = ( ( rtDW . ktwxy2gk4t
== 3 ) || ( rtDW . ktwxy2gk4t == 4 ) || _rtXdis -> mir041liby ) ; } _rtXdot
-> jz4lzneeo1 = 0.0 ; _rtXdot -> jz4lzneeo1 += rtP . StateSpace_A_pgmfa5yhzo
* rtX . jz4lzneeo1 ; _rtXdot -> jz4lzneeo1 += rtP . StateSpace_B_pl13jcfikc *
rtB . npq14v1sxw ; _rtXdot -> ebee4njyij = rtB . dg4rfafxi2 ; if ( ( rtDW .
da1gnnba33 != 3 ) && ( rtDW . da1gnnba33 != 4 ) ) { _rtXdot -> i302uyv4ub =
rtB . czljrbrypr ; _rtXdis -> i302uyv4ub = false ; } else { _rtXdot ->
i302uyv4ub = 0.0 ; _rtXdis -> i302uyv4ub = ( ( rtDW . da1gnnba33 == 3 ) || (
rtDW . da1gnnba33 == 4 ) || _rtXdis -> i302uyv4ub ) ; } _rtXdot -> cvoatslkxn
= rtB . feadnsrfon ; _rtXdot -> ozdje1tbeq [ 0 ] = 0.0 ; _rtXdot ->
ozdje1tbeq [ 0 ] += rtP . CONTROLSYSTEM_A_oy0zvzwgbs [ 0 ] * rtX . ozdje1tbeq
[ 0 ] ; _rtXdot -> ozdje1tbeq [ 1 ] = 0.0 ; _rtXdot -> ozdje1tbeq [ 0 ] +=
rtP . CONTROLSYSTEM_A_oy0zvzwgbs [ 1 ] * rtX . ozdje1tbeq [ 1 ] ; _rtXdot ->
ozdje1tbeq [ 1 ] += rtX . ozdje1tbeq [ 0 ] ; _rtXdot -> ozdje1tbeq [ 0 ] +=
rtB . dg5y4n2fx5 ; if ( ( rtDW . kb03ykgabx != 3 ) && ( rtDW . kb03ykgabx !=
4 ) ) { _rtXdot -> c3odb1pgdi = rtB . k5vss3m212 ; _rtXdis -> c3odb1pgdi =
false ; } else { _rtXdot -> c3odb1pgdi = 0.0 ; _rtXdis -> c3odb1pgdi = ( (
rtDW . kb03ykgabx == 3 ) || ( rtDW . kb03ykgabx == 4 ) || _rtXdis ->
c3odb1pgdi ) ; } _rtXdot -> dumyo0mi3u = 0.0 ; _rtXdot -> dumyo0mi3u += rtP .
TF1_A_in4jblwda4 * rtX . dumyo0mi3u ; _rtXdot -> dumyo0mi3u += rtB .
lrb3pzyxyo ; _rtXdot -> mjljeeps1u = 0.0 ; _rtXdot -> mjljeeps1u += rtP .
TF2_A_enodlnrioj * rtX . mjljeeps1u ; _rtXdot -> mjljeeps1u += rtB .
kdezj5zhgl ; _rtXdot -> e32unymcc4 = 0.0 ; _rtXdot -> e32unymcc4 += rtP .
StateSpace_A_egh3gfm2o1 * rtX . e32unymcc4 ; _rtXdot -> e32unymcc4 += rtP .
StateSpace_B_ffyet4mzai * rtB . jgmqqelntj ; if ( ( rtDW . phi4pfmr53 != 3 )
&& ( rtDW . phi4pfmr53 != 4 ) ) { _rtXdot -> om4zueiy1s = rtB . k0htkyngm1 ;
_rtXdis -> om4zueiy1s = false ; } else { _rtXdot -> om4zueiy1s = 0.0 ;
_rtXdis -> om4zueiy1s = ( ( rtDW . phi4pfmr53 == 3 ) || ( rtDW . phi4pfmr53
== 4 ) || _rtXdis -> om4zueiy1s ) ; } _rtXdot -> nafgdh5awp = 0.0 ; _rtXdot
-> nafgdh5awp += rtP . StateSpace_A_hz0n2nokjy * rtX . nafgdh5awp ; _rtXdot
-> nafgdh5awp += rtP . StateSpace_B_cies5b1jkk * rtB . f1xtfhhhqv ; _rtXdot
-> pvsfs5bviq = rtB . iwhl53vsbp ; if ( ( rtDW . nopy54tklg != 3 ) && ( rtDW
. nopy54tklg != 4 ) ) { _rtXdot -> oh1bpz4njz = rtB . o2yzakmz1p ; _rtXdis ->
oh1bpz4njz = false ; } else { _rtXdot -> oh1bpz4njz = 0.0 ; _rtXdis ->
oh1bpz4njz = ( ( rtDW . nopy54tklg == 3 ) || ( rtDW . nopy54tklg == 4 ) ||
_rtXdis -> oh1bpz4njz ) ; } _rtXdot -> mtfzfgh35r = rtB . nvzgkwwurg ;
_rtXdot -> kvt4cjhlrh [ 0 ] = 0.0 ; _rtXdot -> kvt4cjhlrh [ 0 ] += rtP .
CONTROLSYSTEM_A_fmcipdkw5g [ 0 ] * rtX . kvt4cjhlrh [ 0 ] ; _rtXdot ->
kvt4cjhlrh [ 1 ] = 0.0 ; _rtXdot -> kvt4cjhlrh [ 0 ] += rtP .
CONTROLSYSTEM_A_fmcipdkw5g [ 1 ] * rtX . kvt4cjhlrh [ 1 ] ; _rtXdot ->
kvt4cjhlrh [ 1 ] += rtX . kvt4cjhlrh [ 0 ] ; _rtXdot -> kvt4cjhlrh [ 0 ] +=
rtB . prgl4v4rcs ; if ( ( rtDW . kpe5ac43ty != 3 ) && ( rtDW . kpe5ac43ty !=
4 ) ) { _rtXdot -> nk334zxlzp = rtB . kfay54rwhc ; _rtXdis -> nk334zxlzp =
false ; } else { _rtXdot -> nk334zxlzp = 0.0 ; _rtXdis -> nk334zxlzp = ( (
rtDW . kpe5ac43ty == 3 ) || ( rtDW . kpe5ac43ty == 4 ) || _rtXdis ->
nk334zxlzp ) ; } _rtXdot -> geip5cv4tr = 0.0 ; _rtXdot -> geip5cv4tr += rtP .
TF1_A_jog0zs3jsk * rtX . geip5cv4tr ; _rtXdot -> geip5cv4tr += rtB .
nwxyngwvoo ; _rtXdot -> j51tfhhdgm = 0.0 ; _rtXdot -> j51tfhhdgm += rtP .
TF2_A_nfpoakqhp5 * rtX . j51tfhhdgm ; _rtXdot -> j51tfhhdgm += rtB .
h2f5ohv0un ; _rtXdot -> icyr0u0hwc = 0.0 ; _rtXdot -> icyr0u0hwc += rtP .
StateSpace_A_ggjpwot10c * rtX . icyr0u0hwc ; _rtXdot -> icyr0u0hwc += rtP .
StateSpace_B_k2dlv21nqs * rtB . o5yahrnyq3 ; if ( ( rtDW . pxa1vgfiln != 3 )
&& ( rtDW . pxa1vgfiln != 4 ) ) { _rtXdot -> b0v4jzhvdz = rtB . jx22a2iggv ;
_rtXdis -> b0v4jzhvdz = false ; } else { _rtXdot -> b0v4jzhvdz = 0.0 ;
_rtXdis -> b0v4jzhvdz = ( ( rtDW . pxa1vgfiln == 3 ) || ( rtDW . pxa1vgfiln
== 4 ) || _rtXdis -> b0v4jzhvdz ) ; } _rtXdot -> mia0akgecm = 0.0 ; _rtXdot
-> mia0akgecm += rtP . StateSpace_A_f04ittyphn * rtX . mia0akgecm ; _rtXdot
-> mia0akgecm += rtP . StateSpace_B_oeqazzuglo * rtB . eyy42dwotr ; } void
MdlProjection ( void ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnProjection ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ;
} } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; nlzkrjo2aq ( & rtB . cqi4cjmse0 , &
rtDW . cqi4cjmse0 , & _rtZCSV -> cqi4cjmse0 ) ; nlzkrjo2aq ( & rtB .
gqdbtcmlhky , & rtDW . gqdbtcmlhky , & _rtZCSV -> gqdbtcmlhky ) ; nlzkrjo2aq
( & rtB . puvrgymrfw , & rtDW . puvrgymrfw , & _rtZCSV -> puvrgymrfw ) ; {
SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; ssSetNonsampledZCs ( rts , & (
( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> cfqlsew1dc [ 0 ] ) ) ;
sfcnZeroCrossings ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } if ( ( rtDW . dxzyqf5nmc == 1 ) && ( rtX . i5wyejvw00 >= rtP .
Integrator_UpperSat ) ) { _rtZCSV -> afoguwqjfk = 0.0 ; } else { _rtZCSV ->
afoguwqjfk = rtX . i5wyejvw00 - rtP . Integrator_UpperSat ; } if ( ( rtDW .
dxzyqf5nmc == 2 ) && ( rtX . i5wyejvw00 <= rtP . Integrator_LowerSat ) ) {
_rtZCSV -> lucojiysrq = 0.0 ; } else { _rtZCSV -> lucojiysrq = rtX .
i5wyejvw00 - rtP . Integrator_LowerSat ; } if ( ( rtDW . dxzyqf5nmc == 3 ) ||
( rtDW . dxzyqf5nmc == 4 ) ) { _rtZCSV -> nlqb31wufv = rtB . asp4dkpswc ; }
else { _rtZCSV -> nlqb31wufv = 0.0 ; } _rtZCSV -> k3knvu32n3 = rtB .
eiwmp0uix0 - rtP . input_Value ; _rtZCSV -> imzfl2vebh = rtB . eiwmp0uix0 -
rtP . input1_Value ; _rtZCSV -> fbrddyyoy4 = rtB . eiwmp0uix0 - rtP .
input2_Value ; if ( ( rtDW . kds0u3jlha == 1 ) && ( rtX . ccho5ckvhr >= rtP .
Integrator_UpperSat_f4njfmemxq ) ) { _rtZCSV -> kemkb2mise = 0.0 ; } else {
_rtZCSV -> kemkb2mise = rtX . ccho5ckvhr - rtP .
Integrator_UpperSat_f4njfmemxq ; } if ( ( rtDW . kds0u3jlha == 2 ) && ( rtX .
ccho5ckvhr <= rtP . Integrator_LowerSat_dbtbuno0hm ) ) { _rtZCSV ->
lp1sb12ryi = 0.0 ; } else { _rtZCSV -> lp1sb12ryi = rtX . ccho5ckvhr - rtP .
Integrator_LowerSat_dbtbuno0hm ; } if ( ( rtDW . kds0u3jlha == 3 ) || ( rtDW
. kds0u3jlha == 4 ) ) { _rtZCSV -> o4vvijvzcg = rtB . edtnmnr3vm ; } else {
_rtZCSV -> o4vvijvzcg = 0.0 ; } if ( ( rtDW . ktwxy2gk4t == 1 ) && ( rtX .
mir041liby >= rtP . Integrator_UpperSat_drvyrbacf3 ) ) { _rtZCSV ->
e33nze2ssx = 0.0 ; } else { _rtZCSV -> e33nze2ssx = rtX . mir041liby - rtP .
Integrator_UpperSat_drvyrbacf3 ; } if ( ( rtDW . ktwxy2gk4t == 2 ) && ( rtX .
mir041liby <= rtP . Integrator_LowerSat_hx5r22dn01 ) ) { _rtZCSV ->
ag1vf4a4u3 = 0.0 ; } else { _rtZCSV -> ag1vf4a4u3 = rtX . mir041liby - rtP .
Integrator_LowerSat_hx5r22dn01 ; } if ( ( rtDW . ktwxy2gk4t == 3 ) || ( rtDW
. ktwxy2gk4t == 4 ) ) { _rtZCSV -> nyphc2q12b = rtB . kkwarc0rc1 ; } else {
_rtZCSV -> nyphc2q12b = 0.0 ; } _rtZCSV -> o1mqsqyrdy = rtB . k2ed141a0b -
rtP . VRmin_UpperSat ; _rtZCSV -> l1argoqxtw = rtB . k2ed141a0b - rtP .
VRmin_LowerSat ; if ( ( rtDW . da1gnnba33 == 1 ) && ( rtX . i302uyv4ub >= rtP
. Integrator_UpperSat_emevdxcfrg ) ) { _rtZCSV -> pin3rosxsg = 0.0 ; } else {
_rtZCSV -> pin3rosxsg = rtX . i302uyv4ub - rtP .
Integrator_UpperSat_emevdxcfrg ; } if ( ( rtDW . da1gnnba33 == 2 ) && ( rtX .
i302uyv4ub <= rtP . Integrator_LowerSat_b2xzznseid ) ) { _rtZCSV ->
h3xmsgwx0g = 0.0 ; } else { _rtZCSV -> h3xmsgwx0g = rtX . i302uyv4ub - rtP .
Integrator_LowerSat_b2xzznseid ; } if ( ( rtDW . da1gnnba33 == 3 ) || ( rtDW
. da1gnnba33 == 4 ) ) { _rtZCSV -> ojyuykcebz = rtB . czljrbrypr ; } else {
_rtZCSV -> ojyuykcebz = 0.0 ; } _rtZCSV -> afo2krhylm = rtB . lds45me1tz -
rtP . input_Value_j4v0x1onoy ; _rtZCSV -> jiyga13sh4 = rtB . lds45me1tz - rtP
. input1_Value_jwembzy4jc ; _rtZCSV -> lzqlelecs4 = rtB . lds45me1tz - rtP .
input2_Value_mfn5w3js4u ; if ( ( rtDW . kb03ykgabx == 1 ) && ( rtX .
c3odb1pgdi >= rtP . Integrator_UpperSat_gojjo5eoxp ) ) { _rtZCSV ->
pr43eilg0t = 0.0 ; } else { _rtZCSV -> pr43eilg0t = rtX . c3odb1pgdi - rtP .
Integrator_UpperSat_gojjo5eoxp ; } if ( ( rtDW . kb03ykgabx == 2 ) && ( rtX .
c3odb1pgdi <= rtP . Integrator_LowerSat_odmybcofvo ) ) { _rtZCSV ->
fzgnkwz4ye = 0.0 ; } else { _rtZCSV -> fzgnkwz4ye = rtX . c3odb1pgdi - rtP .
Integrator_LowerSat_odmybcofvo ; } if ( ( rtDW . kb03ykgabx == 3 ) || ( rtDW
. kb03ykgabx == 4 ) ) { _rtZCSV -> mcho1hqrfy = rtB . k5vss3m212 ; } else {
_rtZCSV -> mcho1hqrfy = 0.0 ; } if ( ( rtDW . phi4pfmr53 == 1 ) && ( rtX .
om4zueiy1s >= rtP . Integrator_UpperSat_mx32ysi3tz ) ) { _rtZCSV ->
olc3qibfzx = 0.0 ; } else { _rtZCSV -> olc3qibfzx = rtX . om4zueiy1s - rtP .
Integrator_UpperSat_mx32ysi3tz ; } if ( ( rtDW . phi4pfmr53 == 2 ) && ( rtX .
om4zueiy1s <= rtP . Integrator_LowerSat_pgmxfrs2lk ) ) { _rtZCSV ->
cyqwvwitw3 = 0.0 ; } else { _rtZCSV -> cyqwvwitw3 = rtX . om4zueiy1s - rtP .
Integrator_LowerSat_pgmxfrs2lk ; } if ( ( rtDW . phi4pfmr53 == 3 ) || ( rtDW
. phi4pfmr53 == 4 ) ) { _rtZCSV -> nnlg152k0e = rtB . k0htkyngm1 ; } else {
_rtZCSV -> nnlg152k0e = 0.0 ; } _rtZCSV -> fzlvwva4rk = rtB . bbuesupjvr -
rtP . VRmin_UpperSat_kemkgh34w4 ; _rtZCSV -> gut4jb4uiu = rtB . bbuesupjvr -
rtP . VRmin_LowerSat_jrg3s5kvpl ; if ( ( rtDW . nopy54tklg == 1 ) && ( rtX .
oh1bpz4njz >= rtP . Integrator_UpperSat_m3couvae5u ) ) { _rtZCSV ->
iz32uk5vdq = 0.0 ; } else { _rtZCSV -> iz32uk5vdq = rtX . oh1bpz4njz - rtP .
Integrator_UpperSat_m3couvae5u ; } if ( ( rtDW . nopy54tklg == 2 ) && ( rtX .
oh1bpz4njz <= rtP . Integrator_LowerSat_cp3m3xxjrp ) ) { _rtZCSV ->
pkkrqvkifu = 0.0 ; } else { _rtZCSV -> pkkrqvkifu = rtX . oh1bpz4njz - rtP .
Integrator_LowerSat_cp3m3xxjrp ; } if ( ( rtDW . nopy54tklg == 3 ) || ( rtDW
. nopy54tklg == 4 ) ) { _rtZCSV -> ka3jflam1t = rtB . o2yzakmz1p ; } else {
_rtZCSV -> ka3jflam1t = 0.0 ; } _rtZCSV -> lcz4sncvlf = rtB . jsjdhroynv -
rtP . input_Value_kgzybnfuyq ; _rtZCSV -> f14gz5sodg = rtB . jsjdhroynv - rtP
. input1_Value_lmbqbgulqv ; _rtZCSV -> dbpph1ukxp = rtB . jsjdhroynv - rtP .
input2_Value_damfqfxz2b ; if ( ( rtDW . kpe5ac43ty == 1 ) && ( rtX .
nk334zxlzp >= rtP . Integrator_UpperSat_g2nmqxfxgj ) ) { _rtZCSV ->
ihtd2vlsmg = 0.0 ; } else { _rtZCSV -> ihtd2vlsmg = rtX . nk334zxlzp - rtP .
Integrator_UpperSat_g2nmqxfxgj ; } if ( ( rtDW . kpe5ac43ty == 2 ) && ( rtX .
nk334zxlzp <= rtP . Integrator_LowerSat_jpz1embdbj ) ) { _rtZCSV ->
bxxmi03ihe = 0.0 ; } else { _rtZCSV -> bxxmi03ihe = rtX . nk334zxlzp - rtP .
Integrator_LowerSat_jpz1embdbj ; } if ( ( rtDW . kpe5ac43ty == 3 ) || ( rtDW
. kpe5ac43ty == 4 ) ) { _rtZCSV -> drrwapyu32 = rtB . kfay54rwhc ; } else {
_rtZCSV -> drrwapyu32 = 0.0 ; } if ( ( rtDW . pxa1vgfiln == 1 ) && ( rtX .
b0v4jzhvdz >= rtP . Integrator_UpperSat_awe5bjjzds ) ) { _rtZCSV ->
dxf0nfzrqw = 0.0 ; } else { _rtZCSV -> dxf0nfzrqw = rtX . b0v4jzhvdz - rtP .
Integrator_UpperSat_awe5bjjzds ; } if ( ( rtDW . pxa1vgfiln == 2 ) && ( rtX .
b0v4jzhvdz <= rtP . Integrator_LowerSat_boizxptfju ) ) { _rtZCSV ->
keqw4vkkic = 0.0 ; } else { _rtZCSV -> keqw4vkkic = rtX . b0v4jzhvdz - rtP .
Integrator_LowerSat_boizxptfju ; } if ( ( rtDW . pxa1vgfiln == 3 ) || ( rtDW
. pxa1vgfiln == 4 ) ) { _rtZCSV -> pnuya4ge5o = rtB . jx22a2iggv ; } else {
_rtZCSV -> pnuya4ge5o = 0.0 ; } _rtZCSV -> kl0bottimb = rtB . e4g0rxt1yl -
rtP . VRmin_UpperSat_k0uoo5f5gu ; _rtZCSV -> h3e5cojcqq = rtB . e4g0rxt1yl -
rtP . VRmin_LowerSat_aseabweop3 ; _rtZCSV -> jxacyjfq4p = rtB . ehtl4hikfh -
rtP . HitCrossing_Offset ; _rtZCSV -> nmw0voae41 = rtB . d3d4jc4vne - rtP .
HitCrossing_Offset_byy35c2pe2 ; _rtZCSV -> nij3cfqygn = rtB . nvwpe0rwjl -
rtP . HitCrossing_Offset_ckyjwcjlvs ; _rtZCSV -> if5ci4lvbz = rtB .
brtuqherkv - rtP . HitCrossing_Offset_fvwyzrflnb ; } void MdlTerminate ( void
) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnTerminate ( rts ) ;
} rt_TDelayFreeBuf ( rtDW . d2mee5ywuy . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . iin0a1rkif . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . abwpuwwzkr . TUbufferPtrs [ 0 ] ) ; if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 69 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
4 ) ; ssSetNumBlocks ( rtS , 818 ) ; ssSetNumBlockIO ( rtS , 392 ) ;
ssSetNumBlockParams ( rtS , 9421 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 1.0 ) ; ssSetSampleTime ( rtS , 3 , 8.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 1074908781U ) ;
ssSetChecksumVal ( rtS , 1 , 319055505U ) ; ssSetChecksumVal ( rtS , 2 ,
3192287614U ) ; ssSetChecksumVal ( rtS , 3 , 1810229351U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 16 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
testingV10_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "testingV10" ) ;
ssSetPath ( rtS , "testingV10" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 80.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
{ static int_T rt_LoggedStateWidths [ ] = { 1 , 5 , 1 , 5 , 1 , 5 , 12 , 1 ,
1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ;
static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 }
; static int_T rt_LoggedStateDimensions [ ] = { 1 , 5 , 1 , 5 , 1 , 5 , 12 ,
1 , 1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 }
; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
} ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_UINT8 , SS_UINT8 , SS_UINT8 } ; static int_T rt_LoggedStateComplexSignals
[ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"testingV10/G3/SM\n3.125 MVA/Mechanical model/Rotor angle dtheta" ,
 "testingV10/G3/SM\n3.125 MVA/Electrical model/Synchronous Machine\nContinuous Model/phi/Integrator"
, "testingV10/G1/SM\n3.125 MVA/Mechanical model/Rotor angle dtheta" ,
 "testingV10/G1/SM\n3.125 MVA/Electrical model/Synchronous Machine\nContinuous Model/phi/Integrator"
, "testingV10/G2/SM\n3.125 MVA/Mechanical model/Rotor angle dtheta" ,
 "testingV10/G2/SM\n3.125 MVA/Electrical model/Synchronous Machine\nContinuous Model/phi/Integrator"
, "testingV10/powergui/EquivalentModel1/State-Space" ,
"testingV10/G1/SM\n3.125 MVA/Mechanical model/Rotor speed\ndeviation (dw)" ,
"testingV10/G1/EXCITATION/AC1A/AC1A/Model/Integrator" ,
"testingV10/G1/SM\n3.125 MVA/Mechanical model/theta" ,
"testingV10/G1/Diesel Engine Governor/CONTROL SYSTEM" ,
"testingV10/G1/Diesel Engine Governor/Integrator" ,
"testingV10/G1/Diesel Engine Governor/TF1" ,
"testingV10/G1/Diesel Engine Governor/TF2" ,
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Damping Filter\nKf.s//(Tf.s+1)/State Space"
, "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ,
 "testingV10/G1/EXCITATION/AC1A/AC1A/Model/Low Pass Filter\n1//(Tr.s+1)/State Space"
, "testingV10/G2/SM\n3.125 MVA/Mechanical model/Rotor speed\ndeviation (dw)"
, "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Integrator" ,
"testingV10/G2/SM\n3.125 MVA/Mechanical model/theta" ,
"testingV10/G2/Diesel Engine Governor/CONTROL SYSTEM" ,
"testingV10/G2/Diesel Engine Governor/Integrator" ,
"testingV10/G2/Diesel Engine Governor/TF1" ,
"testingV10/G2/Diesel Engine Governor/TF2" ,
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Damping Filter\nKf.s//(Tf.s+1)/State Space"
, "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ,
 "testingV10/G2/EXCITATION/AC1A/AC1A/Model/Low Pass Filter\n1//(Tr.s+1)/State Space"
, "testingV10/G3/SM\n3.125 MVA/Mechanical model/Rotor speed\ndeviation (dw)"
, "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Integrator" ,
"testingV10/G3/SM\n3.125 MVA/Mechanical model/theta" ,
"testingV10/G3/Diesel Engine Governor/CONTROL SYSTEM" ,
"testingV10/G3/Diesel Engine Governor/Integrator" ,
"testingV10/G3/Diesel Engine Governor/TF1" ,
"testingV10/G3/Diesel Engine Governor/TF2" ,
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Damping Filter\nKf.s//(Tf.s+1)/State Space"
, "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Vaminmax/Integrator" ,
 "testingV10/G3/EXCITATION/AC1A/AC1A/Model/Low Pass Filter\n1//(Tr.s+1)/State Space"
,
 "testingV10/G3/SM\n3.125 MVA/Electrical model/Synchronous Machine\nContinuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
,
 "testingV10/G3/SM\n3.125 MVA/Electrical model/Synchronous Machine\nContinuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
,
 "testingV10/G2/SM\n3.125 MVA/Electrical model/Synchronous Machine\nContinuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
,
 "testingV10/G2/SM\n3.125 MVA/Electrical model/Synchronous Machine\nContinuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
,
 "testingV10/G1/SM\n3.125 MVA/Electrical model/Synchronous Machine\nContinuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
,
 "testingV10/G1/SM\n3.125 MVA/Electrical model/Synchronous Machine\nContinuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
,
 "testingV10/Cooling System/Repeating\nSequence\nInterpolated8/LimitedCounter/Output"
,
 "testingV10/Cooling System/Repeating\nSequence\nInterpolated7/LimitedCounter/Output"
,
 "testingV10/Cooling System/Repeating\nSequence\nInterpolated6/LimitedCounter/Output"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "DSTATE" , "DSTATE" , "DSTATE" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
} ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_UINT8 , SS_UINT8 , 0 , 0 , 0 , 1.0 , 0 , 0.0
} , { 0 , SS_UINT8 , SS_UINT8 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_UINT8
, SS_UINT8 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 46 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 46 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . dxcqn52y0j ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . prvbwmxe5d [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . ftxl3ve1we ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . cqlekexsf4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . pbf0mwqvxu ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . ezu3nw0jme [ 0 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . mpaduaczra [ 0 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . ipldudc4jc ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . i5wyejvw00 ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . jzaacseaxt ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . ir2k1m2xef [ 0 ] ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . ccho5ckvhr ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . oq42ze3zlo ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . jlygjdr5nw ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . fo31vd32p4 ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . mir041liby ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . jz4lzneeo1 ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtX . ebee4njyij ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtX . i302uyv4ub ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtX . cvoatslkxn ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) & rtX . ozdje1tbeq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) & rtX . c3odb1pgdi ;
rt_LoggedStateSignalPtrs [ 22 ] = ( void * ) & rtX . dumyo0mi3u ;
rt_LoggedStateSignalPtrs [ 23 ] = ( void * ) & rtX . mjljeeps1u ;
rt_LoggedStateSignalPtrs [ 24 ] = ( void * ) & rtX . e32unymcc4 ;
rt_LoggedStateSignalPtrs [ 25 ] = ( void * ) & rtX . om4zueiy1s ;
rt_LoggedStateSignalPtrs [ 26 ] = ( void * ) & rtX . nafgdh5awp ;
rt_LoggedStateSignalPtrs [ 27 ] = ( void * ) & rtX . pvsfs5bviq ;
rt_LoggedStateSignalPtrs [ 28 ] = ( void * ) & rtX . oh1bpz4njz ;
rt_LoggedStateSignalPtrs [ 29 ] = ( void * ) & rtX . mtfzfgh35r ;
rt_LoggedStateSignalPtrs [ 30 ] = ( void * ) & rtX . kvt4cjhlrh [ 0 ] ;
rt_LoggedStateSignalPtrs [ 31 ] = ( void * ) & rtX . nk334zxlzp ;
rt_LoggedStateSignalPtrs [ 32 ] = ( void * ) & rtX . geip5cv4tr ;
rt_LoggedStateSignalPtrs [ 33 ] = ( void * ) & rtX . j51tfhhdgm ;
rt_LoggedStateSignalPtrs [ 34 ] = ( void * ) & rtX . icyr0u0hwc ;
rt_LoggedStateSignalPtrs [ 35 ] = ( void * ) & rtX . b0v4jzhvdz ;
rt_LoggedStateSignalPtrs [ 36 ] = ( void * ) & rtX . mia0akgecm ;
rt_LoggedStateSignalPtrs [ 37 ] = ( void * ) & rtX . cqi4cjmse0 . k0qcscyfkp
; rt_LoggedStateSignalPtrs [ 38 ] = ( void * ) & rtX . cqi4cjmse0 .
fj3dlbq3k3 ; rt_LoggedStateSignalPtrs [ 39 ] = ( void * ) & rtX . puvrgymrfw
. k0qcscyfkp ; rt_LoggedStateSignalPtrs [ 40 ] = ( void * ) & rtX .
puvrgymrfw . fj3dlbq3k3 ; rt_LoggedStateSignalPtrs [ 41 ] = ( void * ) & rtX
. gqdbtcmlhky . k0qcscyfkp ; rt_LoggedStateSignalPtrs [ 42 ] = ( void * ) &
rtX . gqdbtcmlhky . fj3dlbq3k3 ; rt_LoggedStateSignalPtrs [ 43 ] = ( void * )
& rtDW . nq0bdz3dwr ; rt_LoggedStateSignalPtrs [ 44 ] = ( void * ) & rtDW .
dntwmboj5l ; rt_LoggedStateSignalPtrs [ 45 ] = ( void * ) & rtDW . hdwuwozgch
; } rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static struct _ssSFcnModelMethods3 mdlMethods3
; static struct _ssSFcnModelMethods2 mdlMethods2 ; static boolean_T
contStatesDisabled [ 69 ] ; static real_T absTol [ 69 ] = { 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 69 ] = { 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U } ; static real_T contStateJacPerturbBoundMinVec [
69 ] ; static real_T contStateJacPerturbBoundMaxVec [ 69 ] ; static uint8_T
zcAttributes [ 62 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL
) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [ 6 ] = {
{ 1 * sizeof ( real_T ) , ( char * ) ( & rtB . j4zpdoh2yb ) , ( NULL ) } , {
1 * sizeof ( real_T ) , ( char * ) ( & rtB . i0iyh4zr0m ) , ( NULL ) } , { 1
* sizeof ( real_T ) , ( char * ) ( & rtB . brcsbdnmx5 ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . ipenwii4hv ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . cpqapklze4 ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . amufqu02uc ) , ( NULL ) } } ; { int
i ; for ( i = 0 ; i < 69 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0
; contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol
( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0
) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 )
; ssSetMaxStepSize ( rtS , 0.00555594138481839 ) ; ssSetSolverMaxOrder ( rtS
, - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , (
NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 )
; ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
6 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode23tb" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 1 ) ; (
void ) memset ( ( void * ) & mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ;
ssSetModelMethods2 ( rtS , & mdlMethods2 ) ; ( void ) memset ( ( void * ) &
mdlMethods3 , 0 , sizeof ( mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , &
mdlMethods3 ) ; ssSetModelProjection ( rtS , MdlProjection ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 62 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 62 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1074908781U ) ; ssSetChecksumVal ( rtS , 1 ,
319055505U ) ; ssSetChecksumVal ( rtS , 2 , 3192287614U ) ; ssSetChecksumVal
( rtS , 3 , 1810229351U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 31 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = ( sysRanDType * ) &
rtDW . fkvhgnbbpt ; systemRan [ 2 ] = ( sysRanDType * ) & rtDW . ewfusfxrh1 ;
systemRan [ 3 ] = ( sysRanDType * ) & rtDW . msqb4sdl5r ; systemRan [ 4 ] = (
sysRanDType * ) & rtDW . igmpp4jfdvg . pcotaqjtuk ; systemRan [ 5 ] = (
sysRanDType * ) & rtDW . attmdly3nwd . gxuxajwdt5 ; systemRan [ 6 ] = (
sysRanDType * ) & rtDW . e22kv3zqsq0 . g33nsvnzmn ; systemRan [ 7 ] = (
sysRanDType * ) & rtDW . mfbj0yzfuo4 . iywpiqxv2q ; systemRan [ 8 ] = (
sysRanDType * ) & rtDW . gqdbtcmlhky . ene3psc5eg ; systemRan [ 9 ] = (
sysRanDType * ) & rtDW . gqdbtcmlhky . lwv41vwpbg ; systemRan [ 10 ] = (
sysRanDType * ) & rtDW . gqdbtcmlhky . lwv41vwpbg ; systemRan [ 11 ] = (
sysRanDType * ) & rtDW . gqdbtcmlhky . ene3psc5eg ; systemRan [ 12 ] = (
sysRanDType * ) & rtDW . a1ytfvhs5e . pcotaqjtuk ; systemRan [ 13 ] = (
sysRanDType * ) & rtDW . dslix2t5ne . gxuxajwdt5 ; systemRan [ 14 ] = (
sysRanDType * ) & rtDW . clza3n5d4t . g33nsvnzmn ; systemRan [ 15 ] = (
sysRanDType * ) & rtDW . ghjqwoc3wx . iywpiqxv2q ; systemRan [ 16 ] = (
sysRanDType * ) & rtDW . puvrgymrfw . ene3psc5eg ; systemRan [ 17 ] = (
sysRanDType * ) & rtDW . puvrgymrfw . lwv41vwpbg ; systemRan [ 18 ] = (
sysRanDType * ) & rtDW . puvrgymrfw . lwv41vwpbg ; systemRan [ 19 ] = (
sysRanDType * ) & rtDW . puvrgymrfw . ene3psc5eg ; systemRan [ 20 ] = (
sysRanDType * ) & rtDW . b0yuwkfotx . pcotaqjtuk ; systemRan [ 21 ] = (
sysRanDType * ) & rtDW . plxey5q4z3 . gxuxajwdt5 ; systemRan [ 22 ] = (
sysRanDType * ) & rtDW . a12lwium4g . g33nsvnzmn ; systemRan [ 23 ] = (
sysRanDType * ) & rtDW . ecdtivcszk . iywpiqxv2q ; systemRan [ 24 ] = (
sysRanDType * ) & rtDW . cqi4cjmse0 . ene3psc5eg ; systemRan [ 25 ] = (
sysRanDType * ) & rtDW . cqi4cjmse0 . lwv41vwpbg ; systemRan [ 26 ] = (
sysRanDType * ) & rtDW . cqi4cjmse0 . lwv41vwpbg ; systemRan [ 27 ] = (
sysRanDType * ) & rtDW . cqi4cjmse0 . ene3psc5eg ; systemRan [ 28 ] = &
rtAlwaysEnabled ; systemRan [ 29 ] = & rtAlwaysEnabled ; systemRan [ 30 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } rtP . Integrator_UpperSat = rtInf ; rtP .
Integrator_UpperSat_emevdxcfrg = rtInf ; rtP . Integrator_UpperSat_m3couvae5u
= rtInf ; ssSetNumSFunctions ( rtS , 1 ) ; { static SimStruct childSFunctions
[ 1 ] ; static SimStruct * childSFunctionPtrs [ 1 ] ; ( void ) memset ( (
void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions ) ) ;
ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction ( rtS ,
0 , & childSFunctions [ 0 ] ) ; { SimStruct * rts = ssGetSFunction ( rtS , 0
) ; static time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static
int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof
( time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof (
time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; { static struct _ssBlkInfo2 _blkInfo2 ; struct
_ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ;
} { static struct _ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 =
& _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; }
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ; static
ssJacobianPerturbationBounds jacPerturbationBounds ; ssSetStatesInfo2 ( rts ,
& statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ;
ssSetAbsTolVector ( rts , ssGetAbsTolVector ( rtS ) + 18 ) ;
ssSetAbsTolControlVector ( rts , ssGetAbsTolControlVector ( rtS ) + 18 ) ; }
{ static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts
, 2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 9 ] ; sfcnUPtrs [ 0 ] = & rtB . mhvoaxr3ny [ 0 ] ;
sfcnUPtrs [ 1 ] = & rtB . mhvoaxr3ny [ 1 ] ; sfcnUPtrs [ 2 ] = & rtB .
oyz4fl5tkc [ 0 ] ; sfcnUPtrs [ 3 ] = & rtB . oyz4fl5tkc [ 1 ] ; sfcnUPtrs [ 4
] = & rtB . h2jybzg354 [ 0 ] ; sfcnUPtrs [ 5 ] = & rtB . h2jybzg354 [ 1 ] ;
sfcnUPtrs [ 6 ] = & rtB . d5bucyfqa0 ; sfcnUPtrs [ 7 ] = & rtB . icdvip4qf2 ;
sfcnUPtrs [ 8 ] = & rtB . ltfwzxychx ; ssSetInputPortSignalPtrs ( rts , 0 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0
, 1 ) ; ssSetInputPortWidth ( rts , 0 , 9 ) ; } { static real_T const *
sfcnUPtrs [ 3 ] ; sfcnUPtrs [ 0 ] = & rtB . bt3z4wm1qx ; sfcnUPtrs [ 1 ] = &
rtB . l3hudrc3jb ; sfcnUPtrs [ 2 ] = & rtB . gm2c3kojd1 ;
ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 1 , 1 ) ; ssSetInputPortWidth ( rts , 1
, 3 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 2 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 2 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 2 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortUnit ( rts , 1 , 0 ) ; { static struct
_ssOutPortCoSimAttribute outputPortCoSimAttribute [ 2 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 1 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 30 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB . bx1vifjqa5
) ) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetOutputPortWidth ( rts , 1 , 6 ) ; ssSetOutputPortSignal ( rts , 1 , ( (
real_T * ) rtB . jaedqymkno ) ) ; } } ssSetContStates ( rts , & rtX .
mpaduaczra [ 0 ] ) ; ssSetContStateDisabled ( rts , & ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> mpaduaczra [ 0 ] ) ; { real_T * minVec =
& ( ( CXPtMin * ) ssGetJacobianPerturbationBoundsMinVec ( rtS ) ) ->
mpaduaczra [ 0 ] ; real_T * maxVec = & ( ( CXPtMax * )
ssGetJacobianPerturbationBoundsMaxVec ( rtS ) ) -> mpaduaczra [ 0 ] ;
ssSetJacobianPerturbationBoundsMinVec ( rts , minVec ) ;
ssSetJacobianPerturbationBoundsMaxVec ( rts , maxVec ) ; } ssSetModelName (
rts , "State-Space" ) ; ssSetPath ( rts ,
"testingV10/powergui/EquivalentModel1/State-Space" ) ; if ( ssGetRTModel (
rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts ,
ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) )
; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; }
ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray *
sfcnParams [ 10 ] ; ssSetSFcnParamsCount ( rts , 10 ) ; ssSetSFcnParamsPtr (
rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
StateSpace_P1_Size ) ; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP .
StateSpace_P2_Size ) ; ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP .
StateSpace_P3_Size ) ; ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP .
StateSpace_P4_Size ) ; ssSetSFcnParam ( rts , 4 , ( mxArray * ) rtP .
StateSpace_P5_Size ) ; ssSetSFcnParam ( rts , 5 , ( mxArray * ) rtP .
StateSpace_P6_Size ) ; ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP .
StateSpace_P7_Size ) ; ssSetSFcnParam ( rts , 7 , ( mxArray * ) rtP .
StateSpace_P8_Size ) ; ssSetSFcnParam ( rts , 8 , ( mxArray * ) rtP .
StateSpace_P9_Size ) ; ssSetSFcnParam ( rts , 9 , ( mxArray * ) rtP .
StateSpace_P10_Size ) ; } ssSetRWork ( rts , ( real_T * ) & rtDW . hxehg13vgz
[ 0 ] ) ; ssSetIWork ( rts , ( int_T * ) & rtDW . gin5y5hus0 [ 0 ] ) ;
ssSetPWork ( rts , ( void * * ) & rtDW . djqjasg2hy [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 4 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 4 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 4 ) ;
ssSetDWorkWidth ( rts , 0 , 4 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
lt4gmic1yi [ 0 ] ) ; ssSetDWorkWidth ( rts , 1 , 2 ) ; ssSetDWorkDataType (
rts , 1 , SS_DOUBLE ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork
( rts , 1 , & rtDW . hxehg13vgz [ 0 ] ) ; ssSetDWorkWidth ( rts , 2 , 23 ) ;
ssSetDWorkDataType ( rts , 2 , SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . gin5y5hus0 [ 0 ] ) ;
ssSetDWorkWidth ( rts , 3 , 22 ) ; ssSetDWorkDataType ( rts , 3 , SS_POINTER
) ; ssSetDWorkComplexSignal ( rts , 3 , 0 ) ; ssSetDWork ( rts , 3 , & rtDW .
djqjasg2hy [ 0 ] ) ; } ssSetModeVector ( rts , ( int_T * ) & rtDW .
lt4gmic1yi [ 0 ] ) ; sfun_spid_contc ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 4 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetInputPortConnected ( rts , 1 , 1 ) ; _ssSetOutputPortConnected ( rts
, 0 , 1 ) ; _ssSetOutputPortConnected ( rts , 1 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 1 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 4 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID4 ( tid ) ; }
