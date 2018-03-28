# C Super Preprocessing
This is the development repo of C Super Preprocessing project.

CSP is a LISP dialect completely implemented using C macro, which provides LISP compile-time meta programming ability on C preprocessors.

The code is full of hacks like logic riddles, to make it easier for users to join in the development of this project I'm writing wiki pages about the implementation details. 

[Here's the link.](https://github.com/BlueFlo0d/CSP/wiki/Implementation-details) 

Some of my original studies are marked. Please do not publish or transfer the articles without permission.

Welcome to join me! 

_(should I use plural pronoun? 23333 I hope I can use 'us' soon)_

## Plan
Core interpreter
- STEP 1: Implement interpreter A which supports F-function operations
- STEP 2: Implement interpreter B on A which supports the 9 LISP primitives
- STEP 3: Provide access to some built-in common funtions.

Application framework (not started yet)
- Provide C code manipulating routines.
- Framework for writing C programs in LISP. The C preprocessor serves as a translator.
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
$zeval((((lambda)((x))((cons)(x)((quote)((b)))))((quote)(w))),())//Expands to ((w)(b))
$zeval((( (lambda) ((f)) ((f) ((quote) ((b) (c)))))((quote) ( (lambda) ((x)) ((cons) ((quote)(a)) (x))))),())//Expands to ((a)(b)(c))
```
Note that you have to define some comparing macro for any atom you used. (car) (cdr) (cons) (cond) (eq) (atom) (lambda) (quote) (x) (y) (f) (a) (b) (c) (T) are predefined.
To make your atom comparable you need to define the following macro:
```C
#define EQmyatommyatom )EQ_T( //making (myatom) comparable
#define EQqq )EQ_T( //making (q) comparable
```
Just pass your file to your C compiler preprocessor to see the result. It is also possible to use the header in your C/C++ project to provide LISP meta programming ability.
```bash
$ cc -E mycsp.h
```
Enjoy yourself!
## Current Progress
- Interpreter A almost done.
Supports CAR CDR CONS APPEND LIST SAFE_CAR SAFE_CDR EQ ATOM QUOTE COND PAIR NULL AND NOT ASSOC EVLIS EVCON

- Interpreter B (The main eval recursion)
Supports atom quote eq car cdr cons lambda cond

**NOTE** cond is not short-circuited. There may be better solution.

IT SUPPORTS LAMBDA!
## Run the tests

```bash
$ cd tests
$ ./test.sh
```
ack command is required to run the tests.

## Note
It is proved that being SAFE is very important for primitive macros being used in CSP.
Since there seems to be no way to implement short-circuit condition on C preprocessor, any primitive macro should not cause error or break the bracket balance when accepting illegal list. Otherwise, it will spoil the main eval condition and cause fail of the whole process.
