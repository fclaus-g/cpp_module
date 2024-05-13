/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:25:00 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/13 20:28:49 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Para cada ejercicio, debes proporcionar las pruebas más completas que puedas.
Los constructores y destructores de cada clase deben mostrar mensajes específicos. No uses el
Mismo mensaje para todas las clases.
Comience implementando una clase base simple llamada Animal. tiene uno protegido
atributo:
• std::tipo de cadena;
Implemente una clase Perro que herede de Animal.
Implemente una clase Cat que herede de Animal.
Estas dos clases derivadas deben establecer su campo de tipo según su nombre. Entonces,
el tipo de Perro se inicializará a "Perro" y el tipo de Gato se inicializará a "Gato".
El tipo de clase Animal puede dejarse vacío o establecerse con el valor que elija.
Cada animal debe poder utilizar la función miembro:
hacer sonido()
Imprimirá un sonido apropiado (los gatos no ladran).*/

#include "Animal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	...
	return 0;
}
