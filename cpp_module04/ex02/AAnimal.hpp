/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:49:21 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/22 13:57:01 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define CYN "\033[1;36m"
# define RST "\033[0m"

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(std::string type);//constructor con parametro
		virtual ~AAnimal();//virtual destructor para que se llame al destructor de las clases hijas
		AAnimal(const AAnimal& other);//copy constructor
		AAnimal&	operator=(const AAnimal &other);//asignacion por sobrecarga de operador
		
		std::string		getType() const;
		virtual void	makeSound() const = 0;//metodo virtual puro
};

#endif
