/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:22:20 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/28 13:47:48 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain& operator=(const Brain &other);
};

#endif
