/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:27:16 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/24 17:37:00 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>
/*Creamos la clase Zombie que incluirá la string name en private el constructor
destructor y la función que hace el anuncio. */
#include "Zombie.hpp"

class Zombie 
{
	private:
		std::string _name;
	public:
		Zombie();
		~Zombie(void);
		void announce(void);
		void setName(std::string name);
		std::string getName(void);
};
Zombie*	zombieHorde(int N, std::string name);

#endif