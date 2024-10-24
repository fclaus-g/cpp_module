
/*Implementa una clase Serializer, que no será inicializable por el usuario de ninguna manera, con los siguientes métodos estáticos:
```cpp
uintptr_t serialize(Data* ptr);
```
Toma un puntero y lo convierte al tipo entero sin signo uintptr_t.
```cpp
Data* deserialize(uintptr_t raw);
```
Toma un parámetro entero sin signo y lo convierte en un puntero a Data.

Escribe un programa para probar que tu clase funciona como se espera.

Debes crear una estructura de datos no vacía (es decir, que tenga miembros de datos).

Usa serialize() en la dirección del objeto Data y pasa su valor de retorno a deserialize(). Luego, asegúrate de que el valor de retorno de deserialize() sea igual al puntero original.

No olvides entregar los archivos de tu estructura de datos.*/

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