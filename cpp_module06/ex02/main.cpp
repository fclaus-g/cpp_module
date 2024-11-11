/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:45:29 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/11 09:45:33 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Implementa una clase Base que tenga solo un destructor virtual público. Crea tres clases vacías A, B y C, que hereden públicamente de Base.
Estas cuatro clases no tienen que estar diseñadas en la forma canónica ortodoxa.
Implementa las siguientes funciones:
```cpp
Base * generate(void);
```
Instancia aleatoriamente A, B o C y devuelve la instancia como un puntero Base. Siéntete libre
de usar lo que quieras para la implementación de elección aleatoria.
```cpp
void identify(Base* p);
```
Imprime el tipo real del objeto al que apunta p: "A", "B" o "C".
```cpp
void identify(Base& p);
```
Imprime el tipo real del objeto al que apunta p: "A", "B" o "C".

Está prohibido usar un puntero dentro de esta función.

Está prohibido incluir el encabezado typeinfo.

Escribe un programa para probar que todo funciona como se espera.*/

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
