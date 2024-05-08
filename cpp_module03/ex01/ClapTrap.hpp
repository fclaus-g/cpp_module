/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:23:05 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/08 13:05:53 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YEL "\033[0;33m"
# define BLU "\033[0;34m"
# define MAG "\033[0;35m"
# define RES "\033[0m"

#include <iostream>
#include <string>
#include <iomanip>

/*ATRIBUTOS PRIVADOS
• Nombre, que se pasa como parámetro a un constructor.
• Puntos de vida (10), representan la salud del ClapTrap.
• Puntos de energía (10)
• Daño de ataque (0)
Agregue las siguientes funciones de miembros públicos para que ClapTrap parezca más realista:
• void attack(const std::string& target); 
• void takeDamage(unsigned int amount);
• void beRepaired(unsigned int amount);*/

class ClapTrap{
	protected:
	std::string 	_name;
	unsigned int	_life_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);
	~ClapTrap();

	std::string		getName(void);
	unsigned int	getLifePoints(void);
	unsigned int	getEnergyPoints(void);
	unsigned int	getAttackDamage(void);
	void 			setLifePoints(unsigned int life_points);
	void 			setEnergyPoints(unsigned int energy_points);
	void 			setAttackDamage(unsigned int attack_damage);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void 	printClapTrap(void);
};

#endif
