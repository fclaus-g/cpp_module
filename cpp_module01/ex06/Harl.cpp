/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:01:44 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/24 19:27:54 by fclaus-g         ###   ########.fr       */
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

    while (i < 4 && lvl[i] != level)
        i++;
    switch (i)
    {
        case 0:
            (this->*f[0])();
            //fall through
        case 1:
            (this->*f[1])();
            //fall through
        case 2:
            (this->*f[2])();
            //fall through
        case 3:
            (this->*f[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    // while (i < 4)
    // {
    //     if (lvl[i] == level)
    //     {
    //         /*si el nivel de queja coincide con el argumentoo pasado al método complain
	// 		se llama al método correspondiente del array de funciones*/
	// 		(this->*f[i])();
    //         return ;
    //     }
    //     i++;
    // }
    // if (i >= 4)
    //     std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return ;
}
