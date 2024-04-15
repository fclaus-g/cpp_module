/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:08:05 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/15 11:48:25 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*HumanA y HumanB. Ambos tienen un arma y un
nombre. También tienen una función miembro attack() que muestra (por supuesto,
sin el paréntesis angulares):
<nombre> ataca con su <tipo de arma>
HumanA y HumanB son casi iguales excepto por estos dos pequeños detalles:
• Mientras HumanA toma el Arma en su constructor, HumanB no.
• Es posible que HumanB no siempre tenga un arma, mientras que HumanA siempre
estará armado.*/

#include "HumanA.hpp"

/*en el constructor debemos pararle la lista de inicialización porque al ser refWeapon
una referencia debe de iniciarse en el momento de su declaración, declararlo 
dentro del constructor sería tarde*/
HumanA::HumanA(std::string newName, Weapon &Weapon): name(newName), refWeapon(Weapon)
{
	std::cout << BLU << "HumanA " << this->name << " created" << RST << std::endl; 
}

HumanA::~HumanA()
{
	std::cout << YEL << "HumanA says goodbye" << RST << std::endl;
}

void HumanA::attack()
{
	std::cout << RED << this->name << " attacks with his " << this->refWeapon.getType() << RST << std::endl;
}

const std::string HumanA::getName(void) const
{
	return (this->name);
}

void HumanA::setName(std::string newName)
{
	this->name = newName;
}
