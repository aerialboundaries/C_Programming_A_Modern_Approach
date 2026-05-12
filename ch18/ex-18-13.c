/* C Programming A Modern Approach
ex-18-13.c
2026-05-11

Which of the following declarations are legal? (Assume that PI is a macro that
represents 3.14159.)

(a) char c = 65;
(b) static int i = 5, j = i * i;
(c) double d = 2 * PI;
(d) double angles[] = {0, PI/ 2, PI, 3 * PI / 2};

My Answer:
(a) legal. c has 'A'
(b) illegal. Definition of static must be constatnt.
(c) legal. d has 6.28318
(d) legal. angles will have elements converted to double.
*/
