# CPP_modules 01

## Ex00 -> Zombie!

### Subject
Primero, implementa una clase Zombie. Tiene un atributo privado string name. Añade una función miembro void announce( void ); a la clase Zombie. Los zombis se anuncian como sigue: <nombre>: BraiiiiiiinnnzzzZ...
No imprimas los corchetes angulares (< y >). Para un zombi llamado Foo, el mensaje sería:
Foo: BraiiiiiiinnnzzzZ...
A continuación, implementa las dos funciones siguientes:
* **Zombie* newZombie( std::string name );**

Crea un zombi, ponle nombre y devuélvelo para que puedas usarlo fuera del ámbito de la función
ámbito.
* **void randomChump( std::string nombre );**

Crea un zombi, le asigna un nombre, y el zombi se anuncia a sí mismo.
Ahora, ¿cuál es el objetivo real del ejercicio? Tienes que determinar en qué caso es mejor asignar los zombies en la pila o en el heap.
Los zombies deben ser destruidos cuando ya no los necesites. El destructor debe imprimir un mensaje con el nombre del zombi para propósitos de depuración.

### Objetivo
El objetivo de este ejercicio es practicar el uso de clases, la creación de nuevos objetos y la asignación de memoria.
Conceptos a tener en cuenta:
* **operador new->** Asigna dinámicamente memoria en el heap, creando un nuevo objeto en
heap y devuelve un puntero a él.
* **heap->** Es una región de memoria del sistema que se utiliza para la asignación de memoria dinámica de memoria. A diferencia de la pila(donde se almacenan las variables locales) el heap no tiene un orden de asignación y liberación de memoria específicopor lo que hay que liberar la memoria despues de su uso con el operador delete y establecer el puntero a nullptr.


### ¿Porqué crear objetos en la pila o en el heap?
Depende de las necesidades quie tengamos, aqui tenemos unas consideraciones específicas:

1. **Tiempo de vida**-> Los objetos creados en la pila se destruyen automáticamente cuando salen de su ámbito. Si necesitamos que un objeto sobreviva más alla del ámbito de la función deberíamos crearlos en el heap.
2. **Tamaño**-> La pila tiene un tamaño limitado (menor que el del heap). Si necesitamos crear un objeto grande o muchos objetos sería conveniente crearlos en el heap.
3. **Rendimiento**-> La asignación y liberación de memoria en la pila es mas rápida en la pila que en el heap, porque la pila solo necesita mover un puntero mientras que el heap necesita buscar un bloque de memoria suficientemente grande.
4. **Gestión de memoria**-> Los objetos creados en el heap deben ser eliminados manualmente con delete para evitar fugas de memoria mientras que los objetos en la pila se eliminan automáticamente y no hay que preocuparse por las fugas de memoria.

## Ex01-> La horda!

### Subject
¡Es hora de crear una horda de zombies!
Implemente la siguiente función en el archivo apropiado:

**Zombi* zombieHorde( int N, std::stringname);**

Debe asignar **N** objetos **Zombie** en una única asignación. Luego, tiene que inicializar el zombies, dándole a cada uno de ellos el nombre pasado como parámetro. La función devuelve un puntero al primer zombi.
Implemente sus propias pruebas para garantizar que su función zombieHorde() funcione como se esperaba. Intenta llamar **announce()** para cada uno de los zombies.
No olvides eliminar todos los zombies y comprobar si hay pérdidas de memoria.

### Objetivo 

Reservar memoria en el heap a través del operador new y liberarla despues de su uso.

### Desarrollo

En este ejercicio hemos visto como creamos un array de objetos usando new a traves de un iterador(**bucle for**), de la misma manera ejecutamos el método albergado en el objeto (**announce()**) y liberar la memoria de un array tras su uso(**delete [] Zombie** -libera el array completo).

## Ex02-> HI THIS IS BRAIN

### Subject
Escribe un programa que contenga:
• Una variable de cadena inicializada como "HI THIS IS BRAIN".
• stringPTR: Un puntero a la cadena.
• stringREF: una referencia a la cadena.
Su programa tiene que imprimir:
• La dirección de memoria de la variable de cadena.
• La dirección de memoria mantenida por stringPTR.
• La dirección de memoria mantenida por stringREF.
Y luego:
• El valor de la variable de cadena.
• El valor al que apunta stringPTR.
• El valor al que apunta stringREF.
Eso es todo, sin trucos. 
### Objetivo
El objetivo de este ejercicio es desmitificar las referencias que pueden
Parece completamente nuevo. Aunque hay algunas pequeñas diferencias, esta es otra sintaxis.
para algo que ya haces: manipulación de direcciones.

### Desarrollo
```C
	std::string str = "HI THIS IS BRAIN"; //cadena
	std::string *stringPTR = &str; //puntero a cadena
	std::string &stringREF = str; //referencia

	std::cout << "Address of the string: " << &str << std::endl;//Address of the string: 0x7ffd49ffb630
	std::cout << "Address of the stringPTR: " << stringPTR << std::endl;//Address of the stringPTR: 0x7ffd49ffb630
	std::cout << "Address of the stringREF: " << &stringREF << std::endl;//Address of the stringREF: 0x7ffd49ffb630
	std::cout << "Value of the string: " << str << std::endl;//Value of the string: HI THIS IS BRAIN
	std::cout << "Value of the stringPTR: " << *stringPTR << std::endl;//Value of the stringPTR: HI THIS IS BRAIN
	std::cout << "Value of the stringREF: " << stringREF << std::endl;//Value of the stringREF: HI THIS IS BRAIN
```
* **std::string str = "HI THIS IS BRAIN";:** Esta línea declara una variable str de tipo std::string y la inicializa con la cadena de texto "HI THIS IS BRAIN".

* **std::string *stringPTR = &str;:** Esta línea declara una variable stringPTR que es un puntero a std::string. Se inicializa con la dirección de la variable str (obtenida con el operador &). Por lo tanto, stringPTR apunta a str.

* **std::string &stringREF = str;:** Esta línea declara una variable stringREF que es una referencia a std::string. Se inicializa con str, por lo que stringREF es otra forma de acceder a str. Cualquier cambio que hagas a stringREF también cambiará str, y viceversa.

## Ex03

### Subject
Implemente una clase de Arma que tenga:

* Un tipo de atributo privado, que es una cadena.
* Una función miembro getType() que devuelve una referencia constante al tipo.
* Una función miembro setType() que establece el tipo usando el nuevo pasado como parámetro.

Ahora, crea dos clases: HumanA y HumanB. Ambos tienen un arma y un nombre. También tienen una función miembro attack() que muestra (por supuesto, sin el paréntesis angulares):

**\<nombre\> ataca con su \<tipo de arma\>**

HumanA y HumanB son casi iguales excepto por estos dos pequeños detalles:
• Mientras HumanA toma el Arma en su constructor, HumanB no.
• Es posible que HumanB no siempre tenga un arma, mientras que HumanA siempre estará armado.

8Asignación de memoria, punteros a los miembros,
referencias, declaración de cambio
Si su implementación es correcta, ejecutar el siguiente código imprimirá un ataque con "un garrote tosco con púas" y luego un segundo ataque con "algún otro tipo de garrote" para ambos.
Casos de prueba:
```C
int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other tipe of club");
		jim.attack();
	}
	return 0;
}
```

¿En que caso piensas que sería mejor usar un puntero a Weapon?¿Por qué?
Piensa sobre eso antes de empezar el ejercicio.


