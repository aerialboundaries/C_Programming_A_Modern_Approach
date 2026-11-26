/* C Programming A Modern Approach
 * pp-09-03.c
 * 2026-01-27
 *
 * Modify Programming Project 9 from Chapter 8 so that it includes the following
 * functions:
 *
 * void generate_random_walk(char wark[10][10]);
 * void print_array(char walk[10][10]);
 *
 * main first calls generate_random_walk, which initialized the array to contain
 * ' . ' characters and then replaces some of these characters by the letters A
 * through Z, as described in the original project. main then calls print_array
 * to display the array on the screen.
 *
 *
 * C Programming A Modern Approadh
 * pp08-09.c
 * 2025-11-28
 *
 * Write a program that generates a "random walk" across a 10 x 10 array.
 * The area will cotain characters (all '.' initially). The programs must
 * randomly "walk" from element to element, always going up, down, left, or
 * right by one element. The elements visited by the program will be labeled
 * with the letters A through Z, in the order visited. Here's an example
 * of the desired output:
 *
 * A . . . . . . . . .
 * B C D . . . . . . .
 * . F E . . . . . . .
 * H G . . . . . . . .
 * I . . . . . . . . .
 * J . . . . . . . . .
 * K . . R S T U V Y .
 * L M P Q . . . W X .
 * . N O . . . . . . .
 * . . . . . . . . . .
 *
 * Hint: Use the srand and rand functions (see deal.c) to generage random
 * numbers. After generating a number, look at its remainder when divided
 * by 4. There are four possible values for the remainder - 0, 1, 2, and 3
 * - indicating the direction of the next move. Before performing a move,
 *   check that (a) it won't go outside the array, and (b) it doesn't take
 *   us to an element that already has a letter assigned. If either
 *   condition is violated, try moving in another directions. If all four
 *   directions are blocked, the program must terminate. Here's an example
 *   of premature termination:
 *
 * A B G H I . . . . .
 * . C F . J K . . . .
 * . D E . M L . . . .
 * . . . . N O . . . .
 * . . W X Y P Q . . .
 * . . V U T S R . . .
 * . . . . . . . . . .
 * . . . . . . . . . .
 * . . . . . . . . . .
 * . . . . . . . . . .
 *
 * Y is blocked on all four sides, so there's no place to put Z.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 10
#define C 10
#define is_in_bounds (new_r >= 0 && new_r < R && new_c >= 0 && new_c < C)
#define NEW_CELL walk[new_r][new_c]
#define is_movable (walk[new_r][new_c] == '.')

// Proto type
void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

// Definition of direction 0: up, 1: down, 2:Left, 3:Right
// dr : change of row, dc: change of column
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int main(void) {

  srand((unsigned)time(NULL));
  char walk[R][C];

  generate_random_walk(walk);

  // Print the field
  print_array(walk);

  return 0;
}

void generate_random_walk(char walk[10][10]) {

  // Initialize the field
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++)
      walk[r][c] = '.';
  }

  int current_r = rand() % 10;
  int current_c = rand() % 10;
  walk[current_r][current_c] = 'A';

  // Maim Logic
  for (int ch = 'B'; ch <= 'Z'; ch++) {
    int tries = 0;
    int direction_start = rand() % 4;
    bool moved = false;

    while (tries < 4) {
      int direction = (direction_start + tries) % 4;

      int new_r = current_r + dr[direction];
      int new_c = current_c + dc[direction];

      if (is_in_bounds) {
        if (is_movable) {
          NEW_CELL = ch;
          current_r = new_r;
          current_c = new_c;
          moved = true;
          break;
        }
      }
      tries++;
    }
    if (!moved) {
      break; // for loop
    }
  }
}

void print_array(char walk[10][10]) {
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++)
      printf("%c ", walk[r][c]);
    printf("\n");
  }
}
