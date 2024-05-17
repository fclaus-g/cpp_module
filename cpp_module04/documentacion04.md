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


## Ex01-> I don’t want to set the world on fire

### Subject

Los constructores y destructores de cada clase deben mostrar mensajes específicos.
Implementar una clase Brain. Contiene una matriz de 100 std::string llamadas ideas.
De esta manera, Perro y Gato tendrán un atributo Brain* privado.
Tras la construcción, Perro y Gato crearán su Cerebro usando new Brain();
Tras la destrucción, Perro y Gato eliminarán su cerebro.
En su función principal, cree y complete una serie de objetos Animales. La mitad será serán objetos de Perro y la otra mitad serán objetos de Gato. Al final de su programa ejecución, recorra esta matriz y elimine todos los animales. Debes eliminar directamente los perros y gatos como animales. Los destructores apropiados deben llamarse en el orden esperado.
No olvide comprobar si hay pérdidas de memoria.
Una copia de un Perro o un Gato no debe ser superficial. Por lo tanto, debes probar que tus copias
son copias profundas!

### Objetivo

Seguir practicando con la forma canónica ortodoxa, con clases con diferentes atributos, conocer lo que es la copia profunda.

### Desarrollo

Para hacer este ejercicio hemos creado la clase Brain tal como indica el subject y para que todo funcione  correctamente debemos modificar nuestras clases Cat y Dog para que inicien y destruyan su atributo _brain de forma correcta además de añadir el correspondiente constructor de copia y la sobrecarga del operador '='.

**Copia profunda**-> Se refiere a la creación de una nueva copia de cada valor de datos en el objeto original en lugar de copiar las referencias. Es importante cuando se trabaja con punteros o con recursos que necesitan ser liberados, como la memoria dinámica. Ejemplo:
```cpp
class ClaseConPuntero {
    int* datos;
    size_t tamano;

public:
    ClaseConPuntero(size_t tamano) : tamano(tamano) {
        datos = new int[tamano];
    }

    // Constructor de copia que realiza una copia profunda
    ClaseConPuntero(const ClaseConPuntero& otra) : tamano(otra.tamano) {
        datos = new int[tamano];
        std::copy(otra.datos, otra.datos + tamano, datos);
    }

    // Sobrecarga del operador de asignación que realiza una copia profunda
    ClaseConPuntero& operator=(const ClaseConPuntero& otra) {
        if (this != &otra) {
            delete[] datos;

            tamano = otra.tamano;
            datos = new int[tamano];
            std::copy(otra.datos, otra.datos + tamano, datos);
        }
        return *this;
    }

    ~ClaseConPuntero() {
        delete[] datos;
    }
};
/*En este código el constructor de copia y el operador de asignación crean una nueva copia
de los datos en lugar de copiar simplemente el puntero. Esto significa que si el objeto original
se destruye o cambia, la copia no se verá afectada.*/
```
**Copia superficial**-> Simplemente copia los valores de los miembros de un objeto a otro. Si un miembro es un puntero, la copia superficial copiará la dirección del puntero, no los datos a los que apunta. Ejemplo:
```cpp
class ClaseConPuntero {
    int* datos;
    size_t tamano;

public:
    ClaseConPuntero(size_t tamano) : tamano(tamano) {
        datos = new int[tamano];
    }

    // Constructor de copia que realiza una copia superficial
    ClaseConPuntero(const ClaseConPuntero& otra) : tamano(otra.tamano), datos(otra.datos) {
    }

    // Sobrecarga del operador de asignación que realiza una copia superficial
    ClaseConPuntero& operator=(const ClaseConPuntero& otra) {
        if (this != &otra) {
            tamano = otra.tamano;
            datos = otra.datos;
        }
        return *this;
    }

    ~ClaseConPuntero() {
        delete[] datos;
    }
};
/*En este código, el constructor de copia y el operador de asignación solo copian el puntero datos
 y el tamaño tamano del objeto original*/
 ```
 
## Ex02-> Abstract Class

### Subject
Después de todo, crear objetos animales no tiene sentido. ¡Es verdad, no emiten ningún sonido!
Para evitar posibles errores, la clase Animal predeterminada no debe ser instanciable. Arregla la clase Animal para que nadie pueda crear una instancia de ella. Todo debería funcionar como antes.
Si lo desea, puede actualizar el nombre de la clase agregando un prefijo A a Animal.

### Objetivo

Conocer como funciona la clase abstracta y los métodos virtuales puros.

### Desarrollo

Pues es sorprendentemente rápido terminar este ejercicio puesto que lo que tenemos que hacer es cambiar el método virtual makeSound() de la clase Animal por un método virtual puro añadiendo una igualación a 0. Esto haría que no podamos instanciar una clase Animal, sino que solo serviria como clase base para las subclases.

```cpp
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
		virtual void	makeSound() const = 0;//metodo virtual puro
};
```

## Ex03 -> Interface & Recap

### Subject

Las interfaces no existen en C++98 (ni siquiera en C++20). Sin embargo, las clases puramente abstractas comúnmente se denominan interfaces. Por lo tanto, en este último ejercicio, intentemos implementar interfaces para asegurarte de que tienes este módulo.
1. Complete la definición de la siguiente clase AMateria e implemente las necesarias funciones miembro.
```cpp
class AMateria
{
	protected:
	[...]
	public:
	AMateria(std::string const & type);
	[...]
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
```
* Implementar las clases de Materias concretas Ice y Cure. Utilice su nombre en minúsculas
case ("ice" para Ice, "cure" para Cure) para establecer sus tipos. Por supuesto, su función de miembro.
* clone() devolverá una nueva instancia del mismo tipo (es decir, si clonas un Ice Materia,
obtendrás una nueva Materia de Hielo).
* La función miembro use(ICharacter&) mostrará:
	* Hielo: "* dispara un rayo de hielo a <nombre> *"
	* Cura: "*cura las heridas de <nombre>*"
	<nombre> es el nombre del carácter pasado como parámetro. No imprimas el ángulocorchetes (< y >).
* Al asignar una Materia a otra, copiar el tipo no hace sentido.

2. Escriba la clase concreta Carácter que implementará la siguiente interfaz

```cpp
class ICharacter
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};
```

* El Personaje posee un inventario de 4 espacios, lo que significa 4 Materias como máximo.
* El inventario está vacío en la construcción. Equipan las Materias en el primer hueco vacío ellos encuentran. Esto significa, en este orden: del slot 0 al slot 3. En caso de que intenten agregar una Materia a un inventario completo, o usar/desequipar una Materia inexistente, no hagas nada(pero aún así, los errores están prohibidos). La función miembro unequip() NO debe eliminar el ¡Materia!
* Maneja las Materias que tu personaje dejó en el suelo como quieras.
* Guarde las direcciones antes de llamar a unequip(), o cualquier otra cosa, pero
	No olvides que debes evitar pérdidas de memoria.
* La función miembro use(int, ICharacter&) tendrá que usar Materia en el
	slot[idx] y pase el parámetro de destino a la función AMateria::use.
* El inventario de tu personaje podrá soportar cualquier tipo de Materia.
* Tu personaje debe tener un constructor que tome su nombre como parámetro. cualquier copia
(usando el constructor de copia o el operador de asignación de copia) de un personaje debe ser profundo.
Durante la copia, las Materias de un Personaje deben eliminarse antes de agregar las nuevas.
a su inventario. Por supuesto, las Materias deben eliminarse cuando se destruye un Personaje.

3. Escriba la clase concreta MateriaSource que implementará la siguiente interfaz:.

```cpp
class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};
```

* • aprenderMateria(AMateria*)
	Copia la Materia pasada como parámetro y la almacena en la memoria para poder clonarla más tarde. Al igual que el personaje, MateriaSource puede conocer como máximo 4 Materias. Ellos
	no son necesariamente únicos.
* • createMateria(std::string const &)
	Devuelve una nueva Materia. Esta última es una copia de la Materia previamente aprendida por MateriaSource cuyo tipo es igual al pasado como parámetro. Devuelve 0 si el tipo es desconocido. 
* En pocas palabras, su MateriaSource debe poder aprender "plantillas" de Materias para crearlos cuando sea necesario. Luego, podrás generar una nueva Materia usando solo una cadena que identifique su tipo.

