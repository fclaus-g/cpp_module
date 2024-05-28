/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:28:03 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 13:21:08 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		~Cat();

		void makeSound() const;
};

#endif
