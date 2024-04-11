/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:24:29 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/11 10:41:13 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
	std::string name;
	Weapon *pointWeapon;
	public:
	HumanB(std::string initName);
	~HumanB();
	void attack();
	const std::string getName(void) const;
	void setName(std::string newName);
	void setWeapon(Weapon &newWeapon);
};
#endif
