/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:57:38 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/03 12:10:15 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*El ejercicio anterior fue un buen comienzo pero nuestra clase es bastante inútil. Sólo puede
representan el valor 0,0.
Agregue los siguientes constructores públicos y funciones miembro públicas a su clase:
• Un constructor que toma un número entero constante como parámetro.
Lo convierte al valor de punto fijo correspondiente. El valor de bits fraccionarios es
inicializado a 8 como en el ejercicio 00.
• Un constructor que toma un número de coma flotante constante como parámetro.
Lo convierte al valor de punto fijo correspondiente. El valor de bits fraccionarios es
inicializado a 8 como en el ejercicio 00.
• Una función miembro float toFloat( void ) const;
que convierte el valor de punto fijo en un valor de punto flotante.
• Una función miembro int toInt( void ) const;
que convierte el valor de punto fijo en un valor entero.
Y agregue la siguiente función a los archivos de clase fija:
• Una sobrecarga del operador de inserción («) que inserta una representación de punto flotante
del número de punto fijo en el objeto de flujo de salida pasado como parámetro.*/

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;//constructor predeterminado
	Fixed const b(10);//constructor que toma un número entero constante como parámetro
	Fixed const c(42.42f);//constructor que toma un número de coma flotante constante como parámetro
	Fixed const d(b);//constructor de copias
	
	a = Fixed(1234.4321f);
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	return 0;
}
