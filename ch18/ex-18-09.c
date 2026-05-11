/* C Programming A Modern Approach */

/* ex-18-09.c
2026-05-10

Use a series of type definitions to simplify each of the declarations in
Exercise 8.

(a) char (*x[10])(int);
(b) int (*x(int))[5] ;
(c) float *(*x(void)) (int);
(d) void (*x(int, void (*y) (int))) (int);

My Answer:
(a) char (*x[10])(int);
typedef char Fcn(int);
typedef Fcn *Fcn_ptr_array[10];
Fcn_ptr_array x;


(b) int (*x(int))[5] ;
typedef int Array5[5];  //intを５つ持つ配列を定義
typedef Array5 *Fcn(int);  // Array5へのポインタを返す関数型を定義
Fcn x;  // xを宣言

(c) float *(*x(void)) (int);
typedef float *Fcn(int);
typedef Fcn *Fcn_ptr(void);
Fcn_ptr x;

(d) void (*x(int, void (*y) (int))) (int);
typedef void Handler(int);
typedef void ReturnFunc(int);
typedef ReturnFunc *X_type(int, Handler *);
X_type x;

*/
