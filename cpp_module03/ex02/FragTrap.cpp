/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:19:08 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/09 10:22:06 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*------------------------[CONSTRUCTOR|DESTRUCTOR]-----------------------------*/

FragTrap::FragTrap(){
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name){
	std::cout << "FragTrap name constructor called" << std::endl;
	this->_name = name;
	this->_life_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy){
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->_name = copy._name;
	this->_life_points = copy._life_points;
	this->_energy_points = copy._energy_points;
	this->_attack_damage = copy._attack_damage;
}

FragTrap &FragTrap::operator=(const FragTrap &copy){
	std::cout << "FragTrap assignation operator called" << std::endl;
	this->_name = copy._name;
	this->_life_points = copy._life_points;
	this->_energy_points = copy._energy_points;
	this->_attack_damage = copy._attack_damage;
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

/*------------------------------[MEMBER FUNCTIONS]-----------------------------*/

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->_name << " says: \"High five!\"" << std::endl;
}
