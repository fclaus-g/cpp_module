/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:01:38 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/26 10:48:10 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
/*randomChump es una funcion que crea un objeto de tipo Zombie **en la pila**
y le asigna un nombre para luego llamar al metodo announce de la clase Zombie
para que el objeto se anuncie a si mismo. Una vez sale del ámbito de la función
la variable zombie se destruye automaticamente.*/

void	randomChump(std::string name) 
{
	Zombie	zombie = Zombie(name);
	zombie.announce();
}
