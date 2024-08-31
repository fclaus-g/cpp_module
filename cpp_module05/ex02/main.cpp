#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*Dado que ahora tiene formularios básicos, es hora de crear algunos más que realmente hagan algo.
En todos los casos, 
* [ ]la clase base Form debe ser una clase abstracta y, por lo tanto, debe renombrarse AForm. 
	Tenga en cuenta que los atributos del formulario deben permanecer privados y que están en la clase base.
Agregue las siguientes clases concretas:

• [ ] ShrubberyCreationForm: Required grades: sign 145, exec 137
		* [ ] Crea un archivo <target>_shrubbery en el directorio de trabajo y escribe árboles ASCII dentro de él.
• [ ] RobotomyRequestForm: Required grades: sign 72, exec 45
		* [ ] Hace algunos ruidos de perforación. 
		* [ ] Luego, informa que <target> se ha robotizado con éxito el 50 % de las veces.
			De lo contrario, informa que la robotomización falló.
• [ ] PresidentialPardonForm: Required grades: sign 25, exec 5
		* [ ]Informa que <target> ha sido indultado por Zaphod Beeblebrox.
    	* [ ]Todos ellos toman solo un parámetro en su constructor: el objetivo del formulario. Por
			ejemplo, "home" si desea plantar arbustos en su hogar.
9C++ - Módulo 05
Repetición y excepciones
* [ ] Ahora, agregue la función miembro constexecute(Bureaucrat const & executor) al formulario base 
	[ ] e implemente una función para ejecutar la acción del formulario de las clases concretas. 
	[ ] Debe verificar que el formulario esté firmado y que la calificación del burócrata que intenta ejecutar 
		el formulario sea lo suficientemente alta. De lo contrario, lance una excepción apropiada.

Depende de usted si desea verificar los requisitos en cada clase concreta o en la clase base
(luego llamar a otra función para ejecutar el formulario). Sin embargo, una forma es más bonita que la otra.
* [ ] Por último, agregue la función miembroexecuteForm(AForm const & form) al burócrata. Debe intentar ejecutar el formulario.
	Si tiene éxito, imprima algo como:
	<bureaucrat> performed <form> 
	Si no, imprima un mensaje de error explícito.
* [ ] Implemente y entregue algunas pruebas para asegurarse de que todo funcione como se espera.
*/
int	main()
{
	Bureaucrat bone;
	Bureaucrat hight("hight", 1);
	Bureaucrat low("low", 150);
	Bureaucrat tooLow("toolow", 151);

	Form basicForm;
	Form hightForm("hightForm", 1, 1);
	std::cout << "este es el formulario mas alto" << std::endl;
	Form lowForm("lowForm", 150, 150);
	std::cout << "este es el formulario mas bajo" << std::endl;
	Form badFormTooHight("badFormTooHight", 0, 151);
	std::cout << "este formulario debe mostrar too hight" << std::endl;
	Form badFormTooLow("badFormTooLow", 151, 0);
	std::cout << "este formulario debe mostrar too hight" << std::endl;
	Form f6(hightForm);//copia de hightForm
	std::cout << "este es el formulario copia de hightForm" << std::endl;
	Form f7 = lowForm;//copia de lowForm
	std::cout << "este es el formulario copia de lowForm" << std::endl;

	std::cout << bone << std::endl;
	std::cout << hight << std::endl;
	std::cout << low << std::endl;
	std::cout << tooLow << std::endl;

	std::cout << basicForm << std::endl;
	std::cout << hightForm << std::endl;
	std::cout << lowForm << std::endl;
	std::cout << badFormTooHight << std::endl;
	std::cout << badFormTooLow << std::endl;
	std::cout << f6 << std::endl;//must be hightFormcopy,1 ,1.
	std::cout << f7 << std::endl; //must be lowFormcopy, 150, 150.

	hightForm.beSigned(hight);
	std::cout << hightForm << std::endl;
	hightForm.beSigned(low);
	std::cout << hightForm << std::endl;

	hight.signForm(hightForm);
	low.signForm(hightForm);
	bone.signForm(f6);

	return 0;
}
