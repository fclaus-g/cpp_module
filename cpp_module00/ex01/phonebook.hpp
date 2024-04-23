/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:51:56 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/23 18:46:18 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class	Phonebook
{
private:
	Contact contact[8];
	int 	index_c;
public:
	Phonebook();
	~Phonebook();
	void	add_contact(Phonebook *phonebook);
	void	searchContact();
	void	printPhonebook();
	void	set_index_c(int index);
	int		get_index_c();
};

#endif
