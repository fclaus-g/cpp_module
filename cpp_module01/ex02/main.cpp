/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:50:57 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/24 18:03:32 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Escribe un programa que contenga:
• Una variable de cadena inicializada como "HI THIS IS BRAIN".
• stringPTR: Un puntero a la cadena.
• stringREF: una referencia a la cadena.
Su programa tiene que imprimir:
• La dirección de memoria de la variable de cadena.
• La dirección de memoria mantenida por stringPTR.
• La dirección de memoria mantenida por stringREF.
Y luego:
• El valor de la variable de cadena.
• El valor al que apunta stringPTR.
• El valor al que apunta stringREF.
Eso es todo, sin trucos. El objetivo de este ejercicio es desmitificar las referencias que pueden
Parece completamente nuevo. Aunque hay algunas pequeñas diferencias, esta es otra sintaxis.
para algo que ya haces: manipulación de direcciones.
*/

#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Address of the string: " << &str << std::endl;
	std::cout << "Address of the stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of the stringREF: " << &stringREF << std::endl;
	std::cout << "Value of the string: " << str << std::endl;
	std::cout << "Value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of the stringREF: " << stringREF << std::endl;
	return (0);
}

/*
std::string str = "HI THIS IS BRAIN";: 
Esta línea declara una variable str de tipo std::string y 
la inicializa con la cadena de texto "HI THIS IS BRAIN".

std::string *stringPTR = &str;: Esta línea declara una variable
stringPTR que es un puntero a std::string. Se inicializa
con la dirección de la variable str (obtenida con el operador &).
Por lo tanto, stringPTR apunta a str.

std::string &stringREF = str;: Esta línea declara una variable
stringREF que es una referencia a std::string. Se inicializa con str,
por lo que stringREF es otra forma de acceder a str. Cualquier cambio
que hagas a stringREF también cambiará str, y viceversa.

*/