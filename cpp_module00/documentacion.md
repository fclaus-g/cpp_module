# CPP module 00

## Ex00 Megaphone

### Subject

Sólo para asegurarse de que todos estén despiertos, escriba un programa que se comporte de la siguiente manera:

```bash
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF. $>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

### Desarrollo

En este ejercicio nos vamos a familiarizar un poco con c++ y  vamos a trabajar con el método toupper. La intencion es que conozcamos los distintos métodos y empecemoas a usarlos.

```cpp
		while (i < ac)
		{
			j = 0;
			while(av[i][j])
			{
				std::cout << (char)std::toupper(av[i][j]);//usamos el método toupper
				j++;
			}
			i++;
		}
```
Ejemplos de métodos:
**std::cout:** Se utiliza para la salida estándar, es decir, para imprimir texto en la consola.
**std::vector:** Es un contenedor de matriz dinámica. Puedes agregar elementos, eliminar elementos y acceder a elementos de un std::vector.
**std::sort:** Se utiliza para ordenar un contenedor como un std::vector.
**std::string:** Es una clase para trabajar con cadenas de texto.

## Ex01 Phonebook

### Subject

¡Bienvenidos a los años 80 y su increíble tecnología! Escribe un programa que se comporte como un increíble software de agenda telefónica.
Tienes que implementar dos clases:
* Directorio telefónico
* Tiene una variedad de contactos.
* Puede almacenar un máximo de 8 contactos. Si el usuario intenta agregar un noveno contacto, reemplace el más antiguo por el nuevo.
* Tenga en cuenta que la asignación dinámica está prohibida. 
* Contacto
	* Representa un contacto de la agenda telefónica.
	En su código, se debe crear una instancia de la guía telefónica como una instancia de la clase PhoneBook. Lo mismo para los contactos. Cada uno de ellos debe ser instanciado como una instancia de la clase Contacto. Eres libre de diseñar las clases como quieras, pero ten en cuenta que todo lo que siempre se usará dentro de una clase es privado y todo lo que se puede usar fuera de una clase es público.
       
Al iniciar el programa, la agenda está vacía y se le solicita al usuario que ingrese uno de tres comandos. El programa sólo acepta ADD, SEARCH y EXIT.
* ADD: guarda un nuevo contacto
	* Si el usuario ingresa este comando, se le solicita que ingrese la información del nuevo contacto un campo a la vez. Una vez completados todos los campos, agregue el contacto a la agenda.
	* Los campos de contacto son: nombre, apellido, apodo, número de teléfono y secreto más oscuro. Un contacto guardado no puede tener campos vacíos.
* SEARCH: muestra un contacto específico
	* Muestra los contactos guardados como una lista de 4 columnas: índice, nombre, apellido
	nombre y apodo.
	* Cada columna debe tener 10 caracteres de ancho. Un carácter de barra vertical ('|') los separa. El texto debe estar alineado a la derecha. Si el texto es más largo que la columna, se debe truncar y el último carácter visible se debe reemplazar por un punto ('.').
	* Luego, solicite nuevamente al usuario que muestre el índice de la entrada. Si el índice está fuera de rango o es incorrecto, defina un comportamiento relevante. De lo contrario, muestre la información de contacto, un campo por línea.
* EXIT
	* ¡El programa se cierra y los contactos se pierden para siempre!
	* Cualquier otra entrada se descarta.
Una vez que un comando se ha ejecutado correctamente, el programa espera otro. Él
se detiene cuando el usuario ingresa EXIT.
Dale un nombre relevante a tu ejecutable.

### Objetivo

Espacios de nombres, clases, funciones miembro, flujos stdio, C++ - Listas de inicialización del Módulo 00, estático, constante y algunas otras cosas básicas

### Desarrollo

Para la ejecución de este ejercicio debemos:
1. Crear una clase *Phonebook* que albergará el array de contactos[8] enel que iremos guardando los datos de cada contacto. Desde la instancia phonebook usaremos las funciones previamente definidas en nuestro phonebook.cpp que se encargarán de ejecutar los comandos que el usuario nos introduce por el prompt.
	* ADD -> Crea un contacto en el array, para ello usaremos una función definida en la clase contacto que rellenará los campos o atributos de este contacto.
	* SEARCH -> Nos mostrará con formato el array de contactos con 4 atributos, tras elegir el indice del contacto mostraremos todos los atributos de este.
	* EXIT -> Nos sacará del programa.
```cpp
//phonebook.hpp
#include "contact.hpp"

class	Phonebook
{
private:
	Contact contact[8];
	int 	index_c;
public:
	Phonebook();
	~Phonebook();
	void	add_contact(Phonebook *phonebook);
	void	searchContact();
	void	printPhonebook();
	void	set_index_c(int index);
	int		get_index_c();
};

//phonebook.cpp

void	Phonebook::add_contact(Phonebook *phonebook)
{
	/*si la agenda está llena podremos sobreescibir el primer contacto*/
	if (index_c > 7)
	{
		std::cout<<"The phonebook is full"<<std::endl;
		std::cout<<"Do you want to overwrite a contact? (yes/no)"<<std::endl;
		std::string answer;
		std::getline(std::cin, answer);
		if (answer == "y" || answer == "yes")
			index_c = 0;
		else
			return;
	}
	if (index_c < 8)
	{
		std::cout<<"Adding contact "<<index_c<<std::endl;
		phonebook->contact[index_c].addContact(index_c);
		std::cout<<"Contact "<<index_c<<" added"<<std::endl;
		index_c++;
	}	
}

void	Phonebook::searchContact()
{
	if (contact[0].getName().empty())
	{
		std::cout<<"The phonebook is empty"<<std::endl;
		return;
	}
	printPhonebook();
	std::cout<<"Searching contact"<<std::endl;
	std::cout<<"Enter the index of the contact"<<std::endl;
	int index = -1;
	std::cin>>index;
	std::cout<<"index: "<<index<<std::endl;
	if (std::cin.fail()) 
    {
        std::cin.clear(); // limpia el estado de error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta la entrada incorrecta
        std::cout<<"Invalid input"<<std::endl;
        return;
    }
	if (index < 0 || index > 7) 
	{
		std::cout<<"Invalid index"<<std::endl;
		std::cin.ignore();
		return;
	}
	std::cin.ignore();
	if (contact[index].getName().empty())//protegemos si la agenda está vacía 
	{
		std::cout<<"Phonebook is empty "<<std::endl;
		return;
	}
	contact[index].printContact();
}
```
2. Trabajaremos en la clase contacto declarando los atributos como privados y los métodos publicos correspondientes.
	* Rellenar los atributos con la entrada del usuario.
	* Imprimir el contacto cuando se solicite a través de search.

```cpp
//Contact.hpp
class	Contact
{
private:
	int			index;
	std::string	name;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
public:
	Contact();
	~Contact();
	std::string	getName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
	std::string	getInput();
	int			getIndex();
	void		setIndex(int new_index);
	void		addContact(int index);
	void		printContact();
	bool		isNumeric(std::string str);
};

//Contact.cpp
void Contact::addContact(int index)
{
	setIndex(index);
	std::cout << "Enter the name of the contact" << std::endl;
	name = getInput();
	if (std::cin.eof()) return; //cada una de estas lineas protege que al hacer C^d nos solicite el resto de datos
	std::cout << "Enter the last name of the contact" << std::endl;
	lastName = getInput();
	if (std::cin.eof()) return;
	std::cout << "Enter the nickname of the contact" << std::endl;
	nickName = getInput();
	if (std::cin.eof()) return;
	std::cout << "Enter the phone number of the contact" << std::endl;
	phoneNumber = getInput();
	if (std::cin.eof()) return;
	if (phoneNumber.length() != 9 || !isNumeric(phoneNumber))
	{
		std::cout << "The phone number must have 9 digits" << std::endl;
		std::cout << "Enter the phone number of the contact" << std::endl;
		phoneNumber = getInput();
	}
	std::cout << "Enter the darkest secret of the contact" << std::endl;
	darkestSecret = getInput();
	if (std::cin.eof()) return;
}
```
3. Nuestro main tendra un loop en el que recibiremos los comandos y llamará a las funciones correspondientes de nuestra agenda.

```cpp
int main()
{
	Phonebook phonebook;
	std::string command;

	ft_welcome();
	while (std::getline(std::cin, command))
	{
		if (command == "ADD")
			phonebook.add_contact(&phonebook);
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout<<"Invalid command"<<std::endl;
		std::cin.clear();
		ft_welcome();
	}
	return 0;
}
```

Hay una serie de detalles que tenemos que tener en cuenta:

* **std::cin**-> Entrada estandar de flujo, lee hasta el primer espacio en blanco. Si el usuario presiona C^d enviara un carácter EOF que std::cin interpretará como el final de entrada. Despues de esto todas las lecturas postriores fallarán hasta que se limpie su estado por ello es buena práctica limpiar el estado de flujo con **std::cin.clear()**. Especialmente si estamos leyendo en un bucle, ya que un error en una lectura puede hacer que el resto de lecturas fallen.
* **std::cin.ignore()**-> Si estamos leyendo un valor y luego queremos leer una línea es importante usarlo ya que la siguiente lectura de linea podría leer el resto de la línea actual en lugar e la siguiente línea completa.
* **std::getline(std::cin, myString)** -> Leerá una línea completa de texto hasta que el usuario presione enter(encuentre '\n' o se alcance el final del flujo) y lo almacenará en la cadena pasada como argumento. Leerá '\n' pero no lo almacenará.
* **std::streamsize**-> Se utiliza para representar el num de carácteres en un flujo de entrada/salida.
* **std::numeric_limits\<std::streamsize\>::max()**-> El valor más grande que puede representar un std::streamsize. Se suele utilizar con std::cin.ignore() para ignorar todos los carácteres hasta el final de la linea o del flujo.
