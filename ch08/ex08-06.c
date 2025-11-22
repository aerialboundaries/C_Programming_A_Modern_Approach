/* C Programming A Modern Approach
 * ex08-06.c
 *
 * 2022-11-22
 *
 * Calculators, watches, and other electronic devices often rely on seven-
 * segment displays for numerical output. To form a digit, such devides
 * "trun on" some of the seven segments while leaving others "off";
 *
 * Here's what the array might look like, with each row representing
 * one digit:
 *
 * const int seguments[10][7] = {{1, 1, 1,1, 1, 1, 0}, ...};
 *
 * I've given you the first row of the initializer; fill in the rest.
 */

const int seguments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1},
};
