/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:38:09 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/12 15:07:00 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Desarrolla una clase Span que pueda almacenar un máximo de N números enteros. N es una variable int
sin signo y será el único parámetro que se pase al constructor.
Esta clase tendrá una función miembro llamada addNumber() para agregar un solo númeroal Span. Se usará para llenarlo. Cualquier intento de agregar un nuevo elemento si ya hay N elementos almacenados debe generar una excepción.
A continuación, implementa dos funciones miembro: shortestSpan() y longestSpan()
Estas funciones encontrarán respectivamente el span más corto o el span más largo (o la distancia, si lo prefieres) entre todos los números almacenados y lo devolverán. Si no hay números almacenados,
o solo uno, no se puede encontrar ningún span. Por lo tanto, genera una excepción.
Por supuesto, escribirás tus propias pruebas y serán mucho más exhaustivas que las que se muestran a continuación. Prueba tu Span al menos con un mínimo de 10 000 números. Más sería incluso mejor.
```cpp
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
//debe mostrar
$> ./ex01
2
14
$>
```
Por último, pero no por ello menos importante, sería fantástico llenar tu Span usando un rango de iteradores.
Hacer miles de llamadas a addNumber() es muy molesto. Implementa una función miembro
para agregar muchos números a tu Span en una sola llamada.
Si no tienes idea, estudia los Contenedores. Algunas funciones miembro
toman un rango de iteradores para agregar una secuencia de
elementos al contenedor.*/
#include "span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << GRN << "Test methods" << RST << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << GRN << "Test exceptions" << RST << std::endl;
	try{
		sp.addNumber(1);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RST << std::endl;
	}
	
	std::vector<int> vec;
	for (int i = 0; i < 100; i++)
		vec.push_back(i);
	try 
	{
		sp.addNumbers(vec.begin(), vec.end());
	}
	catch (std::exception &e)
	{
		std::cout << RED <<"Exception: " << e.what() << RST << std::endl;
	}
	std::cout << GRN << "Test Range of Numbers" << RST << std::endl;
	Span sp2 = Span(100);
	try
	{
		sp2.addNumbers(vec.begin(), vec.end());
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RST << std::endl;
	}
	std::cout << sp << std::endl;
	std::cout << sp2 << std::endl;
	return 0;
}
