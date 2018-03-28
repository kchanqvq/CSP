#include "csp.h"
//$zipped_evcon((((quote)(T))((quote)(a)))(((quote)(T))((quote)(b))),())
$zipped_evcon((( (eq) ( (quote) (a)) ( (quote) (b)) ) ((quote) (first)) ) ( ( (atom) ((quote) (a)) ) ((quote) (second))),())
$zeval(((cond)(( (eq) ( (quote) (a)) ( (quote) (b)) ) ((quote) (first)) ) ( ( (atom) ((quote) (a)) ) ((quote) (second)))),())
