/* C Programming A Modern Approach
 * ex-09-01.c
 * 2026-01-12
 */

/* The following function, which computes the area of a triangle, contains
 * two errors. Locate the errors and show how to fix them. (Hint: There are
 * no errors in the formula.)
 *
 * double triangle_area(double base, height)
 * double product;
 * {
 * product = base * height;
 * return product / 2;
 * }
 *
 * error1: The parameter height needs type double.
 * error2: The variable product must be defined within {}
 *
 * Correction:
 *
 * double triangle_area(double base, double height)
 * {
 * double product;
 * product = base * height;
 * return product / 2;
 * }
 
