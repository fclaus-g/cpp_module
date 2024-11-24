#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
	validateArgs(av);
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	if (this != &other)
		*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_input = other._input;
		_vector = other._vector;
		_list = other._list;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

/**
 * @brief parsea la matriz de args chequeando cada string de la matriz si ea un numero
 * a continuación con ayuda de stringstream convierte el string a un entero y lo va guardando
 * en los contenedores vector y deque.
 * @param matriz 
 */
void PmergeMe::validateArgs(char **matriz)
{
	_vector.clear();
	_deque.clear();
	_list.clear();

	std::string str;
	std::stringstream ss;
	int num;

	if (!matriz[2])
		throw std::invalid_argument("Not enough arguments");

	for (int i = 1; matriz[i]; i++)
	{
		str = matriz[i];
		if (str.find_first_not_of("0123456789") == false)
			throw std::invalid_argument("Invalid argument");
		ss << str;
		ss >> num;
		if (ss.fail() || num < 0 )
			throw std::invalid_argument("Invalid argument");
		_vector.push_back(num);
		_deque.push_back(num);
		_list.push_back(num);
		ss.clear();
	}
}

/**
 * @brief Arranca el programa e inicia el contador de tiempo imprimiendo el antes y despues 
 * de ordenar los contenedores, al final de cada ordenamiento imprime el tiempo que tarda
 * en ordenar cada contenedor 
 */
void PmergeMe::run()
{
	std::cout << GREEN << "[VECTOR]" << RESET << std::endl;
	std::cout << "Before: " << std::endl;
	print(_vector);
	std::clock_t startVector = std::clock(); 
	mergeInsertionSort(_vector);
	std::clock_t endVector = std::clock();
	std::cout << "After: " << std::endl;
	print(_vector);
	
	std::cout << GREEN << "[DEQUE]" << RESET << std::endl;
	//std::cout << "Before: " << std::endl;
	std::clock_t startDeque = std::clock();
	mergeInsertionSort(_deque);
	std::clock_t endDeque = std::clock();
	print(_deque);

	//std::cout << GREEN << "[LIST]" << RESET << std::endl;
	std::cout << "Before: " << std::endl;
	print(_list);
	std::clock_t startList = std::clock();
	mergeInsertionSortList(_list);
	std::clock_t endList = std::clock();
	std::cout << "After: " << std::endl;
	print(_list);


	std::cout << std::fixed << std::setprecision(6) << YELLOW << "Time to process a range of " << _vector.size();
	std::cout << " elements with insertionSort : " << (static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC) << " us" << RESET << std::endl;
	std::cout << std::fixed << std::setprecision(6) << YELLOW << "Time to process a range of " << _deque.size();
	std::cout << " elements with insertionSort : " << (static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC) << " us" <<  RESET << std::endl;
	std::cout << std::fixed << std::setprecision(6) << YELLOW << "Time to process a range of " << _list.size();
	std::cout << " elements with insertionSort : " << (static_cast<double>(endList - startList) / CLOCKS_PER_SEC) << " us" << RESET << std::endl;
}

/**
 * @brief Imprime el contenido de un contenedor con iteradores
 * 
 * @tparam T 
 * @param container el contenedor a imprimir 
 */
template <typename T>
void PmergeMe::print(T &container)
{
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();

	while (it != ite)
	{
		std::cout << *it;
		it++;
		if (it != ite)
			std::cout << " ";
	}
	std::cout << std::endl;
}


/**
 * @brief Algoritmo de ordenamiento merge con inserción, en primer lugar se comprueba si el tamaño
 * del contenedor es menor a 10, si es así se ordena con el algoritmo de inserción, si no se divide
 * el contenedor en dos mitades y se llama recursivamente a la función mergeInsertionSort para
 * las dos mitades y luego se llama a la función merge para ordenar el contenedor completo
 * 
 * @tparam T 
 * @param container 
 * @param start 
 * @param end 
 */
template <typename T>
void PmergeMe::mergeInsertionSort(T &container)
{
	if (container.size() < 2)
		return;

	T large; //para los mayores de los pares
	T small; //para los menores de los pares

	//1º crear y ordenar pares
	createPairs(container, large, small);

	//2º ordenar los pares mayores
	std::sort(large.begin(), large.end());

	//3º Insertar la lista de los pares menores en la lista de los pares mayores
	insertSmallInLarge(large, small);

	//4º copiar la lista ordenada en la lista original
	container = large;
}

/**
 * @brief función que crea pares de elementos de un contenedor y los guarda en dos contenedores separando
 * los mayores de los menores si el tamaño del contenedor es impar el último elemento se guarda en el contenedor
 * de los mayores
 * 
 * @tparam T 
 * @param container contenedor a ordenar
 * @param large contenedor en el que guardaremos los mayores de los pares
 * @param small contenedor en el que guardaremos los menores de los pares
 */
template <typename T>
void PmergeMe::createPairs(T &container, T &large, T&small)
{
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
		{
			large.push_back(container[i]);
			small.push_back(container[i + 1]);
		}
		else
		{
			large.push_back(container[i + 1]);
			small.push_back(container[i]);
		}
	}
	if (container.size() % 2 != 0)
	{
		large.push_back(container.back());
	}
}

/**
 * @brief Inserta los elementos de un contenedor pequeño en un contenedor grande buscando la posición del elemento 
 * en el contenedor grande con la función lower_bound y luego inserta el elemento en esa posición
 * 
 * @tparam T 
 * @param large contenedor grande
 * @param small contenedor pequeño
 */
template <typename T>
void PmergeMe::insertSmallInLarge(T &large, T &small)
{
	typename T::iterator it = small.begin();
	typename T::iterator ite = small.end();

	for (;it != ite; it++)
	{
		typename T::iterator pos = std::lower_bound(large.begin(), large.end(), *it);
		large.insert(pos, *it);
	}
}

void PmergeMe::mergeInsertionSortList(std::list<int> &container)
{
	if (container.size() < 2)
		return;

	std::list<int> large;
	std::list<int> small;

	createPairsList(container, large, small);
	large.sort();
	insertSmallInLargeList(large, small);
	container = large;
}	

void PmergeMe::createPairsList(std::list<int> &container, std::list<int> &large, std::list<int> &small)
{
	std::list<int>::iterator it = container.begin();
	std::list<int>::iterator ite = container.end();

	while (it != ite)
	{
		std::list<int>::iterator next = it;
		++next;
		if (next != ite)
		{
			if (*it > *next)
			{
				large.push_back(*it);
				small.push_back(*next);
			}
			else
			{
				large.push_back(*next);
				small.push_back(*it);
			}
			it = ++next;
		}
		else
		{
			large.push_back(*it);
			++it;
		}
	}
}

void PmergeMe::insertSmallInLargeList(std::list<int> &large, std::list<int> &small)
{
	std::list<int>::iterator it = small.begin();

	while (it != small.end())
	{
		std::list<int>::iterator pos = large.begin();
		for (; pos != large.end(); ++pos)
		{
			if (*it < *pos)
				break;
		}
		large.insert(pos, *it);
		++it;
	}
}
