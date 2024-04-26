/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:50:04 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/26 10:59:19 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*¿Conoces a Harl? Todos lo hacemos, ¿verdad? En caso de que no lo hagas, encuentra a continuación el tipo de
comentarios que hace Harl. Se clasifican por niveles:
• Nivel "DEBUG": los mensajes de depuración contienen información contextual. son en su mayoría
utilizado para el diagnóstico de problemas.
Ejemplo: "Me encanta tener tocino extra para mi 7XL-doble-queso-triple-pepinillo-especial-
hamburguesa con salsa de tomate. ¡Realmente lo hago!"
• Nivel "INFO": Estos mensajes contienen amplia información. Son útiles para
Seguimiento de la ejecución del programa en un entorno de producción.
Ejemplo: "No puedo creer que agregar tocino extra cueste más dinero. No pusiste
¡Suficiente tocino en mi hamburguesa! ¡Si lo hicieras, no pediría más!"
• Nivel "ADVERTENCIA": los mensajes de advertencia indican un problema potencial en el sistema.
Sin embargo, se puede manejar o ignorar.
Ejemplo: "Creo que merezco un poco de tocino extra gratis. He estado viniendo por
años mientras que tú empezaste a trabajar aquí desde el mes pasado."
• Nivel "ERROR": Estos mensajes indican que se ha producido un error irrecuperable.
Este suele ser un problema crítico que requiere intervención manual.
Ejemplo: "¡Esto es inaceptable! Quiero hablar con el gerente ahora".
11Asignación de memoria, indicaciones para los miembros,
referencias, declaración de cambio
C++ - Módulo 01
Vas a automatizar a Harl. No será difícil ya que siempre dice lo mismo.
cosas. Tienes que crear una clase Harl con las siguientes funciones de miembros privados:
• depuración nula (nulo);
• información nula (anular);
• advertencia de anulación (anula);
• error de anulación (anular);
Harl también tiene una función miembro pública que llama a las cuatro funciones miembro anteriores.
dependiendo del nivel pasado como parámetro:
vacío
complain (std::nivel de cadena);
El objetivo de este ejercicio es utilizar punteros a funciones miembro. Esto no es una
sugerencia. Harl tiene que quejarse sin usar un bosque de if/else if/else. no piensa
¡dos veces!
Cree y entregue pruebas para demostrar que Harl se queja mucho. Puedes usar los ejemplos.
de los comentarios enumerados anteriormente en el asunto o elija utilizar sus propios comentarios.
*/

#include "Harl.hpp"

void	printMsg()
{
	std::cout << "Harl is a very special person. He always says the same things."<<std::endl;
	std::cout << "He has 4 levels of complaints: DEBUG, INFO, WARNING, ERROR." <<std::endl;
	std::cout << "You can make him complain by typing one of these levels. If you want to exit, type EXIT." << std::endl;

}

int main(void) 
{
	std::string	input;
	Harl 		harl;
		
	printMsg();
	do
	{
		std::cout << "Enter the level of complaint: ";
		std::cin >> input;
		harl.complain(input);
	} while (input != "EXIT");
	return (0);
}
