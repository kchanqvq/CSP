#include "../csp.h"
$zeval(( (atom) ((quote) (x)) ) ,())
$zeval(( (cons) ((quote)(a)) ((quote) ((a) (b)))),())
$zeval((((lambda)((x))((cons)(x)((quote)((b)))))((quote)(w))),())
$zeval((( (lambda) ((f)) ((f) ((quote) ((b) (c)))))((quote) ( (lambda) ((x)) ((cons) ((quote)(a)) (x))))),())
