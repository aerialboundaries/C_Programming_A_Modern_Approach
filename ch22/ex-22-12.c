// Find the error in the following function and show how to fix it.
//
// int count periods (const char *filename)
// {
//   FILE *fp;
//   int n = 0;
//
//   if ((fp = fopen(filename, "r") ) != NULL) {
//     while (fgetc(fp) != EOF)
//       if (fgetc(fp) == '.')
//         n++;
//     fclose(fp);
//   }
//
//   return n;
// }

#include <stdio.h>

int countperiods(const char *filename)
{
  FILE *fp;
  int n = 0, ch;

  if ((fp = fopen(filename, "r")) != NULL) {
    while ((ch = fgetc(fp)) != EOF)
      if (ch == '.')
        n++;
    fclose(fp);
  }

  return n;
}
