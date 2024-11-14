/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:37:43 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/14 18:40:44 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Debe crear un programa con estas restricciones:
* El nombre del programa es RPN.
* Su programa debe tomar una expresión matemática polaca invertida como argumento.

* Los números utilizados en esta operación y pasados ​​como argumentos siempre serán menores
a 10. El cálculo en sí mismo, pero también el resultado, no tienen en cuenta esta regla.
* Su programa debe procesar esta expresión y generar el resultado correcto en la salida
estándar.
* Si ocurre un error durante la ejecución del programa, se debe mostrar un mensaje de error en el error estándar.
* Su programa debe poder manejar operaciones con estos tokens: "+ - / *".
Debe usar al menos un contenedor en su código para validar este
ejercicio.
No necesita administrar los corchetes ni los números decimales.
A continuación, se muestra un ejemplo de un uso estándar:
```bash
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>
```
Advertencia: Los contenedores que utilizó en el ejercicio anterior están
prohibidos aquí. Los contenedores que utilizó para validar este ejercicio
no se podrán utilizar en el resto de este módulo.
*/

