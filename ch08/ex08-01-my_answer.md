Because c has the better method to calculate the lenth of an array by pointer.

> what is the correct answer for ex08-01.md?                         █
✦ The expression sizeof(a) / sizeof(a[0]) is considered superior     █
  because it is more maintainable and less prone to errors.          █
  If you later change the data type of the array a (e.g., from int to█
  long or double), the expression sizeof(a) / sizeof(a[0]) will      █
  automatically work correctly without any changes.                  █
  In contrast, with sizeof(a) / sizeof(t), you would have to find and█
  manually change the type t everywhere you've used it. Forgetting to█
  update the type in even one place would lead to an incorrect       █
  calculation of the number of elements, causing bugs in your        █
  program.                                                           █


