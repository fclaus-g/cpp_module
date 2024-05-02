/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:55 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/02 16:54:12 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/*Constructor predeterminado*/
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*Constructor de copia*/
Fixed::Fixed(const Fixed &copy) : _value(copy._value) 
{
	std::cout << "Copy constructor called" << std::endl;
}

/*Destructor*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*Sobrecarga del operador de asignación de copia*/
Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	_value = copy._value;
	return *this;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits( int const raw )
{
	_value = raw;
}
