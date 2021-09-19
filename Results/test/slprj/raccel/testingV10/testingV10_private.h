#ifndef RTW_HEADER_testingV10_private_h_
#define RTW_HEADER_testingV10_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "testingV10.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
extern void rt_invd5x5_snf ( const real_T u [ 25 ] , real_T y [ 25 ] ) ; void
* rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) ;
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) ; real_T rt_TDelayInterpolate (
real_T tMinusDelay , real_T tStart , real_T * tBuf , real_T * uBuf , int_T
bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput
, boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput ) ; extern
real_T look1_pbinlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table
[ ] , uint32_T prevIndex [ ] , uint32_T maxIndex ) ; extern real_T
look1_binlcpw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T maxIndex ) ; extern real_T look1_binlxpw ( real_T u0 , const real_T
bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) ; extern void
sfun_spid_contc ( SimStruct * rts ) ; void rt_TDelayFreeBuf ( void * buf ) ;
extern void mbwj5xxyv5 ( SimStruct * rtS_e ) ; extern void julesvnt2d (
SimStruct * rtS_p ) ; extern void attmdly3nw ( SimStruct * rtS_i , real_T
ayyzh10w3r , real_T * j0u5w4s5kd , d2o1h43yf5 * localP ) ; extern void
cmjweld2k1 ( SimStruct * rtS_i ) ; extern void ab0lumfo3e ( SimStruct * rtS_m
) ; extern void igmpp4jfdv ( SimStruct * rtS_e , real_T nozwu1f12r , real_T *
jkusnymiui , acuaihhzpu * localP ) ; extern void a5me1li4az ( SimStruct *
rtS_p ) ; extern void fwicy1bcaz ( SimStruct * rtS_g ) ; extern void
e22kv3zqsq ( SimStruct * rtS_j , real_T gp5wlbp5k2 , real_T * d4vsegz52q ,
bek1yqg5mv * localP ) ; extern void doisemfibt ( SimStruct * rtS_m ) ; extern
void j34hurn5mj ( SimStruct * rtS_f ) ; extern void mfbj0yzfuo ( SimStruct *
rtS_c , real_T * biep1lmlsg , ozd4wyfuvi * localP ) ; extern void f3adcfr20z
( hy4g22ft5l * localB , chh2ehjaxn * localP , pb1p3lro1p * localX ) ; extern
void mner3hbxuo ( SimStruct * rtS_k , ixnicbdqnf * localDW , p4cqd5zcze *
localXdis ) ; extern void gh4mkhetsb ( hy4g22ft5l * localB , ixnicbdqnf *
localDW , gawmg1mpfd * localXdot ) ; extern void nlzkrjo2aq ( hy4g22ft5l *
localB , ixnicbdqnf * localDW , j4bdse2byj * localZCSV ) ; extern void
gz4umw2aaz ( ixnicbdqnf * localDW ) ; extern void gqdbtcmlhk ( SimStruct *
rtS_b , real_T ihtr2n3nur , const real_T brkujkabcz [ 5 ] , hy4g22ft5l *
localB , ixnicbdqnf * localDW , chh2ehjaxn * localP , pb1p3lro1p * localX ,
p4cqd5zcze * localXdis ) ; extern void gqdbtcmlhkTID4 ( SimStruct * rtS_p ,
ixnicbdqnf * localDW ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
