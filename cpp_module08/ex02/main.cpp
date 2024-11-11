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