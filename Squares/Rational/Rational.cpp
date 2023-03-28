#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Rational.h"

int GCD(int a, int b) {
	while (a != 0 && b != 0) {
		int x = std::min(a, b);
		int y = std::max(a, b) / std::min(a, b);
		a = std::max(a, b) - y * std::min(a, b);
		b = x;
	}
	return std::max(a, b);
}

Rational::Rational() : numerator(0), denominator(1) {};
Rational::Rational(const Rational& number) : numerator(number.numerator), denominator(number.denominator) {};
Rational::Rational(int _numerator, int _denominator) {
	if (_denominator == 0) { throw std::invalid_argument("Denominator is 0"); }
	numerator = _numerator;
	denominator = _denominator;
}

void Rational::simplifying() {
	while (GCD(numerator, denominator) > 1) {
		int x = GCD(numerator, denominator);
		numerator /= x;
		denominator /= x;
	}
}
void Rational::set_numerator(int _numerator) { numerator = _numerator; };
void Rational::set_denominator(int _denominator) {
	if (_denominator == 0) { throw std::invalid_argument("Denominator is 0"); }
	denominator = _denominator;
}
int Rational::get_numerator() const { return numerator; }
int Rational::get_denominator() const { return denominator; }
void Rational::print() const {
	if (numerator != 0) {
		printf_s("%d/%d", numerator, denominator);
	}
	else { std::cout << 0; }

}

Rational Rational::addition(const Rational& num_2) const {
	Rational result;
	result.numerator = this->numerator * num_2.denominator + num_2.numerator * this->denominator;
	result.denominator = this->denominator * num_2.denominator;
	result.simplifying();
	return result;
}
Rational Rational::addition(const int& num_2) const {
	Rational _num_2(num_2);
	Rational result;
	result.numerator = this->numerator * _num_2.denominator + _num_2.numerator * this->denominator;
	result.denominator = this->denominator * _num_2.denominator;
	result.simplifying();
	return result;
}
Rational Rational::operator+(const Rational& num_2) const {
	return this->addition(num_2);
};
Rational Rational::operator+(const int& num_2) const {
	return this->addition(num_2);
};

Rational Rational::difference(const Rational& num_2) const {
	Rational result;
	result.numerator = this->numerator * num_2.denominator - num_2.numerator * this->denominator;
	result.denominator = this->denominator * num_2.denominator;
	result.simplifying();
	return result;
}
Rational Rational::difference(const int& num_2) const {
	Rational _num_2(num_2);
	Rational result;
	result.numerator = this->numerator * _num_2.denominator - _num_2.numerator * this->denominator;
	result.denominator = this->denominator * _num_2.denominator;
	result.simplifying();
	return result;
}
Rational Rational::operator-(const Rational& num_2) const {
	return this->difference(num_2);
}
Rational Rational::operator-(const int& num_2) const {
	return this->difference(num_2);
}

Rational Rational::multiplication(const Rational& num_2)  const{
	Rational result;
	result.numerator = this->numerator * num_2.numerator;
	result.denominator = this->denominator * num_2.denominator;
	result.simplifying();
	return result;
}
Rational Rational::multiplication(const int& num_2) const {
	Rational _num_2(num_2);
	Rational result;
	result.numerator = this->numerator * _num_2.numerator;
	result.denominator = this->denominator * _num_2.denominator;
	result.simplifying();
	return result;
}
Rational Rational::operator*(const Rational& num_2) const {
	return this->multiplication(num_2);
}
Rational Rational::operator*(const int& num_2) const {
	return this->multiplication(num_2);
}

Rational Rational::division(const Rational& num_2) const {
	if (num_2.numerator == 0) { throw std::invalid_argument("Division on zero"); }
	Rational result;
	result.numerator = this->numerator * num_2.denominator;
	result.denominator = this->denominator * num_2.numerator;
	result.simplifying();
	return result;
}
Rational Rational::division(const int& _num_2) const {
	if (_num_2 == 0) { throw std::invalid_argument("Division on zero"); }
	Rational num_2(_num_2);
	Rational result;
	result.numerator = this->numerator * num_2.denominator;
	result.denominator = this->denominator * num_2.numerator;
	result.simplifying();
	return result;
}
Rational Rational::operator/(const Rational& num_2) const {
	return this->division(num_2);
};
Rational Rational::operator/(const int& num_2) const {
	return this->division(num_2);
};