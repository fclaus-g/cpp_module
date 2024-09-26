/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:20:25 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/26 10:20:26 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExe;
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExe);
		Form(const Form& copy);
		~Form();
		Form& operator=(const Form& copy);

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExe() const;

		void beSigned(Bureaucrat& bureaucrat);
		/*Declaramos la clase GradeToHighExcepcion que hereda de std::exception*/
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();//sobreescribe el método what() de la clase std::exception
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
