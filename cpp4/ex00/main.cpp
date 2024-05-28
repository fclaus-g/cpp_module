/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:25:00 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 13:58:56 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongCat();
	std::cout << j2->getType() << " " << std::endl;
	j2->makeSound();
	meta2->makeSound();

	delete meta2;
	delete j2;
	return 0;
}
