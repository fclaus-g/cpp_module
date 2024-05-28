/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:39:14 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 11:20:24 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria*	_materias[4];
		int			_index;
	public:
		MateriaSource();
		MateriaSource(const std::string& type);
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		MateriaSource&	operator=(const MateriaSource& other);

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(const std::string& type);
};

# endif