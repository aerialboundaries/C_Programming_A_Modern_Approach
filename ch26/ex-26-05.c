/*
Write the following function:

   char *vstrcat (const char *first, ... );

All arguments of vstrcat are assumed to be strings, except for the last
argument, which must be a null pointer (cast to char * type). The function
returns a pointer to a dynamically allocated string containing the concatenation
of the arguments. vstrcat should return a null pointer if not enough memory is
available. Hint: Have vstrcat go through the arguments twice: once to determine
the amount of memory required for the returned string and once to copy the
arguments into the string.
*/
