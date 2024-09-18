
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
/* Canonical Ortodox*/
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
		//this->setSigned(rhs.getSigned());//pte añadir un setSigned a AForm
	}
	return (*this);
}

/*Get*/
std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

/*Method*/
void PresidentialPardonForm::action() const
{
	std::cout << BLU << this->_target << " has been pardoned by Zaphod Beeblebrox" << RES << std::endl;
}

/*Operator*/
std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form)
{
	out << GRN <<  "PresidentialPardonForm"<< RES << std::endl;
	out << "Signed: " << form.getSigned() << std::endl;
	out << "Grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Grade to exe: " << form.getGradeToExe() << std::endl;
	out << "Target: " << form.getTarget() << std::endl;
	return (out);
}
