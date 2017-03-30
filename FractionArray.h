#ifndef _FRACTION_ARRAY_H_
#define _FRACTION_ARRAY_H_
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Fraction.hpp"

Fraction* SetArrayFromFile (std::fstream& is, int* size);
void print_Fraction_array (Fraction* Fraction_array, int size);
void task_proceeding (Fraction* Fraction_Array, int size);

#endif //_FRACTION_ARRAY_H_