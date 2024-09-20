#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

/*
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
*/
int	main()
{
	Bureaucrat officer("officer", 1);
	Intern intern;
	Form* form;
	Form* form2;
	Form* nonExistingForm;

	form = intern.makeForm("shrubbery creation", "home");
	form2 = intern.makeForm("robotomy request", "home");
	nonExistingForm = intern.makeForm("non existing form", "home");
	std::cout << *form << std::endl;
	std::cout << *form2 << std::endl;
	officer.signForm(*form);
	officer.signForm(*form2);
	officer.executeForm(*form2);
	if (nonExistingForm)
		std::cout << *nonExistingForm << std::endl;
	delete form;
	delete form2;
	std::cout << GRN << "\n Starts Destruction" << RES << std::endl;

	return 0;
}
