/* C Programming A Modern Approach
 * pp08-12.c
 * 2025-12-02
 *
 * Modify Programming Project 5 from Chapter 7 so that the SCRABBLE values
 * of the letters are stored in an array. The array will have 26 elements,
 * corresponding to the 26 letters of the alphabet. For example, element 0
 * of the array will store 1 (because the SCRABBLE value of the letter A
 * is 1), element 1 of the array will store 3 (because the SCRABBLE value
 * of the letter B is 3), and so forth. As each character of the input
 * words is read, the program will use the array to determine the
 * SCRABBLE value of that character. Use an array initializer to set up
 * the array. */

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
  int sum = 0;
  int scrabble[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

  printf("Enter a word: ");

  while ((ch = getchar()) != '\n') {
    ch = toupper(ch);
    sum += scrabble[ch - 65];
  }
  printf("Scrabble value: %d\n", sum);

  return 0;
}
