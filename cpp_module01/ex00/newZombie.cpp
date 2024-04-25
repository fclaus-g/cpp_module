/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:16:45 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/24 17:59:10 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Función que crea un nuevo zombie con el operador new
*new*-> asigna dinámicamente memoria en el heap, creando un nuevo objeto en
heap y devuelve un puntero a él.
*heap*-> Es una región de memoria del sistema que se utiliza para la asignación
de memoria dinámica de memoria. A diferencia de la pila(donde se almacenan las
variables locales) el heap no tiene un orden de asignación y liberación de 
memoria específicopor lo que hay que liberar la memoria despues de su uso
con el operador delete y establecer el puntero a NULL (nullptr  en c++ 11)*/

Zombie	*newZombie(std::string name) 
{
	Zombie *zombie = new Zombie(name);
	return zombie;
}
