/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:22:05 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/21 12:55:26 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout << CYN "Dog constructor called" RST << std::endl;
	this->type = "Dog";
}
Dog::Dog(const Dog& copy) : Animal() {	
	std::cout << CYN "Dog constructor called" RST << std::endl;
	*this = copy;
}

Dog::~Dog() {
	std::cout << CYN "Dog destructor called" RST << std::endl;
}

Dog&	Dog::operator=(const Dog& copy) {
	std::cout << CYN "Dog assignation operator called" RST << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return *this;
}
void Dog::makeSound() const {
	std::cout << CYN "Woof! Woof!" RST << std::endl;
}
