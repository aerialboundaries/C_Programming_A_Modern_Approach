/*
Explain the meaning of the following statement, assuming that value is a
variable of type long int and p is a variable of type char *:

   value = strtol (p, &p, 10);

Answer:
This statement converts the initial portion of the string pointed to by p to a
long int value in base 10 and assigns it to value. Additionally, it updates the
pointer p to point to the first character after the converted number. If no
conversion could be performed, p remains unchanged and 0 is returned.

*/
