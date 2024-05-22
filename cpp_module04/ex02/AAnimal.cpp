/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:00:11 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/22 13:56:18 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() {
	this->type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type){
	this->type = type;
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << YEL "Animal destructor called" RST << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
	*this = other;
}

AAnimal&	AAnimal::operator=(const AAnimal& other) {
	this->type = other.type;
	return *this;
}

std::string AAnimal::getType() const {
	return this->type;
}

void AAnimal::makeSound() const {
	std::cout << YEL "Animal sound" RST << std::endl;
}
