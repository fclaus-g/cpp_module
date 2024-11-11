/*Un primer ejercicio sencillo es la forma de empezar con el pie derecho.
Escribe una plantilla de función easyfind que acepte un tipo T. Toma dos parámetros.
El primero tiene el tipo T y el segundo es un entero.
Suponiendo que T es un contenedor de enteros, esta función tiene que encontrar la primera aparición
del segundo parámetro en el primer parámetro.
Si no se encuentra ninguna aparición, puedes lanzar una excepción o devolver un valor de error
de tu elección. Si necesitas algo de inspiración, analiza cómo se comportan los contenedores estándar.
Por supuesto, implementa y entrega tus propias pruebas para asegurarte de que todo funciona como se espera.
No tienes que manejar contenedores asociativos.*/

#include "easyfind.hpp"

int main ()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);
	vec.push_back(10);
	try
	{
		std::cout << easyfind(vec, 5) << std::endl;
		std::cout << easyfind(vec, 11) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}