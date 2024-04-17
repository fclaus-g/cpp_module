/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:01:50 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/17 13:02:19 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

/*COLOURS*/
# define GRN "\033[32m"
# define YEL "\033[33m"
# define ORG "\033[38;5;208m"
# define RED "\033[31m"
# define RST "\033[0m"

# define DEBUG_MSG "[DEBUG]I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do! "
# define INFO_MSG "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING_MSG "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month. "
# define ERROR_MSG "[ERROR] This is unacceptable! I want to speak to the manager now"

#include <iostream>
#include <string>



class Harl
{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
	public:
		Harl(void);
		~Harl(void);
		void complain( std::string level );
};

#endif