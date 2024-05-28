/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:00:11 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 13:24:13 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type){
	this->type = type;
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << YEL "Animal destructor called" RST << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal&	Animal::operator=(const Animal& other) {
	this->type = other.type;
	return *this;
}

std::string	Animal::getType() const {
	return this->type;
}

void	Animal::makeSound() const {
	std::cout << YEL "Animal sound" RST << std::endl;
}
