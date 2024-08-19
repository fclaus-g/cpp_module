#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form& copy);
	~Form();
	Form& operator=(const Form& copy);

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

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

#endif