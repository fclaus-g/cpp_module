/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:49:06 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 11:48:20 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	this->_name = "Default";
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << BLU "Character default constructor called" RST << std::endl;
}

Character::Character(std::string name) {
	this->_name = name;
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << BLU "Character " << this->_name << " constructor with parameter called" RST << std::endl;
}

Character::Character(const Character& copy) {
	this->_name = copy._name;
	this->_index = copy._index;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i];
	std::cout << BLU "Character copy constructor called" RST << std::endl;
}

Character::~Character() {
	std::cout << BLU "Character " << this->_name << " destructor called" RST << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
}

Character& Character::operator=(const Character& rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_index = rhs._index;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
	}
	std::cout << BLU "Character operator= called" RST << std::endl;
	return (*this);
}

const std::string& Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (this->_index < 4 && m )
	{
		this->_inventory[this->_index] = m;
		this->_index++;
		std::cout << BLU << this->_name << " has equipped " << m->getType() << RST<< std::endl;
	}
	else
		std::cout << BLU "Inventory is full"  RST << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
	{
		std::cout << BLU << this->_name << " has unequipped " << this->_inventory[idx]->getType() << RST << std::endl;
		this->_inventory[idx] = NULL;
		this->_index--;
	}
	else
		std::cout << BLU "Invalid index" RST << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
	{
		std::cout << BLU << this->_name << " uses " << this->_inventory[idx]->getType() << " on " << target.getName() << RST << std::endl;
		this->_inventory[idx]->use(target);
	}
	else
		std::cout << BLU "Invalid index" RST << std::endl;
}
