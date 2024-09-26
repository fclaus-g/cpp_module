/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:25:58 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/26 10:26:00 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm ();
		RobotomyRequestForm (std::string target);
		RobotomyRequestForm (const RobotomyRequestForm& copy);
		virtual ~RobotomyRequestForm ();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

		std::string	getTarget() const;
		void		action() const;
};

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& form);

#endif
