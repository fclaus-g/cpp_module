/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:31:53 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 13:20:46 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define MAG "\033[0;35m"
# define PNK "\033[1;35m"	
# define RST "\033[0m"

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& other);

		std::string	getType() const;
		void		makeSound() const;
};

#endif
