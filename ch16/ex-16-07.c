/* C Programming A Modern Approach
 * ex-16-07.c
 * 2016-03-30
 *
 * Assume that the fraction structure contains two members: numerator
 * and denominator (both of type int). Write function that perform
 * the following operations on fractions:
 *
 * (a) Reduce the fraction f to lowest terms. Hint: To reduce a
 * fraction to lowest terms, first compute the greatest common divisor (GCD)
 * of the numerator and denominator. Then divide both the numerator
 * and denominator by the GCD.
 *
 * (b) Add the fractions f1 and f2.
 *
 * (c) Substract the fraction f2 from the fraction f1.
 *
 * (d) Multiply the fractions f1 and f2.
 *
 * (e) Divide the faction f1 by the fraction f2.
 *
 * The fraction f, f1 and f2 will be arguments of type struct fraction;
 * each function will return a value of type struct fraction. The fractions
 * returned by the function in parts (b) - (3) should be reduced to lower
 * terms. Hint: You may use the function from part (a) to help write the
 * functions in parts (b) - (e).
 */

/// My Answer:
#include <stdio.h>

typedef struct {
    int numerator, denominator;
} Fraction;

int gcd(int a, int b);
Fraction lowest(Fraction f); // (a)
Fraction add_fraction(Fraction f1, Fraction f2); // (b)
Fraction sub_fraction(Fraction f1, Fraction f2); // (c)
Fraction multi_fraction(Fraction f1, Fraction f2); // (d)
Fraction div_fraction(Fraction f1, Fraction f2); // (e)

int main(void)
{
    Fraction f = { 90, 126 };
    Fraction f1 = { 9, 12 };
    Fraction f2 = { 6, 24 };
    Fraction low, add, sub, multi, div;

    low = lowest(f);
    add = add_fraction(f1, f2);
    sub = sub_fraction(f1, f2);
    multi = multi_fraction(f1, f2);
    div = div_fraction(f1, f2);

    printf("Lowest term of %d/%d : %d/%d\n", f.numerator, f.denominator,
        low.numerator, low.denominator);
    printf("%d/%d + %d/%d = %d/%d\n", f1.numerator, f1.denominator,
        f2.numerator, f2.denominator, add.numerator, add.denominator);
    printf("%d/%d - %d/%d = %d/%d\n", f1.numerator, f1.denominator,
        f2.numerator, f2.denominator, sub.numerator, sub.denominator);
    printf("%d/%d * %d/%d = %d/%d\n", f1.numerator, f1.denominator,
        f2.numerator, f2.denominator, multi.numerator, multi.denominator);
    printf("%d/%d / %d/%d = %d/%d\n", f1.numerator, f1.denominator,
        f2.numerator, f2.denominator, div.numerator, div.denominator);

    return 0;
}

int gcd(int a, int b)
{
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

Fraction lowest(Fraction f)
{
    int g;
    g = gcd(f.numerator, f.denominator);
    f.numerator /= g;
    f.denominator /= g;
    return f;
}

Fraction add_fraction(Fraction f1, Fraction f2)
{
    Fraction a;
    a.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    a.denominator = f1.denominator * f2.denominator;
    a = lowest(a);
    return a;
}

Fraction sub_fraction(Fraction f1, Fraction f2)
{
    Fraction a;
    a.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    a.denominator = f1.denominator * f2.denominator;
    a = lowest(a);
    return a;
}

Fraction multi_fraction(Fraction f1, Fraction f2)
{
    Fraction a;
    a.numerator = f1.numerator * f2.numerator;
    a.denominator = f1.denominator * f2.denominator;
    a = lowest(a);
    return a;
}

Fraction div_fraction(Fraction f1, Fraction f2)
{
    Fraction a;
    a.numerator = f1.numerator * f2.denominator;
    a.denominator = f1.denominator * f2.numerator;
    a = lowest(a);
    return a;
}
