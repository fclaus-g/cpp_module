/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:20:33 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/28 19:49:59 by fclaus-g         ###   ########.fr       */
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
	Bureaucrat high("high", 1);
	std::cout << high << std::endl;
	Bureaucrat low("low", 150);
	std::cout << low << std::endl;

	Form basicForm;
	std::cout << basicForm << std::endl;
	std::cout << GRN << "El siguiente formulario es el mas alto" << RES << std::endl;
	Form highForm("highForm", 1, 1);
	std::cout << highForm << std::endl;
	std::cout << GRN << "El siguiente formulario es el mas bajo" << RES << std::endl;
	Form lowForm("lowForm", 150, 150);
	std::cout << lowForm << std::endl;
	try
	{
		std::cout << GRN << "El siguiente formulario debe mostrar la excepcion" << RES << std::endl;
		Form badForm("badFormToohigh", 0, 150);
		std::cout << badForm << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		highForm.beSigned(high);
		std::cout << highForm << std::endl;
		high.signForm(lowForm);
		std::cout << lowForm << std::endl;
		Form highFormCopy(highForm);
		low.signForm(highFormCopy);
		high.signForm(highForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << YEL << "The destruction starts" << RES << std::endl;
	return 0;
}
