
/*Escriba una clase ScalarConverter que contenga solo un método estático "convert"
que tome como parámetro una representación en cadena de un literal de C++ en su forma más común y muestre su valor en la siguiente serie de tipos escalares:
• char
• int
• float
• double
Como esta clase no necesita almacenar nada en absoluto, los usuarios no deben poder instanciarla.

A excepción de los parámetros char, solo se utilizará la notación decimal.
Ejemplos de literales char: 'c', 'a', ...
Para simplificar las cosas, tenga en cuenta que los caracteres no visibles no deben usarse como
entradas. Si una conversión a char no se puede mostrar, imprime un mensaje informativo.
Ejemplos de literales int: 0, -42, 42...
Ejemplos de literales float: 0.0f, -4.2f, 4.2f...
También tienes que manejar estos pseudoliterales (ya sabes, por ciencia): -inff, +inff y nanf.
Ejemplos de literales double: 0.0, -4.2, 4.2...
También tienes que manejar estos pseudoliterales (ya sabes, por diversión): -inf, +inf y nan.*/

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert [literal]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}