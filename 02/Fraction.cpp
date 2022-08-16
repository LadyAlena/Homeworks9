#include <iostream>
#include <stdexcept>
#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
	if (!denominator) { throw(std::logic_error("The denominator cannot be zero")); }
	numerator_ = numerator;
	denominator_ = denominator;
}

std::string Fraction::GetValueFraction()
{
	if (numerator_) {
		if (numerator_ == denominator_) { return "1"; }
		else { return std::to_string(numerator_) + "/" + std::to_string(denominator_); }
	}
	else { return "0"; }
}

bool Fraction::operator == (const Fraction& other)
{
	return (static_cast<double>(numerator_) / denominator_ == static_cast<double>(other.numerator_) / other.denominator_);
}

bool Fraction::operator != (const Fraction& other)
{
	return !(*this == other);
}

bool Fraction::operator > (const Fraction& other)
{
	return (static_cast<double>(numerator_) / denominator_ > static_cast<double>(other.numerator_) / other.denominator_);
}

bool Fraction::operator < (const Fraction& other)
{
	return (static_cast<double>(numerator_) / denominator_ < static_cast<double>(other.numerator_) / other.denominator_);
}

bool Fraction::operator >= (const Fraction& other)
{
	return !(*this < other);
}

bool Fraction::operator <= (const Fraction& other)
{
	return !(*this > other);
}

Fraction& Fraction::Reduction()
{
	if (numerator_) {
		int NOD = 0;

		NOD = (numerator_ < 0 && denominator_ < 0) ? -euclid_gcd(-numerator_, -denominator_) :
			(numerator_ < 0 ? euclid_gcd(-numerator_, denominator_) :
				(denominator_ < 0 ? -euclid_gcd(numerator_, -denominator_) :
					euclid_gcd(numerator_, denominator_)));

		numerator_ /= NOD;
		denominator_ /= NOD;
	}

	return *this;
}

Fraction Fraction::operator + (const Fraction& other)
{
	Fraction f(numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_);

	return f.Reduction();
}

Fraction Fraction::operator - (const Fraction& other)
{
	Fraction f(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_);

	return f.Reduction();
}

Fraction Fraction::operator*(const Fraction& other)
{
	Fraction f(numerator_ * other.numerator_, denominator_ * other.denominator_);

	return f.Reduction();
}

Fraction Fraction::operator / (const Fraction& other)
{
	Fraction f(numerator_ * other.denominator_, denominator_ * other.numerator_);

	return f.Reduction();
}

Fraction& Fraction::operator++()
{
	numerator_ += denominator_;

	return (*this).Reduction();
}

Fraction Fraction::operator++(int i)
{
	Fraction temp(*this);

	numerator_ += denominator_;

	return temp.Reduction();

}

Fraction& Fraction::operator--()
{
	numerator_ -= denominator_;

	return (*this).Reduction();
}

Fraction Fraction::operator--(int i)
{
	Fraction temp(*this);

	numerator_ -= denominator_;

	return temp.Reduction();
}

Fraction& Fraction::operator-()
{
	Reduction();
	numerator_ = -numerator_;

	return (*this);
}

int Fraction::euclid_gcd(int a, int b)
{   // Алгоритм Евклида поиска НОД
	while (a != b) {
		if (a > b) { a -= b; }
		else { b -= a; }
	}
	return a;
}