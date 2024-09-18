#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*Dado que ahora tiene formularios básicos, es hora de crear algunos más que realmente hagan algo.
En todos los casos, 
* [x]la clase base Form debe ser una clase abstracta y, por lo tanto, debe renombrarse AForm. 
	Tenga en cuenta que los atributos del formulario deben permanecer privados y que están en la clase base.
Agregue las siguientes clases concretas:

• [x] ShrubberyCreationForm: Required grades: sign 145, exec 137
		* [x] Crea un archivo <target>_shrubbery en el directorio de trabajo y escribe árboles ASCII dentro de él.
• [x] RobotomyRequestForm: Required grades: sign 72, exec 45
		* [x] Hace algunos ruidos de perforación. 
		* [x] Luego, informa que <target> se ha robotizado con éxito el 50 % de las veces.
			De lo contrario, informa que la robotomización falló.
• [x] PresidentialPardonForm: Required grades: sign 25, exec 5
		* [x]Informa que <target> ha sido indultado por Zaphod Beeblebrox.
* [x]Todos ellos toman solo un parámetro en su constructor: el objetivo del formulario. Por
			ejemplo, "home" si desea plantar arbustos en su hogar.
9C++ - Módulo 05
Repetición y excepciones
* [x] Ahora, agregue la función miembro const execute(Bureaucrat const & executor) al formulario base 
	[x] e implemente una función para ejecutar la acción del formulario de las clases concretas. 
	[x] Debe verificar que el formulario esté firmado y que la calificación del burócrata que intenta ejecutar 
		el formulario sea lo suficientemente alta. De lo contrario, lance una excepción apropiada.

Depende de usted si desea verificar los requisitos en cada clase concreta o en la clase base
(luego llamar a otra función para ejecutar el formulario). Sin embargo, una forma es más bonita que la otra.
* [ ] Por último, agregue la función miembro executeForm(AForm const & form) al burócrata. Debe intentar ejecutar el formulario.
	Si tiene éxito, imprima algo como:
	<bureaucrat> performed <form> 
	Si no, imprima un mensaje de error explícito.
* [ ] Implemente y entregue algunas pruebas para asegurarse de que todo funcione como se espera.
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
	//AForm *badForm = new AForm("badForm", 0, 0);

	//Bureacrat executeForm test
	std::cout << YEL << "Bureacrat executeForm test" << RES << std::endl;
	hight.executeForm(form);
	lowRobot.executeForm(robot);


	std::cout << GRN << "\n Starts Destruction" << RES << std::endl;

	return 0;
}
