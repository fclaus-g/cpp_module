/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:37:56 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/15 11:54:04 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Implemente una clase de Arma que tenga:
• Un tipo de atributo privado, que es una cadena.
• Una función miembro getType() que devuelve una referencia constante al tipo.
• Una función miembro setType() que establece el tipo usando el nuevo pasado 
como parámetro.
Ahora, crea dos clases: HumanA y HumanB. Ambos tienen un arma y un
nombre. También tienen una función miembro attack() que muestra (por supuesto,
sin el paréntesis angulares):
<nombre> ataca con su <tipo de arma>
HumanA y HumanB son casi iguales excepto por estos dos pequeños detalles:
• Mientras HumanA toma el Arma en su constructor, HumanB no.
• Es posible que HumanB no siempre tenga un arma, mientras que HumanA siempre
estará armado.
8 Asignación de memoria, punteros a los miembros,
referencias, declaración de cambio

Si su implementación es correcta, ejecutar el siguiente código imprimirá un 
ataque con "un garrote tosco con púas" y luego un segundo ataque con "algún otro
tipo de garrote" para ambos
Casos de prueba:*/
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("baseball bat");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("baseball bat");
		jim.attack();
	}
	return 0;
}