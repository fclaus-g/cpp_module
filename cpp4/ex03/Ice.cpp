/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:02:05 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 11:30:43 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << CYN "Ice default constructor called" RST<< std::endl;
};

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << CYN "Ice copy constructor called" RST << std::endl;
};

Ice::~Ice() {
	std::cout << CYN "Ice destructor called" RST << std::endl;
};

Ice&	Ice::operator=(const Ice& other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << CYN "Ice operator= called" RST << std::endl;
	return (*this);
}

AMateria*	Ice::clone() const {
	Ice* clone;
	clone = new Ice(*this);
	std::cout << CYN "Ice clone called" RST << std::endl;
	return (clone);
}

void Ice::use(ICharacter& target) {
	std::cout << CYN "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
