#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExe;
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExe);
		AForm(const AForm& copy);
		/*Declaramos el destructor como virtual para que se llame al destructor de las clases hijas*/
		virtual ~AForm();
		
		AForm& operator=(const AForm& copy);

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExe() const;

		void setSign(bool sign);

		void beSigned(Bureaucrat& bureaucrat);
			/*Declaramos la función execute que recibe un Bureaucrat como parametro y hará las
		comprobaciones pertinentes para la correcta ejecución*/
		bool execute(Bureaucrat const& executor) const;
		/*Añadimos la función virtual que nos hará la clase abstracta, esto hará que tengamos que definir
		esta funcion en cada subclase dandole el comportamiento que necesitemos segun clase*/
		virtual void action() const = 0;
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
		class FormSignedException : public std::exception
		{
			public:
			const char* what() const throw();
		};		
		class FormNotSignedException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		class GradeInvalidException : public std::exception
		{
			public:
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif