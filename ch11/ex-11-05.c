/* C Programming A Modern Approach
 * ex-11-05.c
 * 2022-02-12
 *
 * Write the following function:
 * void split_time(long total_sec, int *hr, int *min, int *sec);
 * total_sec is a time represented as the number of seconds since midnight.
 * hr, min, and sec are pointers to variables in which the funcetion will
 * store the equivalent time in hours (0-23), minutes (0-59), and seconds
 * (0-59), respectively.
 */

void split_time(long total_sec, int *hr, int *min, int *sec) {
  *hr = total_sec / 60 / 60;
  *min = (total_sec - *hr * 60 * 60) / 60;
  *sec = (total_sec - *hr * 60 * 60) - *min * 60;
}
