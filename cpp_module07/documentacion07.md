# Cpp_module07 - Templates

## Ex00

### Subject

Implemente las siguientes plantillas de funciones:
* swap: intercambia los valores de dos argumentos dados. No devuelve nada.
* min: compara los dos valores pasados ​​en sus argumentos y devuelve el más pequeño.
Si los dos son iguales, devuelve el segundo.
* max: compara los dos valores pasados ​​en sus argumentos y devuelve el más grande.
Si los dos son iguales, devuelve el segundo.
Estas funciones se pueden llamar con cualquier tipo de argumento. El único requisito es
que los dos argumentos deben tener el mismo tipo y deben admitir todos los operadores de comparación.
Las plantillas se deben definir en los archivos de encabezado.
```cpp
int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}

/*Debería mostrar esto:
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
*/
```
 ### Teoría
 Las templates en C++ son una poderosa característica que permite definir funciones y clases genéricas, facilitando la creación de código reutilizable y flexible. Una plantilla puede aceptar uno o más parámetros de tipo, lo que permite a los programadores escribir funciones y clases que pueden operar con cualquier tipo de datos, siempre que esos tipos cumplan con ciertas condiciones (como la posibilidad de realizar operaciones específicas). Las plantillas se definen utilizando la palabra clave template, seguida de uno o más parámetros de tipo entre ángulos (<>). Durante la compilación, el compilador genera instancias específicas de las plantillas cuando se utilizan con tipos concretos. Esto no solo promueve la reutilización del código, sino que también proporciona una forma segura de implementar algoritmos y estructuras de datos que pueden trabajar con distintos tipos, sin sacrificar el rendimiento o la seguridad de tipos en tiempo de ejecución. Sin embargo, es importante recordar que la implementación de plantillas debe estar disponible en el archivo de encabezado, ya que el compilador necesita ver la definición completa de la plantilla en el momento de su instanciación.

 ### Implementación

 ```cpp
 #include <iostream>

// Función de plantilla para intercambiar dos valores
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Función de plantilla para encontrar el valor mínimo
template <typename T>
const T &min(const T &a, const T &b) {
    return (a < b ? a : b);
}

// Función de plantilla para encontrar el valor máximo
template <typename T>
const T &max(const T &a, const T &b) {
    return (a > b ? a : b);
}

int main() {
    int x = 5, y = 10;
    swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl; // x = 10, y = 5

    std::cout << "Min of x and y: " << min(x, y) << std::endl; // Min: 5
    std::cout << "Max of x and y: " << max(x, y) << std::endl; // Max: 10

    double a = 3.14, b = 2.71;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl; // a = 2.71, b = 3.14

    return 0;
}
```
## Ex01 

### Subject
Implementa una plantilla de función iter que tome 3 parámetros y no devuelva nada.
* El primer parámetro es la dirección de una matriz.
* El segundo es la longitud de la matriz.
* El tercero es una función que se llamará en cada elemento de la matriz.
Entregue un archivo main.cpp que contenga sus pruebas. Proporcione suficiente código para generar un
ejecutable de prueba.
Su plantilla de función iter debe funcionar con cualquier tipo de matriz. El tercer parámetro
puede ser una plantilla de función instanciada.

### Objetivo

El proyecto tiene como objetivo implementar una plantilla de función llamada iter, que permite aplicar una función específica a cada elemento de una matriz genérica. Las plantillas en C++ son una poderosa característica que permite definir funciones y clases de manera independiente del tipo de datos, promoviendo la reutilización del código y la flexibilidad. En este contexto, iter toma tres parámetros: un puntero a una matriz, la longitud de dicha matriz y un puntero a una función que se invocará para cada elemento de la matriz. Esta implementación permite trabajar con diferentes tipos de datos (como enteros y dobles) sin necesidad de escribir código específico para cada tipo. A través de esta función, se puede demostrar la versatilidad de las plantillas en C++, ya que permite aplicar operaciones de manera uniforme y eficiente en colecciones de datos heterogéneos.

### Implementación
```cpp
/*iter.hpp*/
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>

void iter(T *array, int length,F function)
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}

#endif

/*main.cpp*/
#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const &t)
{
	std::cout << t << " ";
}
template <typename T>
void increment(T &t)
{
	++t;
}

int main( void ) {
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "intArray: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	std::cout << "Increment intArray: ";
	iter(intArray, 5, increment<int>);
	std::cout << std::endl;

	std::cout << "intArray: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;
	

	std::cout << "floatArray: ";
	iter(floatArray, 5, print<float>);
	std::cout << std::endl;

	std::cout << "Increment floatArray: ";
	iter(floatArray, 5, increment<float>);
	std::cout << std::endl;

	std::cout << "floatArray: ";
	iter(floatArray, 5, print<float>);
	std::cout << std::endl;

	std::cout << "stringArray: ";
	iter(stringArray, 5, print<std::string>);
	std::cout << std::endl;

	return 0;
}
