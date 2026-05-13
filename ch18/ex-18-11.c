/* C Programming A Modern Approach
ex-18-11.c
2026-05-11

In Section 18.4, we saw that the following declarations are illegal:

int f(int) [];      // functions can't return arrays
int g(int) (int);   // functions can't return functions
int a[10](int);     // array elements can't be functions

We can, however, achieve similar effects by using pointers: a function can
return a pointer to the first element in an array, a function can return a
pointer to a function, and the elements of an array can be pointers to
functions. Revise each of these declarations accordingly.


My asnwer:

int f(int)[];      // functions can't return arrays
int (*f(int))[];


int g(int)(int);   // functions can't return functions
int (*g(int))(int);


int a[10](int);     // array elements can't be functions
int (*a[10])(int);

*/
