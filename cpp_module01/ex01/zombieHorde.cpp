/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:40:20 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/26 10:52:15 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Crea un array de objetos (zombie) en el heap y devuelve un puntero 
 * a la primera posición del array. Con stringstream se concatena el nombre
 * con el número de objeto.
 * 
 * @param N -> Cantidad de objetos a crear.
 * @param name -> Nombre de los objetos.
 * @return Zombie* -> Puntero a la primera posición del array.
 */

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::stringstream	ss;
		ss << i;
		horde[i].setName(name + ss.str());
	}
	return (horde);
}
