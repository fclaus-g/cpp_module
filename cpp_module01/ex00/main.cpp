/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:16:26 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/09 17:48:51 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Primero, implementa una clase Zombie. Tiene un atributo privado string name.
Añade una función miembro void announce( void ); a la clase Zombie. Los zombis
se anuncian como sigue:
<nombre>: BraiiiiiiinnnzzzZ...
No imprimas los corchetes angulares (< y >). Para un zombi llamado Foo, el mensaje
sería:
Foo: BraiiiiiiinnnzzzZ...
A continuación, implementa las dos funciones siguientes:
- Zombie* newZombie( std::string name );
Crea un zombi, ponle nombre y devuélvelo para que puedas usarlo fuera del ámbito de la función
ámbito.
- void randomChump( std::string nombre );
Crea un zombi, le asigna un nombre, y el zombi se anuncia a sí mismo.
Ahora, ¿cuál es el objetivo real del ejercicio? Tienes que determinar en qué caso
es mejor asignar los zombies en la pila o en el heap.
Los zombies deben ser destruidos cuando ya no los necesites. El destructor debe
imprimir un mensaje con el nombre del zombi para propósitos de depuración.*/