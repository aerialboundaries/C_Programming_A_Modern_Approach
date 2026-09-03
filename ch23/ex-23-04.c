/* Using isalpha and isalnum, write a function that checks whether a string has the syn-
tax of a C identifier (it consists of letters, digits, and underscores, with a letter or underscore
at the beginning).

bool syntacs(a[])
{
    if (a[0] == '\0'
      return false;
    if ((a[0]) != '_' && !isalpha((unsigned char)a[0]))
      return false;
    for (int i = 1; a[i] != '\0'; i++) {
      if (a[i] != '_' && !isalnum((unsigned char)a[i]))
        return false;
    }
    return true;
}

*/
