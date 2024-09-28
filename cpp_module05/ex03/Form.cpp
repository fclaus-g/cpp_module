/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:27:15 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/28 20:07:52 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*----------------------------[Canonical Ortodox]----------------------------*/

Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExe(150)
{
	std::cout << this->_name << " Form constructor called" << std::endl;
}

Form::Form (std::string name, int gradeToSign, int gradeToExe): _name(name), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
	this->_signed = false;
	if (gradeToSign < 1 || gradeToExe < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExe > 150)
		throw Form::GradeTooLowException();
	std::cout << this->_name << " Form parametric constructor called" << std::endl;
}

Form::Form(const Form& copy): _name(copy._name + "copy"), _gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe)
{
	std::cout << this->_name << " Form copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	/*if (copy._signed)
		this->_signed = true;*/
}

Form::~Form()
{
	std::cout << this->_name << " Form destructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
	std::cout << this->_name << " Form assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return *this;
}

/*----------------------------[Getter]----------------------------*/

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExe() const
{
	return this->_gradeToExe;
}

/*----------------------------[Setter]----------------------------*/
void Form::setSign(bool sign)
{
	this->_signed = sign;
}

/*----------------------------[Method]----------------------------*/

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_signed)
		throw Form::FormSignedException();
	else if (this->_gradeToSign < 1 || this->_gradeToExe < 1)
		throw Form::GradeInvalidException();
	else if (this->_gradeToSign > 150|| this->_gradeToExe > 150)
		throw Form::GradeInvalidException();
	else if (this->_gradeToSign < bureaucrat.getGrade())
		throw Form::GradeTooHighException();
	this->_signed = true;
	std::cout << GRN << bureaucrat.getName() << RES << " has signed " << this->_name << std::endl;
}

bool Form::execute(Bureaucrat const& executor) const
{
	if (!this->_signed)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->_gradeToExe)
		throw Form::GradeTooHighException();
	action();
	std::cout << GRN << executor.getName() << RES << " has executed " << this->_name << std::endl;
	return true;
}

/*---------------------[Excepction Methods]----------------------*/

const char* Form::GradeTooHighException::what() const throw()
{
	return RED "Form: Grade is too high" RES;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return RED "Form: Grade is too low" RES;
}

const char* Form::FormSignedException::what() const throw()
{
	return RED "Form: Form is already signed" RES;
}

const char* Form::FormNotSignedException::what() const throw()
{
	return RED "Form: Form is not signed" RES;
}
const char* Form::GradeInvalidException::what() const throw()
{
	return RED "Form: Grade of this form is invalid" RES;
}

/*---------------------[Operator]----------------------*/

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	std::string signedStr;
	if (form.getSigned())
		signedStr = "true";
	else
		signedStr = "false";
	out << YEL << "Form info" << RES << std::endl;
	out << "Form name: " << form.getName() << std::endl;
	out << "Form signed: " << signedStr << std::endl;
	out << "Form grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Form grade to execute: " << form.getGradeToExe() << std::endl;
	return out;
}
