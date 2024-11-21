/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:37:43 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/21 18:49:04 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Debe crear un programa con estas restricciones:
•El nombre del programa es PmergeMe.
•Su programa debe poder usar una secuencia de números enteros positivos como argumento.
•Su programa debe usar el algoritmo de ordenamiento por combinación e inserción para ordenar la secuencia de números enteros positivos.

Para aclarar, sí, debe usar el algoritmo Ford-Johnson.
(fuente: Art Of Computer Programming, vol. 3. Merge Insertion,
página 184).
•Si ocurre un error durante la ejecución del programa, se debe mostrar un mensaje de error
en el error estándar.
Debe usar al menos dos contenedores diferentes en su código para
validar este ejercicio. Su programa debe poder manejar al
menos 3000 números enteros diferentes.
10
C++ - Módulo 09 STL
Se recomienda enfáticamente implementar su algoritmo para cada contenedor
y así evitar usar una función genérica.
A continuación se ofrecen algunas pautas adicionales sobre la información que debe mostrar línea por línea
en la salida estándar:
•En la primera línea debe mostrar un texto explícito seguido de la secuencia de
números enteros positivos sin ordenar.

•En la segunda línea debe mostrar un texto explícito seguido de la secuencia de
números enteros positivos ordenados.

•En la tercera línea debe mostrar un texto explícito que indique el tiempo utilizado por
su algoritmo especificando el primer contenedor utilizado para ordenar la secuencia de
números enteros positivos.

•En la última línea debe mostrar un texto explícito que indique el tiempo utilizado por
su algoritmo especificando el segundo contenedor utilizado para ordenar la secuencia de
números enteros positivos.

El formato para la visualización del tiempo utilizado para realizar su ordenación
es libre, pero la precisión elegida debe permitir ver claramente la
diferencia entre los dos contenedores utilizados.
A continuación se muestra un ejemplo de un uso estándar:
```bash
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$
```
La indicación de la hora es deliberadamente extraña en este ejemplo.
Por supuesto, debe indicar la hora utilizada para realizar todas sus operaciones, tanto la parte de ordenación como la parte de gestión de datos.

Atención: Los contenedores que utilizó en los ejercicios anteriores están
prohibidos aquí.
La gestión de errores relacionados con duplicados queda a su
discreción.
*/

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Usage " << av[0] << " <set of numbers>" << std::endl;
		return 1;
	}
	try {
		PmergeMe p(av);
		p.run();
		
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	return 0;
	}
}