/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:40:20 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/10 13:30:56 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Crea un array de objetos (zombie) en el heap y devuelve un puntero 
 * a la primera posición del array.
 * 
 * @param N -> Cantidad de objetos a crear.
 * @param name -> Nombre de los objetos.
 * @return Zombie* -> Puntero a la primera posición del array.
 */
Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name + std::to_string(i));
	}
	return (horde);
}
