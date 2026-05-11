/* C Programming A Modern Approach */

/* ex-18-04.c
2026-05-09

Let f be the following function. What will be the value of f (10) if f has
never been called before? What will be the value of f(10) if f has been
called five times previously?

int f(int i)
{
  static int j = 0;
  return i * j++;
}

My Answer:
f(10) = 0 if f has never been called before.
f(10) = 50 if f has been called five times previously.
*/
