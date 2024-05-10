/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:32:42 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/10 11:06:16 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*En este ejercicio, crearás un monstruo: un ClapTrap que es mitad FragTrap, 
mitad ScavTrap. Se llamará DiamondTrap y heredará tanto de FragTrap como de 
ScavTrap. ¡Esto es tan arriesgado!
La clase DiamondTrap tendrá un atributo privado de nombre. Asigne a este 
atributo exactamente el mismo nombre de variable (sin hablar aquí del nombre 
del robot) que el de la clase base de ClapTrap.
Para ser más claro, aquí hay dos ejemplos.
Si la variable de ClapTrap es nombre, asigne el nombre a la de DiamondTrap.
Si la variable de ClapTrap es _name, dale el nombre _name a la de DiamondTrap.
Sus atributos y funciones miembro se seleccionarán de cualquiera de sus clases principales:
• Nombre, que se pasa como parámetro a un constructor.
• ClapTrap::name (parámetro del constructor + sufijo "_clap_name") 
• Puntos de vida (FragTrap)
• Puntos de energía (ScavTrap)
• Daño de ataque (FragTrap)
• ataque() (Scavtrap)
C++ - Módulo 03 Herencia
Además de las funciones especiales de ambas clases principales, DiamondTrap 
tendrá su propia capacidad especial:
	anular quién soy ();
Esta función miembro mostrará tanto su nombre como su nombre de ClapTrap.
Por supuesto, el subobjeto ClapTrap de DiamondTrap se creará una vez, y sólo una vez. Sí, hay un truco.
Nuevamente, agregue más pruebas a su programa.*/

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void){
	ClapTrap	Hero("Hero");
	ClapTrap	Villain("Villain");
	ScavTrap	Robot("Robot");
	FragTrap	Frag("Frag");
	DiamondTrap	Diamond("Diamond");
	
	
	Hero.printClapTrap();
	Villain.printClapTrap();
	Robot.printClapTrap();
	Frag.printClapTrap();
	Diamond.printClapTrap();
	Hero.attack(Villain.getName());
	Villain.takeDamage(0);
	Robot.guardGate();
	Villain.attack(Robot.getName());
	Robot.takeDamage(Villain.getAttackDamage());	
	Frag.attack(Villain.getName());
	Villain.takeDamage(Frag.getAttackDamage());
	Frag.highFivesGuys();
	Diamond.whoAmI();
	Diamond.attack(Robot.getName());
	Robot.takeDamage(Diamond.getAttackDamage());
	return (0);
}
