/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:51:56 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/09 12:22:13 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

class Phonebook
{
private:
	Contact contact[8];
	int index_c;
	int overwrite;
public:
	Phonebook();
	void add_contact(Phonebook *phonebook);
	//void search_contact(Phonebook *phonebook);
	void set_index_c(int index);
	int get_index_c();
	//~Phonebook();
};

