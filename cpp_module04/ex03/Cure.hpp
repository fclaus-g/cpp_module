/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:35:53 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 11:36:28 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& other);
		~Cure();

		Cure&	operator=(const Cure& other);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif