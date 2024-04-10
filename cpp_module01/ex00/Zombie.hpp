/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:17:09 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/09 18:11:48 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
/*Creamos la clase Zombie que incluirá la string name en private el constructor
destructor y la función que hace el anuncio. */
class Zombie 
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};

#endif