#include "../csp.h"
$zeval((( (lambda) ((f)) ((f) ((quote) ((b) (c)))))((quote) ( (lambda) ((x)) ((cons) ((quote)(a)) (x))))),())
$eval_expand($zeval(( (cond) (((eq)(((quote)(a)) ((quote)(b)))) ((quote) (first)) ) ( ( (atom) ((quote) (a)) ) ((quote) (second)))),()))
