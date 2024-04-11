/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:08:05 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/11 10:48:34 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon &refWeapon)
{
	this->name = newName;
	this->refWeapon = refWeapon;

}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->refWeapon.getType() << std::endl;
}

const std::string HumanA::getName(void) const
{
	return (this->name);
}

void HumanA::setName(std::string newName)
{
	this->name = newName;
}
