/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:59:12 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 14:01:02 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	this->_type = "Materia";
	std::cout << YEL << "AMateria default constructor called" << RST << std::endl;
}

AMateria::AMateria(std::string const& type) {
	this->_type = type;
	std::cout << YEL << "AMateria constructor with parameter called" << RST << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	*this = other;
	std::cout << YEL << "AMateria copy constructor called" << RST << std::endl;
}

AMateria::~AMateria() {
	std::cout << YEL "AMateria " << this->_type << " destructor called" << RST << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other) {
	if (this != &other)
		this->_type = other.getType();
	std::cout << YEL << "AMateria operator= called" << RST << std::endl;
	return *this;
}

std::string const&	AMateria::getType() const {
	return this->_type;
}

void	AMateria::setType(std::string type) {
	this->_type = type;
}

void AMateria::use(ICharacter& target) {
	std::cout << YEL "AMateria " << this->_type << "used on " RST << target.getName() << std::endl;
}
