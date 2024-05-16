/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:25:00 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/16 17:04:25 by fclaus-g         ###   ########.fr       */
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
	Animal *animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	for (int i = 0; i < 2; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
	return 0;
}
