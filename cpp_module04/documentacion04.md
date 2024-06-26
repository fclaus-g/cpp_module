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

```cpp
class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& other);

		std::string	getType() const;
		void		makeSound() const; 
		/*al no declarar el método como virtual a la hora de llamar al método de la subclase
		se ejecutará el de la clase madre por defecto*/
};
```

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

* • learnMateria(AMateria*)
	Copia la Materia pasada como parámetro y la almacena en la memoria para poder clonarla más tarde. Al igual que el personaje, MateriaSource puede conocer como máximo 4 Materias. Ellos
	no son necesariamente únicos.
* • createMateria(std::string const &)
	Devuelve una nueva Materia. Esta última es una copia de la Materia previamente aprendida por MateriaSource cuyo tipo es igual al pasado como parámetro. Devuelve 0 si el tipo es desconocido. 
* En pocas palabras, su MateriaSource debe poder aprender "plantillas" de Materias para crearlos cuando sea necesario. Luego, podrás generar una nueva Materia usando solo una cadena que identifique su tipo.

### Objetivo 

Poner en práctica todo lo aprendido en estos módulos, es un buen proyecto final muy completo.

### Desarrollo

Vamos a empezar declarando los hpp que nos pide el subject, poco a poco iremos comprendiendo exactamente que es y como tenemos que ir haciendo el ejercicio.

1. El primer hpp que vamos a hacer es el de **AMateria**, una **clase abstracta**(tiene un método virtual puro y no puede instanciarse directamente, solo a través de herencia). Respetaremos la forma canónica ortodoxa.
```cpp
class AMateria{
	protected://para que sea accesible por las subclases
		std::string _type;

	public:
		AMateria();//constructor por defecto
		AMateria(const std::string& type);//constructor con parámetro(string)
		AMateria(const AMateria& other);//constructor de copia const porque no se va a modificar.
		~AMateria();//destructor
		AMateria& operator=(const AMateria& other);//asignacion por sobrecarga de operador
		/*el siguiente método tiene 2 const-> el 1º porque no se va a poder modificar el std::string que se devuelve y el 2ª indica que getName es una función constante y no puede modificar ningún miembro del objeto en el que se llama*/ 
		const	std::string& getType() const;
		void	setType(std::string type);
		
		/**
		 * virtual:la función puede ser sobreescrita, 
		 * AMateria*: devuelve un puntero a un objeto AMateria.
		 * clone(): la función en si.
		 * const: no podrá modificar ningun miembro de la clase.
		 * =0: debe ser implementada por la subclase que herede de esta clase.*/
		virtual AMateria* 	clone() const = 0;
		virtual void		use(ICharacter& target);
};
```
2. A continuación implementaremos el header de ICharacter que será simpl,emente una plantilla o **interface**, no hay que hacerle el .cpp porque serán las clases que hereden de esta la que se encarguen de este trabajo.
```cpp
class ICharacter {
	public:
		/*virtual destructor: asegura que se llame al destructor correcto cuando se destruye un objeto a través de un puntero a la clase base
		*{}-> nos ahorramos definir el destructor (se encargará la subclase que lo herede)*/ 
		virtual ~ICharacter() {};
		/*El resto de funciones son virtuales puras (=0) por lo que se encargará la subclase de implementarlas*/
		virtual const 	std::string& getName() const = 0;
		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;
};
```
3. Vamos a por el siguiente header o .hpp que nos da el subject que sería **IMateriaSource** otra **interface** que será heredada por **MateriaSource** una subclase que crearemos en el siguiente paso.
```cpp
class IMateriaSource {
	public:
		virtual ~IMateriaSource() {};
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria( std::string& type) = 0;
};
/*como podemos observar de nuevo, al ser IMateriaSource una interface contiene funciones virtuales puras para que sean heredadas e implementadas por las subclases*/ 
```
4. A continuación vamos a crear una clase **MateriaSource** que será la que heredará de la plantilla o interface **IMateriaSource**. Haciendo caso de lo que nos pide el subject esta subclase vba a tener una capacidad de materia de 4 puestos. De momento le voy a añadir un int indice, quizá nos sirva mas adelante.
```cpp
/*En la declaración de MateriaSource podemos ver como hereda de la clase madre IMateriaSource a través de los ':'*/
class MateriaSource : public IMateriaSource {
	private:
		AMateria*	_materias[4];
		int			_index;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		MateriaSource&	operator=(const MateriaSource& other);

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(const std::string& type);
};
```
4. Vamos a crear el header de nuetro personaje o character que heredará de la interface **ICharacter** y su .cpp para desarrollar sus métodos y asinar sus atributos.
```cpp
/*----------[HEADER]------------*/
class Character {
	private:
		std::string _name;
		AMateria*	_inventory[4];//invenario de materias
		int			_index;//indice para el inventario
	public:
		Character();//constructor por defecto
		Character(std::string name);//constructor con nombre
		Character (const Character& copy);//constructor de copia
		~Character();//destructor

		Character& operator=(const Character& copy);//sobrecarga de =

		const std::string& getName() const;//getter del nombre
		void equip(AMateria* m);//función que añade una materia al inventario
		void unequip(int idx);//funcion que elimina una materia del inventario
		void use(int idx, ICharacter& target);//funcion que usa la materia contra un objetivo pasado por parametros.
};

/*------------------[.cpp]-------------------------*/
Character::Character() {
	this->_name = "Default";
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name) {
	this->_name = name;
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& copy) {
	this->_name = copy._name;
	this->_index = copy._index;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i];
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
}

Character& Character::operator=(const Character& rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_index = rhs._index;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

const std::string& Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (this->_index < 4 && m == NULL)
	{
		this->_inventory[this->_index] = m;
		this->_index++;
		std::cout << this->_name << " has equipped " << m->getType() << std::endl;
	}
	else
		std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
	{
		std::cout << this->_name << " has unequipped " << this->_inventory[idx]->getType() << std::endl;
		this->_inventory[idx] = NULL;
		this->_index--;
	}
	else
		std::cout << "Invalid index" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
	{
		std::cout << this->_name << " uses " << this->_inventory[idx]->getType() << " on " << target.getName() << std::endl;
		this->_inventory[idx]->use(target);
	}
	else
		std::cout << "Invalid index" << std::endl;
}
```

5. Ahora crearemos nuestra primera materia "ice" que heredará de **AMateria** e implementaremos los métodos que llevará.
```cpp
/*--------------[HEADER]----------------*/
class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& other);
		~Ice();

		Ice&	operator=(const Ice& other);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};
/*--------------[.cpp]-----------------*/
Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
};

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Ice copy constructor called" << std::endl;
};

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
};

Ice&	Ice::operator=(const Ice& other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AMateria*	Ice::clone() const {
	Ice* clone;
	clone = new Ice(*this);
	return (clone);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
```
6. Repetimos el ultimo paso para crear nuestra materia cure

* En nuestro main hay algunas cosas a tener en cuenta:
```cpp
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
   	/*cuando vamos a usar una clase ejemplo MateriaSource y esta tiene una Interfaz debemos
	declarar la interface debido al principio de "Programar para la Interface, no para la 
	implementación. La ventaja de hacer esto es que permite cambiar implementaciones completas 
	sin tener que cambiar el código que utilizan estas abstracciones.*/
	IMateriaSource* src = new MateriaSource();//declaración de la interfaz
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

	ICharacter* Wizard = new Character("Wizard");
	Wizard->equip(src->createMateria("ice"));
	Wizard->equip(src->createMateria("cure"));
	
	ICharacter* Warrior = new Character("Warrior");
	Warrior->equip(src->createMateria("cure"));
	Warrior->equip(src->createMateria("cure"));
	Warrior->equip(src->createMateria("cure"));
	Warrior->equip(src->createMateria("cure"));//llenamos el inventory y nos dá el input inventory is full
	Warrior->equip(src->createMateria("cure"));
	Warrior->unequip(3);
	Warrior->unequip(2);
	Wizard->use(0, *Warrior);
	Wizard->use(1, *Warrior);
	Wizard->use(2, *Warrior);//usamos un indice que aun no existe, nos imprime index invalid
	ICharacter* Loco = new Character("Loco");
	Loco = Warrior;//usamos el operador para comprobar que funciona.
	Warrior->use(0, *Loco);

	delete Loco;
	delete Warrior;
	delete Wizard;
	
    return 0;
}
```
