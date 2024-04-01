/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:04:39 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/01 16:53:51 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string command;
	while (1)
	{
		std::cout<<"Enter a command "<<std::endl;
		std::cin>>command;
		if (command == "ADD")
			//phonebook.add_contact();
			std::cout<<"ADD"<<std::endl;
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