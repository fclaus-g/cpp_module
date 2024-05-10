/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:01:48 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/10 11:10:55 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*-------------------------------[CONSTRUCTOR|DESTRUCTOR]---------------------*/

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->_name = "DiamondTrap";
	ClapTrap::_name = "DiamondTrap_clap_name";
	this->_life_points = FragTrap::_life_points;
	this->_attack_damage = FragTrap::_attack_damage;
	this->_energy_points = ScavTrap::_scavEnergy;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_life_points = FragTrap::_life_points;
	this->_attack_damage = FragTrap::_attack_damage;
	this->_energy_points = ScavTrap::_scavEnergy;
	std::cout << "DiamondTrap Name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

/*-----------------------------------[MEMBER FUNCIONS]------------------------*/

void DiamondTrap::whoAmI() {
	std::cout << BLU"My name is " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << RES << std::endl;
}

/*-----------------------------------[OPERATOR OVERLOAD]----------------------*/

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
	this->ClapTrap::operator=(copy);
	this->ScavTrap::operator=(copy);
	this->FragTrap::operator=(copy);
	return (*this);
}
