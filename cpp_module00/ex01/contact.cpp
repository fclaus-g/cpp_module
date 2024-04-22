/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:04:33 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/22 18:49:59 by fclaus-g         ###   ########.fr       */
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
	darkestSecret= "";
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
	std::cout<<"Enter the name of the contact"<<std::endl;
	name = getInput();
	std::cout<<"Enter the last name of the contact"<<std::endl;
	lastName = getInput();
	std::cout<<"Enter the nickname of the contact"<<std::endl;
	nickName = getInput();
	std::cout<<"Enter the phone number of the contact"<<std::endl;
	phoneNumber = getInput();
	while (phoneNumber.length() != 9) // && isNumeric(phoneNumber) == false) COMPROBAR SI EL TELEFONO CONTIENE SOLO NUM
	{
		std::cout<<"The phone number must have 9 digits"<<std::endl;
		std::cout<<"Enter the phone number of the contact"<<std::endl;
		phoneNumber = getInput();
	}
	std::cout<<"Enter the darkest secret of the contact"<<std::endl;
	darkestSecret = getInput();	
}
/********************[getInput]**************************/
std::string Contact::getInput()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}
/***********************[printContact]*********************/
void Contact::printContact()
{
	std::cout<<"Name: "<<name<<std::endl;
	std::cout<<"Last name: "<<lastName<<std::endl;
	std::cout<<"Nickname: "<<nickName<<std::endl;
	std::cout<<"Phone number: "<<phoneNumber<<std::endl;
	std::cout<<"Darkest secret "<<darkestSecret<<std::endl;
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
