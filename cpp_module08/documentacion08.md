# Cpp_modules08

## Ex00

### Subject

Un primer ejercicio sencillo es la forma de empezar con el pie derecho.
Escribe una plantilla de función easyfind que acepte un tipo T. Toma dos parámetros.
El primero tiene el tipo T y el segundo es un entero.
Suponiendo que T es un contenedor de enteros, esta función tiene que encontrar la primera aparición
del segundo parámetro en el primer parámetro.
Si no se encuentra ninguna aparición, puedes lanzar una excepción o devolver un valor de error
de tu elección. Si necesitas algo de inspiración, analiza cómo se comportan los contenedores estándar.
Por supuesto, implementa y entrega tus propias pruebas para asegurarte de que todo funciona como se espera.
No tienes que manejar contenedores asociativos.

### Explicación

El objetivo principal del ejercicio es implementar una función plantilla (template) en C++ llamada easyfind. Esta función debe aceptar un contenedor (como std::vector, std::list, etc.) y buscar un valor entero dentro de este contenedor.

* **Explicación de la Función easyfind** 

Plantilla de función: easyfind es una función plantilla, lo que significa que puede adaptarse para trabajar con diferentes tipos de contenedores, siempre que contengan enteros. La plantilla utiliza un parámetro de tipo T para hacer que la función sea genérica.

* Parámetros de la función:

El primer parámetro es un contenedor del tipo T (por ejemplo, std::vector<int>, std::list<int>, etc.).

El segundo parámetro es un entero, que representa el valor que queremos encontrar dentro del contenedor.


* **Uso de Algoritmos Estándar:**

La función easyfind puede utilizar algoritmos de la biblioteca estándar de C++, como std::find, que permite buscar en un rango de elementos.
std::find retorna un iterador apuntando al elemento si lo encuentra, o un iterador al final del contenedor (container.end()) si no encuentra el valor.

* **Manejo de Excepciones:**

Si el valor no se encuentra, easyfind debería lanzar una excepción o retornar un valor de error. Usualmente, en C++, lanzar una excepción personalizada (std::runtime_error o una clase propia) es una buena práctica en estos casos, para notificar al usuario de que el valor no fue encontrado.


## Ex01
### Subject
Desarrolla una clase Span que pueda almacenar un máximo de N números enteros. N es una variable int
sin signo y será el único parámetro que se pase al constructor.
Esta clase tendrá una función miembro llamada addNumber() para agregar un solo número
al Span. Se usará para llenarlo. Cualquier intento de agregar un nuevo elemento si ya hay N elementos almacenados debe generar una excepción.
A continuación, implementa dos funciones miembro: shortestSpan() y longestSpan()
Estas funciones encontrarán respectivamente el span más corto o el span más largo (o la distancia, si lo prefieres) entre todos los números almacenados y lo devolverán. Si no hay números almacenados,
o solo uno, no se puede encontrar ningún span. Por lo tanto, genera una excepción.
Por supuesto, escribirás tus propias pruebas y serán mucho más exhaustivas que las que se muestran a continuación. Prueba tu Span al menos con un mínimo de 10 000 números. Más sería incluso mejor.
```cpp
int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
//debe mostrar
$> ./ex01
2
14
$>
```
Por último, pero no por ello menos importante, sería fantástico llenar tu Span usando un rango de iteradores.
Hacer miles de llamadas a addNumber() es muy molesto. Implementa una función miembro
para agregar muchos números a tu Span en una sola llamada.
Si no tienes idea, estudia los Contenedores. Algunas funciones miembro
toman un rango de iteradores para agregar una secuencia de
elementos al contenedor.

## Explicación

El objetivo es crear una clase en C++ llamada Span que permite almacenar un conjunto de números enteros y calcular la distancia entre ellos. A continuación, se explica en detalle cada uno de los requerimientos de esta clase.

* **Descripción de la Clase Span**

	+ **Atributo de Almacenamiento:**

	La clase debe almacenar un máximo de N números enteros, donde N es un entero sin signo (unsigned int) que se pasa como parámetro al constructor.
	Puedes usar un contenedor de la STL como std::vector<int> para almacenar estos números.
	
	+ **Constructor:**

	Span(unsigned int N): El constructor recibe un solo parámetro N, que representa el límite máximo de números enteros que se pueden almacenar en la instancia de Span.

	+ **Función addNumber:**

	addNumber(int number): Esta función permite agregar un número entero al contenedor.
	Si la cantidad de elementos en el contenedor ya alcanzó N, la función debe lanzar una excepción (por ejemplo, usando std::runtime_error) para evitar sobrepasar el límite.

	+ **Funciones shortestSpan y longestSpan:**

		- **shortestSpan():** Calcula la distancia mínima entre cualquier par de números en el contenedor. Para esto, puedes ordenar los números almacenados y luego encontrar la diferencia mínima entre elementos adyacentes. Si hay menos de dos números almacenados, se lanza una excepción.
		- **longestSpan():** Calcula la distancia máxima entre el valor más pequeño y el valor más grande en el contenedor. Similarmente, si hay menos de dos números, lanza una excepción.

## Ex02
### Subject
Ahora, es hora de pasar a cosas más serias. Desarrollemos algo extraño.
El contenedor std::stack es muy bueno. Desafortunadamente, es uno de los únicos contenedores STL que NO es iterable. Eso es una pena.
Pero, ¿por qué aceptaríamos esto? Especialmente si podemos tomarnos la libertad de destrozar la pila
original para crear características faltantes.
Para reparar esta injusticia, tienes que hacer que el contenedor std::stack sea iterable.
Escribe una clase MutantStack. Se implementará en términos de un std::stack.
Ofrecerá todas sus funciones miembro, más una característica adicional: iteradores.
Por supuesto, escribirás y entregarás tus propias pruebas para asegurarte de que todo funciona como se espera.
```cpp
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
```
Si lo ejecutas por primera vez con MutantStack y una segunda vez reemplazas MutantStack con, por ejemplo, un std::list, las dos salidas deberían ser las mismas. Por supuesto, cuando pruebes otro contenedor, actualiza el código a continuación con las funciones miembro correspondientes (push() puede convertirse en push_back()).

## Explicación

El objetivo es crear una clase llamada MutantStack que herede de std::stack y que sea iterable. Esto significa que se le deben agregar iteradores, algo que std::stack no tiene de forma nativa en la STL de C++.

* Descripción de la Clase MutantStack
	Herencia de std::stack:

	MutantStack debe heredar de std::stack y mantener toda la funcionalidad de una pila normal (push, pop, top, size, etc.).

* Iteradores:

	La funcionalidad clave que debe agregar MutantStack es la capacidad de iterar sobre sus elementos.
	Para esto, se deben definir iteradores que apunten al comienzo y al final de la pila. Se pueden implementar utilizando los iteradores del contenedor subyacente de std::stack, que típicamente es std::deque.

* Uso en main():

	En el ejemplo de main, se demuestra el uso de MutantStack al realizar operaciones de pila (como push y pop), y luego se muestra la iteración sobre los elementos.
	La salida de MutantStack debería ser la misma que la de otros contenedores iterables (como std::list), demostrando que se comporta como una estructura iterable.

**Resumen**

-MutantStack es una pila basada en std::stack que añade soporte para iteradores.
Los iteradores se logran accediendo al contenedor subyacente de std::stack (por defecto std::deque).
MutantStack permite recorrer los elementos almacenados de manera similar a otros contenedores iterables de la STL, solucionando la limitación original de std::stack.
Este diseño hace que MutantStack sea completamente compatible con std::stack, añadiendo al mismo tiempo la flexibilidad de ser iterable.