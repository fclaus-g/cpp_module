/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:55 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/03 12:08:08 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/*Constructor predeterminado*/
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*Constructor num entero*/
/*Convierte un int a su valor de punto fijo para ello desplazamos
el num entero 8 bits a la izquierda*/
Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _bits;
}

/*Constructor num flotante*/
/*Convierte un float a su valor de punto fijo para ello multiplicamos
el num flotante por 2^bit y redondeamos*/
Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << _bits));
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
	if (this!= &copy)
		this->_value = copy.getRawBits();
	return *this;
}

/*Getter de _value*/
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

/*Setter de _value*/
void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (float)this->_value / (1 << this->_bits);
}

int		Fixed::toInt( void ) const
{
	return this->_value >> this->_bits;
}

std::ostream	&operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}
