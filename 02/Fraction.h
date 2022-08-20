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

	Fraction operator + (const Fraction& other) const;
	Fraction operator - (const Fraction& other) const;
	Fraction operator * (const Fraction& other) const;
	Fraction operator / (const Fraction& other) const;
	Fraction& operator ++ ();
	Fraction operator ++ (int i);
	Fraction& operator -- ();
	Fraction operator -- (int i);
	Fraction operator - () const;

private:
	Fraction& Reduction();
	int euclid_gcd(int a, int b);
};

