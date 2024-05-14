# Cpp_module 04

## Ex00-> Polimorphism

### Subject

Para cada ejercicio, debes proporcionar las pruebas más completas que puedas. Los constructores y destructores de cada clase deben mostrar mensajes específicos. No uses el mismo mensaje para todas las clases.
Comience implementando una clase base simple llamada Animal, tiene un atributo protegido:

	std::string type;
* Implemente una clase Perro que herede de Animal.
* Implemente una clase Cat que herede de Animal.
Estas dos clases derivadas deben establecer su campo de tipo según su nombre. Entonces, el tipo de Perro se inicializará a "Perro" y el tipo de Gato se inicializará a "Gato". El tipo de clase Animal puede dejarse vacío o establecerse con el valor que elija.

Cada animal debe poder utilizar la función miembro:

	makeSound();

Imprimirá un sonido apropiado (los gatos no ladran).

La ejecución de este código debería imprimir los sonidos específicos de las clases Perro y Gato, no los animales.

```cpp
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	...
	return 0;
}
```
Para asegurarse de comprender cómo funciona, implemente una clase WrongCat que herede de una clase WrongAnimal. Si reemplazas el Animal y el Gato por los incorrectos en el código anterior, WrongCat debería emitir el sonido WrongAnimal.
Implemente y entregue más pruebas que las indicadas anteriormente.

### Objetivo

Familiarizarnos con el polimorfismo de inclusión.

### Desarrollo
