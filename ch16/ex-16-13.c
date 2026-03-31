/* C Programming A Modern Approach
 * ex-16-13.c
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
 * If the value of shape_kind is RECTANGLE, the height and width members
 * store the dimensions of a rectangle. If the value of shape_kind is
 * CIRCLE, the radius member stores the radius of a circle. Indicate
 * which of the following statements are legal, and show how to repair
 * the ones that aren't:
 *
 * (a) s.shape_kind = RECTANGLE;
 * (b) s.center.x = 10;
 * (c) s.height = 25;
 * (d) s.u.rectangle.width = 8;
 * (e) s.u.circle = 5;
 * (f) s.u.radius = 5;
 *
 * My Answer:
 * (a) legal.
 * (b) legal.
 * (c) illegal. s.u.rectangle.height = 25;
 * (d) legal.
 * (e) illegal. s.u.circle.radius = 5;
 * (f) illegal. s.u.circle.radius = 5;
 *
 */
