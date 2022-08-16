#include <iostream>
#include <stdexcept>
#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
	if (!denominator) {throw(std::logic_error("The denominator cannot be zero"));}
	numerator_ = numerator;
	denominator_ = denominator;
}

std::string Fraction::GetValueFraction()
{
	if (numerator_) {
		if (numerator_ == denominator_) { return "1";}
		else { return std::to_string(numerator_) + "/" + std::to_string(denominator_);}
	}
	else {return "0";}
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
	return (static_cast<double>(numerator_)/denominator_ > static_cast<double>(other.numerator_) / other.denominator_);
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