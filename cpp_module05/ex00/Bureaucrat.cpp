#include "Bureaucrat.hpp"

// /*Constructor*/
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) 
{
	std::cout << "Default constructor called" << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Grade: " << _grade << std::endl;

}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "Parametric constructor called" << std::endl;
	this->_name = "paapagallido";
	this->_grade = 150;
	
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

/*Destructor*/
Bureaucrat::~Bureaucrat() 
{
	std::cout << "Destructor called" << std::endl;
}

/*Operator*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	//No se porque no se puede igualar _name = rhs._name
	//al rhs._name ser const  no se puede igualar a _name
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
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
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
