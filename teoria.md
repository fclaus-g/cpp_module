# C++ conceptos

## namespace

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

## Class and instance
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

## Initializacion list

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

## Const

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

## Visibilidad

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
## Funciones privadas

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

## Class vs struct

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

## Getter

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

## Funciones y atributos no miembros

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

## Punteros a miembros

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

## New y delete

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

## Referencias

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

## filestream

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

## Números flotantes
 Los números flotantes(float) tiene una serie de particularidades que debemos tener en cuenta a la hora de trabajar con ellos.

 * En ocasiones los float qaunque parezcan iguales necesariamente no satisfacen la prueba '==' de C.
 * Un float de 4 bytes puede contener menos valores distintos que un int de 4 bytes debido a que los bits que representan un float tienen una interpretación mas complicada que la de los int.
 ####  * Exactitud vs precisión

La **exactitud** se refiere a que tan cerca está una medición del valor real, mientras que la **precisión** tiene que ver con la cantidad de información que de tiene sobre una cantidad, con qué precisión se tiene definida.

La aritmética de int tiene una precisión total: si tengo el int '2', es exactamente 2 en el punto indiscutiblemente y si le sumamos uno obtendremos exactamente 3. Independientemente de las operaciones que se hagan con int, siempre que no haya desbordamiento, obtendremos un número con la respuesta correcta bit por bit.
Los float son exactamente lo opuesto a los int con respecto a exactitud y precisión. En muchos casos literalmente no hay esperanza de que una respuesta de float coincida bit a bit con la respuesta correcta. No todas las fracciones se pueden representar exactamente en binario mientras que cualquier entero si. Esta restricción se aplica a cualquier sistema base no solo al binario. Por ej: 1/3 = 0,333333333... ninguna representación de dígitos decimales finitos podria ser igual a 1/3.
Nuestro trabajo es evitar que esos errores de redondeo supongan un problema.

#### * Representación de números en coma flotante

Las representaciones en coma flotante varína de una máquina a otra, pero para ello tenemos el estándar IEEE-754.
Un flotante IEEE-754 (4bytes) o doble(8bytes) tiene tres componentes:
1. Un bit de signo que representa si el float es postivo o negativo.
2. Un exponente que da su orden de magnitud. 8 bits
3. Y una mantisa que especifica los digitos reales del número. 23 bits

*El valor del número se calcula como (-1)^signo * 1.mantisa * 2^(exponente - 127), donde el "1." antes de la mantisa representa el "1" implícito.*

Ejemplo: 

Seeeeeeemmmmmmmmmmmmmmmmmmmmmmm 
s = bit de signo, e = exponente, m = mantisa.

El valor del número es la es la mantisa multiplicada por 2^x, donde x es el exponente. Estamos tratando con fracciones binarias, de modo que el 0,1(el bit de mantisa mas a la izquierda) significa 1/2 (los valores posicionales a la derecha del punto decimal son 2^-1, 2^-2, etc (tal como tener 10^-1, 10^-2 en decimal)).
Existe un problema potencial al almacenar tanto a una mantisa como un exponente: 2x10^-1 = 0,2x10^0 = 0,02x10^1. Esto correspondería a muchos patrones de bits diferentes que representa la misma cantidad. Este problema se soluciona interpretando que la mantisa completa esta a la derecha del punto decimal, con un '1' implícito siempre presente a la izquierda del decimal. Nos referiremos a esto como una representación "1,m". ¿Que pasa si no quieres un 1 en ese lugar?. Hay que pensarlo de la siguiente manera: imaginemos que escribimos un número en binario. A menos que sea cero debe tener un 1 en alguna parte. Cambia su punto decimal justo después del primer 1, luego no se moleste en almacenar ese 1 ya que sabemos que siempre estará implicito. Ahora todo lo que hay que hacer es configurar el exponente correctamente para reproducir la cantidad original.
Si el número es 0, si cada bit es cero(el bit de signo es irrelevante), el número se considera 0.

La interpretación de los bits del exponente seria de la siguiente manera:
* Está codificado como "shift-127" lo que significa que el exponente real es eeeeeee - 127.
* Cede en el extremo inferior siendo el exponente mas bajo posible -126.


Property	                    Value for float	| Value for double
Mayor num representable	        3.402823466e+38	| 1.7976931348623157e+308
Menor num sin perder pres	    1.175494351e-38	| 2.2250738585072014e-308
Menor num representable(*)  	1.401298464e-45	| 5e-324
Mantissa bits	                             23	| 52
Exponent bits	                              8	| 11
Epsilon(**)	                       1.1929093e-7	| 2.220446049250313e-16

(*) Si se establecen los bits del exponente en 0, se puede representar num distintos de 0 usando los bits de mantisa. Ya hemos visto que la mantisa se interpreta como "1.m" siendo el 1 un implícito, sin embargo, si todos los bits del exp son 0, se hace una excepción y se interpreta la mantisa como "0.m". Esto permitiría representar num mas pequeños que 2^126, que sería el num mas bajo representable contando con el 1 implícito.
(**) Épsilon es el x más pequeño tal que 1+x > 1. Es el valor posicional del bit menos significativo cuando el exponente es cero (es decir, almacenado como 0x7f). Por lo que Épsilon determina la precisión(double es mas preciso que float).

### Igualdad

El operador '==' dirá si dos float son exactamente iguales(coinciden bit por bit). Normalmente tiene poco sentido comparar bits cuando alguno de ellos podría ser incorrecto y esta situación la tenemos con la precisión limitada de flotadores. Los resultados deben redondearse para que quepan en una variable finita, y si la CPU o el software no redondean como esperamos , las pruebas de igualdad podrian fallar. Nos encontramos con el panorama en que debemos trabajar con igualdad significando *"lo suficientemente cerca"* con algo parecido a esto.
```cpp

#define EPSILON 1.0e-7//le asignamos ese valor pequeño para usarlo para comparar floats EPSILON = 0,0000001

#define  flt_equals(a, b)(fabs((a) - (b)) < EPSILON)
/*comprueba si dos floats son aprox iguales,restando uno de otro tomando el valor absoluto (positivo) y comprobando que el resultado es menor que EPSILON. 
```
Esta técnica a veces funciona pero no siempre es la apropiada, no tienen en cuenta los exponentes de los dos números.Esto se debe a que la precisión de un flotante no está determinada por la magnitud ("¡En esta CPU, los resultados siempre están dentro de 1,0e-7 de la respuesta!"), sino por el número de bits correctos. El EPSILON de arriba es una tolerancia; es una declaración de cuánta precisión espera en sus resultados. Y la precisión se mide en dígitos significativos, no en magnitud; No tiene sentido hablar de "1.0e-7 de precisión". Un ejemplo rápido hace que esto sea obvio: digamos que tenemos los números 1,25e-20 y 2,25e-20. Su diferencia es 1e-20, mucho menor que EPSILON, pero claramente no queremos que sean iguales. Sin embargo, si los números fueran 1,2500000e-20 y 1,2500001e-20, entonces podríamos considerarlos iguales.

### Desbordamiento (Overflow)

El desbordamiento es una de las preocupaciones mas comunes del programador. Si sumamos 1 al mayor entero sin signo posible este vuelve a 0. Una de las cosas buenas de los floats es que cuando se desbordan lo que queda es +/-inf. Estas cantidades tienden a comportarse como esperamos: +inf es mayor que cualquier numero y -inf es menor que cualquier num. Esta propiedad hace que los floats sean útiles para comprobar el desbordamiento en matemáticas de enteros. Puedes hacer un cálculo en float y luego comparar el resultado con INT_MAX antes de volver a convertirlo en num entero. Siempre con cuidado porque puede ser que el float no tenga la precisión suficiente para un int completo. Un int de 32bits puede representar un decimas de 9 dígitos pero un float de 32bits solo representaría unos 7 dígitos de precisión. Sin embargo un double si tendría la suficiente precisión para representarlo.

## Polymorphism (Polimorfismo)

Es un concepto fundamental de la programación orientada a objetos. Se refiere a la capacidad de un objeto para tomar muchas formas, permite que las clases derivadas hereden y modifiquen los comportamientos de las clases base.
Se logra principalmente a través de funciones virtuales y herencia. Ejemplo:
```cpp
class Base {
public:
    virtual void hacerAlgo() {
        std::cout << "Haciendo algo en la clase base.\n";
    }
};

class Derivada : public Base {
public:
    void hacerAlgo() override {
        std::cout << "Haciendo algo en la clase derivada.\n";
    }
};

int main() {
    Base* b = new Derivada();
    b->hacerAlgo();  // Imprime: "Haciendo algo en la clase derivada."

    delete b;
    return 0;
}
/*En este código, Base es una clase con un método virtual hacerAlgo(). Derivada es una clase que hereda de Base y sobreescribe
el método hacerAlgo(). Cuando llamamos a hacerAlgo() en un puntero a Base que realmente apunta a un objeto Derivada se llama al 
método hacerAlgo() de la clase Derivada. Esto es polimorfismo.*/
```
El polimorfismo tiene varios subtipos:

1. **Polimorfismo de subtipos o polimorfismo de inclusión**-> Lo veremos un poco mas adelante, es el tipo mas común y ocurre cuando una clase hija es tratada como su clase padre. La clase hija puede sobreescribir la clase padre, permitiendo comportamientos diferentes.
2. **Polimorfismo paramétrico->** Permite que el código sea escrito sin mencionar tipos específicos, esto se logra con las plantillas **templates**.
3. **Polimorfismo Ad-hoc->** Permite que una función tenga el mismo nombre pero distintos comportamientos dependiendo de los argumentos que se le pasen. esto se logra a través de la sobrecarga de operadores y de funciones.
4. **Polimorfismo de coerción->** Permite que un tipo sea tratado como otro, a menudo a través de conversiones. Esto se logra a través de las conversiones de tipo y las funciones de conversión.

## Adhoc Polymorphism (Polimorfismo de sobrecarga)

Es un tipo de polimorfismo en el que una función puede tener múltiples implementaciones dependiendo de los args con los que se llame. Esto se logra a trvés de la sobrecarga de funciones o métodos, por lo que podemos tener varias funciones con el mismo nombre y distintos tipor o números de args. El compilador seleccionará la implementación correcta en tiempo de compilación basándose en los args usados para llamar la función. Ejemplo:
```cpp
#include <iostream>
#include <string>

class MiClase {
public:
    // Método para sumar dos enteros
    int sumar(int a, int b) {
        return a + b;
    }

    // Método para concatenar dos strings
    std::string sumar(std::string a, std::string b) {
        return a + b;
    }
};

int main() {
    MiClase obj;
    int num1 = 5, num2 = 10;
    std::string str1 = "Hola ", str2 = "Mundo";

    // Llamada al método sumar con enteros
    std::cout << "Suma de enteros: " << obj.sumar(num1, num2) << std::endl;

    // Llamada al método sumar con strings
    std::cout << "Concatenación de strings: " << obj.sumar(str1, str2) << std::endl;

    return 0;
}
```
## Operator overload (Sobrecarga de operador)

Es una característica que permite cambiar el funcionamiento de los operadores(+, - *, /, etc...) para que funcionen con los tipos de datos definidos por el usuario.
```cpp
class Vector {
public:
    Vector(int x, int y): x(x), y(y) {}

    // Sobrecarga del operador +
    Vector operator+(const Vector& other) {
        return Vector(x + other.x, y + other.y);
    }

private:
    int x, y;
};
/*En este código el operador '+' se sobrecarga para la clase Vector definiendo una función de operador+. Esta función toma otro vector como arg y devuelve un nuevo vector que es la suma de los dos vectores(Definimos de que manera se puede sumar una clase con otra como si fueran números)*/
```

## Forma canónica

Se refiere a un conjunto de convenciones de diseño para las clases que incluyen un contructor por defecto, un constructor de copia, un operador de asignación de copia y un destructor. Ejemplo:
```cpp
class MyClass
{
public:
    // Constructor por defecto
    MyClass() 
    { 
        // Inicialización de los miembros de la clase
    }

    // Constructor de copia
    MyClass(const MyClass& other) 
    { 
        // Copia de los miembros de la clase
    }

    // Operador de asignación de copia
    MyClass& operator=(const MyClass& other) 
    {
        if (this != &other) 
        {
            // Liberación de los recursos actuales
            // Copia de los miembros de la clase
        }
        return *this;
    }

    // Destructor
    ~MyClass() 
    { 
        // Liberación de los recursos
    }

private:
    // Miembros de la clase
};
```
Estas convenciones son importantes cuando tu clase maneja recursos, como memoria dinámicao archivos. En estos casos necesitas asegurarte de que los recursos se copien correctamente en el constructor de copia y el operador de asignación de copia y se liberen correctamente.

## Datos de punto fijo

Se utiliza en el procesamiento de señales digitales y aplicaciones de juegos donde el rendimiento es más importante que la precisión. La aritmética de punto fijo es mucho más rápida que la de punto flotante.

* **Punto binario->** Es la clave para representar num fraccionarios. Actúa como divisor entre la parte entera y la parte fraccionaria de un num.
* **Son parientes de los int, solo se diferencian en la posición del punto binario**. Los int se pueden interpretar como un caso especial de los num de punto fijo donde el punto binario está en la posición 0.
* La arítmetica de punto fijo es tan sencilla y eficiente como la aritmética de int en las computadoras.
* **La desventaja es la pérdida de rango y precisión en comparación con los float. Por ejemplo en una repersentación fixed<8,1> nuestra parte fraccionaria solo tiene una precisión de 0.5. No podemos reperesentar num como 0,75. Podemos representar 0,75 con fixed<8,2> pero perderíamos rango en la parte entera.
* La idea de punto fijo es almacenar los valores multiplicados por una determinada cantidad, utilizar los valores multiplicados para todos los cálculos y dividirlos por la misma cantidad cuando queramos el resultado. **El propósito es usar aritmética de num enteros (int ,long...) y al mismo tiempo poder representar fracciones.**

## El punto binario

En el sistema decimal el punto decimal denota la posición en un num en la que el coeficiente debe multiplicarse por 10^0 = 1. Por ejemplo en el num 26,5, el coeficiente 6 tiene un peso de 10^0=1 y el 5 a la derecha del punto decimal tendría un peso de 10^-1. Sabemos que el num 26,5 representa el valor veintiseis y medio porque 2*10^1 + 6*10^0 + 5*10^-1 = 26,5 o lo que sería lo mismo 20 + 6 + 0,5 = 26,5.
El mismo concepto de punto decimal se aplicaría a nuestra representación binaria formando el **punto binario**. Como en el sistema decimal un punto binario representa el coeficiente del término 2^0=1. Todos los dígitos o bits a la izquierda del punto binario tienen un peso de 2^0, 2^1, 2^2, etc. Los num o bits a la derecha del punto binario tienen un peso de 2^-1, 2^-2, 2^-3 , etc. Por ejemplo, el num :

11010.1^2 representa el valor:
| 2^5 |  2^4  |  2^3  |  2^2  |  2^1  |  2^0  |  2^-1  |  2^-2  | 2^-3 |
|-----|-------|-------|-------|-------|-------|--------|--------|------|
| ... |   1   |   1   |   0   |   1   |   0   |    1   |    0   |  ... |
| ... | 1*2^4 | 1*2^3 | 0*2^2 | 1*2^1 | 0*2^0 | 1*2^-1 | 0*2^-2 |  ... |
| ... |   16  |   8   |   0   |   2   |   0   |   0,5  |    0   |  ... |
| ... |-------|result-|-------|-[26,5]|-------|-result-|--------|  ... |


## Inheritance (Herencia)

La herencia es unprincipio fundamental de la programación orientada a objetos(OOP ó POO). Permite que una clase adquiera las propiedades y métodos de otra clase. La clase de la que se heredan las propiedades se llama *clase base o clase padre*, y la clase que hereda se llama *clase hija o clase derivada*
Por ejemplo si tienes una clase **Vehículo** con propiedades como **color** y **velocidad**, y métodos como **acelerar()** y **frenar()**, prodrias tener una clase **Coche** que herede de **Vehículo**. Tendría todas las propiedades de **Vehículo** y podría tener propiedades y métodos adicionales como **numDePuertas()** y **abrirPuerta()**
En C++ la herencia se denota con el símbolo **':'**. Ejemplo:
```cpp
class Vehiculo{
public:
    std::string color;
    int         velocidad;
    void        acelerar();
    void        frenar();
};

class Coche : public Vehiculo{
public:
    int numDePuertas;
    void    abrirPuerta();
};
```

### Sensible specialisations (Especializaciones sensatas)

Se refiere a la práctica de proporcionar versiones especializadas de una función o clase genérica que son más eficientes para ciertos tipos de datos específicos. Por ejemplo podríamos tener una funcion genérica para comparar dos elementos, pero luego proporcionar una especialización sensata para los num enteros que utiliza operaciones de comparación de enteros rápidas.

### Prueba "is a" y prueba "has a"

* **Prueba "is a"->** Permite verificar si un objeto es de un cierto tipo o si un puntero o referencia a una clase base apunta a un objeto de la clase derivada. Ejemplo:
```cpp
#include <typeinfo>
class Base{
    virtual ~base();
};
class Derived : public Base {};

int main(){
    Base    *b = new Derived();

    if (typeid(*b) == typeid(Derived))
        std::cout << "b is a Derived\n";
    else 
        std::cout << "b is not a derived\n";
    delete b;
    return 0;
}
```
Para que esto funcione, la clase base debe tener al menos un método virtual, para que el objeto tenga información de tipo en tiempo de ejecución.
Además este código solo verifica el tipo exacto del objeto. No considera la herencia. Si **Derived** tuviera una subclase **subDerived**, un objeto de tipo **subDerived** no pasaría la prueba typeid(*b) == typeid(Derived).

* **prueba "has a"->** Es una verificación en tiempo de compilación que verifica si un objeto tiene un miembro de cierto tipo.

#### Agregation 

Término en la POO para decribir una relación entre dos clases que se conoce como *"has a"*. En la agregación una clase ("contenedora/padre") tiene una referencia a otra clase ("contenida/hija"). Sin embargo la clase contenida puede existir independientemente de la clase contenedora.
Por ejemplo, podríamos tener una clase **Equipo** que tiene una lista de objetos **Jugador**. Cada **Jugador** es un miembro del **Equipo**, pero también puede existir sin pertenecer a un **Equipo**.
```cpp
class Jugador {
    // ...
};

class Equipo {
public:
    std::vector<Jugador> jugadores;
    // ...
};
/*En este código, la clase Equipo tiene una agregación de objetos Jugador. Cada Equipo tiene una lista de Jugadores, pero cada Jugador también puede existir independientemente de un Equipo.*/
```

### Access specifier (base class & class members) Acceso específico.

Determina como acceder a los miembros de la clase base dentro de la clase derivada.
* **Private->** Los miembros son totalmente privados de la clase. No solo no se puede acceder a ellos desde fuera de la clase base, sino que tampoco se puede acceder a ellos desde dentro de una clase que los hereda.

* **Protected->** Se puede acceder a los miembros de una clase base desde dentro de una clase derivada, pero están protegidos de interferencias externas.

El acceso a los miembros heredados de un objeto no sólo está determinado por su especificación de acceso en la clase base, sino también por el especificador de acceso de la clase base en la clase derivada.

Poder **cambiar el nivel de acceso** de los miembros heredados en una clase derivada le brinda cierto grado de flexibilidad, pero **solo puede hacer que el nivel de acceso sea mas estricto**, no puede relajar el nivel de acceso despecificado en la clase base.
```cpp
class Quadruped { // Can access name, run() and legs

private:
	std::string name; // Only accessible from an Quadruped object

protected:
	Leg legs[4]; // Accessible from an Quadruped or derived object

public:
	void run(); // Accessible from wherever
};
```

## Multiple Inheritance (Herencia múltiple)

Una clase puede heredar comportamientos y carácterísticas de más de una clase base:
```cpp
class Base1 {
public:
    void methodFromBase1() {
        // Implementación del método
    }
};

class Base2 {
public:
    void methodFromBase2() {
        // Implementación del método
    }
};

class Derived : public Base1, public Base2 {
    // Derived hereda de Base1 y Base2
};
```

En este ejemplo la clase **Derived** hereda de **Base1** y **Base2** pudendo usar los métodos de las dos clases.
La herencia múltiple puede ser complicada y generar problemas cuando no se maneja con cuidado. Si las dos clases base tienen un método con el mismo nombre, es confuso determinar cual de los métodos se usará. Esto se conoce como el problema del diamante.
Este problema se resuelve en C++ de la siguiente manera:
```cpp
class Base {
public:
    virtual void foo() {}
};

class Derived1 : virtual public Base {
public:
    void foo() override {}
};

class Derived2 : virtual public Base {
public:
    void foo() override {}
};

class Diamond : public Derived1, public Derived2 {
    // Ahora Diamond solo tiene una versión de foo()
};
```
Al hacer que **Derived1** y **Derived2** hereden virtualmente de **Base**, se asegura que soo haya una copia de los miembros de **Base** en **Diamond**, resolviendo así el problema del diamante. 

### Diamond problem

Es un problema de ambigüedad que puede suceder con la herencia múltiple, ocurre cuando una clase hereda de dos o mas clases que tienen un método con la misma firma.
```cpp
class A {
public:
    void foo() { cout << "A::foo" << endl; }
};

class B : public A { };

class C : public A { };

class D : public B, public C { };
/*En este caso si llamamos al método foo, el compilador no sabrá si usar B::foo() o C::foo() ya que 
ambos son válidos debido a la herencia de A.*/
```
En lenguajes como python y C#, utilizan un método llamado "Linearización de C3" para determinar un orden de resolución. Otros lenguajes como Java evitan el problema no permitiendo la herencia múltiple. 
En C++ usamos la herencia virtual, que asegura que sólo se crea una copia base de la clase base A, independientemente de cuantas clases intermedias hereden de ella.
```cpp
class A {
public:
    void foo() { cout << "A::foo" << endl; }
};

class B : virtual public A { };

class C : virtual public A { };

class D : public B, public C { };
```
Ahora D::foo() se compilará y ejecutará sin problemas, ya que hay un A::foo al que llamar.


## Sub-typing polimorphism (Polimorfismo de subtipos o de inclusión)

Es un tipo de polimorfismo en el que una clase derivada (subtipo) puede ser utilizada en lugar de una clase base (supertipo), permitiendo diferentes comportamientos al sobreescribir los métodos de la clase base en la clase derivada. Ejemplo:
```cpp
#include <iostream>

class Animal {
public:
    virtual void hacerSonido() {
        std::cout << "(silencio)" << std::endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        std::cout << "Guau!" << std::endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() override {
        std::cout << "Miau!" << std::endl;
    }
};

void reproducirSonido(Animal* animal) {
    animal->hacerSonido();
}

int main() {
    Perro perro;
    Gato gato;

    reproducirSonido(&perro);  // Imprime "Guau!"
    reproducirSonido(&gato);   // Imprime "Miau!"

    return 0;
}
/*En este código, Animal es la clase base que tiene un método hacerSonido(). Perro y Gato son clases derivadas 
que sobreescriben este método. La función reproducirSonido() toma un puntero a Animal y llama al método 
hacerSonido() en él. Gracias al polimorfismo de inclusión puedes pasar un puntero a Perro o Gato a esta 
función, y se llamará al método hacerSonido() apropiado.*/
```

## Etiqueta virtual

Se utiliza para permitir que una función en una clase base sea sobreescrita en una clase derivada. Esto es fundamental para el polimorfismo.

```cpp
class Animal {
public:
    virtual void hacerSonido() {
        std::cout << "El animal hace un sonido" << std::endl;
    }
};
```
### Destructor virtual

Se utiliza para asegurar que el destructor correcto se llame para un objeto cuando se elimina un puntero a la clase base que apunta aun objeto de la clase derivada. Si no se hacde el destructor de la clase base virtual, cuando se elimina el puntero a la clase base, solo se llamará al destructor de la clase base, no el de la clase derivada. Esto puede conllevar memory leaks si la clase derivada tiene recursos que necesitan ser liberados en su destructor.
```cpp
class Base {
public:
    virtual ~Base() {
        std::cout << "Destructor de Base" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "Destructor de Derived" << std::endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // Llama al destructor de Derived y luego al de Base
    return 0;
}
/*En este código, el destructor de Base es virtual, lo que significa que si eliminas 
un puntero a Base que apunta a un objeto Derived, se llamará al destructor correcto.
Primero se llamará al destructor de Derived y luego al de Base.*/
```

## Abstrass Classes

Una classe abstracta es una clase que **no puede ser instanciada directamente**. Se utiliza principalmente como una clase base para otras clases.
En C++ una clase se vuelve abstracta si tiene al menos un **método virtual puro**. Un **método virtual puro** es un método que se declara en una clase base y tiene una especificación '= 0' en su declaración.
Las clases derivadas de la clase abstracta deben implementar todos los métodos virtuales puros, de lo contrario, también se convertirán en clases abstractas y no podrán ser instanciadas. Ejemplo:
```cpp
#include <iostream>

// Clase abstracta
class Animal {
public:
    // Método virtual puro
    virtual void makeSound() = 0;

    // Método concreto
    void eat() {
        std::cout << "El animal come" << std::endl;
    }
};

// Clase derivada
class Dog : public Animal {
public:
    // Implementación del método virtual puro
    void makeSound() override {
        std::cout << "El perro ladra" << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.makeSound(); // El perro ladra
    myDog.eat(); // El animal come

    return 0;
}
/*En este código, Animal es una clase abstracta que tiene un método virtual puro makeSound().
La clase Dog hereda de la clase Animal y proporciona una implementación para el método makeSound()*/
```

## Excepciones

Son una forma de manejar errores y condiciones excepcionales en nuestro programa. Permiten separar el código de manejo de errores del código principal, lo que permite que nuestro código sea más limpio y facil de mantener. Así funcionan las excepciones en c++:
1. **Lanzar una excepción** : Utilizariamos la palabra clave **throw**. Implica generar una señal de que ha ocurrido un error o una condición excepcional en el programa. Cuando se lanza una excepción el flujo de ejecución del programa se interrumpe y se transfiere el control a la parte del código que está preparada para manejar esa excepción.
2. **Capturar una excepción**: Utilizaremos un bloque **try** para envolver el código que puede lanzar una excepción y un bloque **catch** para manejarla.
Ejemplo:
```c++
#include <iostream>
#include <stdexcept> //para std::runtime_error

void    funcionQuePuedeFallar(int valor)
{
    if (valor < 0)
    {
        throw std::runtime_error("Valor negativo no permitido");
    }
    std::cout << "valor: " << valor << std::endl; 
}
/*
 *const std::runtime_error& e -> Significa que el bloque catch esta diseñado para capturar excepciones de tipo std::runtime_error.(se captura como referencia constante para evitar copias innecesarias y que la excepción original no se modifique). La excepción std::runtime_error en si es una clase con sus métodos y atributos y hereda de la clase std::exception.
 *e.what()-> es un método de std::exception que devuelve un mensaje de error en forma de string (const char*). Este mensaje se establece cuando se lanza la excepción y puede ser utilizado para dar info sobre el error ocurrido.
*/
int main()
{
    try
    {
        funcionQuePuedeFallar(10);
        funcionQuePuedeFallar(-1);//aqui fallaría la función y saltaría el catch
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "El programa continua..." << std::endl;
    return 0;
}
```
### Tipos de excepciones

En c++, existen varios tipos de escepciones estándar que se encuentran en la biblioteca **\<stdexcept\>**.
Estas serian algunas de las mas comunes:

* **Excepciones estándar en C++**:
1. **std::exception**
    * La clase base para todas las excepciones estándar de c++.
    * El método **what()** devuelve un mensaje de error genérico.
2. **std::runtime_error**
    * Hereda de **std::exception**.
    * Se usa para errores que solo pueden ser detectados en tiempo de ejecución.
    * Ej: std::runtime_error("Error en tiempo de ejecución");
3. **std::logic_error**
    * Hereda de **std::exception**.
    * Se utiliza para errores lógicos en el programa, que podrian ser detectados en tiempo de compilación.
    * Ej: std::logic_error("Error en tiempo de compilación");
4. **std::out_of_range**:
    * Hereda de **std::logic_error**.
    * Se utiliza cuando se accede a un elemento fuera del rango válido.
    * Ej: std::out_of_range("Índice fuera de rango");
5. **std::invalid_argument**:
    * Hereda de **std::logic_error**.
    * Se utiliza cuando se pasa un argumento inválido a una función.
    * Ej: std::invalid_argument("Argumento inválido");
6. **std::length_error**:
    * Hereda de **std::logic_error**.
    * Se utiliza cuando se intenta crear un objeto con una longitud que excede la max permitida.
    * Ej: std::length_error("Longitud excedida").
7. **std::domain_error**:
    * Hereda de **std::runtime_error**.
    * Se usa cuando un argumento está fuera del dominio válido de una función matemática.
    * Ej: std::domain_error("Error de dominio").
8. **std::overflow_error**:
    * Hereda de std::runtime_error.
    * Se utiliza cuando una operación aritmética produce un desbordamiento.
    * Ej: std::overflow_error("Desbordamiento aritmético");
9. **std::underflow_error**:
    * Hereda de std::runtime_error.
    * Se utiliza cuando una operación aritmética produce un subdesbordamiento.
    * Ej: std::underflow_error("Subdesbordamiento aritmético");

Estas excepciones permiten manejar errores de manera más específica y controlada en los programas C++.
