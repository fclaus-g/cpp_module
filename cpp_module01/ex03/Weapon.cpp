/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:21:50 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/11 10:23:30 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string initType)
{
	this->type = initType;
}

Weapon::~Weapon()
{
}
void Weapon::setType(std::string newType)
{
	this->type = newType;
}

const std::string &Weapon::getType(void) const
{
	return (this->type);
}
