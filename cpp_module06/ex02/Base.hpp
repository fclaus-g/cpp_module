/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:45:19 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/11 09:45:20 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

# define GRE "\033[1;32m"
# define RED "\033[1;31m"
# define RES "\033[0m"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <typeinfo>

class Base
{
	public:
		virtual ~Base() {}
};

#endif
