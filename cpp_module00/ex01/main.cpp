/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:04:39 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/04 19:53:10 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void ft_welcome()
{
	std::cout<<"Welcome to the phonebook"<<std::endl;
	std::cout<<"You can ADD a contact, SEARCH for a contact, PRINT a contact or EXIT"<<std::endl;
}

int main()
{
	Phonebook phonebook;
	std::string command;

	ft_welcome();
	while (command != "EXIT")
	{
		std::cout<<"Enter a command "<<std::endl;
		std::cin>>command;
		if (command == "ADD")
			phonebook.add_contact(&phonebook);
		//	std::cout<<"ADD"<<std::endl;
		else if (command == "SEARCH")
			//phonebook.search_contact();
			std::cout<<"SEARCH"<<std::endl;
		else if (command == "EXIT")
			break;
		else
			std::cout<<"Invalid command"<<std::endl;
	}
	return 0;
}