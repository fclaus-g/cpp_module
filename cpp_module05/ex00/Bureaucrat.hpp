/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:19:25 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/28 17:05:32 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

#define GRE "\033[32m"
#define RED "\033[31m"
#define RES "\033[0m"

class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& copy);
	
		std::string	getName() const;
		int			getGrade() const;
	
		void		incrementGrade();
		void		decrementGrade();
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

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
