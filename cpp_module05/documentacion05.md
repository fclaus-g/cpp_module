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


## Ex 01 -> Forms

### Subject

Ahora que tienes burócratas, démosles algo que hacer. ¿Qué mejor actividad
que la de llenar una pila de formularios?
Entonces, hagamos una clase Form. Tiene:
• Un nombre constante.
• Un booleano que indica si está firmado (en la construcción, no lo está).
• Una calificación constante requerida para firmarlo.
• Y una calificación constante requerida para ejecutarlo.
Todos estos atributos son privados, no protegidos.
Las calificaciones del Form siguen las mismas reglas que se aplican al Bureaucrat. Por lo tanto,
se lanzarán las siguientes excepciones si una calificación de formulario está fuera de los límites:
Form::GradeTooHighException y Form::GradeTooLowException.
Al igual que antes, escriba captadores para todos los atributos y una sobrecarga del operador de inserción («) que imprima toda la información del formulario.
7C++ - Módulo 05
Repetición y excepciones
Agregue también una función miembro beSigned() al formulario que tome un burócrata como
parámetro. Cambia el estado del formulario a firmado si la calificación del burócrata es lo suficientemente alta
(superior o igual a la requerida). Recuerde, la calificación 1 es superior a la calificación 2.
Si la calificación es demasiado baja, genere una Form::GradeTooLowException.
Por último, agregue una función miembro signForm() al burócrata. Si el formulario se firmó,
imprimirá algo como:
<burócrata> firmó <formulario>
De lo contrario, imprimirá algo como:
<burócrata> no pudo firmar <formulario> porque <razón>.
Implemente y entregue algunas pruebas para asegurarse de que todo funcione como se espera.

### Objetivo

Seguir familiarizandonos con el manejo de excepciones, el uso de clases y la implementacion de métodos que hacen uso de otras clases.

### Desarrollo

En este ejercicio debemos crear una nueva clase Form, la cual tendrá unos grados para poder (o no) ser firmada y ejecutada por un burócrata, además haremos que en los métodos de nuestra clase Form se utilice la clase Bureaucrat y viceversa, cosa que hará que nos preocupemos por tener bien declarados nuestros includes. A continuación muestro como he desarrollado mi código con algún comentario.
```cpp
/*----------------[Form.hpp]------------------*/
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp" 
/*incluimos este header porque además de usar la class Bureaucrat 
tenemos declaradas aquí el resto de librerias que usaremos*/

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

/*-----------------[Form.cpp]---------------------*/

/*Además de los métodos de la forma canónica ortodoxa y los setters añadimos 
el método beSigned(), definición del método what() como hicimos en el ejercicio anterior
y la sobrecarga del operador "<<"*/
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
		std::cerr << e.what() << '\n';
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
	out << "Form name: " << form.getName() << std::endl;
	out << "Form signed: " << signedStr << std::endl;
	out << "Form grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Form grade to execute: " << form.getGradeToExe() << std::endl;
	return out;
}

/*Además de lo anterior deberemos de declarar y definir el método en signForm() Bureucrat,hpp y .cpp respectivamente
teniendo en cuenta que debemos declarar la clase Form en el .hpp y definir Form.hpp en Bureaucrat.cpp*/

/*----------------[Bureaucrat.hpp]---------------*/
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Form;

class Bureaucrat
{
	/*Atributos y metodos*/
};

/*-----------------[Bureaucrat.cpp]---------------*/
#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::signForm(Form& form)
{
	if (form.getSigned())
		std::cout << MAG << this->_name << " cannot sign " << form.getName() << " because " << this->_name << " has already signed" << RES << std::endl;
	else
	{
		if (this->_grade <= form.getGradeToSign())
			form.beSigned(*this);
		else
			std::cout << MAG << this->_name << " cannot sign " << form.getName() << " because " << this->_name << " grade is too low" << RES << std::endl;
	}
}
```
En este ejercicio me he encontrado con una peculiaridad la cual he querido resolver pero no se me ocurre una manera válida de solucionarlo. Cuando instanciamos un Bureaucrat con un _grade mayor o menor de lo permitido lo que hacemos es darle el valor mayor o menor permitido ya que _grade es un int, con el Form no sucede lo mismo, el Form tiene un const int _gradeToSign y un const int _gradeToExe, por lo que si instanciamos un Form con valores mayores o menores a los permitidos, podremos lanzar la excepción pero no tenemos una manera de modificar esos valores tras su inmediata construcción, así que si instanciamos un formulario de manera incorrecta quedará instanciado con los parámetros no permitidos.

## Ex 02 -> No, you need form 28B, not 28C...

### Subject

Dado que ahora tiene formularios básicos, es hora de crear algunos más que realmente hagan algo.
En todos los casos, la clase base Form debe ser una clase abstracta y, por lo tanto, debe
renombrarse AForm. Tenga en cuenta que los atributos del formulario deben permanecer privados y que
están en la clase base.
Agregue las siguientes clases concretas:
• ShrubberyCreationForm: Required grades: sign 145, exec 137
Crea un archivo <target>_shrubbery en el directorio de trabajo y escribe árboles ASCII
dentro de él.
• RobotomyRequestForm: Required grades: sign 72, exec 45
Hace algunos ruidos de perforación. Luego, informa que <target> se ha robotizado
con éxito el 50 % de las veces. De lo contrario, informa que la robotomización falló.
• PresidentialPardonForm: Required grades: sign 25, exec 5
Informa que <target> ha sido indultado por Zaphod Beeblebrox.
Todos ellos toman solo un parámetro en su constructor: el objetivo del formulario. Por
ejemplo, "home" si desea plantar arbustos en su hogar.
9C++ - Módulo 05
Repetición y excepciones
Ahora, agregue la función miembro constexecute(Bureaucrat const & executor) al formulario base e implemente una función para ejecutar la acción del formulario de las clases
concretas. Debe verificar que el formulario esté firmado y que la calificación del burócrata
que intenta ejecutar el formulario sea lo suficientemente alta. De lo contrario, lance una excepción apropiada.

Depende de usted si desea verificar los requisitos en cada clase concreta o en la clase base (luego llamar a otra función para ejecutar el formulario). Sin embargo, una forma es
más bonita que la otra.
Por último, agregue la función miembroexecuteForm(AForm const & form) al burócrata. Debe intentar ejecutar el formulario. Si tiene éxito, imprima algo como:
<bureaucrat> performed <form>
Si no, imprima un mensaje de error explícito.
Implemente y entregue algunas pruebas para asegurarse de que todo funcione como se espera.

## Ex 03 -> At least this beats coffee-making

### Subject

Como llenar formularios es bastante molesto, sería cruel pedirle a nuestros burócratas
que hagan esto todo el día. Afortunadamente, los pasantes existen. En este ejercicio, tienes que implementar
la clase Intern. El pasante no tiene nombre, grado ni características únicas. Lo único
que les importa a los burócratas es que hagan su trabajo.
Sin embargo, el pasante tiene una capacidad importante: la función makeForm(). Toma
dos cadenas. La primera es el nombre de un formulario y la segunda es el destino del
formulario. Devuelve un puntero a un objeto Form (cuyo nombre es el que se pasa como parámetro)
cuyo destino se inicializará con el segundo parámetro.
Imprimirá algo como:
Intern crea <form>
Si el nombre del formulario pasado como parámetro no existe, imprime un mensaje de error explícito.
11C++ - Módulo 05
Repetición y excepciones
Debes evitar soluciones ilegibles y feas como usar un bosque if/elseif/else. Este
tipo de cosas no se aceptarán durante el proceso de evaluación. Ya no estás en Piscine
(pool). Como siempre, tienes que probar que todo funciona como se espera.
Por ejemplo, el código siguiente crea un RobotomyRequestForm dirigido a "Bender":
```cpp
{
Intern
Form*
someRandomIntern;
rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```
