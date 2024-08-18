# cpp modules 05

## Ex 00 -> Mommy, I want to be a bureaucrat.

### Subject
Diseñemos una pesadilla artificial de oficinas, pasillos, formularios y colas de espera.
¿Suena divertido? ¿No? Qué lástima.
Primero, comience por el engranaje más pequeño de esta vasta máquina burocrática: el burócrata.
Un **burócrata** debe tener:
• Un nombre de constante.
• Y una calificación que va desde 1 (la calificación más alta posible) hasta 150 (la calificación más baja posible).
Cualquier intento de instanciar un burócrata utilizando una calificación no válida debe generar una excepción:
ya sea una **Bureaucrat::GradeTooHighException** o una **Bureaucrat::GradeTooLowException.**
5C++ - Módulo 05
Repetición y excepciones
Proporcionará captadores para ambos atributos: getName() y getGrade(). Implemente también dos funciones miembro para incrementar o decrementar la calificación del burócrata. Si
la calificación está fuera de rango, ambas arrojarán las mismas excepciones que el constructor.
Recuerde. Dado que la calificación 1 es la más alta y 150 la más baja,
incrementar una calificación 3 debería darle una calificación 2 al burócrata.
Las excepciones arrojadas deben poder capturarse mediante bloques try y catch:
try
{
/* hacer algunas cosas con burócratas */
}
catch (std::exception & e)
{
/* manejar excepción */
}
Implementará una sobrecarga del operador de inserción («) para imprimir algo como
(sin los corchetes angulares):
<nombre>, calificación del burócrata <calificación>.
Como siempre, entregue algunas pruebas para demostrar que todo funciona como se espera.

### Objetivo

Primer contacto con las excepciones y como manejarlas.

### Desarrollo
En este ejercicio nos encontramos por primera vez con las excepciones y su manejo, utilizaremos la std::exception para ello y sobreescribiremos el método what() de dicha clase,  que es el método con el que obtendremos info sobre el error que causó la excepción. Aqui tenemos un ejemplo de como lo implementé en el .hpp.
Usaremos también las palabras clave **try, throw, y catch** con las que manejaremos las excepciones. Veamos nuestra implementación del ejercicio.
```cpp
/*---------------------[HEADER]-------------------------*/
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
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
		/**/
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

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif

/*-----------------------[Bureaucrat.cpp]--------------------------------*/

/*Ejemplo de comomanejaremos las excepciones en nuestro ejercicio*/
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << this->_name << " Parametric constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade = grade;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		_grade = 1;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		_grade = 150;
	}
}

void Bureaucrat::incrementGrade()
{
	try 
	{
		if (_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		_grade = 1;
		return ;
	}
	_grade--;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

/*Copy constructor*/
/*Añado este código porque asi solucioné que el constructor de copia y el operador = añadan el nombre
del Bureaucrat del que toman los atributos más la palabra copy. Me pareció interesante para hacer mas claro 
tanto la corrección como la salida del prorama cuando un Bureaucrat toma el valor de otro*/
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name + "copy")
{
	std::cout << this->_name << " Copy constructor called" << std::endl;
	*this = copy;
}

```

