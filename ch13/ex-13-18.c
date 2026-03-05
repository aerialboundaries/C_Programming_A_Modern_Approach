/* C Programming A Modern Approach
 * ex-13-18.c
 * 2026-03-05
 *
 * Write the following function:
 * void remove_file name(char *url);
 * url points to a string containing a URL (Uniform Resource Locator) that
 * ends with a file name (such as "http://www.knking.com/index.html").
 * The function should modify the string by removing the file name and the
 * preceeding slash. (In this example, the result will be
 * "http://www.knking.com".) Incorporate the "search for the end of a string"
 * idiom into your funciton. Hint: Have the function replace the last slash in
 * the string by a null character.
 */

#include <stdio.h>

void remove_filename(char *url);

int main(void)
{
    char url[80] = "http://www.knking.com/index.html";

    remove_filename(url);

    printf("%s\n", url);
}

void remove_filename(char *url)
{
    while (*url)
        url++;

    while (*url != '/') {
        url--;
    }

    *url = '\0';
}
