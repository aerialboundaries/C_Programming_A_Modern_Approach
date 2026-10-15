/*
 Write a program that tests the atexit function. The program should have two
 functions (in addition to main), one of which prints "That 's all, " and the
 other "folks !". Use the atexit function to register both to be called at
 program termination. Make sure they're called in the proper order, so that we
 see the message That's all, folks! on the screen.
*/

#include <stdio.h>
#include <stdlib.h>

void all(void) { printf("That's all, "); }
void folks(void) { printf("folks!\n"); }

int main(void)
{
  atexit(folks);
  atexit(all);

  return 0;
}
