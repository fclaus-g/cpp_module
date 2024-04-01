/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:51:43 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/01 16:51:08 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/********************[constructor]**************************/
Phonebook::Phonebook()
{
	num_contacts = 0;
	index = 0;
}

/********************[set]**********************************/
void Phonebook::set_index(int new_index)
{
	index = new_index;
}

/********************[get]**********************************/
int Phonebook::get_num_contacts()
{
	return num_contacts;
}

int Phonebook::get_index()
{
	return index;
}

/********************[add_contact]**************************/


/********************[search_contact]***********************/


/********************[print_contact]************************/

void Phonebook::print_contact(int)
{
	std::cout<<std::setw(10)<<std::right<<"index"<<"|";
	std::cout<<std::setw(10)<<std::right<<"name"<<"|";
	std::cout<<std::setw(10)<<std::right<<"last_name"<<"|";
	std::cout<<std::setw(10)<<std::right<<"nickname"<<"|"<<std::endl;
	std::cout<<std::setw(10)<<std::right<<index<<"|";
	std::cout<<std::setw(10)<<std::right<<contacts[index].get_name()<<"|";
	std::cout<<std::setw(10)<<std::right<<contacts[index].get_last_name()<<"|";
	std::cout<<std::setw(10)<<std::right<<contacts[index].get_nickname()<<"|"<<std::endl;
}
