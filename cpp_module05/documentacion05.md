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
Hay que tener en cuenta que cuando acaba el bloque try todo lo que se declara es destruido, o lo que es lo mismo y ya sabemos es que lo que se crea en el ámbito de las llaves no existe fuera de este.
El bloque try y catch lo llamaremos en el main.
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
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
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
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
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

### Objetivo

Trabajar con clases abstractas y subclases, manejar excepciones, metodos virtuales... 

### Desarrollo

Este ejercicio conlleva manejar subclases, métodos virtuales y trabajar con métodos de las clase base. Es por ello que tenemos que tener claro que es lo que tenemos que hacer (a mi me costó bastante perdiéndome entre subclases y donde definir un método u otro), para eso es muy recomendable hacer un pequeño esquema con las clases con las que trabajaremos, sus atributos y sus clases.

En primer lugar tras modificar el Form del ejercicio anterior para que sea una clase abstracta AForm debemos decidir como plantear los métodos y las estructuras de control paraa ejecutarlos. En mi caso al principio decidí hacerlo en cada una de las subclases, pero claro, lógicamente es preferible que la clase abstracta se encargue de las estructuras de control y maneje las excepciones, con lo que, ahorraremos código y sería mas óptimo. Vamos a ver como implemente AForm:
```cpp
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
		void execute(Bureaucrat const& executor) const;
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
```
De esta manera conseguiremos que a la hora de implementar el método action en las subclases sea basicamente una impresión en pantalla, porque AForm ya se encarga de manejar si un bureaucrat es digno de firmar o ejecutar un formulario basandose en su grado.
Con las siguientes subclases trabajaremos usando la forma Canónica Ortodoxa:
```cpp
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

		std::string getTarget() const;
		void action() const;
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif
```
Una vez implementado de manera correcta AForm, implementaremos el método action en cada una de ellas. A tener en cuenta en cada uno de los métodos:
* **ShrubberyCreationForm->** Tiene que crear un archivo con el nombre [target]_Shrubbery y escribir en el un arbol ascii(un dibujo con caracteres ascii), para ello utilizaremos la biblioteca **fstream** que recordaremos que se utiliza para la manipulación de archivos, proporcionando clases para crear, leer y escribir archivos. Usando std::ofstream, si el archivo ya existe se borrará su contenido y se escribirá desde el principio. Si quisieramos agregar gcontenido en lugar de borrar habria que abrir el archivo en modo adición con **std::ios::app**.
```cpp
void ShrubberyCreationForm::action() const
{
	std::ofstream file;//declara un objeto file que se utilizará para escribir en el.
	std::string filename = this->_target + "_shrubbery";
	file.open(filename.c_str());//abre el archivo con el nombre indicado convirtiendo std::string en una cadena de caracteres de tipo C
	if (file.is_open())
	{
		//usaremos el operador << para escribir en el archivo
		file << "       _-_\n";
		file << "    /~~   ~~\\\n";
		file << " /~~         ~~\\\n";
		file << "{               }\n";
		file << " \\  _-     -_  /\n";
		file << "   ~  \\\\ //  ~\n";
		file << "_- -   | | _- _\n";
		file << "   _-  | |   -_\n";
		file << "  _-   | | __-_\n";
		file << "      // \\\\\n";
		file << this->_target << std::endl;
		file.close();
	}
	else
		std::cerr << "Error: could not open file" << std::endl;
}
```
* **RobotomyRequestForm_>** Debe imprimir un mensaje (Drilling noises...) y dar por válida la acción el 50% de las veces. Para ello tenemos que hacer uso de las bibliotecas **cstlib** y **ctime**, y las funciones **srand()** y **rand()**.
```cpp
#include <cstdlib> //Funciones generales de uso común como (la stdlib para c++), srand() y rand()
#include <ctime> //Funciones para manipular y obtener info sobre el tiempo y la fecha, time().

void RobotomyRequestForm::action() const
{
	std::cout << YEL << "Drilling noises..." << RES << std::endl;
	std::srand(std::time(NULL));//Establece la semilla del generador de números aleatorios
	if (rand() % 2)//generador de núm aleatorios
		std::cout << BLU << this->_target << " has been robotomized successfully" << RES << std::endl;
	else
		std::cout << RED << this->_target << " robotomization failed" << RES << std::endl;
}
```

* **PresidentialPardonForm->** Este método al haber implementado las estructuras de control en AForm solo mostrará un mensaje por pantalla.
```cpp
void PresidentialPardonForm::action() const
{
	std::cout << BLU << this->_target << " has been pardoned by Zaphod Beeblebrox" << RES << std::endl;
}
```

Veamos como hemos implementado las estructuras de control en el método execute() y beSigned() de nuestro AForm:
```cpp
void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_signed)
		throw AForm::FormSignedException();
	else if (this->_gradeToSign < 1 || this->_gradeToExe < 1)
		throw AForm::GradeInvalidException();
	else if (this->_gradeToSign > 150|| this->_gradeToExe > 150)
		throw AForm::GradeInvalidException();
	else if (this->_gradeToSign < bureaucrat.getGrade())
		throw AForm::GradeTooHighException();
	this->_signed = true;
	std::cout << GRN << bureaucrat.getName() << RES << " has signed " << this->_name << std::endl;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->_gradeToExe)
		throw AForm::GradeTooHighException();
	action();
	std::cout << GRN << executor.getName() << RES << " has executed " << this->_name << std::endl;
}
```

Tras tener completada la implementación de nuestras clases toca modificar a nuestro Bureaucrat para ejecutar el formulario desde el mismo burócrata. Una vez puesto manos a la obra de primeras intento que el bureaucrat en su método executeForm() haga un try and catch, pero al llamar a otro método que lanza una excepción el catch no saltaba y además era una solución con mas código a mi entender innecesario, así que decidí hacerlo de la siguiente manera, mas sencilla, ya que no queria duplicar excepciones y creo que es la manera correcta de hacerlo.

```cpp
void Bureaucrat::executeForm(const AForm& form)
{
	if (form.execute(*this))
		std::cout << "Bureaucrat: " << this->_name << " performed " << form.getName() << std::endl;
	else
		std::cout << RED << "Bureaucrat: " << this->_name << " cannot execute " << form.getName() << RED << std::endl;		
}
```
Para poder implementarlo simplemente hice que el método execute() del AForm retornara un bool para lanzar un mensaje u otro.


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
	Intern someRandomIntern;
	Form* rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```
### Objetivo

### Desarrollo

En este ejercicio vamos a implementar una clase nueva llamada Intern que se encargará de asignar valor a punteros *AForm(en el subject en el ejemplo declara el formulario como Form pero dado que Form no va a dejar de ser una clase abstracta he decidido dejarlo como AForm). Para esto Intern recibirá como parámetro el tipo de formulario que tiene que crear y el valor que le asignaremos a target. He decidido haciendo uso de lo que arendimos en anteriores ejercicios implementar en el método makeForm() un switch que creará uno u otro formulario a razón de lo que reciba. Veamos como lo he implementado:
```cpp
Form* Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;

	while (i < 3 && forms[i] != name)
		i++;
	switch (i)
	{
		case 0:
		{
			std::cout << GRN  << "Intern creates " << BLU << name << RES << std::endl;
			return new ShrubberyCreationForm(target);
		}
		case 1:
		{
			std::cout << GRN << "Intern creates " << BLU << name << RES << std::endl;
			return new RobotomyRequestForm(target);
		}
		case 2:
		{
			std::cout << GRN  << "Intern creates " << BLU << name << RES << std::endl;
			return new PresidentialPardonForm(target);
		}
		default:
			throw Intern::FormNotFoundException();
	}
}
```