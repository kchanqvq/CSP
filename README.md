# C Super Preprocessing
This is the development repo of C Super Preprocessing project
## Plan
- STEP 1: Implement interpreter A which supports F-function operations
- STEP 2: Implement interpreter B on A which supports the 9 LISP primitives
## Usage
Include the header.
```C
#include "csp.h"
```
A CSP atom should be enclosed with brackets.
```C
(car) //This is an atom
```
Then a list is represented as:
```C
((x) (y) (z))//This is a list
```
You can execute a LISP expression using $zeval.
```C
//$zeval(expression,environment)
$zeval(( (atom) ((quote) (x)) ),())//Expands to (T)
$zeval(( (cons) ((quote)(a)) ((quote) ((a) (b)))),())//Expands to ((a) (a) (b))
```
Enjoy yourself!
## Current Progress
- Interpreter A almost done.
Supports CAR CDR CONS APPEND LIST SAFE_CAR SAFE_CDR EQ ATOM QUOTE COND PAIR NULL AND NOT ASSOC EVLIS
TODO: EVCON

- Interpreter B (The main eval recursion)
Supports atom quote eq car cdr cons
## Note
It is proved that being SAFE is very important for primitive macros using in CSP.
Since there seems to be no way to implement short-circuit condition on C preprocessor, any primitive macro should not cause error or break the bracket balance when accepting illegal list. Otherwise, it will spoil the main eval condition and cause fail of the whole process.
