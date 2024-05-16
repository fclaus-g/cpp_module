# Cpp_module 3

## Ex00->ClapTrap

### Subject

Primero, ¡debes implementar una clase! ¡Cuan original!
Se llamará ClapTrap y tendrá los siguientes atributos privados inicializados
a los valores especificados entre paréntesis:
* Nombre, que se pasa como parámetro a un constructor.
* Puntos de vida (10), representan la salud del ClapTrap.
* Puntos de energía (10)
* Daño de ataque (0)
Agregue las siguientes funciones de miembros públicos para que ClapTrap parezca más realista:
* ataque nulo (const std::string& target);
* anular takeDamage (cantidad int sin firmar);
* anular beRepaired (monto int sin firmar);
Cuando ClapTrack ataca, hace que su objetivo pierda <daño de ataque> puntos de vida.
Cuando ClapTrap se repara solo, recupera <cantidad> puntos de vida. Atacar y reparar
cuestan 1 punto de energía cada uno. Por supuesto, ClapTrap no puede hacer nada si no tiene puntos de vida.
o puntos de energía restantes.

### Objetivo

Practicar clases, miembros y métodos.

### Desarrollo
Dejo aqui el .hpp para ver como quedaría.
```cpp
class ClapTrap{
	private:
	std::string		_name;
	unsigned int	_life_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);
	~ClapTrap();

	std::string		getName(void);
	unsigned int	getLifePoints(void);
	unsigned int	getEnergyPoints(void);
	unsigned int	getAttackDamage(void);
	void			setLifePoints(unsigned int life_points);
	void			setEnergyPoints(unsigned int energy_points);
	void			setAttackDamage(unsigned int attack_damage);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	printClapTrap(void);
};
```

## Ex01->ScavTrap

### Subject

Como nunca puedes tener suficientes ClapTraps, ahora crearás un robot 
derivado. Se llamará ScavTrap y heredará los constructores y destructores de 
ClapTrap. Sin embargo, sus constructores, destructor y attack() imprimirán 
mensajes diferentes. Después de todo, los ClapTraps son conscientes de su 
individualidad.
Tenga en cuenta que en sus pruebas se debe mostrar el encadenamiento adecuado
de construcción/destrucción. Cuando se crea un ScavTrap, el programa comienza 
construyendo un ClapTrap. La destrucción ocurre en orden inverso. ¿Por qué?
ScavTrap utilizará los atributos de ClapTrap (actualizará ClapTrap en 
consecuencia) y deberá inicializarlos para:
• Name, que se pasa como parámetro a un constructor.
• Hit points (100), representan la salud del ClapTrap.
• Energy points (50)
• Attack damage (20)
ScavTrap también tendrá su propia capacidad especial:
    void guardGate();
Esta función miembro mostrará un mensaje informando que ScavTrap ahora está en
modo Gate Keeper.
No olvide agregar más pruebas a su programa.

### Objetivo 

Practicar sobre la herencia y el acceso específico en nuestro programa.

### Desarrollo 

En este caso hemos trabajado sobre el ejercicio anterior creando una clase nueva (**scavTrap**) que heredará los atributos y métodos de la clase base **clapTrap**.
Para ello debemos tener en cuenta que debemos cambiar los atributos privado a protegidos para que la clase hijo pueda acceder ellos. La clase hijo podra acceder a los miembros públicos y protegidos. Aunque un atributo protegido puede ser modificado por una clase derivada, no puede ser accedido desde el código que esta fuera de la clase y sus clases derivadas a no ser, que en el código de la clase en cuestión cuente con su correspondiente setter.

```cpp
#include <iostream>
#include <string>
#include <iomanip>

class ClapTrap{
	protected:
	std::string 	_name;
	unsigned int	_life_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);
	~ClapTrap();

	std::string		getName(void);
	unsigned int	getLifePoints(void);
	unsigned int	getEnergyPoints(void);
	unsigned int	getAttackDamage(void);
	void 			setLifePoints(unsigned int life_points);
	void 			setEnergyPoints(unsigned int energy_points);
	void 			setAttackDamage(unsigned int attack_damage);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void 	printClapTrap(void);
};

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &copy);
		~ScavTrap();

		void guardGate();
};
```

## Ex02->FragTrap

### Subject

Probablemente hacer ClapTraps esté empezando a ponerte de los nervios.
Ahora, implemente una clase FragTrap que hereda de ClapTrap. Es muy similar a ScavTrap. Sin embargo, sus mensajes de construcción y destrucción deben ser diferentes. En sus pruebas se debe mostrar un encadenamiento adecuado de construcción/destrucción. Cuando se crea un FragTrap, el programa comienza construyendo un ClapTrap. La destrucción ocurre en orden inverso.
Lo mismo para los atributos, pero esta vez con valores diferentes:
* Nombre, que se pasa como parámetro a un constructor • Puntos de vida (100), representan la salud del ClapTrap • Puntos de energía (100)
* Daño de ataque (30)
FragTrap también tiene una capacidad especial:
	void highFivesGuys(void);
Esta función miembro muestra una solicitud positiva de choca esos cinco en la salida estándar. Nuevamente, agregue más pruebas a su programa.

### Objetivo

Trabajar con herencias, métodos, con el acceso específico a los atributos, forma canónica ortodoxa, constructor con parámetros, etc. Obserrvar el orden de construcción-destrucción de las clases hijo-padre.

### Desarrollo

Seguimos trabajando con los ClapTrap y en este caso debemos crear una segunda clase heredada **ScavTrap** que heredará los atributos de la clase base **clapTrap** pero con valores diferentes. Incluirá tambien un sencillo método que imprimirá un simpático mensaje. El .hpp de clapTrap se queda como en el ejercicio anterior y el de la clase **ScavTrap** quedaría de la siguiente manera:
```cpp
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		FragTrap	&operator=(const FragTrap &copy);
		~FragTrap();
		
		void	highFivesGuys(void);
};
```

## Ex03->DiamondTrap

### Subject 

En este ejercicio, crearás un monstruo: un ClapTrap que es mitad FragTrap, mitad ScavTrap. Se llamará DiamondTrap y heredará tanto de FragTrap como de ScavTrap. ¡Esto es tan arriesgado!
La clase DiamondTrap tendrá un atributo privado de nombre. Asigne a este atributo exactamente el mismo nombre de variable (sin hablar aquí del nombre del robot) que el de la clase base de ClapTrap.
Para ser más claro, aquí hay dos ejemplos.
Si la variable de ClapTrap es nombre, asigne el nombre a la de DiamondTrap.
Si la variable de ClapTrap es _name, dale el nombre _name a la de DiamondTrap.
Sus atributos y funciones miembro se seleccionarán de cualquiera de sus clases principales:
* Nombre, que se pasa como parámetro a un constructor.
* ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
* Hit points (FragTrap)
* Energy points (ScavTrap)
* Attack damage (FragTrap)
* attack() (Scavtrap)

C++ - Módulo 03 Herencia
Además de las funciones especiales de ambas clases principales, DiamondTrap tendrá su propia capacidad especial:
	void whoAmI();
Esta función miembro mostrará tanto su nombre como su nombre de ClapTrap.
Por supuesto, el subobjeto ClapTrap de DiamondTrap se creará una vez, y sólo una vez. Sí, hay un truco.
Nuevamente, agregue más pruebas a su programa.

### Objetivo

Conocer el problema del diamante, trabajar con herencia múltiple.

### Desarrollo

En nuestro programa tendremos que añadir una nueva clase(**DiamondTrap**) que será una mezcla de dos clases hijas(**ScavTrap** y **FragTrap**) de la clase **ClapTrap** y aqui nos vamos a encontrar con una serie de problemas:

1. Métodos con la misma firma en distintas clases.
	* Solución: declaramos las funciones de la clase base como virtual.
2. Atributos heredados de las clases hijo que se solapan.
	* Añadimos una variable constante en nuestra subclase ScarTrap.
3. Problemas  al mostrar el nombre en nuestra funcion de imprimir el objeto

