/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:57:38 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/06 10:33:12 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Agregue funciones miembro públicas a su clase para sobrecargar los siguientes operadores:
* Los 6 operadores de comparación: >, <, >=, <=, == y !=.
* Los 4 operadores aritméticos: +, -, * y /.
* Los 4 operadores de incremento/decremento (preincremento y post-incremento, pre-decremento y post-decremento), que aumentarán o disminuirán el valor de punto fijo desde el ε más pequeño representable, como 1 + ε > 1.
Agregue estas cuatro funciones miembro públicas sobrecargadas a su clase:
* Una función miembro estática min que toma como parámetros dos referencias a números de punto fijo y devuelve una referencia al más pequeño.
* Una función miembro estática min que toma como parámetros dos referencias a números de punto fijo constantes y devuelve una referencia al más pequeño.
* Una función miembro estática max que toma como parámetros dos referencias a números de punto fijo y devuelve una referencia al mayor.
* Una función miembro estática max que toma como parámetros dos referencias a números de punto fijo constantes y devuelve una referencia al mayor.*/

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}
