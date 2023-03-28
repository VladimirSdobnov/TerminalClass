#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class Rational {
private:
	int numerator;
	int denominator;
public:
	Rational();
	Rational(const Rational& number);
	Rational(int _numerator, int _denominator = 1);

	Rational addition( const Rational& num_2) const;
	Rational addition(const int& _num_2) const;
	Rational operator+(const Rational& num_2) const;
	Rational operator+(const int& num_2) const;

	Rational difference(const Rational& num_2) const;
	Rational difference(const int& num_2) const;
	Rational operator-(const Rational& num_2) const;
	Rational operator-(const int& num_2) const;

	Rational multiplication(const Rational& num_2) const;
	Rational multiplication(const int& num_2) const;
	Rational operator*(const Rational& num_2) const;
	Rational operator*(const int& num_2) const;

	Rational division(const Rational& num_2) const;
	Rational division(const int& _num_2) const;
	Rational operator/(const Rational& num_2) const;
	Rational operator/(const int& num_2) const;


	void simplifying();
	void set_numerator(int _numerator);
	void set_denominator(int _denominator);
	int get_numerator() const;
	int get_denominator() const;
	void print() const;
};
