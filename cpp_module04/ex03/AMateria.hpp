/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:31:39 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 11:18:47 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

# define GRN "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define CYN "\033[36m"
# define RST "\033[0m"

class ICharacter;

class AMateria{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(const std::string&  type);//constructor con parametro
		AMateria(const AMateria& other);//constructor de copia const porque
		virtual ~AMateria();
		AMateria& operator=(const AMateria& other);//asignacion por sobrecarga de operador

		const	std::string& getType() const;
		void	setType(std::string type);
		
		virtual AMateria* 	clone() const = 0;
		virtual void		use(ICharacter& target) = 0;
};

#endif
