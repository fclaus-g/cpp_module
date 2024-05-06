# Cpp modules 02
De ahora en adelante, todas tus clases deben estar diseñadas en la Forma Canónica Ortodoxa,
salvo que expresamente se indique lo contrario. Luego, implementarán los cuatro miembros requeridos.
funciones a continuación:
• Constructor predeterminado
• Copiar constructor
• Copiar operador de asignación
• Destructor
Divide tu código de clase en dos archivos. El archivo de encabezado (.hpp/.h) contiene la clase
definición, mientras que el archivo fuente (.cpp) contiene la implementación.
## Ex00->Fixed

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
std::cout << a.getRawBits() << std::endl; 
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
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
### Objetivo

Conocer y practicar la forma *canónica ortodoxa*, trabajar con la sobrecarga de funciones(funciones con el mismo nombre y con diferentes argumentos) y la sobrecarga de operadores (aclara el comportamiento de un operador cuando se hacen operaciones entre clases y conocer que es el formato de punto fijo.

### Desarrollo

Para la ejecución de este ejercicio vamos a crear una clase fixed cun la que usaremos la forma *canónica ortodoxa* que define:
1. Un constructor por defecto.
2. Un constructor de copia.
3. Un operador de asignación de copia.
4. Un destructor.

De la siguiente manera:
```cpp
 class Fixed{
	private:
		int _value;
		static const int _bits = 8;
	public:
		Fixed();//costuctor
		Fixed(const Fixed &copy);//constructor de copias
		Fixed &operator=(const Fixed &copy);//sobrecarga del operador de asignación de copia
		~Fixed();//destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
```
Estas convenciones son importantes cuando una clase maneja recursos, como memoria dinámica o archivos(deben ser adecuadamente liberados o cerrados).

El main quedaría de la siguiente manera:
```cpp
int main( void ) 
{
	Fixed a;
  Fixed b(a); //Usa el constructor de copia
  Fixed c;
	c = b;//Usa el operador de asignación de copia
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
return 0; 
}
```

**Formato de punto fijo->** Es una representación de num reales en informática que proporciona un num fijo de dígitos antes y después de la coma decimal. Un num se reptresenta como un entero que se divide por una potencia de 2 para obtener el valor real. Ej: Si tienes un num de 16bits en unto fijo con 8bits en la parte entera y 8bits para la parte fraccionaria. El num 256 representaría el num 1.0(256/2⁸= 1)

## Ex01->Fixed II

### Subject
El ejercicio anterior fue un buen comienzo pero nuestra clase es bastante inútil. Sólo puede
representan el valor 0,0.
Agregue los siguientes constructores públicos y funciones miembro públicas a su clase:
• Un constructor que toma un número entero constante como parámetro.
Lo convierte al valor de punto fijo correspondiente. El valor de bits fraccionarios es
inicializado a 8 como en el ejercicio 00.
• Un constructor que toma un número de coma flotante constante como parámetro.
Lo convierte al valor de punto fijo correspondiente. El valor de bits fraccionarios es
inicializado a 8 como en el ejercicio 00.
• Una función miembro float toFloat( void ) const;
que convierte el valor de punto fijo en un valor de punto flotante.
• Una función miembro int toInt( void ) const;
que convierte el valor de punto fijo en un valor entero.
Y agregue la siguiente función a los archivos de clase fija:
• Una sobrecarga del operador de inserción («) que inserta una representación de punto flotante
del número de punto fijo en el objeto de flujo de salida pasado como parámetro.

### Objetivo

El objetivo de este ejercicio sin duda es la comprensión de como funciona y como se trabaja con números de punto fijo y las correspondientes conversiones desde int y float.

### Desarrollo

Hay una teoría que creo que hay que tener muy clara y es la siguiente:

1. **Número de punto fijo->** Representación de un número real que reserva un num fijo de bits para la parte entera y un num de bits para la parte fraccionaria. A diferencia de los floats donde el punto decimal puede flotar y ser representado por un exponente, en el num de punto fijo el punto decimal está en una ubicación fija. Por ejemplo:
Si tienes un num de 16 bits con 8 bits para la parte entera y 8 bits para la parte fraccionaria, podríamos representar num desde -128,0 hasta 127,996 (el valor exacto depende de la precisión que proporcionen esos bits fraccionarios) Recordemos que en los floats la precisión está determinada por los bits de mantisa. A tener en cuenta que la precisión no podemos confundirla con el rango, un num puede representar fracciones muy pequeñas pero tener un rango pequeño(no puede representar num muy grandes o muy pequeños).

2. **Conversión de un punto flotante a un punto fijo->** Implicaría dos pasos:
	1. Multiplicar el float por una potencia de 2 que es igual al num de bits fraccionarios en la representación de punto fijo("movería" la parte fraccionaria del num float a la parte entera del num resultante).
	2. Redondear el num resultante al entero mas cercano y almacenarlo en un int. Este entero representa el num de punto fijo.
Ejemplo:
```cpp
#include <cmath>

class Fixed {
private:
    int _value; 
    static const int _bits = 16;  // Número de bits fraccionarios
public:
    void set(float value) {
        this->_value = std::round(value * (1 << _bits));
		//le damos a _value el resultado de multiplicar el arg de entrada * [(1*2^16) =  65536]
		//value=5,5 * 65536 = 360448 -> 360448.0f -> esto sería la representacion de 5,5 en punto fijo.
    }
    float get() {
        return static_cast<float>(this->_value) / (1 << _bits);
    }
};

int main() {
    Fixed obj;
    obj.set(5.5f);
    std::cout << obj.get();  // Imprime: 5.5
    return 0;
}
```

## Ex02 Now we're talking

### Subject

Agregue funciones miembro públicas a su clase para sobrecargar los siguientes operadores:
* Los 6 operadores de comparación: >, <, >=, <=, == y !=.
* Los 4 operadores aritméticos: +, -, * y /.
* Los 4 operadores de incremento/decremento (preincremento y post-incremento, pre-decremento y post-decremento), que aumentarán o disminuirán el valor de punto fijo desde el ε más pequeño representable, como 1 + ε > 1.
Agregue estas cuatro funciones miembro públicas sobrecargadas a su clase:
* Una función miembro estática min que toma como parámetros dos referencias a números de punto fijo y devuelve una referencia al más pequeño.
* Una función miembro estática min que toma como parámetros dos referencias a números de punto fijo constantes y devuelve una referencia al más pequeño.
* Una función miembro estática max que toma como parámetros dos referencias a números de punto fijo y devuelve una referencia al mayor.
* Una función miembro estática max que toma como parámetros dos referencias a números de punto fijo constantes y devuelve una referencia al mayor.


