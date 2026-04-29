/* C Programming A Modern Approach
 * ex-17-16.c
 * 2026-04-29
 *
 * Write the following function. The call sum(g, i, j) should return g (i) + ...
 * +g(j). int sum(int (*f) (int), int start, int end);
 */
int sum(int (*f)(int), int start, int end);

int sum(int (*f)(int), int start, int end)
{
    int result = 0;

    for (int i = start; i <= end; i++)
        result += f(i);

    return result;
}
