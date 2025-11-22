/* C Programming A Modern Approach
 * ex08-10.c
 * 2025-11-22
 *
 * Write a declaration for an 8 x 8 char array named chess_board.
 * Include an initializer that puts the following data into
 * array (one character per array element):
 *
 * rnbqkbnr
 * pppppppp
 *  . . . .
 * . . . .
 *  . . . .
 * . . . .
 * PPPPPPPP
 * RNBQKBNR
 */

#include <stdio.h>

int main(void) {

  char chess_board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                            {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                            {
                                '.',
                                ' ',
                                '.',
                                ' ',
                                '.',
                                ' ',
                                '.',
                            },
                            {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                            {
                                '.',
                                ' ',
                                '.',
                                ' ',
                                '.',
                                ' ',
                                '.',
                            },
                            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}

  };

  return 0;
}
