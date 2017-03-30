#include <cstdlib>
#include <iostream>
#include "Fraction.hpp"
#include "FractionArray.h"

int main (int argc, char* argv[])
{
    if (argc!=2)
    {
        std::cout << "Not enough or too much arguments\n"
        << "Please enter name of file that contain Fraction data - \n"
        << "fractions in format:\n"
        << "[numerator]/[denominator]"
        << std::endl;
        return -1;
    }
    std::fstream infile (argv[1],  std::ios_base::in);
    if ( ! infile ) {
        std::cerr << "Error, can't open file: " << argv[1] << std::endl;
        return -2;
    }
    int size;
    Fraction* Fraction_Array = SetArrayFromFile (infile, &size);
    if (Fraction_Array==NULL)
    {
        return -3;
    }
    std::cout << "Data read:" <<std::endl;
    print_Fraction_array (Fraction_Array, size);
    task_proceeding (Fraction_Array, size);
    std::cout << "\n\nData after processing according to task:" <<std::endl;
    print_Fraction_array (Fraction_Array, size);
    return 0;
}

