#include "Fraction.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>


Fraction* SetArrayFromFile (std::fstream& infile, int* size)
{
    struct DataList
    {
    	int numerator;
    	int denominator;
    	DataList* ptr;
    };
    bool flag=true;
    DataList* head = new(std::nothrow) DataList, *cur = head;
    if (head == NULL)
    {
    	std::cerr << "Can't allocate "<<sizeof(DataList)<<" bytes of memory." << std::endl;
    	return NULL;
    }
    *size = 0;
    while (infile.good())
    {
    	cur->ptr = NULL;
    	infile >> cur->numerator;
    	char slash;
    	infile >> slash;
        infile >> cur->denominator;
    	(*size)++;
    	cur->ptr = new(std::nothrow) DataList;
    	cur = cur->ptr;
    	if (cur == NULL)
    	{
    		std::cerr << "Can't allocate "<<sizeof(DataList)<<" bytes of memory." << std::endl;
    		return NULL;
    	}
    }
    delete cur;
    (*size)--;
    cur = head;
    Fraction* Fraction_array = new(std::nothrow) Fraction[*size];
    for (int iter=0; iter<*size; iter++)
    {
    	Fraction_array[iter].set_Fraction (cur->numerator, cur->denominator);
    	head = cur;
    	cur = cur->ptr;
    	delete head;
    }
    return Fraction_array;
}
void print_Fraction_array (Fraction* Fraction_array, int size)
{
    for (int iter=0; iter<size; iter++)
        std::cout << Fraction_array[iter] << std::endl;
}
void task_proceeding (Fraction* Fraction_array, int size)
{
    /*функция, которая изменяет каждый элемент массива с четным индексом
путем добавления следующего за ним элемента массива.*/
    if (size%2 == 1)
        size--;
    for (int iter=0; iter<size; iter+=2)
        Fraction_array[iter]+=Fraction_array[iter+1];

}
