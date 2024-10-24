#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs)
{
	if (this != &rhs)
		*this = rhs;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

int ScalarConverter::getType(const std::string& literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
		 literal == "-inf" || literal == "+inf" || literal == "nan" || literal == "inf")
		return SPECIAL;
	if (literal.size() > 11)
	 	return UNDEFINED;
	if (literal.size() == 1 && ((literal[0] >= 32 && literal[0] < 48) || (literal[0] > 57 && literal[0] < 126)))
		return CHAR;
	char *endptr;
	strtol(literal.c_str(), &endptr, 10);
	if (*endptr == '\0')
		return INT;
	strtod(literal.c_str(), &endptr);
	if (*endptr == 'f' && *(endptr + 1) == '\0')
		return FLOAT;
	strtod(literal.c_str(), &endptr);
	if (*endptr == '\0')
		return DOUBLE;
	return UNDEFINED;
}

void ScalarConverter::converToChar(const std::string& literal)
{
	char c = literal[0];

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertToInt(const std::string& literal)
{
	long value = std::strtol(literal.c_str(), NULL, 10);
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << "char: overflow" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
	}
	int i = static_cast<int>(value);
	std::cout << "char: ";
	if (isprint(i))
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (i >= std::numeric_limits<float>::min() && i <= std::numeric_limits<float>::max())
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (i >= std::numeric_limits<double>::min() && i <= std::numeric_limits<double>::max())
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::convertToFloat(const std::string& literal)
{
	float f = std::strtof(literal.c_str(), NULL);
	if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
	{
		std::cout << "char: overflow" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
	}
	std::cout << "char: ";
	if (isprint(f))
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		std::cout << static_cast<int>(f) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (f >= std::numeric_limits<float>::min() && f <= std::numeric_limits<float>::max())
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	else
		std::cout << "imposible" <<std::endl;
	if (f >= std::numeric_limits<double>::min() && f <= std::numeric_limits<double>::max())
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::convertToDouble(const std::string& literal)
{
	double d = std::strtod(literal.c_str(), NULL);
	if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
	{
		std::cout << "char: overflow" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
	}
	std::cout << "char: ";
	if (isprint(d))
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << static_cast<int>(d) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max())
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "imposible" <<std::endl;
	if (d >= std::numeric_limits<double>::min() && d <= std::numeric_limits<double>::max())
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string& literal)
{
	int type = getType(literal);
	switch (type)
	{
		case CHAR:
			converToChar(literal);
			break;
		case INT:
			convertToInt(literal);
			break;
		case FLOAT:
			convertToFloat(literal);
			break;
		case DOUBLE:
			convertToDouble(literal);
			break;
		case SPECIAL:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (literal == "-inf" || literal == "+inf")
				std::cout << "float: " << literal.substr(0, literal.size() - 1) << "f" << std::endl;
			else
			std::cout << "float: " << literal <<  std::endl;
			if (literal == "-inff" || literal == "+inff" || literal == "nanf")
				std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
			else
			std::cout << "double: " << literal << std::endl;
			break;
		case UNDEFINED:
			std::cout << "impossible" << std::endl;
			break;
	}
}
