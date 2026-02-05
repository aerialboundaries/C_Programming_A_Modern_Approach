/* C Programming A Modern Approach
 * ex-10-02.c
 * 2026-02-04
 */

/* The follwoing program outline shows only function defienitions and variable
 * declarations.*/

int b, c;

void f(void) { int b, d; }

void g(int a) {
  int c;
  {
    int a, d;
  }
}

int main(void) { int c, d; }

/* For each of the following scopes, list all variable and parameter names
 * visible in that scope. If there's more than onw variable or parameter
 * with the same name, indicate which one is visible.
 *
 * (a) The f function
 * (b) The g function
 * (c) The block in which a and d are declared
 * (d) The main function
 *
 * My answer:
 * (a) b and d inside f function and c
 * (b) a and c inside g function, and global b
 * (c) a, d, c inside g function, and global b
 * (d) c and d inside main function and global b
 */
