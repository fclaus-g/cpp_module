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

## Ex03 -> Armamos a los humanos!

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

Asignación de memoria, punteros a los miembros,
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

### Objetivo

El objetivo de este ejercicio es familiarizarnos con el uso de la memoria, el uso de punteros a los miembros de la clase, distinguir entre punteros y referencias (HumanA utiliza una referencia a weapon(&refWeapon) y HumanB utiliza un puntero a *pointWeapon).
Seguimos trabajando para diferenciar punteros y referencias, usar métodos en las clases y trabajar con los atributos.
Trabajar con setters y getters.

### Explicación

HumanA debe ser creado con un arma (Weapon) por lo que creamos una referencia que se inicialice en en el momento del constructor, HumanB por otro lado comienza sin arma asi que le declaramos un atributo puntero inicializado a null para darle valor mas adelante en el programa en caso que sea necesario.
Por otro lado weapon no es mas que una clase que alberga una string con el tipo, y su getter y setter.

```cpp

class Weapon
{
	private:
	std::string type;
	public:
	Weapon(std::string initType);
	~Weapon();
	const std::string &getType(void) const;
	void setType(std::string newType);
};

class HumanA
{
	private:
		std::string		name;
		Weapon 			&refWeapon;
	public:
		HumanA(std::string newName, Weapon &Weapon);
		~HumanA();
		void attack();
		const std::string getName(void) const;
		void setName(std::string newName);
};
class HumanB
{
	private:
	std::string name;
	Weapon *pointWeapon;
	public:
	HumanB(std::string initName);
	~HumanB();
	void attack();
	const std::string getName(void) const;
	void setName(std::string newName);
	void setWeapon(Weapon &newWeapon);
};
```
El main es el que se encargará de declarar weapon y asignarla a los humanos.
*En resumen, si quieres una asociación que nunca cambie, usa una referencia. Si necesitas una asociación que pueda cambiar o que pueda no existir en algunos puntos, usa un puntero.*

## Ex04 -> Cambio y cambiucheo de cadenas en archivos

### Subject
Cree un programa que tome tres parámetros en el siguiente orden: un nombre de archivo y
dos strings, s1 y s2.
Abrirá el archivo **<nombre de archivo>** y copiará su contenido en un archivo nuevo.
**<nombre de archivo>.replace**, reemplazando cada aparición de s1 con s2.
El uso de funciones de manipulación de archivos C está prohibido y se considerará trampa. Todo
las funciones miembro de la clase std::string están permitidas, excepto replace. Usalos, usalos a ellos
sabiamente!
Por supuesto, maneje entradas y errores inesperados. Tienes que crear y entregar tu
propias pruebas para garantizar que su programa funcione como se espera.

### Objetivos

Familiarizarnos con el uso de funciones miembro de la clase std::string (menos .replace) y conocer estas funciones.
Usar la biblioteca <fstream> (filestream) que alberga funciones de entrada y salida de archivos.

### Desarrollo

Este ejercicio es muy cortito, solo vamos a necesitar un main y su Makefile. El tema aqui está en tomar los argumentos recibidos por el main y hacer uso de ifstream(lectura) y ofstream(escritura) y de los médodos propios de la clase.
```cpp
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename = av[1];
		std::string target = av[2];
		std::string replace = av[3];
		if (target.empty() || replace.empty() || filename.empty())
		{
			std::cout << "Error: s1, s2 or filename is empty" << std::endl;
			return (1);
		}
		std::ifstream inFile(filename.c_str());//COMPROBAR CON LOS COMPAÑEROS SI ESTO ES NECESARIO
		if (!inFile.is_open())
		{
			std::cout << "Error: file not found" << std::endl;
			return (1);
		}
		std::string newFilename = filename + ".replace";
		std::ofstream outFile(newFilename .c_str());
		if (!outFile.is_open())
		{
			std::cout << "Error: file not created" << std::endl;
			return (1);
		}
		while (!inFile.eof())
			replaceStrings(inFile, outFile, target, replace);
		inFile.close();
		outFile.close();
	}
	else 
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
	}
	return (0);
}
```
Este sería nuestro main. Basicamente comprobamos que ningun argumento este vacío y procedemos a la declaración del objeto inFile que guardará la lectura del archivo y el objeto outFile al que le pasamos el nombre del archivo que vamos a crear para hacer el cambio de strings. Tras eso vamos a ir leyendo inFile hasta el final buscando la cadena objetivo y reemplaandola con la nueva cadena en el archivo outFile mediante la función **replaceStrings()**.

## Ex05 -> Harl el quejoso

### Subject
¿Conoces a Harl? Todos lo hacemos, ¿verdad? En caso de que no lo hagas, encuentra a continuación el tipo de
comentarios que hace Harl. Se clasifican por niveles:
• Nivel "DEBUG": los mensajes de depuración contienen información contextual. son en su mayoría
utilizado para el diagnóstico de problemas.
Ejemplo: "Me encanta tener tocino extra para mi 7XL-doble-queso-triple-pepinillo-especial-
hamburguesa con salsa de tomate. ¡Realmente lo hago!"
• Nivel "INFO": Estos mensajes contienen amplia información. Son útiles para
Seguimiento de la ejecución del programa en un entorno de producción.
Ejemplo: "No puedo creer que agregar tocino extra cueste más dinero. No pusiste
¡Suficiente tocino en mi hamburguesa! ¡Si lo hicieras, no pediría más!"
• Nivel "ADVERTENCIA": los mensajes de advertencia indican un problema potencial en el sistema.
Sin embargo, se puede manejar o ignorar.
Ejemplo: "Creo que merezco un poco de tocino extra gratis. He estado viniendo por
años mientras que tú empezaste a trabajar aquí desde el mes pasado."
• Nivel "ERROR": Estos mensajes indican que se ha producido un error irrecuperable.
Este suele ser un problema crítico que requiere intervención manual.
Ejemplo: "¡Esto es inaceptable! Quiero hablar con el gerente ahora".
11Asignación de memoria, indicaciones para los miembros,
referencias, declaración de cambio
C++ - Módulo 01
Vas a automatizar a Harl. No será difícil ya que siempre dice lo mismo.
cosas. Tienes que crear una clase Harl con las siguientes funciones de miembros privados:
• depuración nula (nulo);
• información nula (anular);
• advertencia de anulación (anula);
• error de anulación (anular);
Harl también tiene una función miembro pública que llama a las cuatro funciones miembro anteriores.
dependiendo del nivel pasado como parámetro:
vacío
complain (std::nivel de cadena);
El objetivo de este ejercicio es utilizar punteros a funciones miembro. Esto no es una
sugerencia. Harl tiene que quejarse sin usar un bosque de if/else if/else. no piensa
¡dos veces!
Cree y entregue pruebas para demostrar que Harl se queja mucho. Puedes usar los ejemplos.
de los comentarios enumerados anteriormente en el asunto o elija utilizar sus propios comentarios.

### Objetivos

La parte clave de este ejercicio está en el uso de punteros a metodos de la clase.

### Desarrollo

La realización de este ejercicio es relativamente sencilla hasta que llegamos a la definición de la función complain(std::stringLevel) que es donde haremos uso del objetivo del ejercicio, punteros a funciones y lo haremos de la siguiente manera:
```cpp
/* Aquí presentamos al objeto Harl con sus 4 métodos privados y su metodo complain(std::string level)*/
class Harl
{
	private:
		/*Cada uno de los métodos privados de Harl son impresiones por pantalla(std::cout) de los mensajes dados en el subject*/
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
	public:
		Harl(void);
		~Harl(void);
		void complain( std::string level );
};

/*Y así sería la definición de la función complain(std::string level)*/
void Harl::complain(std::string level)
{
	/*Array de punteros a los métodos(funciones) de la clase Harl. Cada puntero apunta a un método 
	void método(void)*/
	void (Harl::*f[4]) (void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};//Aquí es donde muere ella
	/*Array de strings con los niveles de queja que usaremos para comparar con el arg de entrada*/
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	while (i < 4)
	{
		if (lvl[i] == level)
		{
			/*si el nivel de queja coincide con el argumentoo pasado al método complain
			se llama al método correspondiente del array de funciones*/
			(this->*f[i])();
			return ;
		}
		i++;
	}
	if (i >= 4)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return ;
}
```

## Ex06 -> HarlFilter

### Subject
A veces no quieres prestar atención a todo lo que dice Harl. Implementar un
sistema para filtrar lo que dice Harl dependiendo de los niveles de registro que desee escuchar.
Cree un programa que tome como parámetro uno de los cuatro niveles. Se mostrará todo
mensajes de este nivel y superiores. Por ejemplo:
$> ./harlFilter "ADVERTENCIA"
[ ADVERTENCIA ]
Creo que merezco tener un poco de tocino extra gratis.
Llevo viniendo desde hace años mientras que tú empezaste a trabajar aquí desde el mes pasado.
[ ERROR ]
Esto es inaceptable, quiero hablar con el gerente ahora.
$> ./harlFilter "No estoy seguro de lo cansado que estoy hoy..."
[Probablemente quejándose de problemas insignificantes]
Aunque hay varias formas de lidiar con Harl, una de las más efectivas es
Apágalo.
Asigne el nombre harlFilter a su ejecutable.
Debe utilizar, y tal vez descubrir, la declaración de cambio en este ejercicio.

### Objetivo
En este ejercicio el reto es que Harl el quejoso muestre in crescendo desde una queja(N) en adelante pasando por todas hasta la última.
De manera que si Harl tiene como quejas {"DEBUG", "INFO", "WARNING", "ERROR"} y por argumentos nos pasan INFO debe mostrar los mensajes INFO, WARNING y ERROR

### Desarrollo

En este ejercicio partimos de la base del ejercicio anterior pero, para solucionar el problema que nos plantean de ejecutar en cascada las quejas a partir la que nos pasen por args para ello una de las opciones mas atractivas sería hacer una lectura de control **switch** y así practicar un poco el uso de estos condicionales, el codigo para ello se vería tal que asi:

```cpp

void	harlComplain(std::string level)
{
	/*Array f de punteros a los métodos privados de la clase Harl, entre corchetes le damos donde apuntará cada función, no devuelven ni reciben nada*/
	void (Harl::*f[4]) (void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	while (i < 4 && lvl[i] != level)
		i++;
	switch (i) 
	{
		case 0:
			(this->*f[i])();
		case 1:
			(this->*f[i])();
		case 2:
			(this->*f[i])();
		case 3:
			(this->*f[i])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" <<std::endl;
	}
}

/*Una vez practicado el condicional switch y probado su funcionamiento, puede ser muy util en algunos casos pero hemos optado por una solución a nuestro entender mas cortita y elegante, usando un bucle while que nos ocuparía muchas menos lineas de código y funciona de la misma manera*/ 

void	harlComplain(std::string level)
{
	void (Harl::*f[4]) (void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	while (i < 4 && lvl[i] != level)
		i++;
	if (i >= 4)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
	{
		while (i < 4)
		{
			(this->*f[i])();
			i++;
		}
	}
}
```
