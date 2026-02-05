/* C Programming A Modern Approach
 * ex-10-01.c
 * 2026-02-04
 *
 * The follwoing program outline shows only function defienitions and variable
 * declarations.*/

int a;
void f(int b) { int c; }

void g(void) {
  int d;
  {
    int e;
  }
}

int main(void) { int f; }

/* For each of the following scopes, list all variable and parameter names
 * visible in that scope:
 *
 * (a) The f function
 * (b) The g function
 * (c) The block in which e is declared
 * (d) The main function
 *
 * My answer:
 * (a) a, b, c
 * (b) a, d
 * (c) a, d, e
 * (d) a, f
 */
