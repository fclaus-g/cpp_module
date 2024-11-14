# Cpp_modules 09

## Ex00

### Subject

Debe crear un programa que muestre el valor de una cierta cantidad de bitcoins
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
ya no podrán utilizarse para el resto de este módulo.[]

## Ex01
Debe crear un programa con estas restricciones:
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

## Ex02

Debe crear un programa con estas restricciones:
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