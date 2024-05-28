/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:35:22 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/22 13:48:01 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << PNK "WrongCat constructor called" RST << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << PNK "WrongCat destructor called" RST << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
	std::cout << PNK "WrongCat copy constructor called" RST << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << PNK "WrongCat assignation operator called" RST << std::endl;
	this->type = other.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << PNK "Meow! Meow!" RST << std::endl;
}
