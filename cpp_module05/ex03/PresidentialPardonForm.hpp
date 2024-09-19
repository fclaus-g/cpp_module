
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

		std::string getTarget() const;
		void action(void) const;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form);

#endif