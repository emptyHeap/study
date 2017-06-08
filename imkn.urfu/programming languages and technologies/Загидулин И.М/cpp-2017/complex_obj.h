#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex
{
private:
	double re, im;
public:
	
	Complex() : re(0), im(0) {}
	Complex(double x, double y)
		: re(x), im(y) {}

	double Re() { return re; }
	double Im() { return im; }

	Complex add(Complex b)
	{
		return Complex(re + b.re, im + b.im);
	}

	Complex sub(Complex b)
	{
		return Complex(this->re - b.re, this->im - b.im);
	}
};

#endif