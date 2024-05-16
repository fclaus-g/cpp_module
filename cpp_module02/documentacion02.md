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

Conocer y practicar la forma *canónica ortodoxa*, trabajar con la sobrecarga de funciones(funciones con el mismo nombre y con diferentes argumentos) y la sobrecarga de operadores (aclara el comportamiento de un operador cuando se hacen operaciones entre clases) y conocer que es el formato de punto fijo.

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

* **A tener en cuenta->** Una variable de tipo int, Fixed o float en tiene un tamaño de 4 bytes (32 bits) en C++ por lo que la diferencia entre ambos  seria la siguiente:
	* Int -> No tiene una parte decimal. 
	* float -> Tiene parte decimal y se divide en 3 partes:
		1. 1 bit de signo.
		2. 8 bits de exponente.
		3. 23 bits de mantisa (parte fraccionaria del num)
	* Fixed -> En nuestro programa Fixed tiene dos partes:
		1. 24 bits para la parte entera
		2. 8 bits para la parte fraccionaria.

**Formato de punto fijo->** Es una representación de num reales en informática que proporciona un num fijo de dígitos antes y después de la coma decimal. Un num se reptresenta como un entero que se divide por una potencia de 2 para obtener el valor real. Ej: Si tienes un num de 16bits en punto fijo con 8bits en la parte entera y 8bits para la parte fraccionaria. El num 256 representaría el num 1.0(256/2⁸= 1)

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

```cpp
//Usando este código

#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );

a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
```
Debería mostrar algo como esto:

```shell
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```

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
3. **Sobrecarga del operador '<<'->** << es el operador de inserción de flujo (se utiliza para insertar datos en flujos de salida, como std::cout). La declaramos fuera del objeto porque el primer parametro es un std::ostream&, no un Fixed. Por lo tanto debe ser una función no miembro. Además al declararla fuera de la clese, permite que la función sea utilizada con la sintaxis natural de la operación de inserción de flujo. (mas intuitiva y legible).
```cpp
std::ostream&	operator<<(std::ostream& out, Fixed const& value);

/**
 * std::ostream -> representa un flujo de salida, envia datos hacia la salida(consola, archivo...)
 * std::ostream& -> referencia a un objeto de la clase std::ostream, cuando se pasan datos a esa ref
 * se estan pasando al objeto original.
 * args->
 * 		std::ostream& out-> Flujo de salida en el que se insertaran los datos.
 * 		Fixed const& value-> valor que se va a insertar en el flujo de salida.
 */
std::ostream	&operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}
/*Se programa o sobrecarga el << de manera que cuando se llame imprima su valor a float.*/

	Fixed const c(42.42f);//literal de punto flotante float, en c++ suelen ser double

	std::cout << "c is " << c << std::endl;//output 42.4219, el elemento fixed es mas preciso por eso muestra mas decimales
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;//output 42
```

## Ex02 Fixed III- Now we're talking

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
```cpp
//Teniendo este código:
#include <iostream>

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
```
El programa debería mostrar algo parecido a esto:
```shell
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```

### Objetivo

Practicar la sobrecarga de operadores y y la sobrecarga y el uso de funciones miembro. En mi caso concreto tambien aprovecho, en las funciones miembro estáticas, para hacer uso de los operadores ternarios.

### Desarrollo

En este ejercicio hemos hecho uso de la sobrecarga en varios operadores (aritméticos, comparativos y decremento e incremento) y añadido algunas funciones miembro estáticas (para no modificar atributos de nuestras clases).

**Función miembro estática->** Función que pertenece a una clase pero no opera en un objeto de esa clase. No necesita un objeto de la clase para ser llamada, son como funciones globales que tienen acceso a los  miembros privados de la clase.

Veamos el .hpp como quedaría:
```cpp
#include <iostream>
 
 class Fixed{
	
	private:
		int					_value;
		static const int	_bits = 8;
	
	public:
		Fixed();
		Fixed(int const value);//constructor que toma un número entero constante como parámetro
		Fixed(float const value);//constructor que toma un número de coma flotante constante como parámetro
		Fixed(const Fixed&	copy);//constructor de copias
		~Fixed();

		Fixed&	operator=(const Fixed &copy);//sobrecarga del operador de asignación de copia
		
		/*Operadores >|>=|<|<=|!=|==*/
		bool	operator>(const Fixed&	value) const;
		bool	operator>=(const Fixed& value) const;
		bool	operator<(const Fixed& value) const;
		bool	operator<=(const Fixed& value) const;
		bool	operator!=(const Fixed& value) const;
		bool	operator==(const Fixed& value) const;

		/*Operadores =|+|-|*|/*/
		Fixed	operator+(const Fixed& rhs) const;//sobrecarga del operador de suma
		Fixed	operator-(const Fixed& rhs) const;//sobrecarga del operador de resta
		Fixed	operator*(const Fixed& rhs) const;//sobrecarga del operador de multiplicación
		Fixed	operator/(const Fixed& rhs) const;//sobrecarga del operador de división

		/*Operadores ++a|a++|--a|a--*/
		Fixed&	operator++(void);//sobrecarga del operador de preincremento
		Fixed	operator++(int);//sobrecarga del operador de postincremento
		Fixed&	operator--(void);//sobrecarga del operador de predecremento
		Fixed	operator--(int);//sobrecarga del operador de postdecremento

		/*Funciones miembro*/
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;//convierte el valor de punto fijo en un valor de punto flotante
		int		toInt( void ) const;//convierte el valor de punto fijo en un valor entero
		
		/*Funciones miembro estáticas*/
		static Fixed&	min(Fixed& a, Fixed& b);//toma como parámetros dos referencias a números de punto fijo y devuelve una referencia al más pequeño
		static Fixed&	min(Fixed const& a, Fixed const& b);//toma como parámetros dos referencias a números de punto fijo constantes y devuelve una referencia al más pequeño
		static Fixed&	max(Fixed& a, Fixed& b);//toma como parámetros dos referencias a números de punto fijo y devuelve una referencia al mayor
		static Fixed&	max(Fixed const& a, Fixed const& b);//toma como parámetros dos referencias a números de punto fijo constantes y devuelve una referencia al mayor
};

//Ejemplo de .cpp de sobrecarga de funciones y uso de operador ternario

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed&	Fixed::min(Fixed const& a, Fixed const& b)
{
	return (a < b) ? (Fixed &)a : (Fixed &)b;
}
```
**Sobrecarga incremento y decremento->**
A tener en cuenta, cuando a = 0, si hacemos el incremento a pasaria a tomar el valor a = 0.00390625 que , en el contexto de punto fijo, es la diferencia mas pequeña que puede representarse entre dos números(Epsilon), y que ajustamos con nuestro atributo _bits. Si aumentáramos el valor de _bits , la precisión de nuestro Fixed aumentaría y Epsilon disminuiría. Lo que al hacer a++ el incremento sería mas pequeño. El cálculo sería si _bits = n, Epsilon = 1/2^n.

```cpp
Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return *this;
}
/*Toma y devuelve una referencia porque el resultado de un preincremento es el objeto incrementado*/

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}
/*crea una copia del objeto original, luego incrementa el objeto original, y devuelve la copia original. Devuelve una copia y no una referencia porque el resultado de un postincremento es el valor original del objeto antes de ser incrementado. El tomar un arg de tipo int, es una convención para distinguir del preincremento, sin embargo este valor no se usa en la función.
```
