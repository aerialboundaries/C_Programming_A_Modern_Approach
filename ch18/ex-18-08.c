/* C Programming A Modern Approach */

/* ex-18-08.c
2026-05-10

Write a complete description of the type of x as specified by each of the
following declarations.

(a) char (*x[10])(int);
(b) int (*x(int))[5] ;
(c) float *(*x(void)) (int);
(d) void (*x(int, void (*y) (int))) (int);

My Answer:

(a) char (*x[10])(int);
x is an array of 10 pointer to function which takes int as argument and returns
char.

(b) int (*x(int))[5] ;
x is a function that returns a pointer to an array of five integers.

(c) float *(*x(void)) (int);
x is a function without argument which returns a pointer to function
with an int argument that returns a pointer to float value.

(d) void (*x(int, void (*y) (int))) (int);
x is a function with two arguments. The first argument is an integer, and
the second is a pointer to a function with an argument and no return value.
x returns a pointer to a function with an int argument and no return value.
(Although this example may seem artificially complex, the signal function - part
of the standard C library - has exactly this prototype. See 0.632 for a
discussion of signal.)

*/
