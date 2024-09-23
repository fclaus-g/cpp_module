
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
