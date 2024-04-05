/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:51:43 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/05 12:08:45 by fclaus-g         ###   ########.fr       */
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
	{
		phonebook->contact[index].ft_new_contact(index);
		std::cout<<"Contact "<<index<<" added"<<std::endl;
		num_contacts++;
		index++;
	}	
	phonebook->contact->print_contact();
}

/********************[search_contact]***********************/


