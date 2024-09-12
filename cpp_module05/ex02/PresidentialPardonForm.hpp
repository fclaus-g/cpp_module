/*
• [ ] PresidentialPardonForm: Required grades: sign 25, exec 5
		* [ ]Informa que <target> ha sido indultado por Zaphod Beeblebrox.
    	* [ ]Todos ellos toman solo un parámetro en su constructor: el objetivo del formulario. Por
			ejemplo, "home" si desea plantar arbustos en su hogar.
*/

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

		void execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form);

#endif