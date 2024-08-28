#include "Form.hpp"
#include "Bureaucrat.hpp"

/*Entonces, hagamos una clase Form. Tiene:
• [x] Un nombre constante.
• [x] Un booleano que indica si está firmado (en la construcción, no lo está).
• [x] Una calificación constante requerida para firmarlo.
• [x] Y una calificación constante requerida para ejecutarlo.
[x] Todos estos atributos son privados, no protegidos.
Las calificaciones del Form siguen las mismas reglas que se aplican al Bureaucrat. Por lo tanto,
se lanzarán las siguientes excepciones si una calificación de formulario está fuera de los límites:
Form::GradeTooHighException y Form::GradeTooLowException.
Al igual que antes, 
* [x]Escriba captadores para todos los atributos y 
* [x]una sobrecarga del operador de inserción («) que imprima toda la información del formulario.
7C++ - Módulo 05
Repetición y excepciones
* [x]Agregue también una función miembro beSigned() al formulario que tome un burócrata como
parámetro. Cambia el estado del formulario a firmado si la calificación del burócrata es lo suficientemente alta
(superior o igual a la requerida). Recuerde, la calificación 1 es superior a la calificación 2.
Si la calificación es demasiado baja, genere una Form::GradeTooLowException.
Por último, 
* [x] agregue una función miembro signForm() al burócrata. Si el formulario se firmó,
imprimirá algo como:
<burócrata> firmó <formulario>
De lo contrario, imprimirá algo como:
<burócrata> no pudo firmar <formulario> porque <razón>.
Implemente y entregue algunas pruebas para asegurarse de que todo funcione como se espera.
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
