/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:51:43 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/24 10:22:58 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/********************[constructor]**************************/
Phonebook::Phonebook()
{
	index_c = 0;
}

/********************[destructor]**************************/

Phonebook::~Phonebook()
{
	std::cout<<"Phonebook destructor"<<std::endl;
}

/********************[set]**********************************/
void	Phonebook::set_index_c(int new_index)
{
	index_c = new_index;
}

/********************[get]**********************************/

int		Phonebook::get_index_c()
{
	return index_c;
}

/********************[add_contact]**************************/

void	Phonebook::add_contact(Phonebook *phonebook)
{
	if (index_c > 7)
	{
		std::cout<<"The phonebook is full"<<std::endl;
		std::cout<<"Do you want to overwrite a contact? (yes/no)"<<std::endl;
		std::string answer;
		std::getline(std::cin, answer);
		if (answer == "y" || answer == "yes")
			index_c = 0;
		else
			return;
	}
	if (index_c < 8)
	{
		std::cout<<"Adding contact "<<index_c<<std::endl;
		phonebook->contact[index_c].addContact(index_c);
		if (phonebook->contact[index_c].getName().empty())
			return;
		std::cout<<"Contact "<<index_c + 1<<" added"<<std::endl;
		index_c++;
	}	
}

/********************[search_contact]***********************/

void	Phonebook::searchContact()
{
	if (contact[0].getName().empty())
	{
		std::cout<<"The phonebook is empty"<<std::endl;
		return;
	}
	printPhonebook();
	std::cout<<"Searching contact"<<std::endl;
	std::cout<<"Enter the index of the contact[from 0 to 7]"<<std::endl;
	int index = -1;
	std::cin>>index;
	if (std::cin.fail()) 
    {
        std::cin.clear(); // limpia el estado de error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta la entrada incorrecta
        std::cout<<"Invalid input"<<std::endl;
        return;
    }
	if (index < 0 || index > 7) 
	{
		std::cout<<"Invalid index"<<std::endl;
		std::cin.ignore();
		return;
	}
	std::cin.ignore();
	if (contact[index].getName().empty())
	{
		std::cout<<"Contact not found"<<std::endl;
		return;
	}
	contact[index].printContact();
}

/*std::cin.fail -> por documentar
  std::cin.ignore()
  std::streamsize::max*/



/********************[printPhonebook]***********************/

void	Phonebook::printPhonebook()
{
	int i = 0;
	std::string aux;

	std::cout<<std::setw(10)<<std::right<<"index"<<"|";
	std::cout<<std::setw(10)<<std::right<<"name"<<"|";
	std::cout<<std::setw(10)<<std::right<<"last_name"<<"|";
	std::cout<<std::setw(10)<<std::right<<"nickname"<<"|"<<std::endl;
	while (i < 8)
	{		
		if (contact[i].getName().empty())
			break;
		std::cout<<std::setw(10)<<std::right<<i<<"|";
		aux = contact[i].getName();
		if (aux.length() >= 10)
			aux = aux.substr(0, 9) + ".";
		std::cout<<std::setw(10)<<std::right<<aux<<"|";
		aux = contact[i].getLastName();
		if (aux.length() >= 10)
			aux = aux.substr(0, 9) + ".";
		std::cout<<std::setw(10)<<std::right<<aux<<"|";
		aux = contact[i].getNickName();
		if (aux.length() >= 10)
			aux = aux.substr(0, 9) + ".";
		std::cout<<std::setw(10)<<std::right<<aux<<"|"<<std::endl;
		i++;
	}
}
