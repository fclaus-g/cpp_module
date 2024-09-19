#include "Intern.hpp"
#include "Form.hpp"

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
	try
	{
		switch (i)
		{
			case 0:
			{
				std::cout << "Intern creates " << name << std::endl;
				return new ShrubberyCreationForm(target);
			}
			case 1:
			{
				std::cout << "Intern creates " << name << std::endl;
				return new RobotomyRequestForm(target);
			}
			case 2:
			{
				std::cout << "Intern creates " << name << std::endl;
				return new PresidentialPardonForm(target);
			}
			default:
				throw Intern::FormNotFoundException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (NULL);
}