#include "Bureaucrat.hpp"
#include "Form.hpp"

// /*Constructor*/
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) 
{
	std::cout <<this->_name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << this->_name << " Parametric constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade = grade;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		_grade = 1;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		_grade = 150;
	}
}

/*Copy constructor*/
/*Init the _name on the constructor because _name is const and its the only method for it
Add the string "copy" for clean and clear correction*/
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name + "copy")
{
	std::cout << this->_name << " Copy constructor called" << std::endl;
	*this = copy;
}

/*Destructor*/
Bureaucrat::~Bureaucrat() 
{
	std::cout << this->_name << " Destructor called" << std::endl;
}

/*Operator*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << this->_name << " Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return *this;
}

/*Getters*/

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

/*Functions*/

void Bureaucrat::incrementGrade()
{
	try 
	{
		if (_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		_grade = 1;
		return ;
	}
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if  (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
		_grade = 150;
		return ;
	}
	_grade++;
}


void Bureaucrat::signForm(Form& form)
{
	if (form.getSigned())
		std::cout << MAG << this->_name << " cannot sign " << form.getName() << " because " << this->_name << " has already signed" << RES << std::endl;
	else
	{
		if (this->_grade <= form.getGradeToSign())
			form.beSigned(*this);
		else
			std::cout << MAG << this->_name << " cannot sign " << form.getName() << " because " << this->_name << " grade is too low" << RES << std::endl;
	}
}

/*Exceptions*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}
