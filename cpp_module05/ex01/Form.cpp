/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:20:20 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/26 10:20:21 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExe(150)
{
	std::cout << this->_name << " Form constructor called" << std::endl;
}

Form::Form (std::string name, int gradeToSign, int gradeToExe): _name(name), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
	this->_signed = false;
	try
	{
		if (gradeToSign < 1 || gradeToExe < 1)
			throw Form::GradeTooHighException();
		if (gradeToSign > 150 || gradeToExe > 150)
				throw Form::GradeTooLowException();
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << RED << e.what() << RES << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << RED << e.what() << RES << '\n';
	}
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

void Form::beSigned(Bureaucrat& bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= this->_gradeToSign)
			this->_signed = true;
		else
			throw Form::GradeTooLowException();

	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << RED << e.what() << RES << '\n';
		this->_signed = false;
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form:Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form:Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
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
