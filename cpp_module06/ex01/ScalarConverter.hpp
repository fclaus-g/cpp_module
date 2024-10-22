#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
 
#define DIGITS "0123456789"

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
} t_type;

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &rhs);

	public:
		static void convert(const std::string& literal);

};

#endif