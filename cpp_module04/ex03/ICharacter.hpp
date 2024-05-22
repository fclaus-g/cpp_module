/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:35:53 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/22 18:20:05 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

/*La clase ICharacter es solo una plantilla que  le va a dar forma a la
clase Character, por lo que no tenemos que programar el .cpp, ya se encargará
la subclase Character de eso.*/

class ICharacter {
	public:

		virtual ~ICharacter() {};

		virtual const 	std::string& getName() const = 0;
		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;
};

#endif
