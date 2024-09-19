#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
	Bureaucrat hight("hight", 1);
	std::cout << hight << std::endl;
	Bureaucrat low("low", 150);
	std::cout << low << std::endl;

	//Test PresidentialPardonForm
	PresidentialPardonForm form("home");
	std::cout << form << std::endl;

	form.beSigned(low);//grade too low
	form.execute(low);//grade too low
	std::cout << low << std::endl;

	std::cout << form << std::endl;
	form.beSigned(low);
	std::cout << form << std::endl;
	form.beSigned(hight);

	std::cout << hight << std::endl;
	std::cout << form << std::endl;
	form.execute(hight);
	std::cout << form << std::endl;


	form.execute(low);//deberia dar grade too low
	while (low.getGrade() > 6)//up the grade to 6
		low.incrementGrade();
	std::cout << low << std::endl;
	form.execute(low);

	//Test RobotomyRequestForm
	Bureaucrat lowRobot("lowRobot", 150);
	std::cout << lowRobot << std::endl;
	Bureaucrat hightRobot("hightRobot", 1);
	std::cout << hightRobot << std::endl;
	RobotomyRequestForm robot("C3PO");
	std::cout << robot << std::endl;

	robot.beSigned(lowRobot);//grade too low
	robot.execute(lowRobot);//not signed

	robot.execute(hightRobot);//not signed
	robot.beSigned(hightRobot);
	robot.execute(hightRobot);
	robot.execute(lowRobot);
	robot.execute(hightRobot);

	//Test ShrubberyCreationForm
	std::cout << "Test ShrubberyCreationForm" << std::endl;
	ShrubberyCreationForm shrubbery("home");
	std::cout << shrubbery << std::endl;
	std::cout << "Test copy constructor" << std::endl;
	ShrubberyCreationForm shrubbery_copy(shrubbery);
	std::cout << shrubbery_copy << std::endl;
	std::cout << "Test assignation operator" << std::endl;
	ShrubberyCreationForm shrubbery_assign = shrubbery;
	std::cout << shrubbery_assign << std::endl;

	shrubbery.beSigned(lowRobot);//grade too low
	shrubbery.execute(lowRobot);//not signed
	std::cout << shrubbery << std::endl;
	shrubbery.execute(hightRobot);//not signed
	shrubbery.beSigned(hightRobot);
	std::cout << shrubbery << std::endl;
	shrubbery.execute(hightRobot);

	//Bad Form test
	//std::cout << YEL << "Bad Form test" << RES << std::endl;
	//Form *badForm = new Form("badForm", 0, 0);

	//Bureacrat executeForm test
	std::cout << YEL << "Bureacrat executeForm test" << RES << std::endl;
	hight.executeForm(form);
	lowRobot.executeForm(robot);


	std::cout << GRN << "\n Starts Destruction" << RES << std::endl;

	return 0;
}
