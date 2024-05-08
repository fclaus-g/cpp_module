/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:21:36 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/08 15:17:19 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Primero, ¡debes implementar una clase! ¡Cuan original!
Se llamará ClapTrap y tendrá los siguientes atributos privados inicializados
a los valores especificados entre paréntesis:
• Nombre, que se pasa como parámetro a un constructor.
• Puntos de vida (10), representan la salud del ClapTrap.
• Puntos de energía (10)
• Daño de ataque (0)
Agregue las siguientes funciones de miembros públicos para que ClapTrap parezca
más realista:
• void attack(const std::string& target); 
• void takeDamage(unsigned int amount);
• void beRepaired(unsigned int amount);
Cuando ClapTrack ataca, hace que su objetivo pierda <daño de ataque> puntos de 
vida.
Cuando ClapTrap se repara solo, recupera <cantidad> puntos de vida. 
Atacar y reparar cuestan 1 punto de energía cada uno. Por supuesto, ClapTrap
no puede hacer nada si no tiene puntos de vida o puntos de energía restantes.
En todas estas funciones miembro, debe imprimir un mensaje para describir lo 
que sucede. Por ejemplo, la función attack() puede mostrar algo como 
(por supuesto, sin los corchetes angulares):
    ¡ClapTrap <nombre> ataca a <objetivo>, causando <daño> puntos de daño!
Los constructores y el destructor también deben mostrar un mensaje, para que 
sus pares evaluadores puedan ver fácilmente que han sido llamados.Implemente y
entregue sus propias pruebas para garantizar que su código funcione como se 
esperaba.*/

#include "ClapTrap.hpp"

int main(void){
	ClapTrap	Hero("Hero");
	ClapTrap	Villain("Villain");	
	
	Hero.printClapTrap();
	Villain.printClapTrap();
	Hero.attack(Villain.getName());
	Villain.takeDamage(0);
	Villain.setAttackDamage(5);
	std::cout<<"Villain take ungry power"<<std::endl;
	Villain.attack(Hero.getName());
	Hero.takeDamage(Villain.getAttackDamage());
	Hero.printClapTrap();
	std::cout<<"Hero take a magic sword"<<std::endl;
	Hero.beRepaired(5);
	Hero.setAttackDamage(10);
	Hero.attack(Villain.getName());
	Villain.takeDamage(Hero.getAttackDamage());
	Villain.printClapTrap();
	return (0);
}
