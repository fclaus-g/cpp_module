/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:32:42 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/08 15:21:02 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Como nunca puedes tener suficientes ClapTraps, ahora crearás un robot 
derivado. Se llamará ScavTrap y heredará los constructores y destructores de 
ClapTrap. Sin embargo, sus constructores, destructor y attack() imprimirán 
mensajes diferentes. Después de todo, los ClapTraps son conscientes de su 
individualidad.
Tenga en cuenta que en sus pruebas se debe mostrar el encadenamiento adecuado
de construcción/destrucción. Cuando se crea un ScavTrap, el programa comienza 
construyendo un ClapTrap. La destrucción ocurre en orden inverso. ¿Por qué?
ScavTrap utilizará los atributos de ClapTrap (actualizará ClapTrap en 
consecuencia) y deberá inicializarlos para:
• Name, que se pasa como parámetro a un constructor.
• Hit points (100), representan la salud del ClapTrap.
• Energy points (50)
• Attack damage (20)
ScavTrap también tendrá su propia capacidad especial:
    void guardGate();
Esta función miembro mostrará un mensaje informando que ScavTrap ahora está en
modo Gate Keeper.
No olvide agregar más pruebas a su programa. 7*/

#include "ScavTrap.hpp"

int main(void){
	ClapTrap	Hero("Hero");
	ClapTrap	Villain("Villain");
	ScavTrap	Robot("Robot");
	
	Hero.printClapTrap();
	Villain.printClapTrap();
	Robot.printClapTrap();
	Hero.attack(Villain.getName());
	Villain.takeDamage(0);
	Robot.attack(Villain.getName());
	Villain.takeDamage(Robot.getAttackDamage());
	Robot.guardGate();
	return (0);
}
