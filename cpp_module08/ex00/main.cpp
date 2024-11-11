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
	std::cout << GRE << "Testing with vector" << RES << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	try
	{
		std::cout << easyfind(vec, 5) << std::endl;
		std::cout << easyfind(vec, 11) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << GRE << "Testing with list" << RES << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	try
	{
		std::cout << easyfind(lst, 3) << std::endl;
		std::cout << easyfind(lst, 6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
	}
	
	std::cout << GRE << "Testing with Map" << RES << std::endl;
	std::map<int, int> map;
	map[1] = 1;
	map[2] = 2;
	map[3] = 3;
	map[4] = 4;
	map[5] = 5;
	try
	{
		std::cout << easyfind(map, 3) << std::endl;
		std::cout << easyfind(map, 6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
	}
	return 0;
}