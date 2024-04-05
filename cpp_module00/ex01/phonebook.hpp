/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:51:56 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/05 13:29:16 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

class Phonebook
{
	Contact contact[8];
	int num_contacts;
	int index;
public:
	Phonebook();
	void add_contact(Phonebook *phonebook);
	//void search_contact(Phonebook *phonebook);
	void set_index(int index);
	int get_num_contacts();
	int get_index();
	//~Phonebook();
};

