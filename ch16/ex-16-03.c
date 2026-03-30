/* C Programming A Modern Approach
 * ex-16-03.c
 * 2016-03-30
 *
 * (a) Show how to declare a tag named complex for a structure with
 *     two members, real and imaginary, of type double.
 *
 * (b) Use the complex tag to declare variables named c1, c2, and c3.
 *
 * (c) Write function named make_complex that stores its tow arguments
 *     (both of type double) in a complex structure, then return the
 *     strucre.
 *
 * (d) Write a function named add_complex that adds the corresponding
 *     members of its arguments (both complex structures), then
 *     return the result (another complex structure).
 */

/* My Answer
 *
 *  (a)
 *  struct complex {
 *    double real, imaginary;
 *  };
 *
 *  (b)
 *  struct complex c1, c2, c3;
 *
 *  (c)
 *  struct complex make_complex(double real, double imaginary)
 *  {
 *    struct complex c;
 *    c.real = real;
 *    c.imaginary = imaginary;
 *    return c;
 *  }
 *
 *  (d) struct complex add_complex(struct complex c1, struct complex c2)
 *      {
 *        struct complex c3;
 *        c3.real = c1.real + c2.real;
 *        c3.imaginary = c1.imaginary + c2.imaginary;
 *        return c3;
 *      }
 *
 */
