/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:33:08 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/15 18:49:59 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << GRN "Cat constructor called" RST << std::endl;
}

Cat::~Cat() {
	std::cout << GRN "Cat destructor called" RST << std::endl;
}

void Cat::makeSound() const {
	std::cout << GRN "Meow! Meow!" RST << std::endl;
}

