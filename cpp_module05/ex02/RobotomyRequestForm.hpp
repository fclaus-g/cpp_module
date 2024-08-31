/*• [ ] RobotomyRequestForm: Required grades: sign 72, exec 45
		* [ ] Hace algunos ruidos de perforación. 
		* [ ] Luego, informa que <target> se ha robotizado con éxito el 50 % de las veces.
			De lo contrario, informa que la robotomización falló.*/

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

		void execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& form);

#endif