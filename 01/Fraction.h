#pragma once
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator);

	std::string GetValueFraction() const;

	bool operator == (const Fraction& other) const;
	bool operator != (const Fraction& other) const;
	bool operator > (const Fraction& other) const;
	bool operator < (const Fraction& other) const;
	bool operator >= (const Fraction& other) const;
	bool operator <= (const Fraction& other) const;
};

