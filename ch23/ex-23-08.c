/*
Use strchr to write the following function:
int numchar(const char *s, char ch);
numchar returns the number of times the character ch occurs in the string s.

KN Answer:

int numchar(const char *s, char ch)
{
  int count = 0;

  s = strchr(s, ch);
  while (s != NULL) {
    count++;
    s = strchr(s + 1, ch);
  }

  return count;
}

*/
