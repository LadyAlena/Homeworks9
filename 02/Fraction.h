#pragma once
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:

	Fraction(int numerator, int denominator);

	std::string GetValueFraction();

	bool operator == (const Fraction& other);
	bool operator != (const Fraction& other);
	bool operator > (const Fraction& other);
	bool operator < (const Fraction& other);
	bool operator >= (const Fraction& other);
	bool operator <= (const Fraction& other);

	Fraction& Reduction();
	Fraction operator + (const Fraction& other);
	Fraction operator - (const Fraction& other);
	Fraction operator * (const Fraction& other);
	Fraction operator / (const Fraction& other);
	Fraction& operator ++ ();
	Fraction operator ++ (int i);
	Fraction& operator -- ();
	Fraction operator -- (int i);
	Fraction& operator - ();


private:
	int euclid_gcd(int a, int b);
};

