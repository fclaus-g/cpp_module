/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:25:00 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/15 20:11:00 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Los constructores y destructores de cada clase deben mostrar mensajes específicos.
*Implementar una clase Brain. Contiene una matriz de 100 std::string llamadas ideas.
De esta manera, Perro y Gato tendrán un atributo Cerebro* privado.
*Tras la construcción, Perro y Gato crearán su Cerebro usando new Brain();
*Tras la destrucción, Perro y Gato eliminarán su cerebro.
*En su función principal, cree y complete una serie de objetos Animales. La mitad será
serán objetos de Perro y la otra mitad serán objetos de Gato. Al final de su programa
ejecución, recorra esta matriz y elimine todos los animales. Debes eliminar directamente los perros.
y gatos como animales. Los destructores apropiados deben llamarse en el orden esperado.
No olvide comprobar si hay pérdidas de memoria.
Una copia de un Perro o un Gato no debe ser superficial. Por lo tanto, debes probar que tus copias
son copias profundas!*/

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[8];

	for (int i = 0; i < 4; i++)
	{
		animals[i] = new Dog();
		animals[i]->makeSound();
		animals[i + 4] = new Cat();
		animals[i + 4]->makeSound();
	}
	for (int i = 0; i < 8; i++)
		delete animals[i];

	return 0;
}
