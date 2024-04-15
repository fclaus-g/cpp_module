# C++ conceptos

### namespace

Un `namespace` en C++ es un contenedor que permite agrupar entidades como clases, objetos y funciones bajo un nombre. El propósito principal de los `namespace` es evitar conflictos de nombres en programas grandes. Por ejemplo, puedes tener dos clases con el mismo nombre en diferentes `namespace` y C++ las tratará como diferentes clases. Para acceder a una entidad en un `namespace`, debes usar el operador de resolución de ámbito (`::`).
```cpp
namespace MyNamespace {
    int myFunction() {
        return 0;
    }
}

int main() {
    int value = MyNamespace::myFunction(); // Acceder a la función usando el operador de resolución de ámbito
    return 0;
}
```

### Class and instance
Una `class` en C++ es una plantilla para crear objetos (una instancia particular de la clase), y define qué atributos (datos) y métodos (funciones) tendrán esos objetos. Una `instance` es un objeto específico creado a partir de una clase. Cada instancia de una clase tiene su propio conjunto de atributos, que no se comparten con otras instancias.

```cpp
class MyClass {
public:
    int myAttribute;

    void myMethod() {
        myAttribute = 0;
    }
};

int main() {
    MyClass instance; // Crear una instancia de MyClass
    instance.myMethod(); // Llamar a un método en la instancia
    return 0;
}
```
### This

En C++, `this` es un puntero que apunta al objeto actual de una clase. `this` es un puntero constante que se crea automáticamente cuando se invoca un método no estático en un objeto. Se puede utilizar para referirse a los miembros de la clase dentro de sus métodos.
El código sin usar `this` sería muy similar. En C++, no necesitas usar `this` para referirte a los miembros de la clase a menos que haya una ambigüedad (por ejemplo, si un parámetro de un método tiene el mismo nombre que un miembro de la clase). 
```cpp
class MyClass {
public:
    int myAttribute;

    void setAttribute(int value) {
        this->myAttribute = value; // 'this' se refiere al objeto actual
    }
};

int main() {
    MyClass instance;
    instance.setAttribute(10); // Establecer el atributo del objeto 'instance'
    return 0;
}
```

### Initializacion list

Las listas de inicialización en C++ se utilizan para inicializar los miembros de datos de una clase durante la construcción de un objeto. Son especialmente útiles cuando se trabaja con miembros de datos que son objetos de otras clases y necesitan ser construidos con argumentos específicos.

```cpp
class MyClass {
public:
    int myAttribute;

    MyClass(int value) : myAttribute(value) { // Lista de inicialización
        // Cuerpo del constructor
    }
};

int main() {
    MyClass instance(10); // Crear una instancia de MyClass con myAttribute inicializado a 10
    return 0;
}
```

# Const

En C++, `const` es una palabra clave que indica que el valor de una variable no puede ser cambiado después de su inicialización. También puede ser utilizado con punteros y referencias para indicar que el objeto al que apuntan no puede ser modificado, o que el puntero mismo no puede ser cambiado para apuntar a otro objeto.

```cpp
int main() {
    const int myConst = 10; // Una constante entera
    // myConst = 20; // Error: no puedes cambiar el valor de una constante

    int value = 10;
    const int* ptr = &value; // Un puntero a una constante entera
    // *ptr = 20; // Error: no puedes cambiar el valor al que apunta un puntero constante

    int* const ptr2 = &value; // Un puntero constante a un entero
    // ptr2 = &myConst; // Error: no puedes cambiar un puntero constante para que apunte a otro objeto

    return 0;
}
```

### Visibilidad

La visibilidad en C++ se refiere a la accesibilidad de los miembros de una clase (atributos y métodos). Hay tres niveles de visibilidad: `public`, `private` y `protected`.

- `public`: Los miembros públicos son accesibles desde cualquier lugar donde el objeto sea visible.
- `private`: Los miembros privados solo son accesibles dentro de la clase que los declara. Según ña convención podemos nombrar a las variables y funciones privadas con un '_' ej : int _numeroPrivate.
- `protected`: Los miembros protegidos son accesibles dentro de la clase que los declara y dentro de cualquier clase que herede de esa clase.

```cpp
class MyClass {
public:
    int myPublicAttribute; // Atributo público

private:
    int myPrivateAttribute; // Atributo privado

protected:
    int myProtectedAttribute; // Atributo protegido
};

int main() {
    MyClass instance;
    instance.myPublicAttribute = 10; // Acceso permitido
    // instance.myPrivateAttribute = 20; // Error: acceso no permitido
    // instance.myProtectedAttribute = 30; // Error: acceso no permitido
    return 0;
}
```
### Funciones privadas

Las funciones `private` en C++ se utilizan para encapsular la lógica interna de una clase que no debe ser accesible desde fuera de la clase. Esto es parte de un principio de programación orientada a objetos llamado encapsulación, que ayuda a mantener la integridad de los datos y a prevenir la manipulación no deseada de los miembros internos de la clase.

```cpp
class MyClass {
public:
    void publicMethod() {
        privateMethod(); // Llamada a un método privado dentro de un método público
    }

private:
    void privateMethod() {
        // Lógica interna de la clase
    }
};

int main() {
    MyClass instance;
    instance.publicMethod(); // Acceso permitido
    // instance.privateMethod(); // Error: acceso no permitido
    return 0;
}
```

### Class vs struct

En C++, `class` y `struct` son muy similares. Ambos pueden tener atributos y métodos, y ambos pueden ser utilizados para definir tipos de datos personalizados. La principal diferencia entre ellos es la visibilidad por defecto de sus miembros:

- En una `class`, los miembros son `private` por defecto.
- En un `struct`, los miembros son `public` por defecto.

```cpp
class MyClass {
    int myPrivateAttribute; // Privado por defecto

public:
    void myMethod() {
        // Lógica del método
    }
};

struct MyStruct {
    int myPublicAttribute; // Público por defecto

    void myMethod() {
        // Lógica del método
    }
};

int main() {
    MyClass classInstance;
    // classInstance.myPrivateAttribute; // Error: acceso no permitido
    classInstance.myMethod(); // Acceso permitido

    MyStruct structInstance;
    structInstance.myPublicAttribute = 10; // Acceso permitido
    structInstance.myMethod(); // Acceso permitido

    return 0;
}
```

### Getter

Un "getter" en C++ es un método que se utiliza para leer el valor de un atributo privado de una clase. Este método permite mantener la encapsulación de los datos, ya que el atributo privado no puede ser accedido directamente desde fuera de la clase.

```cpp
class MyClass {
private:
    int myPrivateAttribute;

public:
    int getAttribute() const {
        return myPrivateAttribute; // Getter
    }
};

int main() {
    MyClass instance;
    int value = instance.getAttribute(); // Obtener el valor del atributo
    return 0;
}
```

### Funciones y atributos no miembros

Son aquellas funciones y atributos que no están contenidos dentro de una clase o struct. Son accesibles de manera global y no están asociados con ningún objeto específico de una clase. Es importante tener en cuenta que el uso excesivo de atributos y funciones globales puede hacer que el código sea dificil de entender y mantener. En la POO se prefiere encapsular los atributos y funciones dentro de clases y struct siempre que sea posible.
```cpp
#include <iostream>

int globalAttribute; // Atributo no miembro

void globalFunction() { // Función no miembro
    std::cout << "Esta es una función no miembro.\n";
}

class MyClass {
    // ...
};

int main() {
    globalAttribute = 10;
    globalFunction();
    return 0;
}
```

### Punteros a miembros

Son un tipo de puntero que puede apuntar a un miembro de una clase(atributo o función).
```cpp
class MyClass {
public:
    int myAttribute;
    void myMethod() {
        // ...
    }
};

int main() {
    // Declarar un puntero a un atributo de MyClass
    int MyClass::*ptrToAttribute = &MyClass::myAttribute;

    // Declarar un puntero a una función de MyClass
    void (MyClass::*ptrToMethod)() = &MyClass::myMethod;

    MyClass instance;

    // Usar el puntero para acceder al atributo
    instance.*ptrToAttribute = 10;

    // Usar el puntero para llamar a la función
    (instance.*ptrToMethod)();

    return 0;
}
```
En este código, ptrToAttribute es un puntero al atributo myAttribute de MyClass, y ptrToMethod es un puntero al método myMethod de MyClass. Se pueden usar estos punteros para acceder al atributo y llamar al método en una instancia de MyClass.

Es importante tener en cuenta que los punteros a miembros de una clase son diferentes de los punteros normales. No podemos usar un puntero a un miembro de una clase para apuntar a una variable o función que no sea miembro de esa clase. Además, para usar un puntero a un miembro de la clase necesitamos una instancia de esa clase.

### New y delete

new y delete son operadores en C++ utilizados para la asignación dinámica de memoria.

* **new:** Este operador se utiliza para asignar memoria en el heap para un objeto de un tipo dado. Devuelve un puntero al espacio de memoria asignado. También se puede utilizar para inicializar el objeto durante la asignación de memoria.
```cpp
int* ptr = new int(10); // Asigna memoria para un entero y lo inicializa a 10
```
* **delete:** Este operador se utiliza para liberar la memoria que ha sido asignada con new. Debes pasarle el puntero que new devolvió. Después de usar delete, ese puntero se convierte en un puntero colgante, por lo que es una buena práctica establecerlo a nullptr.
```cpp
delete ptr; // Libera la memoria
ptr = nullptr; // Evita el puntero colgante
```
Es importante recordar que cada new debe tener un delete correspondiente. Si olvidas usar delete, puedes causar una fuga de memoria, donde la memoria que ya no se necesita sigue ocupada. Esto puede agotar la memoria disponible para tu programa.

### Referencias

Son un tipo de alias que se puede utilizar para nombrar una variable existente. Una vez que una referencia es inicializada con una variable, la referencia y la variable original pueden ser utilizadas indistintamente. Ejemplo:
```cpp
int original = 10; // Variable original
int& ref = original; // Referencia a la variable original

ref = 20; // Cambia el valor de la variable original

std::cout << original; // Imprime 20
```
En este código, ref es una referencia a original. Cuando cambiamos el valor de ref, también cambiamos el valor de original.
Las referencias deben ser inicializadas en el momento de su declaración y NO pueden se REASIGNADAS para referirse a diferentes variables una vez han sido inicializadas. Además, no puedes tener referencias apuntando a null, a diferencia de los punteros.
Son útiles cuando quieres pasar args a una función por referencia(para que la función pueda modificar los argumentos) o cuando quieres devolver mása de un valor de una función o para crear alias para variables con nombres largos o complicados.

### filestream

**fstream** es una biblioteca que proporciona facilidades para realizar operaciones de entrada y salida en archivos. Incluye las clases:
* **ifstream**-> leer de archivos.
* **ofstream**-> escrinir en archivos.
* **fstream**-> leer y escribir.
```cpp
#include <fstream>
#include <iostream>

int main() {
    // Crear un objeto ofstream y abrir un archivo para escribir
    std::ofstream outFile("test.txt");
    if (outFile.is_open()) {
        outFile << "Hola, mundo!\n";
        outFile.close();
    }

    // Crear un objeto ifstream y abrir el mismo archivo para leer
    std::ifstream inFile("test.txt");
    if (inFile.is_open()) {
        std::string line;
        while (getline(inFile, line)) {
            std::cout << line << '\n';
        }
        inFile.close();
    }

    return 0;
}
```
En este código, primero creamos un objeto **ofstream** y escribimos "Hola mundo!" en un archivo llamado "test.txt". Luego creamos un objeto **ifstream** y leemos el contenido de dicho archivo. Es importante cerrar los archivos después de usarlos para liberar los recursos que están utilizando.

