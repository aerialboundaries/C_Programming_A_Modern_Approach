#ifndef READLINE_H
#define READLINE_H

/**************************************************************************
 * read line: Skips leading white-spac characters, then
 *            reads the remainer of the input line and
 *            stores it in str. Truncates the line if its
 *            length exceeds n. Returns the number of
 *            characters stored.
 *************************************************************************/
int read_line(char str[], int n);

#endif
