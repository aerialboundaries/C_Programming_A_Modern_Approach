/* C Programming A Modern Approach
 * ex-16-10.c
 * 2016-03-31
 *
 * The following structures are designed to store informatin about objects
 * on a graphis screen:
 * struct point {int x, y;};
 * struct rectangle {struct point upper_left, lower_right;};
 *
 * A point structure stores the x and y coordinates of a point on the
 * screen. A rectangle structure stores the coordinates of the upper
 * left and lower right corners of a rectangle. Write functions that
 * perform the following operations on a rectangle structure r passed
 * as an argument:
 *
 * (a) Compute the area of r.
 * (b) Compute the center of r, returning it as a point value.
 *     If either x or y coordinate of the center isn't a integer, store its
 *     truncated value in the point structure.
 * (c) Move r by x units in the x direction and y units in the y direction,
 *     returning the modified version of r. (x and y are additional arguments
 *     to the function.)
 * (d) Determine whether a point p lies within r, returning true or false.
 *     (p is an additional argument of type struct point..)
 */

#include <stdbool.h>
#include <stdio.h>

struct point {
    int x, y;
};

struct rectangle {
    struct point upper_left, lower_right;
};

// (a)
int area(struct rectangle r);

// (b)
struct point center(struct rectangle r);

// (c)
struct rectangle move(struct rectangle r, int x, int y);

// (d)
bool is_in(struct rectangle r, struct point p);

int main(void)
{
    struct point ul = { 100, 100 }, lr = { 250, 150 };
    struct rectangle r = { ul, lr };

    printf("Area of r = %d\n", area(r));

    struct point center_p = center(r);
    printf("Center of r : %d, %d\n", center_p.x, center_p.y);

    struct rectangle r2 = move(r, 10, 20);
    printf("r2 = (%d, %d) (%d, %d)\n", r2.upper_left.x, r2.upper_left.y,
        r2.lower_right.x, r2.lower_right.y);

    struct point p1 = { 150, 120 }, p2 = { 168, 200 };
    printf("p1 is on r: %s\n", is_in(r, p1) ? "True" : "False");
    printf("p2 is on r: %s\n", is_in(r, p2) ? "True" : "False");

    return 0;
}

int area(struct rectangle r)
{
    return (r.lower_right.x - r.upper_left.x)
        * (r.lower_right.y - r.upper_left.y);
}

struct point center(struct rectangle r)
{
    return (struct point) { ((r.upper_left.x + r.lower_right.x) / 2),
        ((r.upper_left.y + r.lower_right.y) / 2) };
}

struct rectangle move(struct rectangle r, int x, int y)
{
    r.upper_left.x += x;
    r.lower_right.x += x;
    r.upper_left.y += y;
    r.lower_right.y += y;

    return r;
}

bool is_in(struct rectangle r, struct point p)
{
    return (r.upper_left.x <= p.x && r.lower_right.x >= p.x
        && r.upper_left.y <= p.y && r.lower_right.y >= p.y);
}
