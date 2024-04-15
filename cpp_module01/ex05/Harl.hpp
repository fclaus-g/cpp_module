/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:49:07 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/15 17:43:47 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Tienes que crear una clase Harl con las siguientes funciones de miembros privados:
• void debug( void );
• void info( void );
• void warning( void );
• void error( void );
Harl también tiene una función miembro pública que llama a las cuatro funciones miembro anteriores.
dependiendo del nivel pasado como parámetro:
complain( std::string level );
*/
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		void complain( std::string level );
};

#endif