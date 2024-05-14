/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:35:22 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/14 19:55:29 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << PNK "WrongCat constructor called" RST << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << PNK "WrongCat destructor called" RST << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << PNK "Meow! Meow!" RST << std::endl;
}
