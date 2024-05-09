/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:23:11 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/08 15:30:16 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*------------------------[CONSTRUCTOR|DESTRUCTOR]-----------------------------*/
ClapTrap::ClapTrap(){
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << "ClapTrap name constructor called" << std::endl;
	this->_name = name;
	this->_life_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->_name = copy._name;
    this->_life_points = copy._life_points;
    this->_energy_points = copy._energy_points;
    this->_attack_damage = copy._attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy){
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->_name = copy._name;
	this->_life_points = copy._life_points;
	this->_energy_points = copy._energy_points;
	this->_attack_damage = copy._attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;
}

/*------------------------------[GET]-----------------------------------------*/

std::string ClapTrap::getName(void){
	return (this->_name);
}

unsigned int ClapTrap::getLifePoints(void){
	return (this->_life_points);
}

unsigned int ClapTrap::getEnergyPoints(void){
	return (this->_energy_points);
}

unsigned int ClapTrap::getAttackDamage(void){
	return (this->_attack_damage);
}

/*------------------------------[SET]-----------------------------------------*/

void ClapTrap::setLifePoints(unsigned int life_points){
	this->_life_points = life_points;
}

void ClapTrap::setEnergyPoints(unsigned int energy_points){
	this->_energy_points = energy_points;
}

void ClapTrap::setAttackDamage(unsigned int attack_damage){
	this->_attack_damage = attack_damage;
}


/*------------------------------[FUNCIONES]-----------------------------------*/

void ClapTrap::attack(const std::string &target){
	if (this->_energy_points == 0){
		std::cout << RED << "The hero " << this->_name << "has no energy points left" RES<< std::endl;
		return ;
	}
	std::cout << BLU << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" RES << std::endl; 
	this->_energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << YEL << this->_name << " takes " << amount << " points of damage!" RES << std::endl;
	if (this->_life_points < amount)
		this->_life_points = 0;
	else	
		this->_life_points -= amount;
	if (this->_life_points == 0){
		std::cout << RED << this->_name << " is death" RES << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_life_points == 10){
		std::cout << MAG << "The hero " << this->_name << " has full life points" RES << std::endl;
		return ;
	}
	std::cout << GRN << this->_name << " is repaired by " << amount << " points!" RES << std::endl;
	this->_life_points += amount;
}

void ClapTrap::printClapTrap(void){
	std::cout<<GRN<<std::setw(10)<<std::left<<"name"<<"|";
	std::cout<<std::setw(10)<<std::right<<"life"<<"|";
	std::cout<<std::setw(10)<<std::right<<"energy"<<"|";
	std::cout<<std::setw(10)<<std::right<<"attack"<<"|"<<RES<<std::endl;
	std::cout<<std::setw(10)<<std::left<<this->_name<<"|";
	std::cout<<std::setw(10)<<std::right<<this->_life_points<<"|";
	std::cout<<std::setw(10)<<std::right<<this->_energy_points<<"|";
	std::cout<<std::setw(10)<<std::right<<this->_attack_damage<<"|"<<std::endl;
}
