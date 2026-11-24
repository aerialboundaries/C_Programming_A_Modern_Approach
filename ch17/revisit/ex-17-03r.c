/* C_Programming_A_Modern_Approach
 * ex-17-03.c
 * 2026-04-23, 2026-11-24
 *
 * Write the following function:
 * int *create_array(int n, int initial_value);
 * The function should return a pointer to a dynamically allocated int array
 * with n members, each of which is initialized to initial_value. The return
 * value should be NULL if the array can't be allocated.
 */

#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value)
{
  int *arr = malloc(sizeof(int) * n);
  if (arr == NULL) {
    fprintf(stderr, "Error: Failed to allocate %zu bytes memory\n",
            sizeof(int) * n);
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = initial_value;
  }

  return arr;
}

int main(void)
{
  int *array;
  array = create_array(5, 30);
  for (int i = 0; i < 5; i++) {
    printf("%d", array[i]);
  }
  printf("\n");

  free(array);

  return 0;
}
