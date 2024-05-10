/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:32:42 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/10 09:44:59 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Probablemente hacer ClapTraps esté empezando a ponerte de los nervios.
Ahora, implemente una clase FragTrap que hereda de ClapTrap. Es muy similar a 
ScavTrap. Sin embargo, sus mensajes de construcción y destrucción deben ser 
diferentes. En sus pruebas se debe mostrar un encadenamiento adecuado de 
construcción/destrucción. Cuando se crea un FragTrap, el programa comienza 
construyendo un ClapTrap. La destrucción ocurre en orden inverso.
Lo mismo para los atributos, pero esta vez con valores diferentes:
• Nombre, que se pasa como parámetro a un constructor 
• Puntos de vida (100), representan la salud del ClapTrap 
• Puntos de energía (100)
• Daño de ataque (30)
FragTrap también tiene una capacidad especial:
 void highFivesGuys(void);
Esta función miembro muestra una solicitud positiva de choca esos cinco en la 
salida estándar. Nuevamente, agregue más pruebas a su programa.*/

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	ClapTrap	Hero("Hero");
	ClapTrap	Villain("Villain");
	ScavTrap	Robot("Robot");
	FragTrap	Frag("Frag");
	
	
	Hero.printClapTrap();
	Villain.printClapTrap();
	Robot.printClapTrap();
	Frag.printClapTrap();
	Hero.attack(Villain.getName());
	Villain.takeDamage(0);
	Robot.guardGate();
	Villain.attack(Robot.getName());
	Robot.takeDamage(Villain.getAttackDamage());	
	Frag.attack(Villain.getName());
	Villain.takeDamage(Frag.getAttackDamage());
	Frag.highFivesGuys();
	return (0);
}
