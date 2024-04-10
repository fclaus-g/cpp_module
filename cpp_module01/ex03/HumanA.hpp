/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:02:19 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/10 19:22:33 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	private:
		std::string		name;
		Weapon 			&weapon;
	public:
		HumanA(std::string initName, Weapon &initWeapon);
		~HumanA();
		void attack();
		const std::string getName(void) const;
		void setName(std::string newName);
};
#endif