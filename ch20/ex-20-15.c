// 2026-06-10

/*

(a) Assume that the variable s has been declared as follows:
struct {
  int flag: 1;
} s;

With some compilers, executing the following statements causes 1 to be
displayed, but with other compilers, the output is-1. Explain the reason for
this behavior.

s.flag = 1;
printf("%d\n", s.flag);

(b) How can this problem be avoided?

My Answer:
(a): 1 is treated as sign, because of int.

(b);
struct {
  unsigned int flag: 1;
} s;
*/
