/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:04:36 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/05 13:31:35 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	std::string name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	int index;
public:
	Contact();
	void set_name(std::string new_name);
	void set_last_name(std::string new_last_name);
	void set_nickname(std::string new_nickname);
	void set_phone_number(std::string new_phone_number);
	void set_darkest_secret(std::string new_darkest_secret);
	void set_index(int new_index);
	void ft_new_contact(int index);
	std::string get_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_darkest_secret();
	int get_index();
	void print_contact();
	//~Contact();
};
