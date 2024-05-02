/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:45 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/02 16:51:28 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Cree una clase en forma canónica ortodoxa que represente un número de punto fijo: • Miembros privados:
* Un número entero para almacenar el valor del número de punto fijo.
* Un entero constante estático para almacenar el número de bits fraccionarios. Es valioso
siempre será el literal entero 8. • Miembros públicos:
* Un constructor predeterminado que inicializa el valor numérico de punto fijo en 0.
* Un constructor de copias.
* Una sobrecarga del operador de asignación de copia.
* Un destructor.
* Una función miembro int getRawBits( void ) const; que devuelve el valor bruto del valor de punto fijo.
* Una función miembro void setRawBits( int const raw ); que establece el valor bruto del número de punto fijo.
*/
#include "Fixed.hpp"

int main( void ) 
{
	Fixed	a;
  	Fixed	b(a);
  	Fixed	c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
return 0; 
}