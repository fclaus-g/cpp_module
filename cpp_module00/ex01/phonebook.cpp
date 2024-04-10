/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:51:43 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/09 12:21:08 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/********************[constructor]**************************/
Phonebook::Phonebook()
{
	index_c = 0;
}

/********************[set]**********************************/
void Phonebook::set_index_c(int new_index)
{
	index_c = new_index;
}

/********************[get]**********************************/

int Phonebook::get_index_c()
{
	return index_c;
}

/********************[add_contact]**************************/

void Phonebook::add_contact(Phonebook *phonebook)
{
	if (index_c > 7)
	{
		std::cout<<"The phonebook is full"<<std::endl;
		std::cout<<"Do you want to overwrite a contact? (yes/no)"<<std::endl;
		std::string answer;
		std::cin>>answer;
		if (answer == "y" || answer == "yes")
			index_c = 0;
		else
			return;
	}
	if (index_c < 8)
	{
		std::cout<<"Adding contact"<<index_c<<std::endl;
		phonebook->contact[index_c].ft_new_contact(index_c);
		std::cout<<"Contact "<<index_c<<" added"<<std::endl;
		phonebook->contact[index_c].print_contact();
		index_c++;
	}	
}

/********************[search_contact]***********************/


