#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

void ScalarConverter::convert(const std::string& literal)
{
	std::cout << "char: ";
	try
	{
		char c = static_cast<char>(std::stoi(literal));
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	try
	{
		int i = std::stoi(literal);
		std::cout << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try
	{
		float f = std::stof(literal);
		std::cout << f << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try
	{
		double d = std::stod(literal);
		std::cout << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}
