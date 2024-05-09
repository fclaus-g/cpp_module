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

En este caso hemos trabajado sobre el ejercicio anterior añadiendo acceso específico a nuestra clase principal (ClapTrap) dejando los atributos en **protected** en lugar de en **private** para que nuestra clase hijo(ClapTrap) pueda trabajar y modificarlos en su propia clase además de añadir alguna función mas a nuestra clase **ClavTrap**.

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

