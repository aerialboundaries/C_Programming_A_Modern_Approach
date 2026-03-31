/* C Programming A Modern Approach
 * ex-16-09.c
 * 2016-03-31
 *
 * Let color be the following structure;
 * struct color {
 *   int red;
 *   int green;
 *   int blue;
 * };
 *
 * Write the following functions.
 * (a) struct color make_color(int red, int green, int blue);
 * Returns a color structure containing the specified red, green, and bule
 * values. If any argument is less than zero, the corresponding member
 * of the structure will contain zero instead.
 * If any argument is greater than 255, the corresponding member of the
 * structure will contain 255.
 *
 * (b) int getRed(struct color c);
 * Returns the value of c's red member.
 *
 * (c) bool equal_color(struct color color1, struct color color2);
 * Returns true if the corresponding member of color1 and color2
 * are equal.
 *
 * (d) struct color brighter(struct color c);
 * Returns a color structure that represents a brighter version of the
 * color c. The structure is identical to c, except that each member
 * has been divided by 0.7 (with the result truncated to an integer).
 * However, there are three special cases: (1) If all members of c
 * are zero, the function returns a color whose members all have the
 * value 3. (2) If any member of c is greater than 0 but less than 3,
 * it is replaced by 3 before the division by 0.7. (3) If dividing
 * by 0.7 causes a member to exceed 255, it is reduced to 255.
 *
 * (e) struct color darker(struct color c);
 * Returns a color structure that represents a darker version of the
 * color c. The structure is identical to c, except that each member
 * has been multiplied by 0.7 (with the result truncated to an integer).
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 255
#define MIN_NUM 0

struct color {
    int red;
    int green;
    int blue;
};

struct color make_color(int red, int green, int blue);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);
struct color darker(struct color c);

int main(void)
{
    int r, g, b;
    printf("Input color values RGB: ");
    if (scanf("%d %d %d", &r, &g, &b) != 3) {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }

    struct color c1, c2, c3 = { .red = 100, .green = 150, .blue = 200 }, bright,
                         dark, zero = { 0, 0, 0 }, d2 = { 56, 2, 65 },
                         d3 = { 200, 57, 80 };

    // (a)
    c1 = make_color(r, g, b);
    printf("(a) Red = %d, Green = %d, Blue = %d\n", c1.red, c1.green, c1.blue);

    // (b)
    printf("(b) Red member: %d\n", getRed(c1));

    // (c)
    c2 = c1;
    printf("c1 & c2: %s\n", equal_color(c1, c2) ? "True" : "False");
    printf("c1 & c3: %s\n", equal_color(c1, c3) ? "True" : "False");

    // (d)
    bright = brighter(zero);
    printf("d-1: Red = %d, Green = %d, Blue = %d\n", bright.red, bright.green,
        bright.blue);
    bright = brighter(d2);
    printf("d-2: Red = %d, Green = %d, Blue = %d\n", bright.red, bright.green,
        bright.blue);
    bright = brighter(d3);
    printf("d-3: Red = %d, Green = %d, Blue = %d\n", bright.red, bright.green,
        bright.blue);

    // (e)
    dark = darker(c3);
    printf("(e) Dark version of c3: Red = %d, Green = %d, Blue = %d\n",
        dark.red, dark.green, dark.blue);

    return 0;
}

struct color make_color(int red, int green, int blue)
{
    struct color c;
    c.red = (red < MIN_NUM) ? MIN_NUM : (red > MAX_NUM) ? MAX_NUM : red;
    c.green = (green < MIN_NUM) ? MIN_NUM : (green > MAX_NUM) ? MAX_NUM : green;
    c.blue = (blue < MIN_NUM) ? MIN_NUM : (blue > MAX_NUM) ? MAX_NUM : blue;

    return c;
}

int getRed(struct color c)
{
    return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
    return (color1.red == color2.red && color1.green == color2.green
        && color1.blue == color2.blue);
}

struct color brighter(struct color c)
{
    if (c.red == 0 && c.green == 0 && c.blue == 0) {
        return (struct color) { 3, 3, 3 };
    }

    if (c.red > MIN_NUM && c.red < 3)
        c.red = 3;
    if (c.green > MIN_NUM && c.green < 3)
        c.green = 3;
    if (c.blue > MIN_NUM && c.blue < 3)
        c.blue = 3;

    c.red = (int)(c.red / 0.7);
    c.green = (int)(c.green / 0.7);
    c.blue = (int)(c.blue / 0.7);

    if (c.red > MAX_NUM)
        c.red = MAX_NUM;
    if (c.green > MAX_NUM)
        c.green = MAX_NUM;
    if (c.blue > MAX_NUM)
        c.blue = MAX_NUM;

    return c;
}

struct color darker(struct color c)
{
    c.red = (int)(c.red * 0.7);
    c.green = (int)(c.green * 0.7);
    c.blue = (int)(c.blue * 0.7);
    return c;
}
