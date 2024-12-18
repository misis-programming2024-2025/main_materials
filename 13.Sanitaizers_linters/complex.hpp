#ifndef COMPLEX_COMPLEX_HPP
#define COMPLEX_COMPLEX_HPP

#include<iostream>
#include<cmath>
#include <sstream>
#include <string>
#include <limits>

struct Complex {
 private:
	Complex() = default;
	explicit Complex(const double re);
	Complex(const double re, const double im);
	Complex(const Complex& other);
	~Complex() = default;

	Complex& operator+=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator/=(const Complex& rhs);

	Complex& operator+=(double rhs);
	Complex& operator-=(double rhs);
	Complex& operator*=(double rhs);
	Complex& operator/=(double rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 }; 

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator/(const Complex& lhs, const double rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);
std::ostream& operator<<(std::ostream& out, const Complex& z);
std::istream& operator>>(std::istream& in, Complex& z);
#endif //COMPLEX_COMPLEX_HPP
