/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:37:43 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/14 18:39:13 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Debe crear un programa que muestre el valor de una cierta cantidad de bitcoins
en una fecha determinada.
Este programa debe utilizar una base de datos en formato csv que represente el precio de bitcoins
a lo largo del tiempo. Esta base de datos se proporciona con este tema.
El programa tomará como entrada una segunda base de datos, que almacenará los diferentes precios/fechas
para evaluar.
Su programa debe respetar estas reglas:
* El nombre del programa es btc.
* Su programa debe tomar un archivo como argumento.
* Cada línea de este archivo debe utilizar el siguiente formato: "fecha | valor".
* Una fecha válida siempre tendrá el siguiente formato: Año-Mes-Día.
* Un valor válido debe ser un número flotante o un entero positivo, entre 0 y 1000.

[!WARNING] Debe utilizar al menos un contenedor en su código para validar este
ejercicio. Debe manejar los posibles errores con un mensaje de error
adecuado.

A continuación se muestra un ejemplo de un archivo input.txt:
```bash
$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
$>
```
Su programa utilizará el valor de su archivo de entrada.
Su programa debe mostrar en la salida estándar el resultado del valor multiplicado
por el tipo de cambio de acuerdo con la fecha indicada en su base de datos.
Si la fecha utilizada en la entrada no existe en su base de datos, entonces
debe utilizar la fecha más cercana contenida en su base de datos. Tenga cuidado de utilizar la fecha
inferior y no la superior.
El siguiente es un ejemplo del uso del programa.
```bash
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>
```
[!CAUTION]
Advertencia: Los contenedores que utilice para validar este ejercicio
ya no podrán utilizarse para el resto de este módulo.[]*/