/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:15:29 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/15 11:42:47 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Implemente una clase de Arma que tenga:
• Un tipo de atributo privado, que es una cadena.
• Una función miembro getType() que devuelve una referencia constante al tipo.
• Una función miembro setType() que establece el tipo usando el nuevo pasado 
como parámetro.*/

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

/*COLOURS*/
# define BLU	"\e[1;34m"
# define RED	"\e[1;31m"
# define GRN	"\e[1;32m"
# define YEL	"\e[1;33m"
# define RST	"\e[0m"


class Weapon
{
	private:
	std::string type;
	public:
	Weapon(std::string initType);
	~Weapon();
	const std::string &getType(void) const;
	void setType(std::string newType);
};


#endif