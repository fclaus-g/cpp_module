/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:00:11 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 13:18:32 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
}

Animal::Animal(std::string type){
	this->type = type;
}

Animal::~Animal() {
	std::cout << YEL "Animal destructor called" RST << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
}

Animal&	Animal::operator=(const Animal& other) {
	if (this != &other)
		this->type = other.getType();
	return *this;
}

std::string	Animal::getType() const {
	return this->type;
}

void	Animal::makeSound() const {
	std::cout << YEL "Animal sound" RST << std::endl;
}
