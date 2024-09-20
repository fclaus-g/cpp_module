#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <string>


#ifndef INTERN_HPP
#define INTERN_HPP

class Intern
{
	public:
		Intern();
		Intern(const Intern& rhs);
		~Intern();
		Intern& operator=(const Intern& rhs);

		Form* makeForm(std::string name, std::string target);

		class FormNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
