/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:59:12 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/22 18:17:29 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	this->_type = "Materia";
}

AMateria::AMateria(std::string const& type) {
	this->_type = type;
}

AMateria::AMateria(const AMateria &other) {
	*this = other;
}

AMateria::~AMateria() {
	std::cout << "AMateria" << this->_type << " destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other) {
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

std::string const&	AMateria::getType() const {
	return this->_type;
}

void	AMateria::setType(std::string type) {
	this->_type = type;
}
/*La función clone no se implementa quí sino que debe ser implementada por
la subclase al tratarse de un método virtual puro.*/

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria " << this->_type << "used on " << target.getName() << std::endl;
}
