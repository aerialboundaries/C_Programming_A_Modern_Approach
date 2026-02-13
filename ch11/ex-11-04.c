/* C Programming A Modern Approach
 * ex-11-04.c
 * 2022-02-12
 *
 * Write the following function:
 *
 * void swap(int *p, int *q);
 *
 * When passed the address of two variables, swap should exchange the values
 * of the variables:
 *
 * swap(&i, &j); * exchanges values of i and j *
 *
 */

void swap(int *p, int *q) {
  int temp;
  temp = *p;
  *p = *q;
  *q = temp;
}
