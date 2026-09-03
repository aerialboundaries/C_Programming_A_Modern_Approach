/*
Using isxdigit, write a function that checks whether a string represents a valid hexadec-
imal number (it consists solely of hexadecimal digits). If so, the function returns the value of
the number as a long int. Otherwise, the function returns -1.

long int validhex(const char a[]) {
  if (a[0] == '\0')
    return -1;
  for (int i = 0; a[i] != '\0'; i++)
    if (!isxdigit((unsigned char)a[i]))
      return -1; 
  return strtol(a, NULL, 16);
}
*/
