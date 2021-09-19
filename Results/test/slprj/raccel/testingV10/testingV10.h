#ifndef RTW_HEADER_testingV10_h_
#define RTW_HEADER_testingV10_h_
#include <string.h>
#include <stddef.h>
#include <float.h>
#include "rtw_modelmap.h"
#ifndef testingV10_COMMON_INCLUDES_
#define testingV10_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "testingV10_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_look.h"
#include "rt_look1d.h"
#include "rt_defines.h"
#define MODEL_NAME testingV10
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (392) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (69)   
#elif NCSTATES != 69
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { int8_T gxuxajwdt5 ; } m2bcghii1o ; typedef struct { int8_T
pcotaqjtuk ; int8_T fgld1mwkwa ; } pjgrzvh3wj ; typedef struct { int8_T
g33nsvnzmn ; } nrlcotdpo5 ; typedef struct { int8_T iywpiqxv2q ; } ksis4l2ker
; typedef struct { real_T lzzeeexge0 [ 3 ] ; real_T iwuvpqmdqd ; real_T
m0j312cexm ; real_T dgj2vlo3ae ; real_T dknardu53j ; real_T bqfae1z4xm ;
real_T kkho4m250n ; real_T ebabsrxrur ; real_T iytz0y3ucg ; real_T k33sqomjhg
; real_T jtahvktmal ; real_T okkine1bpp ; real_T kguc1xjgtq ; real_T
e4eaoc3n4j [ 25 ] ; real_T dos2ao4wzk [ 25 ] ; real_T akb1ib2amz [ 25 ] ;
real_T anumpx44cp [ 25 ] ; real_T nyt32tufuy [ 25 ] ; real_T fbja1wrd5n ;
real_T hcoloefwbj [ 2 ] ; real_T igfp3wt3zj ; real_T kdysf2sgiq ; real_T
hyzrfwdn0b ; real_T b3l11gphfb ; real_T ahmbzjodez ; real_T f2a01aevzv ;
real_T ifyloqp5tf ; real_T ihs5uzpoqs ; real_T privppgr4h ; real_T i2v1etu5n3
; real_T oelb25yqch ; real_T j5vjugftgu ; real_T mc0nzpa2g2 ; } hy4g22ft5l ;
typedef struct { real_T mumkhlfn5t [ 25 ] ; uint32_T izbjd0yomk ; uint32_T
pjr2nuseh4 ; int_T fov0xqpu0p ; int_T mw1c4diklt ; int8_T ene3psc5eg ; int8_T
lwv41vwpbg ; boolean_T jmnuu5fkfj ; boolean_T itnod251z1 ; boolean_T
d4fx2pljzn ; boolean_T axnuixsnfy ; } ixnicbdqnf ; typedef struct { real_T
k0qcscyfkp ; real_T fj3dlbq3k3 ; } pb1p3lro1p ; typedef struct { real_T
k0qcscyfkp ; real_T fj3dlbq3k3 ; } gawmg1mpfd ; typedef struct { boolean_T
k0qcscyfkp ; boolean_T fj3dlbq3k3 ; } p4cqd5zcze ; typedef struct { real_T
k0qcscyfkp ; real_T fj3dlbq3k3 ; } hnafmcf0qr ; typedef struct { real_T
k0qcscyfkp ; real_T fj3dlbq3k3 ; } ose1v24qd2 ; typedef struct { real_T
k0qcscyfkp ; real_T fj3dlbq3k3 ; } hfpxnwfvdd ; typedef struct { real_T
nazqzeqojt ; real_T cq0bpaoclk ; real_T lbgqimsikx ; real_T i5mzhw5zf3 ; }
j4bdse2byj ; typedef struct { real_T pgprp2j0mg ; real_T kckr1rsmi3 ; real_T
owqdlcfz5i ; real_T j2hq00la3s [ 5 ] ; real_T kxg24koyh2 [ 25 ] ; real_T
p2ppvvojae [ 5 ] ; real_T dk1omp4wet [ 5 ] ; real_T pq54vjdlkq ; real_T
mhvoaxr3ny [ 3 ] ; real_T dymy5fczgx ; real_T ndv1chiwse ; real_T danklhdtjg
; real_T nyuxeims25 [ 5 ] ; real_T my41lqaa3e [ 25 ] ; real_T axuxlimqfo [ 5
] ; real_T d51r4ddhlp [ 5 ] ; real_T mhlj2wouuq ; real_T oyz4fl5tkc [ 3 ] ;
real_T cqvzl34lfs ; real_T ds252cwh3s ; real_T jrbkd00tcm ; real_T p2ubfcpe4u
[ 5 ] ; real_T jt2zr3xuyu [ 25 ] ; real_T i3xfrtnhpx [ 5 ] ; real_T
ivbwlhlxla [ 5 ] ; real_T ncljwqtey4 ; real_T h2jybzg354 [ 3 ] ; real_T
d5bucyfqa0 ; real_T icdvip4qf2 ; real_T ltfwzxychx ; real_T bx1vifjqa5 [ 30 ]
; real_T jaedqymkno [ 6 ] ; real_T byg1ydrnj5 ; real_T ebqjy0h1vz ; real_T
fhocpb4rlk ; real_T ogontexkwa ; real_T bzmzsahkz0 ; real_T bqh4htctpf ;
real_T npdbafvddp ; real_T lnfeerzdwl [ 2 ] ; real_T ll5lhtaahm [ 2 ] ;
real_T omolj25xda [ 2 ] ; real_T e3cyuxmtad ; real_T n5u3z30051 [ 3 ] ;
real_T h0135r1dh0 [ 3 ] ; real_T hn1104ars0 ; real_T fbmjaug21p [ 2 ] ;
real_T ml5evcnodk [ 2 ] ; real_T ifzgu2ee1l ; real_T m5o0jbgvyx ; real_T
pizp5zm00a ; real_T nhjs51s1ph ; real_T kql5exxrek ; real_T od1v53lcod ;
real_T iucqalgajz ; real_T pfuip4apkg ; real_T oeedo4set2 ; real_T axj0g1at3l
[ 18 ] ; real_T eiwmp0uix0 ; real_T amufqu02uc ; real_T hvcpcic14r ; real_T
npq14v1sxw ; real_T e02gvifuul ; real_T pkqtmwmhph ; real_T cpqapklze4 ;
real_T mtaotlu3kj [ 2 ] ; real_T iodshzwwqj [ 2 ] ; real_T d2i2d0pjwa ;
real_T k3g1mw2mb1 ; real_T ms5yftyqp5 ; real_T icpch50dox ; real_T ou5as25oqf
; real_T ckbwyd51fw ; real_T g3tr54e0gh ; real_T ajb0jd1wax ; real_T
lmjgudxydq ; real_T mgwenfy132 ; real_T edtnmnr3vm ; real_T kb4mvzq0n3 ;
real_T i45iq1kx0r ; real_T p4byd4k51j ; real_T gz2qcnyb1c ; real_T d3prvaxezv
; real_T emn13j4iq4 ; real_T k2ed141a0b ; real_T l5tveyumnb ; real_T
fsbjhr5dz0 ; real_T asp4dkpswc ; real_T b1zkykkz5k ; real_T fg4jwggqvs ;
real_T di4ji05v0o ; real_T my43lbhgf2 ; real_T pm0bgbsy3o ; real_T kkwarc0rc1
; real_T bwynwxckua ; real_T lh3hq5cwil ; real_T k2cexfls20 [ 25 ] ; real_T
lo2ggdoibh [ 25 ] ; real_T oydhroyllb [ 25 ] ; real_T bzuabr4dvk [ 25 ] ;
real_T muljazi4vt [ 25 ] ; real_T haa5p2ptdq [ 5 ] ; real_T gtamjmvbh0 [ 5 ]
; real_T grwocktd5q [ 5 ] ; real_T ljw0dnybdy ; real_T ay3br3a3hq ; real_T
pqzx0wtulf ; real_T ol0nkdk5rw ; real_T brvzzfgdkk ; real_T ljxtwfbyom ;
real_T jbq05nhwpa ; real_T npvosve4cu ; real_T lcbyglc5pf ; real_T jbvbomnw2p
; real_T p0ztjxbfsc ; real_T leh2oxynn2 ; real_T e3mykpbvxu ; real_T
cbo535uscm [ 2 ] ; real_T nwlcni0prp [ 2 ] ; real_T ezhs2i41dg [ 2 ] ; real_T
k1bgn3kbs2 ; real_T gwqqhvgmz0 [ 3 ] ; real_T mrhppm5nnj [ 3 ] ; real_T
effezdjmri ; real_T n34rsgjlm4 [ 2 ] ; real_T keaofkpcfk [ 2 ] ; real_T
ibx54rryug ; real_T b3cqfd55dr ; real_T cbome3ugdq ; real_T hjjlvvkayj ;
real_T meaoaylidx ; real_T aacdpemjnp ; real_T jtkc3lsddk ; real_T o03eqw4qg4
; real_T hnovtssll3 ; real_T fsskatoni2 [ 18 ] ; real_T lds45me1tz ; real_T
ipenwii4hv ; real_T eeez5exivc ; real_T f1xtfhhhqv ; real_T oftl5xnv1o ;
real_T brcsbdnmx5 ; real_T ksrhlo5pxw [ 2 ] ; real_T bqhwxr5qcc [ 2 ] ;
real_T i025vm1xpp ; real_T kquxrsdq3f ; real_T muz5hrtqty ; real_T ialymydhnj
; real_T m1ycajq1qq ; real_T pucoihkeei ; real_T lrb3pzyxyo ; real_T
is1htqzogm ; real_T dg5y4n2fx5 ; real_T kdezj5zhgl ; real_T k5vss3m212 ;
real_T fxujfy1naf ; real_T bltflfqi2c ; real_T lmqrmcycfr ; real_T d54dp4nzot
; real_T jgmqqelntj ; real_T nqfjt0wu52 ; real_T bbuesupjvr ; real_T
in55bj1rrn ; real_T lfna3t2vnq ; real_T czljrbrypr ; real_T olxkln2vrn ;
real_T n5pczeolzc ; real_T pd4pkxomth ; real_T bfl0othxdw ; real_T geqf1klp5b
; real_T k0htkyngm1 ; real_T juqlwmzilg ; real_T cl2yrd4l20 ; real_T
cx2nl0uoty [ 25 ] ; real_T ojbcjx0grt [ 25 ] ; real_T okrtsi5dua [ 25 ] ;
real_T liak5gzlbs [ 25 ] ; real_T kj5c5ay2lr [ 25 ] ; real_T nthau0fysn [ 5 ]
; real_T mh1p4xc2nf [ 5 ] ; real_T aaxc40oml0 [ 5 ] ; real_T izbaih23wf ;
real_T nm1zt5o0wf ; real_T fpw2bhibof ; real_T dg4rfafxi2 ; real_T fr3yekodlk
; real_T feadnsrfon ; real_T cjhy3wufru ; real_T gz4h1n4arf ; real_T
mjcpwqdoim ; real_T lpzstbvwnw ; real_T kosf4p4xvo ; real_T dddvo3hq1e ;
real_T eilem0zhx5 ; real_T e2xvdcfwjv [ 2 ] ; real_T hyw4ezm3jt [ 2 ] ;
real_T nkurjvw04v [ 2 ] ; real_T dddbntcjoq ; real_T b3aww42o13 [ 3 ] ;
real_T nqquna1krn [ 3 ] ; real_T f0m4fsml1k ; real_T p2gohtwhoy [ 2 ] ;
real_T echinzwblw [ 2 ] ; real_T ora01btyv5 ; real_T m1pbevt2be ; real_T
jvrusqmyep ; real_T bzvubtagmj ; real_T hyvvo1s5f2 ; real_T hz5ux0snkr ;
real_T faanufcllo ; real_T inwdxaza5z ; real_T a0qycmun3l ; real_T hxglkl2bua
[ 18 ] ; real_T jsjdhroynv ; real_T i0iyh4zr0m ; real_T kxi0hiouf4 ; real_T
eyy42dwotr ; real_T izwovv53aq ; real_T j4zpdoh2yb ; real_T kgd55h5ywl [ 2 ]
; real_T ilnl1lw0qf [ 2 ] ; real_T om3gsb2wta ; real_T hbasv1e1li ; real_T
gveciz5cnx ; real_T l5jnvhxa3g ; real_T mjgxqzxhn4 ; real_T gecgjcwxl2 ;
real_T nwxyngwvoo ; real_T hwewg0ullm ; real_T prgl4v4rcs ; real_T h2f5ohv0un
; real_T kfay54rwhc ; real_T l4qzjl15fy ; real_T lnyirkbasi ; real_T
evrpjg415a ; real_T fyneqtq03a ; real_T o5yahrnyq3 ; real_T dphvgbxieu ;
real_T e4g0rxt1yl ; real_T i2y4p2vw1k ; real_T imbchlh21y ; real_T o2yzakmz1p
; real_T biqautq04w ; real_T f4wm3ijjcw ; real_T pyb5nlfcal ; real_T
fv5a4vo3xg ; real_T kjdjn4pvtg ; real_T jx22a2iggv ; real_T cgkgxwy5lm ;
real_T d2o4vcwr4t ; real_T g4jauwnx0y [ 25 ] ; real_T j1s3mphmsm [ 25 ] ;
real_T j21pixwogm [ 25 ] ; real_T btni35uwov [ 25 ] ; real_T pszjudozhd [ 25
] ; real_T dfgsexyfsz [ 5 ] ; real_T ikmi0yu0r4 [ 5 ] ; real_T djoydjgvbg [ 5
] ; real_T e4dpd1hqdn ; real_T k43sb00nmf ; real_T gewuongkab ; real_T
iwhl53vsbp ; real_T n0ctdpimv4 ; real_T nvzgkwwurg ; real_T pkizjdds0x ;
real_T aipd2mmrrr ; real_T e2b1dnuz0z ; real_T bt3z4wm1qx ; real_T ehtl4hikfh
; real_T e4wb3lihdw ; real_T l3hudrc3jb ; real_T d3d4jc4vne ; real_T
h4uex5jljn ; real_T gm2c3kojd1 ; real_T nvwpe0rwjl ; real_T brtuqherkv ;
real_T a30jmyeur3 ; real_T hghs1t20yw ; real_T mwbvfjvdmp ; real_T kkekcv3h3x
; real_T lau2uwvqvd ; real_T phjkba00rh ; real_T bgdmyntavi ; real_T
m3mvlja3vc ; real_T enckxhfxqr ; real_T aex4uyx51s ; real_T h20osj2hz4 ;
real_T npyj2l24ut ; real_T opow2w1mi1 ; real_T obphrpkole ; uint8_T
egynfvvlbk ; uint8_T ng0qeau1ay ; uint8_T onvs14ppyq ; hy4g22ft5l cqi4cjmse0
; hy4g22ft5l puvrgymrfw ; hy4g22ft5l gqdbtcmlhky ; } B ; typedef struct {
real_T k2gqgbs5d5 ; real_T hgooub1kfm ; real_T mgitsq1y4c ; real_T ielhf2atex
; real_T kydy0dzs4q ; real_T gpk14zbdx0 ; real_T ix3txx30gm ; real_T
l1uw3rg2qt ; real_T dfk5fcernw ; real_T isywftekv1 ; real_T excno4hjxp ;
real_T ndirfsq4jw ; real_T g0ztsagyor ; real_T hs0fo3ig54 ; real_T fetl5keei4
; real_T nnbixcnsch ; real_T hxehg13vgz [ 2 ] ; struct { real_T modelTStart ;
} ebpysqsn1p ; struct { real_T modelTStart ; } m2ylv2bbdq ; struct { real_T
modelTStart ; } cgj0l4draf ; void * djqjasg2hy [ 22 ] ; struct { void *
TUbufferPtrs [ 2 ] ; } d2mee5ywuy ; struct { void * LoggedData [ 4 ] ; }
p5myg52kno ; struct { void * LoggedData ; } jz4kl3b5de ; struct { void *
LoggedData ; } f3eew54hdp ; struct { void * TUbufferPtrs [ 2 ] ; } iin0a1rkif
; struct { void * LoggedData [ 4 ] ; } nexa0bypqj ; struct { void *
LoggedData ; } jkc3atrn5g ; struct { void * LoggedData ; } c4ip3dhgfo ;
struct { void * TUbufferPtrs [ 2 ] ; } abwpuwwzkr ; struct { void *
LoggedData [ 4 ] ; } hwllhaxhhg ; struct { void * LoggedData ; } h20zxkx5y4 ;
struct { void * LoggedData ; } erml0wxts0 ; struct { void * LoggedData ; }
jw5zam5ccx ; struct { void * LoggedData ; } jgfimpkz4x ; struct { void *
LoggedData ; } lymshr3z02 ; struct { void * LoggedData ; } kxrtcslzga ;
struct { void * LoggedData ; } pzyk012qsb ; struct { void * LoggedData ; }
kp2yrujgqn ; struct { void * LoggedData ; } pmpnlcxj2r ; struct { void *
LoggedData ; } od4jipp1us ; int_T gin5y5hus0 [ 23 ] ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
pom54x2oll ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } g35ini334z ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
aexlfdwpio ; int_T lt4gmic1yi [ 4 ] ; int_T dxzyqf5nmc ; int_T kds0u3jlha ;
int_T ktwxy2gk4t ; int_T g4jaeoabjw ; int_T da1gnnba33 ; int_T kb03ykgabx ;
int_T phi4pfmr53 ; int_T fiaucjz2wl ; int_T nopy54tklg ; int_T kpe5ac43ty ;
int_T pxa1vgfiln ; int_T nazzdgbbki ; uint8_T nq0bdz3dwr ; uint8_T dntwmboj5l
; uint8_T hdwuwozgch ; int8_T hinb1ade0f ; int8_T lzjsd04kej ; int8_T
hz40ksez24 ; int8_T a20bqbbboc ; int8_T ajv3iwzytl ; int8_T jdvbg1vzm5 ;
int8_T msqb4sdl5r ; int8_T ewfusfxrh1 ; int8_T fkvhgnbbpt ; boolean_T
c10lhed5jx ; boolean_T jyij4nxr4z ; boolean_T ohi2tzs1ww ; boolean_T
dpd2hvdwgh ; boolean_T ayvci0hmjr ; boolean_T pzm1pkcrzf ; boolean_T
gqcabwkprt ; boolean_T bbl2l4op42 ; boolean_T mo2lkhaep1 ; ixnicbdqnf
cqi4cjmse0 ; ksis4l2ker ecdtivcszk ; nrlcotdpo5 a12lwium4g ; pjgrzvh3wj
b0yuwkfotx ; m2bcghii1o plxey5q4z3 ; ixnicbdqnf puvrgymrfw ; ksis4l2ker
ghjqwoc3wx ; nrlcotdpo5 clza3n5d4t ; pjgrzvh3wj a1ytfvhs5e ; m2bcghii1o
dslix2t5ne ; ixnicbdqnf gqdbtcmlhky ; ksis4l2ker mfbj0yzfuo4 ; nrlcotdpo5
e22kv3zqsq0 ; pjgrzvh3wj igmpp4jfdvg ; m2bcghii1o attmdly3nwd ; } DW ;
typedef struct { real_T dxcqn52y0j ; real_T prvbwmxe5d [ 5 ] ; real_T
ftxl3ve1we ; real_T cqlekexsf4 [ 5 ] ; real_T pbf0mwqvxu ; real_T ezu3nw0jme
[ 5 ] ; real_T mpaduaczra [ 12 ] ; real_T ipldudc4jc ; real_T i5wyejvw00 ;
real_T jzaacseaxt ; real_T ir2k1m2xef [ 2 ] ; real_T ccho5ckvhr ; real_T
oq42ze3zlo ; real_T jlygjdr5nw ; real_T fo31vd32p4 ; real_T mir041liby ;
real_T jz4lzneeo1 ; real_T ebee4njyij ; real_T i302uyv4ub ; real_T cvoatslkxn
; real_T ozdje1tbeq [ 2 ] ; real_T c3odb1pgdi ; real_T dumyo0mi3u ; real_T
mjljeeps1u ; real_T e32unymcc4 ; real_T om4zueiy1s ; real_T nafgdh5awp ;
real_T pvsfs5bviq ; real_T oh1bpz4njz ; real_T mtfzfgh35r ; real_T kvt4cjhlrh
[ 2 ] ; real_T nk334zxlzp ; real_T geip5cv4tr ; real_T j51tfhhdgm ; real_T
icyr0u0hwc ; real_T b0v4jzhvdz ; real_T mia0akgecm ; pb1p3lro1p cqi4cjmse0 ;
pb1p3lro1p puvrgymrfw ; pb1p3lro1p gqdbtcmlhky ; } X ; typedef struct {
real_T dxcqn52y0j ; real_T prvbwmxe5d [ 5 ] ; real_T ftxl3ve1we ; real_T
cqlekexsf4 [ 5 ] ; real_T pbf0mwqvxu ; real_T ezu3nw0jme [ 5 ] ; real_T
mpaduaczra [ 12 ] ; real_T ipldudc4jc ; real_T i5wyejvw00 ; real_T jzaacseaxt
; real_T ir2k1m2xef [ 2 ] ; real_T ccho5ckvhr ; real_T oq42ze3zlo ; real_T
jlygjdr5nw ; real_T fo31vd32p4 ; real_T mir041liby ; real_T jz4lzneeo1 ;
real_T ebee4njyij ; real_T i302uyv4ub ; real_T cvoatslkxn ; real_T ozdje1tbeq
[ 2 ] ; real_T c3odb1pgdi ; real_T dumyo0mi3u ; real_T mjljeeps1u ; real_T
e32unymcc4 ; real_T om4zueiy1s ; real_T nafgdh5awp ; real_T pvsfs5bviq ;
real_T oh1bpz4njz ; real_T mtfzfgh35r ; real_T kvt4cjhlrh [ 2 ] ; real_T
nk334zxlzp ; real_T geip5cv4tr ; real_T j51tfhhdgm ; real_T icyr0u0hwc ;
real_T b0v4jzhvdz ; real_T mia0akgecm ; gawmg1mpfd cqi4cjmse0 ; gawmg1mpfd
puvrgymrfw ; gawmg1mpfd gqdbtcmlhky ; } XDot ; typedef struct { boolean_T
dxcqn52y0j ; boolean_T prvbwmxe5d [ 5 ] ; boolean_T ftxl3ve1we ; boolean_T
cqlekexsf4 [ 5 ] ; boolean_T pbf0mwqvxu ; boolean_T ezu3nw0jme [ 5 ] ;
boolean_T mpaduaczra [ 12 ] ; boolean_T ipldudc4jc ; boolean_T i5wyejvw00 ;
boolean_T jzaacseaxt ; boolean_T ir2k1m2xef [ 2 ] ; boolean_T ccho5ckvhr ;
boolean_T oq42ze3zlo ; boolean_T jlygjdr5nw ; boolean_T fo31vd32p4 ;
boolean_T mir041liby ; boolean_T jz4lzneeo1 ; boolean_T ebee4njyij ;
boolean_T i302uyv4ub ; boolean_T cvoatslkxn ; boolean_T ozdje1tbeq [ 2 ] ;
boolean_T c3odb1pgdi ; boolean_T dumyo0mi3u ; boolean_T mjljeeps1u ;
boolean_T e32unymcc4 ; boolean_T om4zueiy1s ; boolean_T nafgdh5awp ;
boolean_T pvsfs5bviq ; boolean_T oh1bpz4njz ; boolean_T mtfzfgh35r ;
boolean_T kvt4cjhlrh [ 2 ] ; boolean_T nk334zxlzp ; boolean_T geip5cv4tr ;
boolean_T j51tfhhdgm ; boolean_T icyr0u0hwc ; boolean_T b0v4jzhvdz ;
boolean_T mia0akgecm ; p4cqd5zcze cqi4cjmse0 ; p4cqd5zcze puvrgymrfw ;
p4cqd5zcze gqdbtcmlhky ; } XDis ; typedef struct { real_T dxcqn52y0j ; real_T
prvbwmxe5d [ 5 ] ; real_T ftxl3ve1we ; real_T cqlekexsf4 [ 5 ] ; real_T
pbf0mwqvxu ; real_T ezu3nw0jme [ 5 ] ; real_T mpaduaczra [ 12 ] ; real_T
ipldudc4jc ; real_T i5wyejvw00 ; real_T jzaacseaxt ; real_T ir2k1m2xef [ 2 ]
; real_T ccho5ckvhr ; real_T oq42ze3zlo ; real_T jlygjdr5nw ; real_T
fo31vd32p4 ; real_T mir041liby ; real_T jz4lzneeo1 ; real_T ebee4njyij ;
real_T i302uyv4ub ; real_T cvoatslkxn ; real_T ozdje1tbeq [ 2 ] ; real_T
c3odb1pgdi ; real_T dumyo0mi3u ; real_T mjljeeps1u ; real_T e32unymcc4 ;
real_T om4zueiy1s ; real_T nafgdh5awp ; real_T pvsfs5bviq ; real_T oh1bpz4njz
; real_T mtfzfgh35r ; real_T kvt4cjhlrh [ 2 ] ; real_T nk334zxlzp ; real_T
geip5cv4tr ; real_T j51tfhhdgm ; real_T icyr0u0hwc ; real_T b0v4jzhvdz ;
real_T mia0akgecm ; hnafmcf0qr cqi4cjmse0 ; hnafmcf0qr puvrgymrfw ;
hnafmcf0qr gqdbtcmlhky ; } CStateAbsTol ; typedef struct { real_T dxcqn52y0j
; real_T prvbwmxe5d [ 5 ] ; real_T ftxl3ve1we ; real_T cqlekexsf4 [ 5 ] ;
real_T pbf0mwqvxu ; real_T ezu3nw0jme [ 5 ] ; real_T mpaduaczra [ 12 ] ;
real_T ipldudc4jc ; real_T i5wyejvw00 ; real_T jzaacseaxt ; real_T ir2k1m2xef
[ 2 ] ; real_T ccho5ckvhr ; real_T oq42ze3zlo ; real_T jlygjdr5nw ; real_T
fo31vd32p4 ; real_T mir041liby ; real_T jz4lzneeo1 ; real_T ebee4njyij ;
real_T i302uyv4ub ; real_T cvoatslkxn ; real_T ozdje1tbeq [ 2 ] ; real_T
c3odb1pgdi ; real_T dumyo0mi3u ; real_T mjljeeps1u ; real_T e32unymcc4 ;
real_T om4zueiy1s ; real_T nafgdh5awp ; real_T pvsfs5bviq ; real_T oh1bpz4njz
; real_T mtfzfgh35r ; real_T kvt4cjhlrh [ 2 ] ; real_T nk334zxlzp ; real_T
geip5cv4tr ; real_T j51tfhhdgm ; real_T icyr0u0hwc ; real_T b0v4jzhvdz ;
real_T mia0akgecm ; ose1v24qd2 cqi4cjmse0 ; ose1v24qd2 puvrgymrfw ;
ose1v24qd2 gqdbtcmlhky ; } CXPtMin ; typedef struct { real_T dxcqn52y0j ;
real_T prvbwmxe5d [ 5 ] ; real_T ftxl3ve1we ; real_T cqlekexsf4 [ 5 ] ;
real_T pbf0mwqvxu ; real_T ezu3nw0jme [ 5 ] ; real_T mpaduaczra [ 12 ] ;
real_T ipldudc4jc ; real_T i5wyejvw00 ; real_T jzaacseaxt ; real_T ir2k1m2xef
[ 2 ] ; real_T ccho5ckvhr ; real_T oq42ze3zlo ; real_T jlygjdr5nw ; real_T
fo31vd32p4 ; real_T mir041liby ; real_T jz4lzneeo1 ; real_T ebee4njyij ;
real_T i302uyv4ub ; real_T cvoatslkxn ; real_T ozdje1tbeq [ 2 ] ; real_T
c3odb1pgdi ; real_T dumyo0mi3u ; real_T mjljeeps1u ; real_T e32unymcc4 ;
real_T om4zueiy1s ; real_T nafgdh5awp ; real_T pvsfs5bviq ; real_T oh1bpz4njz
; real_T mtfzfgh35r ; real_T kvt4cjhlrh [ 2 ] ; real_T nk334zxlzp ; real_T
geip5cv4tr ; real_T j51tfhhdgm ; real_T icyr0u0hwc ; real_T b0v4jzhvdz ;
real_T mia0akgecm ; hfpxnwfvdd cqi4cjmse0 ; hfpxnwfvdd puvrgymrfw ;
hfpxnwfvdd gqdbtcmlhky ; } CXPtMax ; typedef struct { real_T cfqlsew1dc [ 4 ]
; real_T afoguwqjfk ; real_T lucojiysrq ; real_T nlqb31wufv ; real_T
k3knvu32n3 ; real_T imzfl2vebh ; real_T fbrddyyoy4 ; real_T kemkb2mise ;
real_T lp1sb12ryi ; real_T o4vvijvzcg ; real_T e33nze2ssx ; real_T ag1vf4a4u3
; real_T nyphc2q12b ; real_T o1mqsqyrdy ; real_T l1argoqxtw ; real_T
pin3rosxsg ; real_T h3xmsgwx0g ; real_T ojyuykcebz ; real_T afo2krhylm ;
real_T jiyga13sh4 ; real_T lzqlelecs4 ; real_T pr43eilg0t ; real_T fzgnkwz4ye
; real_T mcho1hqrfy ; real_T olc3qibfzx ; real_T cyqwvwitw3 ; real_T
nnlg152k0e ; real_T fzlvwva4rk ; real_T gut4jb4uiu ; real_T iz32uk5vdq ;
real_T pkkrqvkifu ; real_T ka3jflam1t ; real_T lcz4sncvlf ; real_T f14gz5sodg
; real_T dbpph1ukxp ; real_T ihtd2vlsmg ; real_T bxxmi03ihe ; real_T
drrwapyu32 ; real_T dxf0nfzrqw ; real_T keqw4vkkic ; real_T pnuya4ge5o ;
real_T kl0bottimb ; real_T h3e5cojcqq ; real_T jxacyjfq4p ; real_T nmw0voae41
; real_T nij3cfqygn ; real_T if5ci4lvbz ; j4bdse2byj cqi4cjmse0 ; j4bdse2byj
puvrgymrfw ; j4bdse2byj gqdbtcmlhky ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct d2o1h43yf5_ { real_T
Gain_Gain ; real_T input2_Value ; } ; struct acuaihhzpu_ { real_T
input2_Value ; } ; struct bek1yqg5mv_ { real_T Gain_Gain ; real_T
input2_Value ; } ; struct ozd4wyfuvi_ { real_T input2_Value ; } ; struct
chh2ehjaxn_ { real_T Lmq_sat_Y0 ; real_T Laq_Y0 ; real_T uLl_q_Gain [ 2 ] ;
real_T Integrator_IC ; real_T uDLookupTable_tableData [ 2 ] ; real_T
uDLookupTable_bp01Data [ 2 ] ; real_T Lmq_Gain ; real_T uTT1e6s_Gain ; real_T
Constant1_Value ; real_T u2_Value [ 3 ] ; real_T Linv_Y0 ; real_T RLinv_Y0 ;
real_T Lmqd_Y0 ; real_T Laqd_Y0 ; real_T uLl_d_Gain [ 3 ] ; real_T
Integrator_IC_g1shtqvluy ; real_T uDLookupTable_tableData_imh4jt4ucy [ 2 ] ;
real_T uDLookupTable_bp01Data_ksienufmbo [ 2 ] ; real_T Lmd_Gain ; real_T
uTT1e6s_Gain_lrfifhs0hf ; real_T Constant1_Value_dvrakrgzwa ; real_T u1_Value
[ 2 ] ; real_T u1_Value_kxgxvrotpn [ 25 ] ; real_T u5_Value [ 25 ] ; real_T
u1_Value_gb2ffz550q [ 25 ] ; real_T u2_Value_ofkq3wczs0 ; real_T u3_Value ;
boolean_T Constant1_Value_cjnzzjd4qz ; boolean_T Constant2_Value ; boolean_T
Constant3_Value ; } ; struct P_ { real_T u00kV1000MVA_Frequency ; real_T
DieselEngineGovernor_K ; real_T DieselEngineGovernor_K_hsep1xrwii ; real_T
DieselEngineGovernor_K_cl2ljmrvvx ; real_T Vaminmax_Ka ; real_T
Vaminmax_Ka_joioxdjv2b ; real_T Vaminmax_Ka_fmvvzu1cvw ; real_T AC1A_Kc ;
real_T AC1A_Kc_lp3kwbrdlq ; real_T AC1A_Kc_ey4gmz0v22 ; real_T AC1A_Kd ;
real_T AC1A_Kd_dmbfzuvmau ; real_T AC1A_Kd_jc2axpnc1z ; real_T
RepeatingSequenceInterpolated8_OutValues [ 3 ] ; real_T
RepeatingSequenceInterpolated7_OutValues [ 3 ] ; real_T
RepeatingSequenceInterpolated6_OutValues [ 3 ] ; real_T
DieselEngineGovernor_Pm0 ; real_T DieselEngineGovernor_Pm0_kdo13i53e1 ;
real_T DieselEngineGovernor_Pm0_a40shkker5 ; real_T ThreePhaseBreaker_SwitchA
; real_T ThreePhaseBreaker_SwitchB ; real_T ThreePhaseBreaker_SwitchC ;
real_T Vaminmax_Ta ; real_T Vaminmax_Ta_m25rkfya5x ; real_T
Vaminmax_Ta_achztkg4yj ; real_T DieselEngineGovernor_Td ; real_T
DieselEngineGovernor_Td_khwtk020bh ; real_T
DieselEngineGovernor_Td_bx2jkcsvfl ; real_T
RepeatingSequenceInterpolated8_TimeValues [ 3 ] ; real_T
RepeatingSequenceInterpolated7_TimeValues [ 3 ] ; real_T
RepeatingSequenceInterpolated6_TimeValues [ 3 ] ; uint8_T
LimitedCounter_uplimit ; uint8_T LimitedCounter_uplimit_hhtrkteiui ; uint8_T
LimitedCounter_uplimit_gpv2tvmki5 ; real_T u1_Y0 ; real_T u2_Y0 ; real_T
u3_Y0 ; real_T Switch_Threshold ; real_T Switch1_Threshold ; real_T
Switch2_Threshold ; real_T Rotorangledtheta_IC ; real_T web2_Gain ; real_T
Integrator_IC [ 5 ] ; real_T Switch_Threshold_es5p4ljhx5 ; real_T
changeIqIdcurrentsigns_Gain [ 5 ] ; real_T ib_Gain ; real_T
Rotorangledtheta_IC_jattgadt2d ; real_T web2_Gain_lxgspwzlqe ; real_T
Integrator_IC_penjbqiku4 [ 5 ] ; real_T Switch_Threshold_e2e0xrm3uu ; real_T
changeIqIdcurrentsigns_Gain_devnvm2504 [ 5 ] ; real_T ib_Gain_k0uiynd021 ;
real_T Rotorangledtheta_IC_ino2tfu01n ; real_T web2_Gain_hafoo1lium ; real_T
Integrator_IC_hskzo4cis1 [ 5 ] ; real_T Switch_Threshold_i2gzs1aal3 ; real_T
changeIqIdcurrentsigns_Gain_oeffjb2exf [ 5 ] ; real_T ib_Gain_a5iu43yzxn ;
real_T SineWaveA_Amp ; real_T SineWaveA_Bias ; real_T SineWaveA_Phase ;
real_T SineWaveB_Amp ; real_T SineWaveB_Bias ; real_T SineWaveB_Phase ;
real_T SineWaveC_Amp ; real_T SineWaveC_Bias ; real_T SineWaveC_Phase ;
real_T StateSpace_P1_Size [ 2 ] ; real_T StateSpace_P1 [ 3645 ] ; real_T
StateSpace_P2_Size [ 2 ] ; real_T StateSpace_P2 [ 4 ] ; real_T
StateSpace_P3_Size [ 2 ] ; real_T StateSpace_P3 [ 12 ] ; real_T
StateSpace_P4_Size [ 2 ] ; real_T StateSpace_P4 [ 4617 ] ; real_T
StateSpace_P5_Size [ 2 ] ; real_T StateSpace_P5 [ 6 ] ; real_T
StateSpace_P6_Size [ 2 ] ; real_T StateSpace_P6 [ 3 ] ; real_T
StateSpace_P7_Size [ 2 ] ; real_T StateSpace_P7 [ 3 ] ; real_T
StateSpace_P8_Size [ 2 ] ; real_T StateSpace_P8 [ 3 ] ; real_T
StateSpace_P9_Size [ 2 ] ; real_T StateSpace_P9 ; real_T StateSpace_P10_Size
[ 2 ] ; real_T StateSpace_P10 ; real_T Rotorspeeddeviationdw_IC ; real_T
units_Gain ; real_T Integrator_IC_dwtmatqar4 ; real_T Integrator_UpperSat ;
real_T Integrator_LowerSat ; real_T uLl_q_Gain [ 2 ] ; real_T
Switch3_Threshold ; real_T uLl_d_Gain [ 3 ] ; real_T u_Vb_Gain ; real_T
Switch2_Threshold_gl2dnbpcoc ; real_T Gain_Gain ; real_T Gain_Gain_go11vj5gb1
; real_T Gain1_Gain ; real_T outputformatting_Gain [ 18 ] ; real_T
Constant4_Value ; real_T Constant3_Value ; real_T Constant5_Value ; real_T
Switch1_Threshold_nhwesj444w ; real_T SampleTimeMath_WtEt ; real_T
Constant1_Value ; real_T Switch2_Threshold_cpu03sarvk ; real_T
Switch1_Threshold_i5r3mlizx4 ; real_T u1_Gain [ 2 ] ; real_T units1_Gain ;
real_T theta_IC ; real_T t_Gain ; real_T units2_Gain ; real_T CONTROLSYSTEM_A
[ 2 ] ; real_T CONTROLSYSTEM_C [ 2 ] ; real_T Integrator_UpperSat_f4njfmemxq
; real_T Integrator_LowerSat_dbtbuno0hm ; real_T TF1_A ; real_T TF1_C ;
real_T TF1_D ; real_T TF2_A ; real_T TF2_C ; real_T Saturation_tableData [ 3
] ; real_T Saturation_bp01Data [ 3 ] ; real_T Gain3_Gain ; real_T
StateSpace_A ; real_T StateSpace_B ; real_T StateSpace_C ; real_T
StateSpace_D ; real_T StateSpace_InitialCondition ; real_T
Integrator_IC_pvpv3edcbn ; real_T Integrator_UpperSat_drvyrbacf3 ; real_T
Integrator_LowerSat_hx5r22dn01 ; real_T VRmin_UpperSat ; real_T
VRmin_LowerSat ; real_T Gain_Gain_ffnxwopg3s ; real_T StateSpace_A_pgmfa5yhzo
; real_T StateSpace_B_pl13jcfikc ; real_T StateSpace_C_m5ukcmidnd ; real_T
StateSpace_InitialCondition_dxz5ijbicj ; real_T StateSpace_D_irddqmjpbm ;
real_T N_Gain ; real_T Gain1_Gain_moin2woj4i ; real_T
Switch1_Threshold_aftgfs3nnz ; real_T wbase_Gain ; real_T u_Pb_Gain ; real_T
F1_Gain ; real_T u_2H_Gain ; real_T web1_Gain ; real_T web3_Gain ; real_T
Rotorspeeddeviationdw_IC_o43mhwbr2s ; real_T units_Gain_iq4q232a3o ; real_T
Integrator_IC_cbuanuvuvp ; real_T Integrator_UpperSat_emevdxcfrg ; real_T
Integrator_LowerSat_b2xzznseid ; real_T uLl_q_Gain_jh4fgceov2 [ 2 ] ; real_T
Switch3_Threshold_pdefg51fln ; real_T uLl_d_Gain_ksdp1qfju0 [ 3 ] ; real_T
u_Vb_Gain_fxx3jygcme ; real_T Switch2_Threshold_ouaxae3tuq ; real_T
Gain_Gain_n4b4vqpdms ; real_T Gain_Gain_kd3xkntxif ; real_T
Gain1_Gain_lni3n3ja03 ; real_T outputformatting_Gain_ghuljw3lhk [ 18 ] ;
real_T SampleTimeMath_WtEt_oqoqay0dg0 ; real_T Constant2_Value ; real_T
Switch3_Threshold_diazeczrov ; real_T Switch1_Threshold_fwfvkbu4fv ; real_T
u1_Gain_h2t4ccjbjb [ 2 ] ; real_T units1_Gain_ck3oazuezb ; real_T
theta_IC_dprjmrmwfq ; real_T t_Gain_ocx2eejdk0 ; real_T
units2_Gain_mdhlfy5yh3 ; real_T CONTROLSYSTEM_A_oy0zvzwgbs [ 2 ] ; real_T
CONTROLSYSTEM_C_aor5asjqzc [ 2 ] ; real_T Integrator_UpperSat_gojjo5eoxp ;
real_T Integrator_LowerSat_odmybcofvo ; real_T TF1_A_in4jblwda4 ; real_T
TF1_C_p2k2li4nfg ; real_T TF1_D_ctmvhklpop ; real_T TF2_A_enodlnrioj ; real_T
TF2_C_cttzu3ti0v ; real_T Saturation_tableData_bxpta2jp2k [ 3 ] ; real_T
Saturation_bp01Data_cujbbzghha [ 3 ] ; real_T Gain3_Gain_l0wnsmveb4 ; real_T
StateSpace_A_egh3gfm2o1 ; real_T StateSpace_B_ffyet4mzai ; real_T
StateSpace_C_hoey44f3p1 ; real_T StateSpace_D_fhquez5sfr ; real_T
StateSpace_InitialCondition_huivxjzddm ; real_T Integrator_IC_h2sy3kxvaj ;
real_T Integrator_UpperSat_mx32ysi3tz ; real_T Integrator_LowerSat_pgmxfrs2lk
; real_T VRmin_UpperSat_kemkgh34w4 ; real_T VRmin_LowerSat_jrg3s5kvpl ;
real_T Gain_Gain_obx54i1vu4 ; real_T StateSpace_A_hz0n2nokjy ; real_T
StateSpace_B_cies5b1jkk ; real_T StateSpace_C_l2uehmt5xx ; real_T
StateSpace_InitialCondition_o3b0kscpl2 ; real_T StateSpace_D_ag504b3buu ;
real_T N_Gain_be3jplttom ; real_T Gain1_Gain_e30uvq0bg2 ; real_T
Switch1_Threshold_fwxhhecccj ; real_T wbase_Gain_ipvpfsncw4 ; real_T
u_Pb_Gain_meqork31l1 ; real_T F1_Gain_ehi20lbmpl ; real_T
u_2H_Gain_fy3z52hrui ; real_T web1_Gain_ntza1b0jr3 ; real_T
web3_Gain_hkaiompgkf ; real_T Rotorspeeddeviationdw_IC_mgh0oddmta ; real_T
units_Gain_knuawugzke ; real_T Integrator_IC_pyisyjlvgu ; real_T
Integrator_UpperSat_m3couvae5u ; real_T Integrator_LowerSat_cp3m3xxjrp ;
real_T uLl_q_Gain_kecofhqc2m [ 2 ] ; real_T Switch3_Threshold_njctu0jfwh ;
real_T uLl_d_Gain_lwwmuggbe5 [ 3 ] ; real_T u_Vb_Gain_euntrylpur ; real_T
Switch2_Threshold_ihudfcdcgg ; real_T Gain_Gain_mlg03jqesr ; real_T
Gain_Gain_cvcbqyleda ; real_T Gain1_Gain_l4eyt2f1nb ; real_T
outputformatting_Gain_pp0gocueod [ 18 ] ; real_T
SampleTimeMath_WtEt_mn443d0ldo ; real_T Constant6_Value ; real_T
Switch4_Threshold ; real_T Switch1_Threshold_bvrzjijffl ; real_T
u1_Gain_i4dhglb1xx [ 2 ] ; real_T units1_Gain_mjfpltedd3 ; real_T
theta_IC_nuqyp4ahc0 ; real_T t_Gain_dbtteubymo ; real_T
units2_Gain_lg4ftazuex ; real_T CONTROLSYSTEM_A_fmcipdkw5g [ 2 ] ; real_T
CONTROLSYSTEM_C_bbvipdfxiw [ 2 ] ; real_T Integrator_UpperSat_g2nmqxfxgj ;
real_T Integrator_LowerSat_jpz1embdbj ; real_T TF1_A_jog0zs3jsk ; real_T
TF1_C_enbbofzqoo ; real_T TF1_D_oklbobiarf ; real_T TF2_A_nfpoakqhp5 ; real_T
TF2_C_b52pyf1de4 ; real_T Saturation_tableData_kxfwt3h3lg [ 3 ] ; real_T
Saturation_bp01Data_en0rvvne43 [ 3 ] ; real_T Gain3_Gain_fuo2nhtpfo ; real_T
StateSpace_A_ggjpwot10c ; real_T StateSpace_B_k2dlv21nqs ; real_T
StateSpace_C_ixsu11uqcc ; real_T StateSpace_D_kgtr0kyhhc ; real_T
StateSpace_InitialCondition_ldzhin2tip ; real_T Integrator_IC_jdcpelpvxo ;
real_T Integrator_UpperSat_awe5bjjzds ; real_T Integrator_LowerSat_boizxptfju
; real_T VRmin_UpperSat_k0uoo5f5gu ; real_T VRmin_LowerSat_aseabweop3 ;
real_T Gain_Gain_gns12i5e1p ; real_T StateSpace_A_f04ittyphn ; real_T
StateSpace_B_oeqazzuglo ; real_T StateSpace_C_gsj3y0bvsj ; real_T
StateSpace_InitialCondition_bacyfv3a4h ; real_T StateSpace_D_px4xwj4emx ;
real_T N_Gain_ibtzqi1ta5 ; real_T Gain1_Gain_mh0xj2zmnv ; real_T
Switch1_Threshold_eqdxhfdxlc ; real_T wbase_Gain_okwmdlnvlt ; real_T
u_Pb_Gain_cmlupu4lup ; real_T F1_Gain_fyk4vsqtoc ; real_T
u_2H_Gain_pa0w4j2kxa ; real_T web1_Gain_pvbmras4px ; real_T
web3_Gain_frif05wfp3 ; real_T LookUpTable_XData [ 4 ] ; real_T
LookUpTable_YData [ 4 ] ; real_T Switch3_Threshold_cusgrt5efp ; real_T
LookUpTable_XData_mq1idq0nl4 [ 5 ] ; real_T LookUpTable_YData_ccvh5hrnif [ 5
] ; real_T Switch3_Threshold_g4hlm5luuc ; real_T HitCrossing_Offset ; real_T
LookUpTable_XData_eezqqd1gay [ 5 ] ; real_T LookUpTable_YData_hvy2xxeyp0 [ 5
] ; real_T Switch3_Threshold_au45uwgzmy ; real_T
HitCrossing_Offset_byy35c2pe2 ; real_T LookUpTable_XData_lgzoqpdmap [ 5 ] ;
real_T LookUpTable_YData_iwdiswx02w [ 5 ] ; real_T
Switch3_Threshold_npd5pduwpp ; real_T HitCrossing_Offset_ckyjwcjlvs ; real_T
HitCrossing_Offset_fvwyzrflnb ; real_T donotdeletethisgain_Gain ; real_T
donotdeletethisgain_Gain_f1ifkvuqfs ; real_T
donotdeletethisgain_Gain_kkqpn0enmg ; real_T Kv1_Gain ; real_T
donotdeletethisgain_Gain_e2auf2j1rh ; real_T
donotdeletethisgain_Gain_mshnmhldd3 ; real_T
donotdeletethisgain_Gain_j0haq310r2 ; real_T Kv_Gain ; real_T puV_Gain ;
real_T donotdeletethisgain_Gain_gmp4pnrphh ; real_T
donotdeletethisgain_Gain_bnawliqvik ; real_T
donotdeletethisgain_Gain_ovofaqt3tg ; real_T Kv1_Gain_bfvq3500bp ; real_T
donotdeletethisgain_Gain_ok2btrhuoi ; real_T
donotdeletethisgain_Gain_jfb5zvz2in ; real_T
donotdeletethisgain_Gain_agzp2l5xoj ; real_T Kv_Gain_czwgps5mha ; real_T
puV_Gain_p1qhxv12dx ; real_T donotdeletethisgain_Gain_lmtenwvpad ; real_T
donotdeletethisgain_Gain_b4h4vrwez2 ; real_T
donotdeletethisgain_Gain_hjafqzuqe3 ; real_T Kv1_Gain_otbflrw2my ; real_T
donotdeletethisgain_Gain_jy0ly32qzq ; real_T
donotdeletethisgain_Gain_b0gdocyoez ; real_T
donotdeletethisgain_Gain_ablp5g31dp ; real_T Kv_Gain_ozfx3cxmrl ; real_T
puV_Gain_k4ukpfvde5 ; real_T donotdeletethisgain_Gain_cnnpmgyozm ; real_T
donotdeletethisgain_Gain_l234soa3tf ; real_T
donotdeletethisgain_Gain_lkyvqrwckq ; real_T Kv1_Gain_fxnn3aho5e ; real_T
donotdeletethisgain_Gain_en3nmrxgld ; real_T
donotdeletethisgain_Gain_hsdfpbzlqb ; real_T
donotdeletethisgain_Gain_by5bos33lx ; real_T Kv_Gain_nftr42q2lb ; real_T
puV_Gain_ff0r1eyugh ; real_T Constant_Value ; real_T
Constant1_Value_ls0pawmfdq ; real_T input_Value ; real_T input1_Value ;
real_T input2_Value ; real_T Vfe0Ka_Value ; real_T Constant2_Value_epm55skuqn
; real_T Constant1_Value_iqgflwhd0e ; real_T Constant2_Value_aotbypyuon ;
real_T Constant3_Value_bcu1pnrcxc ; real_T Constant4_Value_f2c3xayuty [ 25 ]
; real_T Constant5_Value_kqupx0gkxm ; real_T Constant6_Value_aag1qbkfgz [ 25
] ; real_T Constant8_Value ; real_T Laqd_nosat_Value [ 2 ] ; real_T
Lmqd_nosat_Value [ 2 ] ; real_T u1_Value [ 25 ] ; real_T Vkd0Vkq10Vkq20_Value
[ 2 ] ; real_T nomspeed_Value ; real_T Vtrefpu_Value ; real_T
Constant_Value_fsy5hzupsd ; real_T Constant1_Value_gzdhx1y50h ; real_T
input_Value_j4v0x1onoy ; real_T input1_Value_jwembzy4jc ; real_T
input2_Value_mfn5w3js4u ; real_T Vfe0Ka_Value_mornhw3ubx ; real_T
Constant2_Value_ie44msnx1e ; real_T Constant1_Value_bhms2ohso1 ; real_T
Constant2_Value_pvyxnakeki ; real_T Constant3_Value_ekoy4aaewq ; real_T
Constant4_Value_a4umnvtiwg [ 25 ] ; real_T Constant5_Value_owzacacl1u ;
real_T Constant6_Value_k5ippmioel [ 25 ] ; real_T Constant8_Value_erv12cit4q
; real_T Laqd_nosat_Value_i2eposfmya [ 2 ] ; real_T
Lmqd_nosat_Value_guprarme5m [ 2 ] ; real_T u1_Value_jhomplmiue [ 25 ] ;
real_T Vkd0Vkq10Vkq20_Value_nhzucgdnq4 [ 2 ] ; real_T
nomspeed_Value_gur000lokn ; real_T Vtrefpu_Value_dhu50coqb3 ; real_T
Constant_Value_feo10nb4xc ; real_T Constant1_Value_p3y25qn4th ; real_T
input_Value_kgzybnfuyq ; real_T input1_Value_lmbqbgulqv ; real_T
input2_Value_damfqfxz2b ; real_T Vfe0Ka_Value_hmejnrjuz0 ; real_T
Constant2_Value_gn5n2cp44f ; real_T Constant1_Value_gju1j5culq ; real_T
Constant2_Value_pd52okrj2w ; real_T Constant3_Value_ftweuv5hbb ; real_T
Constant4_Value_kflxryerzb [ 25 ] ; real_T Constant5_Value_avkreamlze ;
real_T Constant6_Value_ovz5lrokju [ 25 ] ; real_T Constant8_Value_pcjxv32svc
; real_T Laqd_nosat_Value_fjpqaej0yv [ 2 ] ; real_T
Lmqd_nosat_Value_kp0vqseud3 [ 2 ] ; real_T u1_Value_kgi3v4joec [ 25 ] ;
real_T Vkd0Vkq10Vkq20_Value_ltjzacdd50 [ 2 ] ; real_T
nomspeed_Value_c4afvv0dzn ; real_T Vtrefpu_Value_gqtbi3ry5p ; real_T C4_Value
; real_T C4_Value_j03cbj4w4t ; real_T C4_Value_d2dqb0vhdi ; real_T
C4_Value_oedqg4szxm ; real_T Constant5_Value_p3h5lbxhcf ; boolean_T
Constant1_Value_fzwmfv0kgm ; boolean_T Constant1_Value_pwpdsgpubt ; boolean_T
Constant1_Value_o4y4gj153l ; uint8_T Output_InitialCondition ; uint8_T
Output_InitialCondition_kgl5nejq40 ; uint8_T
Output_InitialCondition_koai1wfyjy ; uint8_T FixPtConstant_Value ; uint8_T
Constant_Value_d1po1vdd0l ; uint8_T FixPtConstant_Value_bhfbq2rm4w ; uint8_T
Constant_Value_lox41z13xd ; uint8_T FixPtConstant_Value_mqj2wqz1c5 ; uint8_T
Constant_Value_nhhzojlawr ; chh2ehjaxn cqi4cjmse0 ; ozd4wyfuvi ecdtivcszk ;
bek1yqg5mv a12lwium4g ; acuaihhzpu b0yuwkfotx ; d2o1h43yf5 plxey5q4z3 ;
chh2ehjaxn puvrgymrfw ; ozd4wyfuvi ghjqwoc3wx ; bek1yqg5mv clza3n5d4t ;
acuaihhzpu a1ytfvhs5e ; d2o1h43yf5 dslix2t5ne ; chh2ehjaxn gqdbtcmlhky ;
ozd4wyfuvi mfbj0yzfuo4 ; bek1yqg5mv e22kv3zqsq0 ; acuaihhzpu igmpp4jfdvg ;
d2o1h43yf5 attmdly3nwd ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ;
extern B rtB ; extern X rtX ; extern DW rtDW ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * testingV10_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
