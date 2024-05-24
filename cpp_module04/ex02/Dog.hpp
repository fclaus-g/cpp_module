/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:21:52 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/24 12:31:01 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog : public AAnimal{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(const Dog& copy);
		Dog&	operator=(const Dog& copy);
		~Dog();
		void makeSound() const;
};

#endif