/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:04:33 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/23 19:12:15 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/********************[constructor]**************************/
Contact::Contact()
{
	name = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret = "";
	index = 0;
}

/********************[destructor]**************************/
Contact::~Contact()
{
}

/********************[ft_new_contact]**************************/
void Contact::addContact(int index)
{
	setIndex(index);
	std::cout << "Enter the name of the contact" << std::endl;
	name = getInput();
	if (std::cin.eof()) return;
	std::cout << "Enter the last name of the contact" << std::endl;
	lastName = getInput();
	if (std::cin.eof()) return;
	std::cout << "Enter the nickname of the contact" << std::endl;
	nickName = getInput();
	if (std::cin.eof()) return;
	std::cout << "Enter the phone number of the contact" << std::endl;
	phoneNumber = getInput();
	if (std::cin.eof()) return;
	if (phoneNumber.length() != 9 || !isNumeric(phoneNumber))
	{
		std::cout << "The phone number must have 9 digits" << std::endl;
		std::cout << "Enter the phone number of the contact" << std::endl;
		phoneNumber = getInput();
	}
	std::cout << "Enter the darkest secret of the contact" << std::endl;
	darkestSecret = getInput();
	if (std::cin.eof()) return;
}
/********************[getInput]**************************/
std::string Contact::getInput()
{
	std::string	input;

	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Invalid input, empty input" << std::endl;
	return input;
}
/***********************[printContact]*********************/
void Contact::printContact()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret " << darkestSecret << std::endl;
}

bool Contact::isNumeric(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}
/********************[set]**********************************/
void Contact::setIndex(int new_index)
{
	index = new_index;
}
/********************[get]**********************************/
std::string Contact::getName()
{
	return name;
}
std::string Contact::getLastName()
{
	return lastName;
}
std::string Contact::getNickName()
{
	return nickName;
}
std::string Contact::getPhoneNumber()
{
	return phoneNumber;
}
std::string Contact::getDarkestSecret()
{
	return darkestSecret;
}

int Contact::getIndex()
{
	return index;
}
