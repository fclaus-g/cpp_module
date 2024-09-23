#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
/*Dado que ahora tiene AFormularios básicos, es hora de crear algunos más que realmente hagan algo.
En todos los casos, 
* [x]la clase base AForm debe ser una clase abstracta y, por lo tanto, debe renombrarse AAForm. 
	Tenga en cuenta que los atributos del AFormulario deben permanecer privados y que están en la clase base.
Agregue las siguientes clases concretas:

• [x] ShrubberyCreationForm: Required grades: sign 145, exec 137
		* [x] Crea un archivo <target>_shrubbery en el directorio de trabajo y escribe árboles ASCII dentro de él.
• [x] RobotomyRequestForm : Required grades: sign 72, exec 45
		* [x] Hace algunos ruidos de perforación. 
		* [x] Luego, inAForma que <target> se ha robotizado con éxito el 50 % de las veces.
			De lo contrario, inAForma que la robotomización falló.
• [x] PresidentialPardonForm: Required grades: sign 25, exec 5
		* [x]InAForma que <target> ha sido indultado por Zaphod Beeblebrox.
* [x]Todos ellos toman solo un parámetro en su constructor: el objetivo del AFormulario. Por
			ejemplo, "home" si desea plantar arbustos en su hogar.
9C++ - Módulo 05
Repetición y excepciones
* [x] Ahora, agregue la función miembro const execute(Bureaucrat const & executor) al AFormulario base 
	[x] e implemente una función para ejecutar la acción del AFormulario de las clases concretas. 
	[x] Debe verificar que el AFormulario esté firmado y que la calificación del burócrata que intenta ejecutar 
		el AFormulario sea lo suficientemente alta. De lo contrario, lance una excepción apropiada.

Depende de usted si desea verificar los requisitos en cada clase concreta o en la clase base
(luego llamar a otra función para ejecutar el AFormulario). Sin embargo, una AForma es más bonita que la otra.
* [x] Por último, agregue la función miembro executeAForm(AAForm const & AForm) al burócrata. Debe intentar ejecutar el AFormulario.
	Si tiene éxito, imprima algo como:
	<bureaucrat> perAFormed <AForm> 
	Si no, imprima un mensaje de error explícito.
* [x] Implemente y entregue algunas pruebas para asegurarse de que todo funcione como se espera.
*/
int	main()
{
	Bureaucrat hight("hight", 1);
	std::cout << hight << std::endl;
	Bureaucrat low("low", 150);
	std::cout << low << std::endl;

	//Test PresidentialPardonForm
	PresidentialPardonForm ppf("home");
	std::cout << ppf << std::endl;

	ppf.beSigned(low);//grade too low
	ppf.execute(low);//grade too low
	std::cout << low << std::endl;

	std::cout << ppf << std::endl;
	ppf.beSigned(low);
	std::cout << ppf << std::endl;
	ppf.beSigned(hight);

	std::cout << hight << std::endl;
	std::cout << ppf << std::endl;
	ppf.execute(hight);
	std::cout << ppf << std::endl;


	ppf.execute(low);//deberia dar grade too low
	while (low.getGrade() > 6)//up the grade to 6
		low.incrementGrade();
	std::cout << low << std::endl;
	ppf.execute(low);

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

	//Bad AForm test
	//std::cout << YEL << "Bad AForm test" << RES << std::endl;
	//AAForm *badAForm = new AAForm("badAForm", 0, 0);

	//Bureacrat executeAForm test
	std::cout << YEL << "Bureacrat executeAForm test" << RES << std::endl;
	hight.executeForm(ppf);
	lowRobot.executeForm(robot);


	std::cout << GRN << "\n Starts Destruction" << RES << std::endl;

	return 0;
}
