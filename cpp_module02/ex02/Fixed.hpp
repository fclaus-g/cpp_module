/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:52 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/02 17:29:42 by fclaus-g         ###   ########.fr       */
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
		Fixed	&operator=(const Fixed &copy);//sobrecarga del operador de asignación de copia
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;//convierte el valor de punto fijo en un valor de punto flotante
		int		toInt( void ) const;//convierte el valor de punto fijo en un valor entero
		//Pte de añadir la sobrecarga del operador de inserción («) que inserta una representación de punto flotante del número de punto fijo en el objeto de flujo de salida pasado como parámetro
};

std::ostream	&operator<<(std::ostream &out, Fixed const &value);//sobrecarga del operador de inserción («) que inserta una representación de punto flotante del número de punto fijo en el objeto de flujo de salida pasado como parámetro

#endif
