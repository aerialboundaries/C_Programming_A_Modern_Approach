/*
(a) Write a "wrapper" function named try_math_fcn that calls a math function
(assumed to have a double argument and return a double value) and then checks
whether the call succeeded. Here's how we might use try_math_fcn:

y = try_math_fcn(sqrt, x, "Error in call of sqrt");

If the call sqrt (x) is successful, try_math_fcn returns the value computed by sqrt.
If the call fails, try_math_fen calls perror to print the message Error in call of
sqrt, then calls exit to terminate the program.

(b) Write a macro that has the same effect as try_math_fcn but builds the error mes-
sage from the function's name:

y = TRY_MATH_FCN(sqrt, x);

If the call of sqrt fails, the message will be Error in call of sqrt. Hint: Have
TRY MATH_FCN call try_math_fcn.

My Answer:
(a)
double try_math_fcn(double (*fcn)(double), double x, const char *message)
{
  double y;
  errno = 0;
  y = fcn(x);
  if (errno != 0) {
    perror(message);
    exit(EXIT_FAILURE);
  }
  return y;
}

(b)
#define TRY_MATH_FCN(fcn, x) try_math_fcn((fcn), (x), "Error in call of " #fcn)

*/
