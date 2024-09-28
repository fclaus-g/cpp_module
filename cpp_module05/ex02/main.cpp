/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:21:21 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/28 19:53:40 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Bureaucrat high("high", 1);
	std::cout << high << std::endl;
	Bureaucrat low("low", 150);
	std::cout << low << std::endl;

	//Test PresidentialPardonForm
	PresidentialPardonForm ppf("home");
	std::cout << ppf << std::endl;
	try
	{
		ppf.beSigned(high);//grade too low
		try
		{
			ppf.execute(low);//grade too low
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//Test RobotomyRequestForm 
	RobotomyRequestForm robot("home");
	std::cout << robot << std::endl;
	try
	{
		robot.beSigned(high);//grade too low
		try
		{
			robot.execute(high);//grade too low
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//Test ShrubberyCreationForm
	std::cout << "Test ShrubberyCreationForm" << std::endl;
	ShrubberyCreationForm shrubbery("home");
	std::cout << shrubbery << std::endl;
	try
	{
		shrubbery.beSigned(high);
		try
		{
			shrubbery.execute(low);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//Bad AForm test
	//std::cout << YEL << "Bad Form test" << RES << std::endl;
	//AForm *badAForm = new AForm("badAForm", 0, 0);

	//Bureacrat executeAForm test
	std::cout << YEL << "Bureacrat executeForm test" << RES << std::endl;
	try
	{
		high.executeForm(ppf);
		high.executeForm(robot);
		high.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << GRN << "\n Starts Destruction" << RES << std::endl;

	return 0;
}
