/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAteriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:11:29 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/23 20:50:05 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	*this = other;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	this->_index = other._index;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = other._materias[i];
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++)
		
}
