/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:12:18 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/15 13:49:21 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Ahora, es hora de pasar a cosas más serias. Desarrollemos algo extraño.
El contenedor std::stack es muy bueno. Desafortunadamente, es uno de los únicos contenedores STL que NO es iterable. Eso es una pena.
Pero, ¿por qué aceptaríamos esto? Especialmente si podemos tomarnos la libertad de destrozar la pila
original para crear características faltantes.
Para reparar esta injusticia, tienes que hacer que el contenedor std::stack sea iterable.
Escribe una clase MutantStack. Se implementará en términos de un std::stack.
Ofrecerá todas sus funciones miembro, más una característica adicional: iteradores.
Por supuesto, escribirás y entregarás tus propias pruebas para asegurarte de que todo funciona como se espera.
```cpp
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
```
Si lo ejecutas por primera vez con MutantStack y una segunda vez reemplazas MutantStack con, por ejemplo, un std::list,
las dos salidas deberían ser las mismas. Por supuesto, cuando pruebes otro contenedor, actualiza el código a continuación 
con las funciones miembro correspondientes (push() puede convertirse en push_back()).*/

#include "MutantStack.hpp"
#include <algorithm>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();//Elimina el último elemento
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;//Incrementa el iterador para que apunte al siguiente elemento
	--it;//Decrementa el iterador para que apunte al elemento anterior
	std::cout << "Iterating through the stack:" << std::endl;
	while (it != ite)//Mientras el iterador no llegue al final
	{
		std::cout << *it << std::endl;//Imprime el valor del elemento al que apunta el iterador
		++it;//Incrementa el iterador
	}
	std::stack<int> s(mstack);//Copia el stack a un std::stack de la STL (Standard Template Library)
	std::cout << "Stack copied to std::stack:" << std::endl;
	while (!s.empty())//mientras no esté vacío
	{
		std::cout << s.top() << std::endl;//imprime el último elemento
		s.pop();//Elimina el último elemento
	}
	
	 // Uso de std::find
    it = std::find(mstack.begin(), mstack.end(), 5);//Busca el elemento 5 en el stack
    if (it != mstack.end())
    {
        std::cout << "Element 5 found in the stack." << std::endl;
    }
    else
    {
        std::cout << "Element 5 not found in the stack." << std::endl;
    }

	return 0;
}
