/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:52 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/02 16:52:48 by fclaus-g         ###   ########.fr       */
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
		Fixed(const Fixed &copy);//constructor de copias
		~Fixed();
		Fixed	&operator=(const Fixed &copy);//sobrecarga del operador de asignación de copia
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
