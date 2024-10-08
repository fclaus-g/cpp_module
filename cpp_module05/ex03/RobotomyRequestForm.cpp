/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:28:10 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/26 10:28:12 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*----------------------------[Canonical Ortodox]------------------------------*/

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	this->_target = "noTarget";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : Form(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExe())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	this->_target = rhs._target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &rhs){
		this->_target = rhs._target;
		this->setSign(rhs.getSigned());
	}
	return (*this);
}

/*Get*/

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

/*Method*/

void RobotomyRequestForm::action() const
{
	std::cout << YEL << "Drilling noises..." << RES << std::endl;
	std::srand(std::time(NULL));
	if (rand() % 2)
		std::cout << BLU << this->_target << " has been robotomized successfully" << RES << std::endl;
	else
		std::cout << RED << this->_target << " robotomization failed" << RES << std::endl;
}

/*Operator*/

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& form)
{
	out << GRN << "RobotomyRequestForm" << RES << std::endl;
	out << "Signed: " << form.getSigned() << std::endl;
	out << "Grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Grade to exe: " << form.getGradeToExe() << std::endl;
	out << "Target: " << form.getTarget() << std::endl;
	return (out);
}
