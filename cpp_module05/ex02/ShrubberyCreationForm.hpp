

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& copy);

		std::string	getTarget() const;
		void		action() const;
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif
