/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:25:00 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 13:59:39 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
