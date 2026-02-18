/* C Programming A Modern Approach
 * ex-12-18.c
 * 2026-02-18
 *
 * Write the evaluate_position function described in Exercise 13 of
 * Chapter 9. Use pinter arithmetic --not subscripting-- to visit
 * array elements. Use a single loop instead of nested loops.
 *
 */

/* C Programming A Modern Approach
 * ex-09-13.c
 * 2026-01-23
 *
 * Write the following function, which evaluates a chess position:
 * int evaluate_position(char board[8][8]);
 * board represents a configuration of pieces on chessboard, where the
 * letters K, Q, R, B, N, P represent White pieces, and the letters k, q, r,
 * b, n, and p represent Black pieces. evaluate_position should sum
 * the values of the White pieces (Q = 9, R = 5, B = 3, N = 3, P = 1).
 * It should also sum the values of the Black pieces (done in a similar way).
 * The function will return the difference between the two numbers.
 * This value will be positive if White has an advantage in material and
 * negative if Black has an advantage. */

#include <stdio.h>

int evaluate_position(char board[8][8]);

int main(void) {
  char board[8][8] = {
      {'r', 'n', 'b', 'q', 'k', '.', 'b', 'r'},
      {'p', 'p', 'p', 'p', '.', 'p', 'p', 'p'},
      {'.', '.', '.', '.', '.', 'n', '.', '.'},
      {'.', '.', 'b', '.', '.', '.', '.', '.'},
      {'.', '.', 'B', '.', 'P', '.', '.', '.'},
      {'.', '.', '.', '.', '.', 'N', '.', '.'},
      {'P', 'P', 'P', 'P', '.', 'P', 'P', 'P'},
      {'R', 'N', 'B', 'Q', 'K', '.', '.', 'R'},
  };

  printf("The anser is: %d\n", evaluate_position(board));

  return 0;
}

int evaluate_position(char board[8][8]) {
  int answer = 0;
  const char *p;

  for (p = *board; p < *board + 8 * 8; p++) {
    switch (*p) {
    case 'Q':
      answer += 9;
      break;
    case 'R':
      answer += 5;
      break;
    case 'B':
      answer += 3;
      break;
    case 'N':
      answer += 3;
      break;
    case 'P':
      answer += 1;
      break;
    case 'q':
      answer -= 9;
      break;
    case 'r':
      answer -= 5;
      break;
    case 'b':
      answer -= 3;
      break;
    case 'n':
      answer -= 3;
      break;
    case 'p':
      answer -= 1;
      break;
    default:
      break;
    }
  }
  return answer;
}
