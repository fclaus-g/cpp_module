/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:22:05 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/14 19:53:37 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << CYN "Dog constructor called" RST << std::endl;
}

Dog::~Dog() {
	std::cout << CYN "Dog destructor called" RST << std::endl;
}

void Dog::makeSound() const {
	std::cout << CYN "Woof! Woof!" RST << std::endl;
}
