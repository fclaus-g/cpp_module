/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:43:52 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/11 09:43:56 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cfloat>

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
	if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "inff" || literal == "+nanf")
		return SPECIALF;
	if ( literal == "-inf" || literal == "+inf" || literal == "nan" || literal == "inf" || literal == "+nan")
		return SPECIALD;
	if (literal == "-nan" || literal == "-nanf")
		return UNDEFINED;
	// if (literal.size() > 11)
	//  	return UNDEFINED;
	if (literal.size() == 1 && ((literal[0] >= 32 && literal[0] < 48) || (literal[0] > 57 && literal[0] < 126)))
		return CHAR;
	char *endptr;
	strtol(literal.c_str(), &endptr, 10);
	if (*endptr == '\0')
		return INT;
	strtof(literal.c_str(), &endptr);
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
	if (value < INT_MIN || value > INT_MAX)
	{
		std::cout << "char: overflow" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
	}
	int i = static_cast<int>(value);
	std::cout << "char: ";
	if (i >= CHAR_MIN && i <= CHAR_MAX && isprint(i))
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
		if (i >= -FLT_MAX && i <= FLT_MAX)
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (i >= -DBL_MAX && i <= DBL_MAX)
		std::cout << "double: " << static_cast<double>(i) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::convertToFloat(const std::string& literal)
{
	float f = std::strtof(literal.c_str(), NULL);
	if (f < FLT_MIN || f > FLT_MAX)
	{
		std::cout << "char: overflow" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
	}
	std::cout << "char: ";
	if (f >= CHAR_MIN && f <= CHAR_MAX && isprint(f))
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (f >= FLT_MIN && f <= FLT_MAX)
		std::cout << static_cast<int>(f) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if (f >= FLT_MIN && f <= FLT_MAX)
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	else
		std::cout << "imposible" <<std::endl;
	if (f >= DBL_MIN && f <= DBL_MAX)
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::convertToDouble(const std::string& literal)
{
	double d = std::strtod(literal.c_str(), NULL);
	if (d < DBL_MIN || d > DBL_MAX)
	{
		std::cout << "char: overflow" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
	}
	std::cout << "char: ";
	if (d >= CHAR_MIN && d <= CHAR_MAX && isprint(d))
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << static_cast<int>(d) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if (d >= FLT_MIN && d <= FLT_MAX)
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "imposible" <<std::endl;
	if (d >= DBL_MIN && d <= DBL_MAX)
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
		case SPECIALF:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (literal == "-inf" || literal == "+inf")
				std::cout << "float: " << literal.substr(0, literal.size() - 1) << "f" << std::endl;
			else
				std::cout << "float: " << literal <<  std::endl;
			std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
			break;
		case SPECIALD:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (literal == "-inf" || literal == "+inf")
				std::cout << "float: " << literal.substr(0, literal.size() - 1) << "f" << std::endl;
			else
				std::cout << "float: " << literal <<  std::endl;
			std::cout << "double: " << literal << std::endl;
			break;
		case UNDEFINED:
			std::cout << "Invalid conversion" << std::endl;
			break;
	}
}
