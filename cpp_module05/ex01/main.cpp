/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:20:33 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/26 10:20:34 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << bone << std::endl;
	Bureaucrat hight("hight", 1);
	std::cout << hight << std::endl;
	Bureaucrat low("low", 150);
	std::cout << low << std::endl;
	Bureaucrat tooHight("toohight", 0);
	std::cout << tooHight << std::endl;
	Bureaucrat tooLow("toolow", 151);
	std::cout << tooLow << std::endl;

	Form basicForm;
	std::cout << GRN << "El siguiente formulario es el mas alto" << RES << std::endl;
	std::cout << basicForm << std::endl;
	Form hightForm("hightForm", 1, 1);
	std::cout << GRN << "El siguiente formulario es el mas bajo" << RES << std::endl;
	std::cout << hightForm << std::endl;
	Form lowForm("lowForm", 150, 150);
	std::cout << GRN << "El siguiente formulario debe mostrar too hight" << RES << std::endl;
	std::cout << lowForm << std::endl;
	Form badFormTooHight("badFormTooHight", 0, 150);
	std::cout << GRN << "El siguiente formulario debe mostrar too low" << RES << std::endl;
	std::cout << badFormTooHight << std::endl;
	Form badFormTooLow("badFormTooLow", 187, 1);
	std::cout << GRN << "El siguiente formulario es el formulario copia de hightForm" << RES << std::endl;
	std::cout << badFormTooLow << std::endl;
	Form f6(hightForm);//copia de hightForm
	std::cout << f6 << std::endl;//must be hightFormcopy,1 ,1.
	std::cout << GRN << "El siguiente formulario es el formulario copia de lowForm" << RES << std::endl;
	Form f7 = lowForm;//copia de lowForm
	std::cout << f7 << std::endl; //must be lowFormcopy, 150, 150.

	std::cout << GRN << "El siguiente formulario será firmado por el bureaucrat \"hight\"" << RES << std::endl;
	hightForm.beSigned(hight);
	std::cout << hightForm << std::endl;
	std::cout << GRN << "El siguiente formulario NO será firmado por el bureaucrat \"low\"" << RES << std::endl;
	hightForm.beSigned(low);
	std::cout << hightForm << std::endl;

	std::cout << GRN << "El siguiente Bureaucrat podra firmar el formulario" << RES << std::endl;
	hight.signForm(hightForm);
	std::cout << hightForm << std::endl;

	std::cout << GRN << "El siguiente Bureaucrat NO podra firmar el formulario" << RES << std::endl;
	low.signForm(hightForm);
	std::cout << GRN << "El siguiente Bureaucrat NO podra firmar el formulario" << RES << std::endl;
	bone.signForm(f6);
	std::cout << std::endl;

	std::cout << YEL << "The destruction starts" << RES << std::endl;
	return 0;
}
