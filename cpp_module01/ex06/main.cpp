/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:36:26 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/17 13:00:59 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A veces no quieres prestar atención a todo lo que dice Harl. Implementar un
sistema para filtrar lo que dice Harl dependiendo de los niveles de registro que desee escuchar.
Cree un programa que tome como parámetro uno de los cuatro niveles. Se mostrará todo
mensajes de este nivel y superiores. Por ejemplo:
$> ./harlFilter "ADVERTENCIA"
[ ADVERTENCIA ]
Creo que merezco tener un poco de tocino extra gratis.
Llevo viniendo desde hace años mientras que tú empezaste a trabajar aquí desde el mes pasado.
[ ERROR ]
Esto es inaceptable, quiero hablar con el gerente ahora.
$> ./harlFilter "No estoy seguro de lo cansado que estoy hoy..."
[Probablemente quejándose de problemas insignificantes]
Aunque hay varias formas de lidiar con Harl, una de las más efectivas es
Apágalo.
Asigne el nombre harlFilter a su ejecutable.
Debe utilizar, y tal vez descubrir, la declaración de cambio en este ejercicio.*/

#include "Harl.hpp"

int main(int ac, char **av) 
{
	Harl 		harl;

	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter [DEBUG, INFO, WARNING, ERROR]" << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}