/* C Programming A Modern Approach
 * pp08-17.c
 * 2025-12-10
 *
 * Write a program that prints an n x n magic square (a square arrangement
 * of the numbers 1, 2, ..., n^2 in which the sums of the rows, columns,
 * and diagonals are all the same). The user will specify the value of n:
 *
 * This program creates a magic square of a specified size.
 * The size must be an odd number between 1 and 99.
 * Enter size of magic square: 5
 *
 * 17   24     1     8    15
 * 23    5     7    14    16
 *  4    6    13    20    22
 * 10   12    19    21     3
 * 11   18    25     2     9
 *
 * Store the magic square in a two-dimensional array. Start by placing
 * the number 1 in the middle of row 0. Place each of the remaining
 * numbers 2, 3, ..., n^2 by moving up one row and over one column.
 * Any attempt to go outside the bounds of the array should "wrap around"
 * to the opposite side of array. For example, instead of storing the
 * next number in row -1, we would store it in row n-1 (the last row).
 * Instead of storing the next number in column n, we would store it
 * in column 0. If a particular array element is already occupied, put
 * the number directly below the previously stored number. If your
 * compiler supports variable length arrays, declare the array to have
 * n rows and n columns. If not, declare the array to have 99 rows
 * and 99 columns. */

/* pp-09-05.c
 * 2026-01-27
 *
 * Modify Programming project 17 from Chapter 8 so that it incoudes the
 * following functions:
 *
 * void create_magic_square(int n, char magic_square[n][n]);
 * void print_magic_square(int n, char magic_square[n][n]);
 *
 * After obtaining the number n from the user, main willl call
 * create_magic_square, passing it an n x n array that is declared inside main.
 * create_magic_square will then call print_magic_square, which will display the
 * array in the format described in the original project. Note: If your compiler
 * doesn't support variable-length arrays, declare the array in main to be 99 x
 * 99 instead of n x n and use the follwo9ign prototypes insteaad:
 *
 * void create_magic_square(int n, char magic_square[99][99]);
 * void print_magic_square(int n, char magic_square[99][99]);
 */

#include <stdio.h>

#define VALID_RANGE(n) (((n + size) % size))

int main(void) {
  int size, r, c, number;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");

  for (;;) {
    printf("Enter size of magic square: ");
    scanf("%d", &size);
    if (size % 2 == 0) {
      printf("Invalid number.\n");
      continue;
    } else {
      break;
    }
  }
  int magic_square[size][size];

  // initialize magic_square
  for (r = 0; r < size; r++) {
    for (c = 0; c < size; c++) {
      magic_square[r][c] = 0;
    }
  }

  // Making magic_square
  c = size / 2; // Set the first column to the middle of the array
  r = 0;
  magic_square[r][c] = 1;
  for (number = 2; number <= size * size; number++) {
    if (magic_square[VALID_RANGE(r - 1)][VALID_RANGE(c + 1)] == 0) {
      r = VALID_RANGE(r - 1);
      c = VALID_RANGE(c + 1);
      magic_square[r][c] = number;
    } else {
      r = r + 1;
      magic_square[r][c] = number;
    }
  }

  // Print magic_square
  for (r = 0; r < size; r++) {
    for (c = 0; c < size; c++) {
      printf("%4d", magic_square[r][c]);
    }
    printf("\n");
  }

  return 0;
}
