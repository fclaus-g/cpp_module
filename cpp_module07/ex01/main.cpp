
/*Implementa una plantilla de función iter que tome 3 parámetros y no devuelva nada.
• El primer parámetro es la dirección de una matriz.
• El segundo es la longitud de la matriz.
• El tercero es una función que se llamará en cada elemento de la matriz.
Entregue un archivo main.cpp que contenga sus pruebas. Proporcione suficiente código para generar un
ejecutable de prueba.
Su plantilla de función iter debe funcionar con cualquier tipo de matriz. El tercer parámetro
puede ser una plantilla de función instanciada.*/

#include <iostream>
#include "iter.hpp"

int main( void ) {
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "intArray: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	std::cout << "floatArray: ";
	iter(floatArray, 5, print<float>);
	std::cout << std::endl;

	std::cout << "stringArray: ";
	iter(stringArray, 5, print<std::string>);
	std::cout << std::endl;

	return 0;
}
