/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:38:17 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 11:39:37 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << GRN "Cure default constructor called" RST << std::endl;
};

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << GRN "Cure copy constructor called" RST << std::endl;
};

Cure::~Cure() {
	std::cout << GRN "Cure destructor called" RST << std::endl;
};

Cure&	Cure::operator=(const Cure& other) {
	if (this != &other)
		this->_type = other._type;
	std::cout << GRN "Cure operator= called" RST << std::endl;
	return (*this);
}

AMateria*	Cure::clone() const {
	Cure* clone;
	clone = new Cure(*this);
	std::cout << GRN "Cure clone called" RST << std::endl;
	return (clone);
}

void Cure::use(ICharacter& target) {
	std::cout << GRN "* heals " << target.getName() << "'s wounds *" << std::endl;
}
