/* C Programming A Modern Approach
 * ex-09-15.c
 * 2026-01-23
 *
 * The following (rather confusing) function finds the median of three
 * numbers. Rewrite the function so that it has just one return statement.
 *
 * double median(double x, double y, double z)
 * {
 *    if (x <= y)
 *      if (y < = z) return y;
 *      else if (x <= z) return z;
 *      else return x;
 *    if (z <= y) return y;
 *    if (x <= z) return x;
 *    return z;
 * }
 *
 * My answer:
 *
 * double median(double x, double y, double z)
 * {
 *    double median;
 *    if (x <= y) {
 *      if (y < = z) median = y;
 *      else if (x <= z) median = z;
 *      else median = x;
 *    } else {
 *      if (z <= y) median = y;
 *      else if (x <= z) median = x;
 *      else median = z;
 *    }
 *    return median;
 * }
 *
 */
