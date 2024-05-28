/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:21:52 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 13:52:47 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal{
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog(const Dog& copy);
		Dog&	operator=(const Dog& copy);
		~Dog();
		
		void	makeSound() const;
};

#endif
