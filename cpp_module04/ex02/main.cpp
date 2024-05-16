/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:25:00 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/16 10:53:33 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Después de todo, crear objetos animales no tiene sentido. ¡Es verdad, 
no emiten ningún sonido!.Para evitar posibles errores, la clase Animal
predeterminada no debe ser instanciable. Arregla la clase Animal para que 
nadie pueda crear una instancia de ella. Todo debería funcionar como antes.
Si lo desea, puede actualizar el nombre de la clase agregando un prefijo A a 
Animal.*/


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
