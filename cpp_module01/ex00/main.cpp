/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:16:26 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/10 12:34:21 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Primero, implementa una clase Zombie. Tiene un atributo privado string name.
Añade una función miembro void announce( void ); a la clase Zombie. Los zombis
se anuncian como sigue:
<nombre>: BraiiiiiiinnnzzzZ...
No imprimas los corchetes angulares (< y >). Para un zombi llamado Foo, 
el mensaje sería:
Foo: BraiiiiiiinnnzzzZ...
A continuación, implementa las dos funciones siguientes:
- Zombie* newZombie( std::string name );
Crea un zombi, ponle nombre y devuélvelo para que puedas usarlo fuera del ámbito 
de la función.
- void randomChump( std::string nombre );
Crea un zombi, le asigna un nombre, y el zombi se anuncia a sí mismo.
Ahora, ¿cuál es el objetivo real del ejercicio? Tienes que determinar en qué caso
es mejor asignar los zombies en la pila o en el heap.
Los zombies deben ser destruidos cuando ya no los necesites. El destructor debe
imprimir un mensaje con el nombre del zombi para propósitos de depuración.*/

#include "Zombie.hpp"
#include <iostream>
#include <string>

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main(void)
{
	Zombie *zombie = newZombie("Zombie1");
	zombie->announce();
	randomChump("Zombie2");
	delete zombie;
	zombie = nullptr;
	return (0);
}

/*En este programa creamos dos zombies uno como puntero invocando 
newZombie("Zombie1"), en esta función se crea con el operador new(en el heap)
y el otro zombie lo creamos con randomChump("Zombie2"), en esta función se crea 
una variable zombie declarándola como tal(se almacena en la pila y al salir de 
la función se destruye ejecutando el destructor al salir).
El primer zombie se destruye  en el momento de llamar al operador delete 
invocando al destructor antes de eliminarse.*/