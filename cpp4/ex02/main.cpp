/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:25:00 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 14:00:36 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	AAnimal *animals[4];

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
