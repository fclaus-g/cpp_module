#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExe(150)
{
	std::cout << this->_name << " AForm constructor called" << std::endl;
}

AForm::AForm (std::string name, int gradeToSign, int gradeToExe): _name(name), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
	this->_signed = false;
	try
	{
		if (gradeToSign < 1 || gradeToExe < 1)
			throw AForm::GradeTooHighException();
		else if (gradeToSign > 150 || gradeToExe > 150)
			throw AForm::GradeTooLowException();
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << this->_name << " AForm parametric constructor called" << std::endl;
}

AForm::AForm(const AForm& copy): _name(copy._name + "copy"), _gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe)
{
	std::cout << this->_name << " AForm copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	/*if (copy._signed)
		this->_signed = true;*/
}

AForm::~AForm()
{
	std::cout << this->_name << " AForm destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
	std::cout << this->_name << " AForm assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExe() const
{
	return this->_gradeToExe;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= this->_gradeToSign)
			this->_signed = true;
		else
			throw AForm::GradeTooLowException();

	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
		this->_signed = false;
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm:Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm:Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	std::string signedStr;
	if (form.getSigned())
		signedStr = "true";
	else
		signedStr = "false";
	out << "AForm name: " << form.getName() << std::endl;
	out << "AForm signed: " << signedStr << std::endl;
	out << "AForm grade to sign: " << form.getGradeToSign() << std::endl;
	out << "AForm grade to execute: " << form.getGradeToExe() << std::endl;
	return out;
}
