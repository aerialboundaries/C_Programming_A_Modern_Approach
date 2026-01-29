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

// #define VALID_RANGE(n) (((n + size) % size))
void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void) {
  int size; //, r, c, number;

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

  char magic_square[size][size];

  create_magic_square(size, magic_square);

  print_magic_square(size, magic_square);

  return 0;
}

void create_magic_square(int n, char magic_square[n][n]) {
  int r, c, number;
  // initialize magic_square
  for (r = 0; r < n; r++) {
    for (c = 0; c < n; c++) {
      magic_square[r][c] = 0;
    }
  }

  // Making magic_square
  c = n / 2; // Set the first column to the middle of the array
  r = 0;
  magic_square[r][c] = 1;
  for (number = 2; number <= n * n; number++) {
    if (magic_square[(r - 1 + n) % n][(c + 1 + n) % n] == 0) {
      r = (r - 1 + n) % n;
      c = (c + 1 + n) % n;
      magic_square[r][c] = number;
    } else {
      r = (r + 1 + n) % n;
      magic_square[r][c] = number;
    }
  }
}

void print_magic_square(int n, char magic_square[n][n]) {
  // Print magic_square
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      printf("%4d", magic_square[r][c]);
    }
    printf("\n");
  }
}
