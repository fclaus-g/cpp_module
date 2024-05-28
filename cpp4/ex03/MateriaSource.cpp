/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAteriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:11:29 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 13:12:57 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << MAG "MateriaSource default constructor called" RST << std::endl;
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << MAG "MateriaSource copy constructor called" RST << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	std::cout << MAG "MateriaSource destructor called" RST << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	this->_index = other._index;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = other._materias[i];
	std::cout << MAG "MateriaSource operator= called" RST << std::endl;
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] == NULL && this->_index < 4)
		{
			this->_materias[i] = materia;
			this->_index++;
			std::cout << MAG << "Materia " << this->_materias[i]->getType() << " learned" RST << std::endl;
			break;
		}
		else if (this->_index == 4)
		{
			std::cout << MAG "MateriaSource is full" RST << std::endl;
			break;
		}
	}

}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
		{
			std::cout << MAG "Materia " << this->_materias[i]->getType() << " created" << RST << std::endl;
			return this->_materias[i]->clone();
		}
	std::cout << MAG "Materia " << type << " not found" RST << std::endl;
	return NULL;
}
