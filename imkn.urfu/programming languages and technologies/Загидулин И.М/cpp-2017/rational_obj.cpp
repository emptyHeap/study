#include "rational_obj.h"
#include <iostream>

inline int abs(int val)
{
    return (val > 0) ? val : -val;
}

int NOD(int a, int b)
{
    int r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}


Rational::Rational(int x, int y)
{
    if (y == 0)
    {
        std::cerr << "Denominator is zero!" << std::endl;
    }
    int nod = NOD(abs(x), abs(y));
    num = x / nod;
    den = y / nod;
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}

// сложение
Rational Rational::add(Rational b)
{
    int n = num*b.den + den*b.num;
    int d = den * b.den;
    return Rational(n, d);
}