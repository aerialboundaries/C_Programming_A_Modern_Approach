/* C Programming A Modern Approach */

/* ex-18-03.c
2026-05-09

List the storage duration (static or automatic), scope (block or file),
and linkage (internal, external, or none) of each variable and parameter
in the following file:

extern float a;

void f(register double b)
{
  static int c;
  auto char d;
}

My answer:
variable a:
  storage duration : static
  scope : file
  linkage : external

variable b:
  storage duration : automatic
  scope : block
  linkage : none

variable c:
  storage duration : static
  scope : block
  linkage : none

variable d:
  storage duration : automatic
  scope : block
  linkage : none

*/
