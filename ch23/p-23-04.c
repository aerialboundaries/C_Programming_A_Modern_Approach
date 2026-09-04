/*
Write a program that prompts the user to enter a series of words separated by single spaces,
then prints the words in reverse order. Read the input as a string, and then use strtok to
break it into words.
*/

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define BUFFER_SIZE 255

int main(void) {
  char buffer[BUFFER_SIZE];
  char *words[MAX_WORDS];
  int num_words = 0;

  printf("Input words separated by space. ");
  if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
    return 1;
  }

  char *p = strtok(buffer, " \n");

  while (p != NULL && num_words < MAX_WORDS) {
    words[num_words] = p;
    num_words++;
    p = strtok(NULL, " \n");
  }

  printf("reversed: ");
  for (int i = num_words - 1; i >= 0; i--) {
    printf("%s", words[i]);
    if (i > 0) {
      printf(" "); // space between words
    }
  }
  printf("\n");

  return 0;
}
