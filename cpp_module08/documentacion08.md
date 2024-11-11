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
