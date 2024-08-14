#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>//quiza no sea necesario

class Bureaucrat
{
	private:
	const std::string	_name;
	int 				_grade;
	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();
	Bureaucrat &operator = (const Bureaucrat &copy);
	
	std::string	getName() const;
	int			getGrade() const;
	
	void		incrementGrade();
	void		decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char* what() const throw();
	};
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif 