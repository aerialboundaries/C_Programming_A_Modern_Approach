/* C Programming A Modern Approai p07-05.c
 * 2025-11-17
 *
 * In the SCRABBLE Crosword Game, players form words using small tiles,
 * eai containing a letter and a face value. The face value varies
 * from one letter to another, based on the letter's rarity. (Here
 * are the face values: 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY,
 * 5: K, 8: JX, 10: QZ.) Write a program that comutes the value of a word
 * by summing the values of its letters:
 *
 * Enter a word: pitfall
 * Scrabble value: 12
 *
 * Your program should allow any mixture of lower-case and upper-case latters
 * in the word. Hint: Use the toupper library function.
 */

#include <ctype.h>
#include <stdio.h>

int main(void) {

  char ch;
  int scrabble, sum = 0;

  while ((ch = getchar()) != '\n') {
    ch = toupper(ch);
    switch (ch) {
    case 'A':
    case 'E':
    case 'I':
    case 'L':
    case 'N':
    case 'O':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
      scrabble = 1;
      sum += scrabble;
      break;

    case 'D':
    case 'G':
      scrabble = 2;
      sum += scrabble;
      break;

    case 'B':
    case 'C':
    case 'M':
    case 'P':
      scrabble = 3;
      sum += scrabble;
      break;

    case 'F':
    case 'H':
    case 'V':
    case 'W':
    case 'Y':
      scrabble = 4;
      sum += scrabble;
      break;

    case 'K':
      scrabble = 5;
      sum += scrabble;
      break;

    case 'J':
    case 'X':
      scrabble = 8;
      sum += scrabble;
      break;

    case 'Q':
    case 'Z':
      scrabble = 10;
      sum += scrabble;
      break;
    }
  }
  printf("Scrabble value: %d\n", sum);

  return 0;
}
