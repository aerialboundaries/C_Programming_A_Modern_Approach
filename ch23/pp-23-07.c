/*
Write a program that counts the number of sentences in a text file (obtained from standard
input). Assume that each sentence ends with a ., ?, or ! followed by a white-space charac-
ter (including \n).
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
  int ch;
  int count = 0;
  int flag = 0;

  while ((ch = getchar()) != EOF) {
    if (flag) {
      if (isspace((unsigned char)ch)) {
        count++;
      }
      flag = 0;
    }

    if (ch == '.' || ch == '?' || ch == '!') {
      flag = 1;
    }
  }

  printf("num of sentences: %d\n", count);

  return 0;
}
