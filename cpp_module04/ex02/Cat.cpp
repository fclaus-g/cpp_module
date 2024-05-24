/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:33:08 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/24 12:32:31 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat") {
	std::cout << GRN "Cat constructor called" RST << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat& copy) : AAnimal(copy) {
	std::cout << GRN "Cat copy constructor called" RST << std::endl;
	this->_brain = new Brain(*copy._brain);//copia profunda de la clase Brain
}

Cat&	Cat::operator=(const Cat& copy) {
	std::cout << GRN "Cat assignation operator called" RST << std::endl;
	if (this != &copy) {
		this->type = copy.getType();
		this->_brain = new Brain(*copy._brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << GRN "Cat destructor called" RST << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const {
	std::cout << GRN "Meow! Meow!" RST << std::endl;
}
