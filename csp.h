/****************************************
The C Super Preprocessing project
Author: BlueFlo0d
E-mail: hongqiantan@pku.edu.cn

LONG LIVE REMILIA SCARLET!

PLAN: STEP 1: Implement interpreter A which supports F-function operations
STEP 2: Implement interpreter B on A which supports the 9 LISP primitives
CURRENT PROGRESS:

Interpreter A almost done.
Supports CAR CDR CONS APPEND LIST SAFE_CAR SAFE_CDR EQ ATOM QUOTE COND PAIR NULL AND NOT
TODO: ASSOC EVLIS EVCON

Interpreter B (The main eval recursion)
Supports atom quote eq car cdr cons

This code repo is released under AGPL v2.0.
If you do not want to use the code under AGPL please email me.
*****************************************/

#define _E(...) __VA_ARGS__
#define _N(...)
#define _e(x) x
#define _n(x)
#define _CAT(x,y) x##y
#define CAT(x,y) _CAT(x,y)
#define _e_sem(x) x(
#define _bsem )
//#define _EVAL(x) _E(_e_sem _e x _bsem)
#include "csp_gen.h"
#define _OEVAL(car,k,...) k(EVAL((car)) OEVALY)
#define _OEVALY(car,k,...) k(EVAL((car)) OEVAL)
#define OEVAL(car,...) _OEVAL(car __VA_ARGS__,_E)
#define OEVALY(car,...) _OEVALY(car __VA_ARGS__,_E)
#define _BOTTOM _E(_N,_N)
#define FOEVAL(x) OEVAL x (_BOTTOM)

#define _DESTROY_E(...) __VA_ARGS__
#define _DESTROY_N(...)
#define _DESTROY_BOTTOM _DESTROY_E(_DESTROY_N,_DESTROY_N)
#define _ODESTROY(car,k,...) k(_n((car)) ODESTROYY)
#define _ODESTROYY(car,k,...) k(_n((car)) ODESTROY)
#define ODESTROY(...) _ODESTROY( __VA_ARGS__,_DESTROY_E)
#define ODESTROYY(...) _ODESTROYY( __VA_ARGS__,_DESTROY_E)

#define _T(x) T
//#define __ATOM(x)  ODESTROY x (_BOTTOM)
#define __ATOM(x) ODESTROY x (_DESTROY_BOTTOM)
#define RODESTROY T _n()(
#define KATOMT(...) (T)
#define KATOMR () _n _n()(
#define ATOM(x) _e(CAT(KATOM,_e(CAT(R,__ATOM(x)) _bsem)))

#define CAR(x) (_CAR x ))
#define _CAR(x) x _n(

#define CDR(x) (_CDR x ))
#define _CDR(x) _e (

#define APPEND(x) (_e(x) _APPEND
#define _APPEND(x) _e(x))

#define QUOTE
#define CADR(x) _e(CAR CDR(x))
#define CAAR(x) _e(CAR CAR(x))
//#define CADDR(x) _EVAL (((CAR) _EVAL (((CDR)_EVAL (((CDR)( x )))))))
#define INTERNAL_EVAL(x) _E(_e _e x)
#define CADDR(x) INTERNAL_EVAL (((CAR) INTERNAL_EVAL (((CDR)INTERNAL_EVAL (((CDR)( x )))))))
//CDR((x)(y)(z))
//CAR((y)(z))
//CADDR((x)(y)(z))
#define _EVAL(x) _E(_e _e x)
//#define _EVAL(x)
#define test(x) _EVAL (((CAR)(x)))
#define EXP ((CDR)((x)(y)(z)))
#define COND_eCOND(x) _CONDY
#define COND_eCONDY(x) _COND
#define COND_e
#define COND_EAT(x) COND_EATY
#define COND_EATY(x) COND_EAT
#define COND_EAT_END
#define COND_EATY_END
#define _COND_END ()
#define _CONDY_END ()
#define TCOND(x) (x) COND_EAT
#define TCONDY(x) (x) COND_EAT
#define _COND(x) CAT(COND,CAT(INTERNAL_EVAL(SAFE_CAR(x)),COND)CADR(x))
#define _CONDY(x) CAT(COND,CAT(INTERNAL_EVAL(SAFE_CAR(x)),CONDY)CADR(x))
//#define COND(x) CAT _n()(_COND  x,_END)
#define COND(x) CAT(_COND  x,_END)
#define _n2() _n
#define T_endeatnCOND_EAT_FIRST_endT )(T) _n2(
#define NULL(x) _e(_n _n()(CAT(ISAFE_CAT(T,_e(x)),T)))()

//#define NULL(x) CAT(ISAFE_CAT(T,_e(x)),T)
#define COND_EAT_FIRST(x) COND_EATY
#define COND_EATY_FIRST(x) COND_EAT

#define EAT_CAR ) ()_n _n()(((
#define eatnCOND_EAT
#define eatnCOND_EATY
#define eatnCOND_EAT_FIRST

#define SAFE_CAT(x,y) CAT(CAT(eatn,CAT(COND_EAT_FIRST x,_END)),CAT(eatn,CAT(COND_EAT_FIRST y,_END)))
#define ISAFE_CAT(x,y) CAT(CAT(eatn,CAT(COND_EAT_FIRST x,_end)),CAT(eatn,CAT(COND_EAT_FIRST y,_end)))
#define COND_EATGBRAKET ()
#define bnot_sigT
#define bnot_sig T
#define NOT(a) (CAT(b,CAT(not_sig,a)))

//@export NOT((T))=>() NOT(()) =>(T)
#define $not(a) NOT a
#define _AND(a) INTERNAL_EVAL((COND((NOT(a)(COND_EAT))((T)(_AND_Y)))))
#define _AND_Y(a) INTERNAL_EVAL((COND((NOT(a)(COND_EAT))((T)(_AND)))))

#define andtransCOND_EAT ()
#define andtransCOND_EATY ()
#define andtrans_AND_Y (T)
#define andtrans_AND (T)

//@export AND((a)(b)(c)...) = (a)&&(b)&&(c) ...
#define $and(a) CAT(andtrans,_AND a)

#define CONS(x) ((x) _CONS
#define _CONS(x) _e(x))
#define $cons(x) CONS x
#define $append(x) APPEND x

//$and((T)(T)(T)(T)(T))

#define _be(y) y)
#define ZIP(x)   _n() (x,_be

#define _PAIR(x,y) _e( __PAIR(x,y))
#define __PAIR(x,y) _E COND((NULL SAFE_CDR(x)((SAFE_CAR(x) SAFE_CAR(y))))((T)((SAFE_CAR (x) SAFE_CAR (y)) _e(_PAIR2(_e SAFE_CDR(x),_e SAFE_CDR(y))))))

//#define _PAIR3(x,y)  _E(NULL CDR(x))
#define _PAIR2(x,y)  _E COND((NULL SAFE_CDR(x)((SAFE_CAR(x) SAFE_CAR(y))))((T)((SAFE_CAR (x) SAFE_CAR (y)) _e(_PAIR3(_e SAFE_CDR(x),_e SAFE_CDR(y))))))

#define _PAIR3(x,y)  _E COND((NULL SAFE_CDR(x)((SAFE_CAR(x) SAFE_CAR(y))))((T)((SAFE_CAR (x) SAFE_CAR (y)) _e(_PAIR4(_e SAFE_CDR(x),_e SAFE_CDR(y))))))

#define _PAIR4(x,y)  _E COND((NULL SAFE_CDR(x)((SAFE_CAR(x) SAFE_CAR(y))))((T)((SAFE_CAR (x) SAFE_CAR (y)) _e(DELAY_INT_54(__PAIR_R) ()(SAFE_CDR(x) SAFE_CDR(y))))))
#define __PAIR_R() _$pair
#define TEST_R() TEST
#define TEST(x) test
#define _PAIR_e(x) x
#define _$pair(x) _PAIR_e(_PAIR ZIP x)
#define PAIR_EVAL(...) PAIR_EVAL2(PAIR_EVAL2(PAIR_EVAL2(__VA_ARGS__)))
#define PAIR_EVAL2(...) PAIR_EVAL3(PAIR_EVAL3(PAIR_EVAL3(__VA_ARGS__)))
#define PAIR_EVAL3(...) PAIR_EVAL4(PAIR_EVAL4(PAIR_EVAL4(__VA_ARGS__)))
#define PAIR_EVAL4(...) PAIR_EVAL_E(PAIR_EVAL_E(PAIR_EVAL_E(__VA_ARGS__)))
#define PAIR_EVAL_E(...) __VA_ARGS__
#define $pair(x) PAIR_EVAL(_$pair(x))
#define EVAL_e(x) x
//_PAIR((x)(y)(z),(a)(b)(c))
//$pair((($pair _n()(((x)(y))((z)(w))))(y)(z)(j))((a)(b)(c)(d))))
#define SAFE_CAR_N(x) (())_n
#define SAFE_CAR_EAT_CAR )SAFE_CAR_N((
#define SAFE_CAR_EAT_CDR )SAFE_CAR_N((
#define COND_EATY_SCEND (a)
#define COND_EAT_SCEND (a)
#define _SAFE_CAR(a)  _e(_n _n()(CAT(SAFE_CAR_EAT,_E(_e CAR(CAT(COND_EAT_FIRST a,_SCEND)))))(CAR(a)))
#define SAFE_CAR(a) _E(_e _SAFE_CAR(a))
#define _SAFE_CADR(a)  _e(_n _n()(CAT(SAFE_CAR_EAT,_E(_e CADR(CAT(COND_EAT_FIRST a,_SCEND)))))(CADR(a)))
#define SAFE_CADR(a) _E(_e _SAFE_CADR(a))

#define _SAFE_CDR(a)  _e(_n _n()(CAT(SAFE_CAR_EAT,_E(_e CDR(CAT(COND_EAT_FIRST a,_SCEND)))))(CDR(a)))
#define SAFE_CDR(a) _E(_e _SAFE_CDR(a))
//_n _n()(CAT(SAFE_CAR_EAT,_E(_e CAR((a)))))
        //EVAL_e($pair(((x)(y)(z)(j)(1)(6)(8)(2))((a)(b)(c)(d)(2)(7)(7)(6))))
//$pair(((x)(y)(k))((j)(z)((w)(r))))
#define EQ_T() T
#define EQ(x) CAT _n()(CAT(EQ,x),_be
#define EQ_e(x) x
#define _$eq(x,y) (_e(_n _n()(_e(EQ(x)(y)))))
#define $eq(x) EQ_e(_$eq ZIP x)

#define EQcarcar )EQ_T(
#define EQcdrcdr )EQ_T(
#define EQconscons )EQ_T(
#define EQcondcond )EQ_T(
#define EQeqeq )EQ_T(
#define EQatomatom )EQ_T(
#define EQlambdalambda )EQ_T(
#define EQlabellabel )EQ_T(
#define EQquotequote )EQ_T(
#define $zipped_eval_R() $zipped_eval
#define $zipped_eval(e,a) COND(\
        (ATOM e (Unimplemented))\
        (ATOM SAFE_CAR e \
         COND(($eq(SAFE_CAR e (quote))EVAL_e(SAFE_CAR SAFE_CDR e))  \
              ($eq(SAFE_CAR e (atom)) (EVAL_e ATOM DELAY_INT_23($zipped_eval_R)() (SAFE_CAR SAFE_CDR e,a))) \
              ($eq(SAFE_CAR e (eq)) (EVAL_e $eq( DELAY_INT_25($zipped_eval_R)() (SAFE_CAR SAFE_CDR e,a) DELAY_INT_25($zipped_eval_R)() (SAFE_CAR SAFE_CDR SAFE_CDR e,a)))) \
              ($eq(SAFE_CAR e (car)) (EVAL_e SAFE_CAR DELAY_INT_23($zipped_eval_R)() (SAFE_CAR SAFE_CDR e,a))) \
              ($eq(SAFE_CAR e (cdr)) (EVAL_e SAFE_CDR DELAY_INT_23($zipped_eval_R)() (SAFE_CAR SAFE_CDR e,a))) \
              ($eq(SAFE_CAR e (cons)) (EVAL_e CONS DELAY_INT_23($zipped_eval_R)() (SAFE_CAR SAFE_CDR e,a) DELAY_INT_23($zipped_eval_R)() (SAFE_CAR SAFE_CDR SAFE_CDR e,a))) \
                 )                                      \
                )                                       \
        )
#define $eval_E(...) __VA_ARGS__
//Here is the tests
$eval_E($eval_E($eval_E($zipped_eval(((atom)((quote)(a))),()))))
$eval_E($eval_E($eval_E($eval_E($zipped_eval(((eq)((quote)(car))((quote)(car))),())))))
$eval_E($eval_E($eval_E($eval_E($eval_E($eval_E($zipped_eval(((cons)((quote)(a))((quote)((a)(b)))),())))))))

        $zipped_eval(((b)(c)),(a))