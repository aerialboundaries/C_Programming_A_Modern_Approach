// Suppose that we call scanf as follows:
// n = scanf("%d%f%d", &i, &x, &j) ;
// (i, j, and n are int variables and x is a float variable.) Assuming that the
// input stream contains the characters shown, give the values of i, j, n, and x
// after the call. In addition, indicate which characters were consumed by the
// call. (a) 10 20 30\n (b) 1.0 2.0 3.0\n (c) 0.1 0.2 0.3\n (d) .1 .2 .3\n
//
// My Answer:
// (a) : i = 10, j = 30, n =3, x = 20.0, consumed 1,0, ,2,0, 3,0
// (b) : i = 1, j = 2, n = 3, x = 0.0, consumed 1,.,0, ,2
// (c) : i = 0, j = 0, n = 3, x = 0.1 consumed 0,.,1, ,0
// (d) : i = none, j = none, n = 0, x = none, consumed none
