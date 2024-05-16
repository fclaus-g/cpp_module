/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:22:05 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/15 19:35:56 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << CYN "Dog constructor called" RST << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << CYN "Dog copy constructor called" RST << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Dog&	Dog::operator=(const Dog& copy) {
	std::cout << CYN "Dog assignation operator called" RST << std::endl;
	if (this != &copy) {
		Animal::operator=(copy);
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << CYN "Dog destructor called" RST << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const {
	std::cout << CYN "Woof! Woof!" RST << std::endl;
}
