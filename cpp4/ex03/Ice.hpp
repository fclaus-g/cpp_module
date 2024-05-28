/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:13:31 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/27 19:09:45 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& other);
		~Ice();

		Ice&	operator=(const Ice& other);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
