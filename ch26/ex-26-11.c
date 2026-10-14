/*
Although the bsearch function is normally used with a sorted array, it will
sometimes work correctly with an array that is only partially sorted. What
condition must an array satisfy to guarantee that bsearch works properly for a
particular key? Hint: The answer appears in the C standard.

Answer:
C99/C11/C17 Standard (§7.22.5.1 p2):
"The array shall consist of elements that compare less than, equal to, or
greater than the key object, in that order."
*/
