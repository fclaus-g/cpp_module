# Cpp_modules06 -Teoría general
## Casts en C++
En C++, las conversiones de tipo (casts) son operaciones que permiten convertir un valor de un tipo de dato a otro. Existen varios tipos de casts en C++, cada uno con su propósito y reglas específicas. Los más comunes son:
1. static_cast
2. dynamic_cast
3. const_cast
4. reinterpret_cast

* **Casts de estilo C**

1. **static_cast**
static_cast se utiliza para realizar conversiones de tipos bien definidas y en tiempo de compilación. Es seguro y no realiza comprobaciones en tiempo de ejecución. Se utiliza principalmente para:

Conversiones entre tipos numéricos (por ejemplo, de int a float).
Conversiones de punteros y referencias en una jerarquía de herencia.
Conversiones explícitas entre tipos de datos compatibles.

2. dynamic_cast
dynamic_cast se utiliza para realizar conversiones seguras en tiempo de ejecución entre punteros o referencias a clases polimórficas. Realiza comprobaciones en tiempo de ejecución y puede devolver nullptr o lanzar una excepción std::bad_cast si la conversión no es posible. Solo funciona con clases que tienen al menos una función virtual.

GitHub Copilot
Claro, aquí tienes una explicación completa sobre los diferentes tipos de conversiones de tipo (casts) en C++ y cómo funcionan:

Casts en C++
En C++, las conversiones de tipo (casts) son operaciones que permiten convertir un valor de un tipo de dato a otro. Existen varios tipos de casts en C++, cada uno con su propósito y reglas específicas. Los más comunes son:

static_cast
dynamic_cast
const_cast
reinterpret_cast
Casts de estilo C
1. static_cast
static_cast se utiliza para realizar conversiones de tipos bien definidas y en tiempo de compilación. Es seguro y no realiza comprobaciones en tiempo de ejecución. Se utiliza principalmente para:

* Conversiones entre tipos numéricos (por ejemplo, de int a float).
* Conversiones de punteros y referencias en una jerarquía de herencia.
* Conversiones explícitas entre tipos de datos compatibles.
Ejemplo:
```cpp
int i = 42;
float f = static_cast<float>(i); // Convertir int a float

class Base {};
class Derived : public Base {};

Base* b = new Derived();
Derived* d = static_cast<Derived*>(b); // Convertir Base* a Derived*
```
2. dynamic_cast
dynamic_cast se utiliza para realizar conversiones seguras en tiempo de ejecución entre punteros o referencias a clases polimórficas. Realiza comprobaciones en tiempo de ejecución y puede devolver nullptr o lanzar una excepción std::bad_cast si la conversión no es posible. Solo funciona con clases que tienen al menos una función virtual.
Ejemplo:
```cpp
class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b); // Convertir Base* a Derived*

if (d) {
    // La conversión fue exitosa
} else {
    // La conversión falló
}
```
3. const_cast
const_cast se utiliza para agregar o eliminar la cualificación const de un tipo de dato. No puede cambiar el tipo subyacente del objeto. Se utiliza principalmente para eliminar la cualificación const de punteros o referencias.
```cpp
const int i = 42;
int* p = const_cast<int*>(&i); // Eliminar la cualificación const

*p = 24; // Modificar el valor a través del puntero no const
```

4. reinterpret_cast
reinterpret_cast se utiliza para realizar conversiones de tipos de bajo nivel y potencialmente peligrosas. No realiza comprobaciones en tiempo de ejecución y puede reinterpretar los bits de un tipo de dato como otro tipo de dato. Se utiliza principalmente para conversiones entre punteros de tipos no relacionados.
```cpp
int i = 42;
void* p = reinterpret_cast<void*>(&i); // Convertir int* a void*

int* ip = reinterpret_cast<int*>(p); // Convertir void* de vuelta a int*
```
5. Casts de estilo C
Los casts de estilo C son la forma original de realizar conversiones de tipo en C y C++. Son menos seguros y más propensos a errores porque no especifican el tipo de conversión que se está realizando. Se recomienda evitar su uso en favor de los casts específicos de C++.
```cpp
int i = 42;
float f = (float)i; // Cast de estilo C

class Base {};
class Derived : public Base {};

Base* b = new Derived();
Derived* d = (Derived*)b; // Cast de estilo C
```
### Comparación de Casts
|--------------------|----------------------------------|-----------------------------------------------------------|
| Tipo de Cast       | Seguridad en Tiempo de Ejecución | Uso Principal                                      		|
|--------------------|----------------------------------|-----------------------------------------------------------|
| `static_cast`      | No                               | Conversiones bien definidas y en tiempo de compilación	|
|--------------------|----------------------------------|-----------------------------------------------------------|
| `dynamic_cast`     | Sí                               | Conversiones seguras en jerarquías de herencia polimórfica|
|--------------------|----------------------------------|-----------------------------------------------------------|
| `const_cast`       | No                               | Agregar o eliminar la cualificación `const`        		|
|--------------------|----------------------------------|-----------------------------------------------------------|
| `reinterpret_cast` | No                               | Conversiones de bajo nivel y potencialmente peligrosas 	|
|--------------------|----------------------------------|-----------------------------------------------------------|
| Cast de estilo C   | No                               | Conversiones de tipo originales de C               		|
|--------------------|----------------------------------|-----------------------------------------------------------|
```cpp
#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

void exampleStaticCast() {
    int i = 42;
    float f = static_cast<float>(i); // Convertir int a float
    std::cout << "static_cast<float>(i): " << f << std::endl;
    // Salida esperada: static_cast<float>(i): 42.0

    Base* b = new Derived();
    Derived* d = static_cast<Derived*>(b); // Convertir Base* a Derived*
    std::cout << "static_cast<Derived*>(b): " << typeid(d).name() << std::endl;
    // Salida esperada: static_cast<Derived*>(b): P7Derived
    delete b;
}

void exampleDynamicCast() {
    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b); // Convertir Base* a Derived*

    if (d) {
        std::cout << "dynamic_cast<Derived*>(b) succeeded: " << typeid(d).name() << std::endl;
        // Salida esperada: dynamic_cast<Derived*>(b) succeeded: P7Derived
    } else {
        std::cout << "dynamic_cast<Derived*>(b) failed" << std::endl;
    }
    delete b;
}

void exampleConstCast() {
    const int i = 42;
    int* p = const_cast<int*>(&i); // Eliminar la cualificación const
    *p = 24; // Modificar el valor a través del puntero no const
    std::cout << "const_cast<int*>(&i): " << *p << std::endl;
    // Salida esperada: const_cast<int*>(&i): 24
}

void exampleReinterpretCast() {
    int i = 42;
    void* p = reinterpret_cast<void*>(&i); // Convertir int* a void*
    int* ip = reinterpret_cast<int*>(p); // Convertir void* de vuelta a int*
    std::cout << "reinterpret_cast<int*>(p): " << *ip << std::endl;
    // Salida esperada: reinterpret_cast<int*>(p): 42
}

int main() {
    exampleStaticCast();
    exampleDynamicCast();
    exampleConstCast();
    exampleReinterpretCast();
    return 0;
}
```

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

### Teoría
Propósitos del Scalar Converter
Conversión de Tipos de Datos:

Permite transformar un valor de un tipo escalar a otro. Por ejemplo, puede convertir un valor de tipo string a int, float, o double, y viceversa.
Esto es útil en situaciones donde se requiere un tipo de dato específico para cálculos, almacenamiento o transmisión.
Interoperabilidad:

Facilita la interoperabilidad entre diferentes partes de un programa que pueden requerir tipos de datos distintos. Por ejemplo, podrías recibir un valor como cadena (texto) desde la entrada del usuario, y necesitar convertirlo a int para realizar cálculos matemáticos.
Manejo de Errores:

Proporciona un mecanismo para manejar errores durante la conversión, como intentar convertir un texto que no es numérico a un tipo numérico (por ejemplo, convertir "abc" a int), lo que puede resultar en excepciones.
Al manejar estos errores, el programa puede ser más robusto y evitar fallos inesperados.
Impresión de Valores:

El conversor puede formatear y presentar los resultados de la conversión de manera amigable para el usuario, indicando claramente el resultado de cada conversión.
Facilita la Comprensión de Tipos:

Ayuda a entender las diferencias entre los tipos de datos escalares en C++. La conversión entre tipos primitivos a menudo es un concepto fundamental en muchos lenguajes de programación, y este ejercicio permite practicar y reforzar ese conocimiento.
Contexto del Ejercicio en C++
En el contexto del ejercicio del Scalar Converter que discutimos, el propósito del conversor se puede resumir en los siguientes pasos:

Entrada de Datos: Se toma un valor de entrada (como argumento de línea de comandos), que puede ser en formato de texto (cadena).
Conversión: El valor de entrada se convierte a varios tipos escalares (como int, char, float, y double).
Salida: Los resultados de las conversiones se imprimen en la consola, mostrando cómo se ve el valor en cada tipo.
Ejemplo Práctico
Imagina que estás creando un programa que necesita realizar cálculos matemáticos basados en la entrada del usuario. El usuario podría ingresar un número en forma de texto (por ejemplo, "123.45"). Para poder utilizar ese número en cálculos, debes convertirlo:

Desde std::string a float o double para realizar cálculos.
Podrías querer imprimir el número como int, redondeando hacia abajo (123).
Tal vez quieras verificar si este número puede ser representado como un char (en este caso, convertirlo podría dar un carácter específico).
Conclusión
El Scalar Converter es una herramienta útil en programación que:

Facilita la conversión de tipos de datos.
Ayuda a manejar la entrada del usuario de manera flexible.
Aumenta la robustez del programa al manejar errores de conversión.
Proporciona una comprensión más clara sobre cómo los diferentes tipos de datos pueden interactuar en un programa.

* **Valores especiales**
	- inf -> infinito positivo. -inf -> infinito negativo. Cuando un valor excede el calculo máximo/mínimo de float. Ej: -1.0 / 0.0 resulta en -inf.
	- inff -> infinito positivo. -inff -> infinito negativo. Cuando un valor excede el calculo máximo/mínimo de float. En algunos compiladores y entornos se usa para diferenciar float de double. Ej: -1.0 / 0.0 resulta en -inff.
	- nan - Not a Number Ej: 0.0 / 0.0 resulta en nan.

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

### Objetivo

Este ejercicio tiene como objetivo ayudarte a entender conceptos clave de la programación orientada a objetos en C++, especialmente cuando se trabaja con polimorfismo y downcasting. Aunque puede parecer simple, te proporciona práctica en las siguientes áreas:

1. Polimorfismo en Tiempo de Ejecución
La clase base Base se utiliza como interfaz para las clases derivadas A, B y C. En muchas aplicaciones, especialmente cuando se usan punteros o referencias a la clase base (Base), no se sabe en tiempo de compilación cuál es el tipo exacto de un objeto (si es A, B, o C). Este ejercicio simula esta situación y te obliga a resolverla en tiempo de ejecución.

2. Identificación de Tipos Derivados usando Downcasting
En el ejercicio, la función identify(Base& p) o identify(Base* p) necesita detectar el tipo exacto de un objeto derivado a partir de un puntero o referencia a la clase base Base. Esto se conoce como downcasting.

C++ proporciona dynamic_cast para este propósito, que es particularmente útil en sistemas donde tienes una jerarquía de clases y deseas realizar operaciones específicas para ciertos tipos de objetos en tiempo de ejecución. Este ejercicio te ayuda a trabajar con dynamic_cast, aprendiendo cómo usarlo y cuándo puede fallar (captura de std::bad_cast en dynamic_cast).

3. Uso de Excepciones y Manejo de Errores
En la versión que usa referencias (identify(Base& p)), el dynamic_cast lanza una excepción si el tipo de p no coincide con el tipo al que intentas convertirlo. Manejar esto de manera apropiada mediante bloques try-catch es una parte importante del ejercicio, enseñándote cómo lidiar con errores en tiempo de ejecución de manera efectiva y limpia.

4. Comprensión de Punteros vs. Referencias
La existencia de dos funciones identify(Base* p) y identify(Base& p) resalta la diferencia entre trabajar con punteros y referencias en C++. En identify(Base* p), puedes verificar fácilmente si el puntero es nullptr o no, y evitar excepciones. Sin embargo, en identify(Base& p), el dynamic_cast lanza excepciones para tipos no coincidentes. Así, el ejercicio también te ayuda a ver cuándo es útil una opción sobre la otra.

5. Diseño y Lógica de Jerarquías de Clases
Este ejercicio también es un recordatorio de cómo diseñar sistemas con jerarquías de clases y de los desafíos asociados con el trabajo en tiempo de ejecución. Dado que el tipo exacto del objeto Base solo se determina en ejecución, este ejercicio simula una situación común en programación orientada a objetos y te ayuda a comprender cómo manejarla.

Conclusión
En resumen, el sentido de este ejercicio es brindarte práctica en conceptos avanzados de C++ que son fundamentales para aplicaciones orientadas a objetos: polimorfismo, downcasting, manejo de excepciones, y la diferencia en el manejo de punteros y referencias. Estos temas son esenciales para aplicaciones de software a gran escala, donde puedes tener muchos tipos derivados y necesitas ejecutar comportamientos específicos para cada tipo, incluso cuando solo tienes acceso a la interfaz base.






