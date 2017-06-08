#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

using namespace std;

struct Complex
{
	double re, im;
};

// сложение
Complex add(Complex a, Complex b)
{
	Complex result;
	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return result;
}
// вычитание
Complex sub(Complex a, Complex b)
{
	Complex result;
	result.re = a.re - b.re;
	result.im = a.im - b.im;
	return result;
}

#endif