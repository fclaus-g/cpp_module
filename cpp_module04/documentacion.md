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

Para este ejercicio debemos hacer varias clases empezando con Animal que será nuestra clase base y luego la clase Cat y Dog. A tener en cuenta que al trabajar con subclases debemos, en nuestra clase base, crear un destructor virtual para evitar leaks de memoria y la correspondiente función virtual, makeSound() en este caso, para poder ser sobreescrita por las subclases.

```cpp

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);//constructor con parametro
		virtual ~Animal();//virtual destructor para que se llame al destructor de las clases hijas
		Animal(const Animal& other);//copy constructor
		Animal&	operator=(const Animal &other);//asignacion por sobrecarga de operador
		
		std::string		getType() const;
		virtual void	makeSound() const;//funcion virtual pura que se implementara en las clases hijas
};
```
Tenemos tambien que crear una clase equivocada para trabajar con errores y muestre mensajes equivocados.