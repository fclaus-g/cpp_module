# Cpp modules 02

## Ex00->

### Subject

Crees que sabes números enteros y de punto flotante. Que lindo.
Lea este artículo de 3 páginas (1, 2, 3) para descubrir que no es así. Anda, léelo.
Hasta hoy, cada número que usabas en tu código era básicamente un número entero o de punto flotante, o cualquiera de sus variantes (corto, char, largo, doble, etc.). Después de leer el artículo anterior, es seguro asumir que los números enteros y de punto flotante tienen características opuestas.
Pero hoy las cosas cambiarán. Descubrirás un tipo de número nuevo e increíble: ¡los números de punto fijo! Siempre ausentes de los tipos escalares de la mayoría de los lenguajes, los números de punto fijo ofrecen un valioso equilibrio entre rendimiento, exactitud, rango y precisión. Eso explica por qué los números de punto fijo son particularmente aplicables a los gráficos por computadora, el procesamiento de sonido o la programación científica, solo por nombrar algunos.
Como C++ carece de números de punto fijo, los sumarás. Este artículo de Berkeley es un buen comienzo. Si no tienes idea de qué es la Universidad de Berkeley, lee esta sección de su página de Wikipedia.
Cree una clase en forma canónica ortodoxa que represente un número de punto fijo: • Miembros privados:
* Un número entero para almacenar el valor del número de punto fijo.
* Un entero constante estático para almacenar el número de bits fraccionarios. Es valioso
siempre será el literal entero 8. • Miembros públicos:
* Un constructor predeterminado que inicializa el valor numérico de punto fijo en 0.
* Un constructor de copias.
* Una sobrecarga del operador de asignación de copia.
* Un destructor.
* Una función miembro int getRawBits( void ) const; que devuelve el valor bruto del valor de punto fijo.
* Una función miembro void setRawBits( int const raw ); que establece el valor bruto del número de punto fijo.

Ejecutando este código:
```cpp
#include <iostream>
int main( void ) {
  Fixed a;
  Fixed b( a );
  Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl; std::cout << b.getRawBits() << std::endl; std::cout << c.getRawBits() << std::endl;
return 0; }
```
Debería mostrar algo parecido a esto:
```bash
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
```

