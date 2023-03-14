#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int GCD(int a, int b) {
	while (a != 0 && b != 0) {
		int x = std::min(a, b);
		int y = std::max(a, b) / std::min(a, b);
		a = std::max(a, b) - y * std::min(a, b);
		b = x;
	}
	return std::max(a, b);
}

class Rational {
private:
	int numerator;
	int denominator;
public:
	Rational(): numerator (0), denominator (1) {};
	Rational(Rational& number): numerator  (number.numerator), denominator (number.denominator) {}
	Rational(int _numerator, int _denominator = 1) {
		if (_denominator == 0) { throw std::invalid_argument ("Denominator is 0"); }
		numerator = _numerator;
		denominator = _denominator;
	}

	Rational addition(Rational num_2) {
		Rational result;
		result.numerator = this->numerator * num_2.denominator + num_2.numerator * this->denominator;
		result.denominator = this->denominator * num_2.denominator;
		result.simplifying();
		return result;
	}
	Rational addition(int _num_2) {
		Rational num_2(_num_2);
		Rational result;
		result.numerator = this->numerator * num_2.denominator + num_2.numerator * this->denominator;
		result.denominator = this->denominator * num_2.denominator;
		result.simplifying();
		return result;
	}

	Rational difference(Rational num_2) {
		Rational result;
		result.numerator = this->numerator * num_2.denominator - num_2.numerator * this->denominator;
		result.denominator = this->denominator * num_2.denominator;
		result.simplifying();
		return result;
	}
	Rational difference(int _num_2) {
		Rational num_2(_num_2);
		Rational result;
		result.numerator = this->numerator * num_2.denominator - num_2.numerator * this->denominator;
		result.denominator = this->denominator * num_2.denominator;
		result.simplifying();
		return result;
	}

	Rational multiplication(Rational num_2) {
		Rational result;
		result.numerator = this->numerator * num_2.numerator;
		result.denominator = this->denominator * num_2.denominator;
		result.simplifying();
		return result;
	}
	Rational multiplication(int _num_2) {
		Rational num_2(_num_2);
		Rational result;
		result.numerator = this->numerator * num_2.numerator;
		result.denominator = this->denominator * num_2.denominator;
		result.simplifying();
		return result;
	}

	Rational division(Rational num_2) {
		if (num_2.numerator == 0) { throw std::invalid_argument("Division on zero"); }
		Rational result;
		result.numerator = this->numerator * num_2.denominator;
		result.denominator = this->denominator * num_2.numerator;
		result.simplifying();
		return result;
	}
	Rational division(int _num_2) {
		if (_num_2 == 0) { throw std::invalid_argument("Division on zero"); }
		Rational num_2(_num_2);
		Rational result;
		result.numerator = this->numerator * num_2.denominator;
		result.denominator = this->denominator * num_2.numerator;
		result.simplifying();
		return result;
	}


	void simplifying() {
		while (GCD(numerator, denominator) > 1) {
			int x = GCD(numerator, denominator);
			numerator /= x;
			denominator /= x;
		}
	}

	void set_numerator(int _numerator) { numerator = _numerator; };
	void set_denominator(int _denominator) {
		if (_denominator == 0) { throw std::invalid_argument("Denominator is 0"); }
		denominator = _denominator;
	}

	int get_numerator() { return numerator; }
	int get_denominator() { return denominator; }

	void print() {
		if (numerator != 0) {
			printf_s("%d/%d", numerator, denominator);
		}
		else { std::cout << 0; }

	}
};

class RationalWithInteger : Rational {
private:
	int integer;
public:
	RationalWithInteger(): integer (0) {}
	RationalWithInteger(RationalWithInteger& num) {
		integer = num.integer;
		set_numerator(num.get_numerator());
		set_denominator(num.get_denominator());
	}
	RationalWithInteger(int _integer, Rational rational){
		convert(rational);
		integer += _integer;
	}
	RationalWithInteger(int _integer, int numerator, int denominator = 1) : Rational(numerator, denominator) {
		convert(get_numerator(), get_denominator());
		integer += _integer;
	}

	void convert(Rational x) {
		x.simplifying();
		integer = x.get_numerator() / x.get_denominator();
		set_numerator(x.get_numerator() - x.get_denominator() * integer);
		set_denominator(x.get_denominator());
	}
	void convert(int numerator, int denominator) {
		Rational x(numerator, denominator);
		x.simplifying();
		integer = x.get_numerator() / x.get_denominator();
		set_numerator(x.get_numerator() - x.get_denominator() * integer);
		set_denominator(x.get_denominator());
	}

	void print() {
		if (integer != 0) {
			std::cout << integer << ' ';
			Rational::print();
		}
		else { Rational::print(); }
	}
};

int main() {
	Rational x(1, 3), y(2, 6), z;
	RationalWithInteger x1(0, 24, 7);
	x1.print();
	x.print();
	y.simplifying();
	y.print();
	x.addition(y);
	z.print();
}