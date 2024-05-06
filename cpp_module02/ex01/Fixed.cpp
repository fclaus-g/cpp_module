/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:55 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/06 19:37:40 by fclaus-g         ###   ########.fr       */
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
	std::cout << "Copy assignment operator called" << std::endl;
	if (this!= &copy)
		this->_value = copy.getRawBits();
	return *this;
}

/*Getter de _value*/
int		Fixed::getRawBits( void ) const
{
	return this->_value;
}

/*Setter de _value*/
void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

/*Conversor a float
Retornamos a float dividiendo el valor por el resultado de la operación de desplazamiento de bits,
es equivalente a elevar 2 a la potencia de this->_bits. */
float	Fixed::toFloat( void ) const
{
	return (float)this->_value / (1 << this->_bits);
}

/*Conversor a int 
Desplaza a la derecha el num de posiciones de this->_bits*/
int		Fixed::toInt( void ) const
{
	return this->_value >> this->_bits;
}

/*Sobrecarga del operador de salida
Convierte el valor de objeto Fixed a float utilizando el método toFloat y lo envia 
al stream(secuencia de datos que se mueven de un lugar a otro) de salida out*/
std::ostream	&operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}
