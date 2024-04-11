/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:02:19 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/11 10:48:59 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string		name;
		Weapon 			&refWeapon;
	public:
		HumanA(std::string newName, Weapon &refWeapon);
		~HumanA();
		void attack();
		const std::string getName(void) const;
		void setName(std::string newName);
};
#endif