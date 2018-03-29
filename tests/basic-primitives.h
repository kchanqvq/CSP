#include "../csp.h"
$zeval(( (atom) ((quote) (x)) ) ,())
$zeval(( (atom) (x) ) ,())
$zeval(( (atom) ((quote) ((x))) ) ,())
$zeval(( (cons) ((quote)(a)) ((quote) ((a) (b)))),())
$zeval(( (car) ((quote) ((a) (b) (c)))),())
$zeval(( (cdr) ((quote) ((a) (b) (c)))),())
$zeval((((lambda)((x))((cons)(x)((quote)((b)))))((quote)(w))),())
$zeval((( (lambda) ((f)) ((f) ((quote) ((b) (c)))))((quote) ( (lambda) ((x)) ((cons) ((quote)(a)) (x))))),())
