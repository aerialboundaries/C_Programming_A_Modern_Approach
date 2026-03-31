/* C Programming A Modern Approach
 * ex-16-08.c
 * 2016-03-30
 *
 * Let color be the following structure;
 * struct color {
 *   int red;
 *   int green;
 *   int blue;
 * };
 *
 * (a) Write a declaration for const varialble named MAGENTA of type
 *     struct color whose members have the values 255, 0, and 255,
 *     respectively.
 *
 * (b) (C99) Repeat part (a), but use a designated initializer that
 *     doesn't specify the value of green, allowing it to default to 0.
 */

struct color {
    int red;
    int green;
    int blue;
};

// (a)
const struct color MAGENTA = { 255, 0, 255 };

// (b)
const struct color MAGENTA2 = { .red = 255, .blue = 255 };
