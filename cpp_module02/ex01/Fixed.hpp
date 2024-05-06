/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:52 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/06 10:45:24 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
 
 class Fixed{
	
	private:
		int					_value;
		static const int	_bits = 8;
	
	public:
		Fixed();
		Fixed(int const value);//constructor que toma un número entero constante como parámetro
		Fixed(float const value);//constructor que toma un número de coma flotante constante como parámetro
		Fixed(const Fixed &copy);//constructor de copias
		~Fixed();

		/*Operadores >|>=|<|<=|!=|==*/
		bool	operator>(const Fixed &value) const;
		bool	operator>=(const Fixed &value) const;
		bool	operator<(const Fixed &value) const;
		bool	operator<=(const Fixed &value) const;
		bool	operator!=(const Fixed &value) const;
		bool	operator==(const Fixed &value) const;

		/*Operadores =|+|-|*|/*/
		Fixed	&operator=(const Fixed &copy);//sobrecarga del operador de asignación de copia
		Fixed	operator+(const Fixed &value) const;//sobrecarga del operador de suma
		Fixed	operator-(const Fixed &value) const;//sobrecarga del operador de resta
		Fixed	operator*(const Fixed &value) const;//sobrecarga del operador de multiplicación
		Fixed	operator/(const Fixed &value) const;//sobrecarga del operador de división

		/*Operadores ++a|a++|--a|a--*/
		Fixed	&operator++(void);//sobrecarga del operador de preincremento
		Fixed	operator++(int);//sobrecarga del operador de postincremento
		Fixed	&operator--(void);//sobrecarga del operador de predecremento
		Fixed	operator--(int);//sobrecarga del operador de postdecremento

		/*Funciones miembro*/
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;//convierte el valor de punto fijo en un valor de punto flotante
		int		toInt( void ) const;//convierte el valor de punto fijo en un valor entero
		
		/*Funciones miembro estáticas*/
		static Fixed	&min(Fixed &a, Fixed &b);//toma como parámetros dos referencias a números de punto fijo y devuelve una referencia al más pequeño
		static Fixed	&min(Fixed const &a, Fixed const &b);//toma como parámetros dos referencias a números de punto fijo constantes y devuelve una referencia al más pequeño
		static Fixed	&max(Fixed &a, Fixed &b);//toma como parámetros dos referencias a números de punto fijo y devuelve una referencia al mayor
		static Fixed	&max(Fixed const &a, Fixed const &b);//toma como parámetros dos referencias a números de punto fijo constantes y devuelve una referencia al mayor
};

std::ostream	&operator<<(std::ostream &out, Fixed const &value);//sobrecarga del operador de inserción («) que inserta una representación de punto flotante del número de punto fijo en el objeto de flujo de salida pasado como parámetro

#endif
