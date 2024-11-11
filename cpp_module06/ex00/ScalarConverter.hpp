/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:44:05 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/11 09:44:07 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cmath>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIALD,
	SPECIALF,
	UNDEFINED
} t_type;

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &rhs);
		static int	getType(const std::string& literal);
		static void	converToChar(const std::string& literal);
		static void	convertToInt(const std::string& literal);
		static void	convertToFloat(const std::string& literal);
		static void	convertToDouble(const std::string& literal);

	public:
		static void	convert(const std::string& literal);

};

#endif