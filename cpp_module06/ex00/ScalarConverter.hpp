#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	UNDEFINED
} t_type;

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &rhs);
		static int getType(const std::string& literal);
		static void converToChar(const std::string& literal);
		static void convertToInt(const std::string& literal);
		static void convertToFloat(const std::string& literal);
		static void convertToDouble(const std::string& literal);

	public:
		static void convert(const std::string& literal);

};

#endif