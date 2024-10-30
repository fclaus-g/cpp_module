# Cpp_module07 - Templates

## Ex00

### Subject

Implemente las siguientes plantillas de funciones:
* swap: intercambia los valores de dos argumentos dados. No devuelve nada.
* min: compara los dos valores pasados ​​en sus argumentos y devuelve el más pequeño.
Si los dos son iguales, devuelve el segundo.
* max: compara los dos valores pasados ​​en sus argumentos y devuelve el más grande.
Si los dos son iguales, devuelve el segundo.
Estas funciones se pueden llamar con cualquier tipo de argumento. El único requisito es
que los dos argumentos deben tener el mismo tipo y deben admitir todos los operadores de comparación.
Las plantillas se deben definir en los archivos de encabezado.
```cpp
int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}

/*Debería mostrar esto:
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
*/
```
 ### Teoría
 Las templates en C++ son una poderosa característica que permite definir funciones y clases genéricas, facilitando la creación de código reutilizable y flexible. Una plantilla puede aceptar uno o más parámetros de tipo, lo que permite a los programadores escribir funciones y clases que pueden operar con cualquier tipo de datos, siempre que esos tipos cumplan con ciertas condiciones (como la posibilidad de realizar operaciones específicas). Las plantillas se definen utilizando la palabra clave template, seguida de uno o más parámetros de tipo entre ángulos (<>). Durante la compilación, el compilador genera instancias específicas de las plantillas cuando se utilizan con tipos concretos. Esto no solo promueve la reutilización del código, sino que también proporciona una forma segura de implementar algoritmos y estructuras de datos que pueden trabajar con distintos tipos, sin sacrificar el rendimiento o la seguridad de tipos en tiempo de ejecución. Sin embargo, es importante recordar que la implementación de plantillas debe estar disponible en el archivo de encabezado, ya que el compilador necesita ver la definición completa de la plantilla en el momento de su instanciación.

 ### Implementación

 ```cpp
 #include <iostream>

// Función de plantilla para intercambiar dos valores
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Función de plantilla para encontrar el valor mínimo
template <typename T>
const T &min(const T &a, const T &b) {
    return (a < b ? a : b);
}

// Función de plantilla para encontrar el valor máximo
template <typename T>
const T &max(const T &a, const T &b) {
    return (a > b ? a : b);
}

int main() {
    int x = 5, y = 10;
    swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl; // x = 10, y = 5

    std::cout << "Min of x and y: " << min(x, y) << std::endl; // Min: 5
    std::cout << "Max of x and y: " << max(x, y) << std::endl; // Max: 10

    double a = 3.14, b = 2.71;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl; // a = 2.71, b = 3.14

    return 0;
}
```
