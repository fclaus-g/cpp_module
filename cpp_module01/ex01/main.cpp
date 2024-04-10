/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:27:12 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/10 13:30:19 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
/**
 * @brief El main va a crear un array de 5 zombies almacenados en el heap
 * 
 * 
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