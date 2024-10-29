# Cpp_modules06

## Ex00

### Subject

Escriba una clase ScalarConverter que contenga solo un método estático "convert"
que tome como parámetro una representación en cadena de un literal de C++ en su forma más común y muestre su valor en la siguiente serie de tipos escalares:
* char
* int
* float
* double
Como esta clase no necesita almacenar nada en absoluto, los usuarios no deben poder instanciarla.

A excepción de los parámetros char, solo se utilizará la notación decimal.

Ejemplos de literales char: 'c', 'a', ...

Para simplificar las cosas, tenga en cuenta que los caracteres no visibles no deben usarse como
entradas. Si una conversión a char no se puede mostrar, imprime un mensaje informativo.

Ejemplos de literales int: 0, -42, 42...

Ejemplos de literales float: 0.0f, -4.2f, 4.2f...

También tienes que manejar estos pseudoliterales (ya sabes, por ciencia): -inff, +inff
y nanf.

Ejemplos de literales double: 0.0, -4.2, 4.2...

También tienes que manejar estos pseudoliterales (ya sabes, por diversión): -inf, +inf y nan.

Escriba un programa para comprobar que su clase funciona como se espera.
Primero debe detectar el tipo del literal pasado como parámetro, convertirlo de
cadena a su tipo real y luego convertirlo explícitamente a los otros tres tipos de datos. Por último,
muestre los resultados como se muestra a continuación.
Si una conversión no tiene sentido o se desborda, muestre un mensaje para informar
al usuario que la conversión de tipo es imposible. Incluya cualquier encabezado que necesite para
manejar límites numéricos y valores especiales.
```bash
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

## Ex01

### Subject

Implementa una clase Serializer, que no será inicializable por el usuario de ninguna manera, con los siguientes métodos estáticos:
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

No olvides entregar los archivos de tu estructura de datos.

### Teoría 
¿Qué es Serialización?
Serialización es el proceso de convertir un objeto en un formato que puede ser fácilmente almacenado o transmitido. Esto puede ser útil para:

Guardar el estado de un objeto en un archivo o en una base de datos.
Enviar objetos a través de redes, como cuando un servidor envía datos a un cliente.
En C++, como en muchos lenguajes de programación, los objetos son estructuras en memoria que contienen datos y pueden ser complejas. La serialización permite que estas estructuras sean transformadas en una representación que pueda ser fácilmente guardada o enviada.

¿Qué es Deserialización?
Deserialización es el proceso inverso, donde tomamos la representación almacenada (en este caso, el número entero que representa un puntero) y lo convertimos de vuelta al objeto original.

Cómo Funciona el Serializer
La clase Serializer que implementamos en el ejercicio tiene dos métodos estáticos:

serialize(Data* ptr): Este método toma un puntero a un objeto de tipo Data y lo convierte a un tipo uintptr_t. Esto nos permite obtener una representación numérica del puntero.

deserialize(uintptr_t raw): Este método toma el número entero (representación del puntero) y lo convierte de nuevo en un puntero a Data.

Flujo del Ejercicio
Creación del Objeto: Se crea un objeto Data que tiene algunos miembros (como id, name, y value).

Serialización:

Se llama a serialize pasando el puntero al objeto Data.
El puntero se convierte a un número entero (uintptr_t). Este número representa la dirección de memoria del objeto.
Deserialización:

Se llama a deserialize pasando el número entero.
El número entero se convierte de nuevo a un puntero de tipo Data*, que apunta a la misma dirección de memoria que el objeto original.
Verificación: Se comprueba que el puntero original y el puntero deserializado apuntan al mismo objeto. Esto asegura que el proceso de serialización y deserialización ha funcionado correctamente.

Propósito en la Programación
Este ejercicio tiene varios propósitos:

Comprender Punteros y Direcciones de Memoria: Aprender a trabajar con punteros en C++ y cómo manipular direcciones de memoria es fundamental en programación de sistemas y aplicaciones de bajo nivel.

Uso de uintptr_t: Familiarizarse con el tipo uintptr_t, que es un tipo entero sin signo capaz de almacenar la dirección de un puntero, lo que ayuda a entender cómo funcionan las direcciones de memoria.

Práctica de Clases y Métodos Estáticos: Aprender a trabajar con clases en C++, en este caso con métodos que no requieren una instancia de la clase.

## Ex02

### Subject

Implementa una clase Base que tenga solo un destructor virtual público. Crea tres clases vacías A, B y C, que hereden públicamente de Base.
Estas cuatro clases no tienen que estar diseñadas en la forma canónica ortodoxa.
Implementa las siguientes funciones:
```cpp
Base * generate(void);
```
Instancia aleatoriamente A, B o C y devuelve la instancia como un puntero Base. Siéntete libre
de usar lo que quieras para la implementación de elección aleatoria.
```cpp
void identify(Base* p);
```
Imprime el tipo real del objeto al que apunta p: "A", "B" o "C".
```cpp
void identify(Base& p);
```
Imprime el tipo real del objeto al que apunta p: "A", "B" o "C". Está prohibido usar un puntero dentro de esta función.

Está prohibido incluir el encabezado typeinfo.

Escribe un programa para probar que todo funciona como se espera.