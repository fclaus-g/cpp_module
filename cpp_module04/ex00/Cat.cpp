/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:33:08 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/21 12:52:55 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << GRN "Cat constructor called" RST << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy){
	std::cout << GRN "Cat copy constructor called" RST << std::endl;
}

Cat::~Cat() {
	std::cout << GRN "Cat destructor called" RST << std::endl;
}

Cat&	Cat::operator=(const Cat& copy) {
	std::cout << GRN "Cat assignation operator called" RST << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}	
	return *this;
}

void	Cat::makeSound() const {
	std::cout << GRN "Meow! Meow!" RST << std::endl;
}

