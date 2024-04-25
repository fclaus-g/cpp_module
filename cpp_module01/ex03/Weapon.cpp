/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:21:50 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/24 18:10:01 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Implemente una clase de Arma que tenga:
• Un tipo de atributo privado, que es una cadena.
• Una función miembro getType() que devuelve una referencia constante al tipo.
• Una función miembro setType() que establece el tipo usando el nuevo pasado 
como parámetro.*/

#include "Weapon.hpp"

/*Constructor*/
Weapon::Weapon(std::string initType)
{
	this->type = initType;
}
/*Destructor*/
Weapon::~Weapon()
{
	std::cout << YEL << "Weapon destroyed" << RST << std::endl;
}


/*Una función miembro setType() que establece el tipo usando el nuevo pasado 
como parámetro (SETTER)*/
void	Weapon::setType(std::string newType)
{
	this->type = newType;
}

/*Una función miembro getType() que devuelve una referencia constante al tipo.*/
const std::string	&Weapon::getType(void) const
{
	return (this->type);
}
