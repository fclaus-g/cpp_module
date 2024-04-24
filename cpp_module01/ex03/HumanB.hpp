/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:24:29 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/24 18:08:00 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
	std::string name;
	Weapon *pointWeapon;
	public:
	HumanB(std::string initName);
	~HumanB();
	const std::string	getName(void) const;
	void				setName(std::string newName);
	void				setWeapon(Weapon &newWeapon);
	void				attack();
};

#endif
