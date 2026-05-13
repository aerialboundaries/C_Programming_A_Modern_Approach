/* C Programming A Modern Approach
ex-18-12.c
2026-05-11

(a) Write a complete description of the type of the function f, assuming that
    it's declared as follows:

    int (*f(float (*)(long), char *)) (double);

    My Answer:
    f is a function with two arguments.  First argument is a pointer to a
fuction whicha takes long int as arugument and returns float.  Second argument
is char *, it returns the pointer to a fuction which takes double as an argument
and return integer.

(b) Give an example showing how f would be called.
My Answer:
float my_callback(long 1) {
  return (float)l;
}

char *str = "Hello";
*/
