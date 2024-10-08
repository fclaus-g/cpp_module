/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:20:57 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/26 10:20:58 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*----------------------------[Canonical Ortodox]----------------------------*/

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
		std::cout << RED << e.what() << RES << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << RED << e.what() << RES << std::endl;
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

/*----------------------------[Getter]----------------------------*/

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

/*----------------------------[Setter]----------------------------*/
void AForm::setSign(bool sign)
{
	this->_signed = sign;
}

/*----------------------------[Method]----------------------------*/

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	try
	{
		if (this->_signed)
			throw AForm::AFormSignedException();
		else if (this->_gradeToSign < 1 || this->_gradeToExe < 1)
			throw AForm::GradeInvalidException();
		else if (this->_gradeToSign > 150|| this->_gradeToExe > 150)
			throw AForm::GradeInvalidException();
		else if (this->_gradeToSign < bureaucrat.getGrade())
			throw AForm::GradeTooHighException();
		this->_signed = true;
		std::cout << GRN << bureaucrat.getName() << RES << " has signed " << this->_name << std::endl;
	}
	catch(const AForm::AFormSignedException& e)
	{
		std::cout << RED << bureaucrat.getName() << " cannot sign " << this->_name << RES << std::endl;
		std::cerr << RED << e.what() << RES << std::endl;
	}
	catch(const AForm::GradeInvalidException& e)
	{
		std::cout << RED << bureaucrat.getName() << " cannot sign " << this->_name << RES << std::endl;
		std::cerr << RED << e.what() << RES << std::endl;
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cout << RED << bureaucrat.getName() << " cannot sign " << this->_name << RES << std::endl;
		std::cerr << RED << e.what() << RES << std::endl;
		this->_signed = false;
	}
}

bool AForm::execute(Bureaucrat const& executor) const
{
	try
	{
		if (!this->_signed)
			throw AForm::AFormNotSignedException();
		else if (executor.getGrade() > this->_gradeToExe)
			throw AForm::GradeTooHighException();
		action();
		std::cout << GRN << executor.getName() << RES << " has executed " << this->_name << std::endl;
		return true;
	}
	catch(const AForm::AFormNotSignedException& e)
	{
		std::cout << RED << executor.getName() << " cannot execute " << this->_name << RES << std::endl;
		std::cerr << RED << e.what() << RES << std::endl;
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cout << RED << executor.getName() << " cannot execute " << this->_name << RES << std::endl;
		std::cerr << RED << e.what() << RES << std::endl;
	}
	return false;
}

/*---------------------[Excepction Methods]----------------------*/

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm: Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm: Grade is too low";
}

const char* AForm::AFormSignedException::what() const throw()
{
	return "AForm: AForm is already signed";
}

const char* AForm::AFormNotSignedException::what() const throw()
{
	return "AForm: AForm is not signed";
}
const char* AForm::GradeInvalidException::what() const throw()
{
	return "AForm: Grade of this AForm is invalid";
}

/*---------------------[Operator]----------------------*/

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	std::string signedStr;
	if (AForm.getSigned())
		signedStr = "true";
	else
		signedStr = "false";
	out << YEL << "AForm info" << RES << std::endl;
	out << "AForm name: " << AForm.getName() << std::endl;
	out << "AForm signed: " << signedStr << std::endl;
	out << "AForm grade to sign: " << AForm.getGradeToSign() << std::endl;
	out << "AForm grade to execute: " << AForm.getGradeToExe() << std::endl;
	return out;
}
