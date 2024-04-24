/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:27:39 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/24 18:06:12 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
	this->name = newName;
	this->pointWeapon = NULL;
	std::cout << GRN << "HumanB " << this->name << " created" << RST << std::endl;
}

HumanB::~HumanB()
{
	std::cout << YEL << "HumanB says goodbye" << RST << std::endl;
}

void	HumanB::attack()
{
	if (this->pointWeapon)
		std::cout<< RED << this->name << " attacks with his " << this->pointWeapon->getType() << RST << std::endl;
	else
		std::cout << this->name << " attacks with his bare hands" << std::endl;
}

const std::string	HumanB::getName(void) const
{
	return (this->name);
}

void	HumanB::setName(std::string newName)
{
	this->name = newName;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->pointWeapon = &newWeapon;
}

