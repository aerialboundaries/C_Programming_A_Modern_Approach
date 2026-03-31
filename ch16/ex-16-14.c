/* C Programming A Modern Approach
 * ex-16-14.c
 * 2016-03-31
 *
 * Suppose that u is the following structure (point is a structure
 * tag declared in Exercise 10):
 *
 * struct shape {
 *   int shape_kind;  // RECTANGLE or CIRCLE
 *   struct point center; // coordinates of center
 *   union {
 *     struct {
 *       int height, width;
 *     } rectangle;
 *     struct {
 *       int radius;
 *     } circle;
 *   } u;
 * } s;
 *
 * Let shape be the structure tag declared in Exercise 13. Write
 * functions that perform the following operations on a shape
 * structure s passed as an argument:
 *
 * (a) Compute the area of s.
 * (b) Move s by x units in the x direction and y units in the y direction,
 *     returning the modified version of s. (x and y are additional arguments
 *     to the function.)
 * (c) Scale s by a factor of c (a double value), returning the modified
 *     version of s. (c is an additional argument to the function.)
 *
 */

#include <stdlib.h>
#define RECTANGLE 0
#define CIRCLE 1

struct point {
    int x, y;
};

struct shape {
    int shape_kind; // RECTANGLE or CIRCLE
    struct point center; // coordinates of center
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

// (a)
double area(struct shape s)
{
    if (s.shape_kind == RECTANGLE)
        return s.u.rectangle.height * s.u.rectangle.width;
    else if (s.shape_kind == CIRCLE)
        return s.u.circle.radius * s.u.circle.radius * 3.14;
    else
        exit(EXIT_FAILURE);
}

// (b)
struct shape move(struct shape s, int x, int y)
{
    struct shape new_shape = s;
    new_shape.center.x += x;
    new_shape.center.y += y;
    return new_shape;
}

// (c)
struct shape scale(struct shape s, double c)
{
    struct shape new_shape = s;
    if (new_shape.shape_kind == RECTANGLE) {
        new_shape.u.rectangle.height = (int)(s.u.rectangle.height * c);
        new_shape.u.rectangle.width = (int)(s.u.rectangle.width * c);
        return new_shape;
    } else if (s.shape_kind == CIRCLE) {
        new_shape.u.circle.radius = (int)(s.u.circle.radius * c);
        return new_shape;
    } else
        exit(EXIT_FAILURE);
}
