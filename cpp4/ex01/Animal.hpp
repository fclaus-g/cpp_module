/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:49:21 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 13:59:24 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"

# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define CYN "\033[1;36m"
# define RST "\033[0m"

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal& other);
		Animal&	operator=(const Animal &other);

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif
