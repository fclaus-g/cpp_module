/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:44:26 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/11 09:44:29 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*Implementa una clase Serializer, que no será inicializable por el usuario de ninguna manera, con los siguientes métodos estáticos:
```cpp
uintptr_t serialize(Data* ptr);
```
Toma un puntero y lo convierte al tipo entero sin signo uintptr_t.
```cpp
Data* deserialize(uintptr_t raw);
```
Toma un parámetro entero sin signo y lo convierte en un puntero a Data.

Escribe un programa para probar que tu clase funciona como se espera.

Debes crear una estructura de datos no vacía (es decir, que tenga miembros de datos).

Usa serialize() en la dirección del objeto Data y pasa su valor de retorno a deserialize(). Luego, asegúrate de que el valor de retorno de deserialize() sea igual al puntero original.

No olvides entregar los archivos de tu estructura de datos.*/

#include "Serializer.hpp"

int main()
{
	Data	data;

	data.id = 42;
	data.value = 3.14;
	data.name = "Hello, World!";

	// Serialize data
	uintptr_t	serialized = Serializer::serialize(&data);
	std::cout << "Serialized data: " << serialized << std::endl;
	std::cout << "Original data: " << &data << std::endl;
	// Deserialize data
	Data*	deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized data: " << deserialized << std::endl;
	std::cout << "Deserialized data->id: " << deserialized->id << std::endl;
	// Check if the deserialized data is the same as the original data
	std::cout << "Original data: " << &data << std::endl;
	if (deserialized == &data)
	{
		std::cout << "Deserialized data is the same as the original data." << std::endl;
	}
	else
		std::cout << "Deserialized data is not the same as the original data." << std::endl;
	return 0;
}
