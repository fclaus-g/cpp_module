/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:27:12 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/10 17:44:34 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
/**
 * @brief El main va a crear un array de 5 zombies almacenados en el heap
 * a traves de new dentro de la funcion zombieHorde. Luego se recorre el array
 * ejecutando el método announce de cada uno de los zombies.
 * @return int 
 */
int main(void)
{
	int i = 0;
	Zombie *horde = zombieHorde(5, "Zombie_");
	while (i < 5)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	return (0);
}