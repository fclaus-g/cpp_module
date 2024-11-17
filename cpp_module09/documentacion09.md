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

### Explicación

Este programa toma como entrada un archivo llamado data.csv, que contiene datos sobre el valor de Bitcoin en fechas específicas, y otro archivo de entrada proporcionado por el usuario que incluye una lista de fechas y cantidades de Bitcoin.

Nuestro programa debe calcular y mostrar el valor de las transacciones dadas las fechas y los valores de Bitcoin.
 * **Requisitos específicos:**

 1. **Entrada**

	* El archivo data.csv (historial de precios del bitcoin) contiene las líneas en formato:
		
		YYYY-MM-DD,value
	
	* El archivo .txt que proporciona el usuario contiene el format:

		YYYY-MM-DD | amount

 2. **Salida**

	* Por cada linea del archivo del usuario, el programa debe calcular el valor total de la cantidad de Bitcoin en la fecha dada.
	* Por ejemplo, si el precio del bitcoin en 2022-01-01 es 47600.23 y la cantidad es 2 el resultado sería: 

		2022-01-01 => 2 = 95200.46

 3. **Validaciones**

	* Validar que el formato de la fecha sea correcto(YYYY-MM-DD)
	* validar que la cantidad de Bitcoin sea un número positivo.
	* Manejar errores con fechas fuera de rango o lineas mal formateadas
	

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

### Explicación

* **Notación polaca inversa**

La Notación Polaca Inversa (RPN, por sus siglas en inglés) es una forma de escribir expresiones matemáticas en la que los operandos van primero y los operadores después. También se conoce como postfija, ya que los operadores "se posponen".

* **Características principales de RPN**

1. Orden de operadores y operandos:

* En lugar de escribir A + B, se escribe A B +.
* No requiere paréntesis porque el orden de evaluación está determinado por la posición de los operadores y operandos.

2. Ventajas:

* Fácil de evaluar: Se utiliza una pila para procesar la expresión.
* Menos ambigüedad: No necesita reglas de precedencia ni paréntesis.

* **Como evaluar una expresión en RPN**

La evaluación sigue estos pasos:

1. Lee la expresión de izquierda a derecha.
2. Si es un número, lo empujas a la pila.
3. Si es un operador, sacas los dos últimos números de la pila, aplicas el operador y empujas el resultado de nuevo a la pila.
4. Al final, el resultado estará en la cima de la pila.

Ejemplo:
Expresión en RPN: 3 4 + 2 * 7 /

1. Empuja 3 y 4 a la pila.
2. Encuentras +, sumas 3 + 4 = 7. Empuja 7.
3. Empuja 2.
4. Encuentras *, multiplicas 7 * 2 = 14. Empuja 14.
5. Empuja 7.
6. Encuentras /, divides 14 / 7 = 2. Empuja 2.
7. Resultado: 2

* **Ventajas de RPN**

+ Simple para computadoras: Las calculadoras y programas pueden evaluarla fácilmente usando una pila.
+ Sin ambigüedades: No necesitas preocuparte por la precedencia de operadores ni paréntesis.
+ Compacta: Menos símbolos que las expresiones tradicionales.

* **Ejemplo de comparación**

Expresión infija: (5 + 3) * (8 - 2)

Expresión en RPN: 5 3 + 8 2 - *

En resumen, RPN es una forma eficiente y lógica de expresar operaciones matemáticas, ampliamente utilizada en aplicaciones computacionales como lenguajes de programación, compiladores, y calculadoras.

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