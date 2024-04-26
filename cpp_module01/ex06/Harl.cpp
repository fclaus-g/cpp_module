/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:01:44 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/26 10:43:55 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl created" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl destroyed" << std::endl;
}

void Harl::_debug(void)
{
	std::cout << GRN << DEBUG_MSG << RST << std::endl;
}

void Harl::_info(void)
{
	std::cout << YEL << INFO_MSG << RST << std::endl;
}

void Harl::_warning(void)
{
	std::cout << ORG WARNING_MSG RST << std::endl;
}

void Harl::_error(void)
{
	std::cout << RED ERROR_MSG RST << std::endl;
}

void Harl::complain(std::string level)
{
	/*Array de punteros a los métodos(funciones) de la clase Harl. Cada puntero apunta a un método
	void método(void)*/
	void (Harl::*f[4]) (void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	/*Array de strings con los niveles de queja*/
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	if (i >= 4)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
	{
		while (i < 4)
		{
			(this->*f[i])();
			i++;
		}
	}
	return ;
}
