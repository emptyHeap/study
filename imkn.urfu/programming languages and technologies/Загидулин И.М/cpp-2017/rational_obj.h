#ifndef _RATIONAL_H_
#define _RATIONAL_H_

class Rational
{
private:
    int num, den;
public:
    Rational() : num(0), den(1) {}
    // опишем конструктор в другом файле
    Rational(int x, int y);
    double getNumerator() { return num; }
    double getDenominator() { return den; }

    Rational add(Rational b);

};

#endif