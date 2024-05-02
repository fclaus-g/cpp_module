/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:55 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/02 20:28:22 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/*Constructor predeterminado*/
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*Constructor num entero*/
Fixed::Fixed(int const value) : _value(value)
{
	std::cout << "Int constructor called" << std::endl;
}

/*Constructor num flotante*/
Fixed::Fixed(float const value) : _value(value)
{
	std::cout << "Float constructor called" << std::endl;
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
	return (float)_value;
}

int		Fixed::toInt( void ) const
{
	return _value;
}

std::ostream	&operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}
