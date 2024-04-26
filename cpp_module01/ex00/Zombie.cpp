/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:17:04 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/26 10:50:14 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Constructor-> inicia la variable name de la clase Zombie. 
*:_name(name)*-> es una lista de inicializacion de miembros, es igual que 
poner en los estamentos name = name por lo que la variable name de la clase
Zombie se inicializara con el valor del arg name
*this->name se refiere al miembro _name del objeto Zombie actual
Destructor->El destructor en C++ es una función especial de la clase que se 
ejecuta automáticamente cuando un objeto de la clase sale del ámbito o se 
destruye explícitamente mediante el operador delete. El destructor se utiliza
para liberar los recursos que el objeto puede haber adquirido durante su vida.*/

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << this->_name << " has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
