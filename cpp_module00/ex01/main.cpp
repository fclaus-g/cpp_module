/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:04:39 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/24 10:18:47 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void ft_welcome()
{
	std::cout<<"Welcome to the phonebook"<<std::endl;
	std::cout<<"You can ADD a contact, SEARCH for a contact or EXIT"<<std::endl;
	std::cout<<"Enter a command "<<std::endl;
}

int main()
{
	Phonebook phonebook;
	std::string command;

	ft_welcome();
	while (std::getline(std::cin, command))
	{
		if (command == "ADD")
			phonebook.add_contact(&phonebook);
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout<<"Invalid command"<<std::endl;
		if (std::cin.eof())
			return 0;
		std::cin.clear();
		ft_welcome();
	}
	return 0;
}
