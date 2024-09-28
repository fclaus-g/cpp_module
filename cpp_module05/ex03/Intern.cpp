/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:27:30 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/28 20:03:17 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern& rhs)
{
	std::cout << "Intern copy constructor" << std::endl;
	*this = rhs;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
	std::cout << "Intern assignation operator" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;

	while (i < 3 && forms[i] != name)
		i++;
	switch (i)
	{
		case 0:
		{
			std::cout << GRN  << "Intern creates " << BLU << name << RES << std::endl;
			return new ShrubberyCreationForm(target);
		}
		case 1:
		{
			std::cout << GRN << "Intern creates " << BLU << name << RES << std::endl;
			return new RobotomyRequestForm(target);
		}
		case 2:
		{
			std::cout << GRN  << "Intern creates " << BLU << name << RES << std::endl;
			return new PresidentialPardonForm(target);
		}
		default:
			throw Intern::FormNotFoundException();
	}
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return (RED "Form not found" RES);
}
