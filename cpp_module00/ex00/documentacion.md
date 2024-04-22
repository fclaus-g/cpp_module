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

