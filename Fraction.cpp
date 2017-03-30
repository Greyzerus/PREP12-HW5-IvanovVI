#include "Fraction.hpp"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

Fraction::~Fraction() {}
Fraction::Fraction () :
	denominator (1)
{}

Fraction::Fraction (int numerator, int denominator) :
denominator (1)
{
	this->numerator = numerator;
	this->denominator = denominator;
	this->solve_to_gcd();
}
Fraction::Fraction (char* fraction_in_string) :
	denominator(1)
{
	int numerator = 0, denominator = 0;
	numerator = atoi (fraction_in_string);
	char* denominator_in_string = strstr (fraction_in_string, "/");
	denominator = atoi (denominator_in_string);
	this->numerator = numerator;
	this->denominator = (denominator!=0) ? denominator : 1;
	this->solve_to_gcd();
}
Fraction::Fraction (double decimal) :
	numerator (0),
	denominator (1)
{
	double numerator, fractional;
	fractional = modf (decimal, &numerator);
	int denominator = 1;
	double trash;
	while (modf (fractional, &trash))
	{
		denominator*=10;
		fractional*=10;
	}
	this->numerator =(int) numerator*denominator + fractional;
	this->denominator = denominator;
	this->solve_to_gcd();
}

/*math operators with fractions*/
Fraction& Fraction::operator+=(const Fraction& rhs)
{
	this->numerator *= rhs.denominator;
	this->numerator += rhs.numerator * this->denominator;
	this->denominator *= rhs.denominator;
	this->solve_to_gcd();
	return *this;
}

void Fraction::solve_to_gcd ()
{
    if (this->denominator == 0) this->denominator = 1;
    if (this->denominator<0)
	{
		this->numerator*=-1;
		this->denominator*=-1;
	}
	int t_gcd = gcd (this->numerator, this->denominator);
	this->numerator/=t_gcd;
	this->denominator/=t_gcd;
}

Fraction& Fraction::operator-=(const Fraction& rhs)
{
	this->numerator *= rhs.denominator;
	this->numerator -= rhs.numerator * this->denominator;
	this->denominator *= rhs.denominator;
	this->solve_to_gcd();
	return *this;
}
Fraction& Fraction::operator/=(const Fraction& rhs)
{
	this->numerator *= rhs.denominator;
	this->denominator *= rhs.numerator;
	this->solve_to_gcd();
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& rhs)
{
	this->numerator *= rhs.numerator;
	this->denominator *= rhs.denominator;
	this->solve_to_gcd();
	return *this;
}
Fraction& Fraction::operator=(const Fraction& rhs)
{
	this->numerator = rhs.numerator;
	this->denominator = rhs.denominator;
	this->solve_to_gcd();
	return *this;
}
Fraction& Fraction::operator+(const Fraction& rhs) const
{
	int numerator = this->numerator;
	numerator *= rhs.denominator;
	numerator += rhs.numerator * this->denominator;
	int denominator = this->denominator * rhs.denominator;
	Fraction *temp = new Fraction(numerator, denominator);
	temp->solve_to_gcd();
	return *temp;
}
Fraction& Fraction::operator-(const Fraction& rhs) const
{
	int numerator = this->numerator;
	numerator *= rhs.denominator;
	numerator -= rhs.numerator * this->denominator;
	int denominator = this->denominator * rhs.denominator;
	Fraction *temp = new Fraction(numerator, denominator);
	temp->solve_to_gcd();
	return *temp;
}
Fraction& Fraction::operator/(const Fraction& rhs) const
{
	int numerator = this->numerator * rhs.denominator;
	int denominator = this->denominator * rhs.numerator;
	Fraction *temp = new Fraction(numerator, denominator);
	temp->solve_to_gcd();
	return *temp;
}
Fraction& Fraction::operator*(const Fraction& rhs) const
{
	int numerator = this->numerator * rhs.numerator;
	int denominator = this->denominator * rhs.denominator;
	Fraction *temp = new Fraction(numerator, denominator);
	temp->solve_to_gcd();
	return *temp;
}
Fraction::operator bool() const
{
	return (this->get_numerator() != 0) ? 1 : 0;
}
Fraction::operator double() const
{
	return ((double) this->numerator / this->denominator );
}

/*setters*/
void Fraction::set_numerator (int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator (int denominator)
{
	this->denominator = denominator;
}
void Fraction::set_sign (bool is_positive)
{
	if (is_positive)
	{
		if(this->numerator < 0)
			this->numerator*=-1;
	}
	else
	{
		if(this->numerator > 0)
			this->numerator*=-1;
	}
}
void Fraction::set_sign (int int_to_set_sign)
{
	if (int_to_set_sign <0)
	{
		numerator*=-1;
	}
}
void Fraction::set_sign (char sign)
{
	if (sign == '+')
	{
		if(this->numerator < 0)
			this->numerator*=-1;
	}
	else if (sign == '-')
	{
		if(this->numerator > 0)
			this->numerator*=-1;
	}
}
void Fraction::set_Fraction (int numerator, int denominator /*= 1*/)
{
	this->numerator = numerator;
	this->denominator = denominator;
	this->solve_to_gcd();
}
void Fraction::set_Fraction (double decimal)
{
	double numerator, fractional;
	fractional = modf (decimal, &numerator);
	int denominator = 1;
	double trash;
	while (modf (fractional, &trash))
	{
		denominator*=10;
		fractional*=10;
	}
	this->numerator =(int) numerator*denominator + fractional;
	this->denominator = denominator;
	this->solve_to_gcd();
}
void Fraction::set_Fraction (char* fraction_in_string)
{
	int numerator = 0, denominator = 0;
	numerator = atoi (fraction_in_string);
	char* denominator_in_string = strstr (fraction_in_string, "/");
	denominator = atoi (denominator_in_string);
	this->numerator = numerator;
	this->denominator = (denominator!=0) ? denominator : 1;
	this->solve_to_gcd();
}


/*getters*/
double Fraction::get_Fraction_as_decimal () const
{
	return (double) this->numerator / this->denominator;
}
int Fraction::get_numerator () const
{
	return this->numerator;
}
int Fraction::get_denominator () const
{
	return this->denominator;
}
int Fraction::get_sign () const
{
	return this->numerator < 0 ? -1 : 1;
}
int Fraction::sign () const
{
	return this->get_sign();
}
bool Fraction::is_positive () const
{
	return this->get_numerator() > 0;
}
bool Fraction::is_negative () const
{
	return this->get_numerator() < 0;
}
bool Fraction::is_whole () const
{
	return abs(this->numerator) > this->denominator;
}
bool Fraction::is_common () const
{
	return abs(this->numerator) < this->denominator;
}

/*show-s*/
void Fraction::show_Fraction () const
{
	std::cout << this->numerator <<'/'<< this->denominator;
}
void Fraction::show_as_decimal () const
{
	std::cout << (double)this->numerator/this->denominator;
}
void Fraction::show_numerator () const
{
	std::cout << this->numerator;
}
void Fraction::show_denominator () const
{
	std::cout << this->denominator;
}
void Fraction::show_sign () const
{
	std::cout << this->is_negative() ? '-' : '+' ;
}

std::ostream& operator << (std::ostream& os, const Fraction& obj)
{
	os << obj.get_numerator() <<'/'<< obj.get_denominator();
	return os;
}

/*Eucledian algorithm in binary*/
int gcd(int u, int v)
{
	u = abs (u);
	v = abs (v);
    int shift, t;
    if (u == 0) return v;
    if (v == 0) return u;
    for (shift = 0; ((u | v) & 1) == 0; ++shift) {
        u >>= 1;
        v >>= 1;
    }
    while ((u & 1) == 0) u >>= 1;
    do
    {
        while ((v & 1) == 0) v >>= 1;
        if (u > v) t = v, v = u, u = t;
        v = v - u;
    }
    while (v != 0);
    return u << shift;
}
