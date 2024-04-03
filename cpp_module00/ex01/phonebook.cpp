/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:51:43 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/03 20:33:47 by fclaus-g         ###   ########.fr       */
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

void Phonebook::add_contact(Phonebook *phonebook)
{
	if (num_contacts > 7)
	{
		std::cout<<"The phonebook is full"<<std::endl;
		std::cout<<"Do you want to overwrite a contact? (yes/no)"<<std::endl;
		std::string answer;
		std::cin>>answer;
		if (answer == "y" || answer == "yes")
			index = 0;
		else
			return;
	}
	else if (num_contacts < 0)
	{
		std::cout<<"Invalid number of contacts"<<std::endl;
		return;
	}
	else
		phonebook->contact[index].ft_new_contact();
	num_contacts++;
	index++;
}

/********************[search_contact]***********************/


/********************[print_contact]************************/

void Phonebook::print_contact(Phonebook *phonebook, int index)
{
	std::cout<<std::setw(10)<<std::right<<"index"<<"|";
	std::cout<<std::setw(10)<<std::right<<"name"<<"|";
	std::cout<<std::setw(10)<<std::right<<"last_name"<<"|";
	std::cout<<std::setw(10)<<std::right<<"nickname"<<"|"<<std::endl;
	std::cout<<std::setw(10)<<std::right<<index<<"|";
	std::cout<<std::setw(10)<<std::right<<contact[index].get_name()<<"|";
	std::cout<<std::setw(10)<<std::right<<contact[index].get_last_name()<<"|";
	std::cout<<std::setw(10)<<std::right<<contact[index].get_nickname()<<"|"<<std::endl;
}
