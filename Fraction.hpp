#ifndef _FRACTION_HPP_
#define _FRACTION_HPP_

#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <fstream>

class Fraction
{
public:
	Fraction();
	Fraction(int numerator, int denominator = 1);
	Fraction(char* fraction_in_string);
	Fraction(double decimal);
	~Fraction();

	void solve_to_gcd ();
	/*math operators with fractions*/
	Fraction& operator+=(const Fraction& rhs);
	Fraction& operator-=(const Fraction& rhs);
	Fraction& operator/=(const Fraction& rhs);			
	Fraction& operator*=(const Fraction& rhs);
	Fraction& operator=(const Fraction& rhs); 
	Fraction& operator+(const Fraction& rhs) const; 
	Fraction& operator-(const Fraction& rhs) const; 
	Fraction& operator/(const Fraction& rhs) const; 	
	Fraction& operator*(const Fraction& rhs) const; 
	operator bool() const;
	operator double() const;
 
	/*setters*/
	void set_numerator (int numerator);
	void set_denominator (int denominator);
	void set_sign (bool is_positive);
	void set_sign (int int_to_set_sign);
	void set_sign (char sign);
	void set_Fraction (int numerator, int denominator = 1);
	void set_Fraction (double);
	void set_Fraction (char*);

	/*getters*/
	double get_Fraction_as_decimal () const;
	int get_numerator () const;
	int get_denominator () const;
	int get_sign () const;
	int sign () const;
	bool is_positive () const;
	bool is_negative () const;
	bool is_whole () const;
	bool is_common () const;

	/*show-s*/
	void show_Fraction () const;
	void show_as_decimal () const;
	void show_numerator () const;
	void show_denominator () const;
	void show_sign () const;

	/* data */
private:
	int numerator;//also stores sign
	int denominator;
};

std::ostream& operator << (std::ostream& os, const Fraction& obj);

int gcd (int v1, int v2); //greatest common divisor




#endif //_FRACTION_HPP_















































/*
*DRAFT*
*THINGS TO IMPROVE*
OTHER TYPES OPERATIONS


/*math operators with [operand]* /
	/*int* /
	Fraction& operator=(const int new_numerator);
	Fraction& operator+(const int sum_numerator);
	Fraction& operator-(const int sub_numerator);
	Fraction& operator/(const int div_numerator);	
	Fraction& operator*(const int multiplier);
	/*double* /
	Fraction& operator=(const double new_decimal);
	Fraction& operator+(const double sum_numerator);
	Fraction& operator-(const double sub_numerator);
	Fraction& operator/(const double div_numerator);	
	Fraction& operator*(const double multiplier);

/*logical operations with [operand]* /
	/*int* /
	bool operator==(const &Fraction to_cmp, const int cmp_numerator);
	bool operator>=(const &Fraction to_cmp, const int cmp_numerator);
	bool operator<=(const &Fraction to_cmp, const int cmp_numerator);
	bool operator>(const &Fraction to_cmp, const int cmp_numerator);
	bool operator<(const &Fraction to_cmp, const int cmp_numerator);
		/*double* /
	bool operator==(const &Fraction to_cmp, const double cmp_decimal);
	bool operator>=(const &Fraction to_cmp, const double cmp_decimal);
	bool operator<=(const &Fraction to_cmp, const double cmp_decimal);
	bool operator>(const &Fraction to_cmp, const double cmp_decimal);
	bool operator<(const &Fraction to_cmp, const double cmp_decimal);

	/*logical operators with fraction* /
	bool operator==(const &Fraction rhs);
	bool operator>=(const &Fraction rhs);
	bool operator<=(const &Fraction rhs);
	bool operator>(const &Fraction rhs);
	bool operator<(const &Fraction rhs);
*/