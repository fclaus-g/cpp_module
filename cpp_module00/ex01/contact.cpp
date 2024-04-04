/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:04:33 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/04 19:54:40 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/********************[constructor]**************************/
Contact::Contact()
{
	name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret= "";
}
/********************[set]**********************************/
void Contact::set_name(std::string new_name)
{
	name = new_name;
}
void Contact::set_last_name(std::string new_last_name)
{
	last_name = new_last_name;
}
void Contact::set_nickname(std::string new_nickname)
{
	nickname = new_nickname;
}	
void Contact::set_phone_number(std::string new_phone_number)
{
	phone_number = new_phone_number;
}
void Contact::set_darkest_secret(std::string new_darkest_secret)
{
	darkest_secret = new_darkest_secret;

}
/********************[ft_new_contact]**************************/
void Contact::ft_new_contact()
{
	std::cout<<"Enter the name of the contact"<<std::endl;
	std::cin>>name;
	std::cout<<"Enter the last name of the contact"<<std::endl;
	std::cin>>last_name;
	std::cout<<"Enter the nickname of the contact"<<std::endl;
	std::cin>>nickname;
	std::cout<<"Enter the phone number of the contact"<<std::endl;
	std::cin>>phone_number;
	std::cout<<"Enter the darkest secret of the contact"<<std::endl;
	std::cin>>darkest_secret;
}
/********************[print_contact]************************/

void Contact::print_contact()
{
	std::cout<<std::setw(10)<<std::right<<"index"<<"|";
	std::cout<<std::setw(10)<<std::right<<"name"<<"|";
	std::cout<<std::setw(10)<<std::right<<"last_name"<<"|";
	std::cout<<std::setw(10)<<std::right<<"nickname"<<"|"<<std::endl;
	//std::cout<<std::setw(10)<<std::right<<index<<"|";//tengo que añadir index en la clase contact
	std::cout<<std::setw(10)<<std::right<<get_name()<<"|";
	std::cout<<std::setw(10)<<std::right<<get_last_name()<<"|";
	std::cout<<std::setw(10)<<std::right<<get_nickname()<<"|"<<std::endl;
}
/********************[get]**********************************/
std::string Contact::get_name()
{
	return name;
}
std::string Contact::get_last_name()
{
	return last_name;
}
std::string Contact::get_nickname()
{
	return nickname;
}
std::string Contact::get_phone_number()
{
	return phone_number;
}
std::string Contact::get_darkest_secret()
{
	return darkest_secret;
}