/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:33:57 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 14:00:50 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << MAG "WrongAnimal default constructor called" RST << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
	this->type = type;
	std::cout << MAG "WrongAnimal parameter constructor called" RST << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << MAG "WrongAnimal destructor called" RST << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	this->type = other.type;
	std::cout << MAG "WrongAnimal copy constructor called" RST << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &other) {
	this->type = other.type;
	std::cout << MAG "WrongAnimal assignation operator called" RST << std::endl;
	return *this;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}

void	WrongAnimal::makeSound() const {
	std::cout << MAG "WrongAnimal sound" RST << std::endl;
}
