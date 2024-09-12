/*• [ ] PresidentialPardonForm: Required grades: sign 25, exec 5
		* [ ]Informa que <target> ha sido indultado por Zaphod Beeblebrox.
    	* [ ]Todos ellos toman solo un parámetro en su constructor: el objetivo del formulario. Por
			ejemplo, "home" si desea plantar arbustos en su hogar.*/
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
 	this->_target = "noTarget";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExe())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	this->_target = rhs._target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this != &rhs){
		this->_target = rhs._target;
		this->setSigned(rhs.getSigned());//pte añadir un setSigned a AForm
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExe())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


