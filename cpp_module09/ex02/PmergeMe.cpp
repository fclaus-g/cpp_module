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
	std::string str;
	std::stringstream ss;
	int num;

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
		_deque.insert(_deque.end(), num);
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
	std::clock_t start = std::clock(); 
	double duration;
	std::cout << "[VECTOR]" << std::endl;
	std::cout << "Before: " << std::endl;
	print(_vector);
	mergeInsertionSort(_vector, 0, _vector.size());
	std::cout << "After: " << std::endl;
	print(_vector);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vector.size() << " elements with insertionSort : " << duration << " us" << std::endl;
	start = std::clock();
	std::cout << "[DEQUE]" << std::endl;
	std::cout << "Before: " << std::endl;
	mergeInsertionSort(_deque, 0, _deque.size());
	print(_deque);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deque.size() << " elements with insertionSort : " << duration << " us" << std::endl;
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
void PmergeMe::mergeInsertionSort(T &container, int start, int end)
{

	if (start < end)
	{
		if (end - start < 10)
		{
			insertionSort(container);
			return;
		}
		else
		{
 			int middle = start + (end - start) / 2;
			mergeInsertionSort(container, start, middle);
			mergeInsertionSort(container, middle + 1, end);
			merge(container, start, middle, end);
		}
	}
}

/**
 * @brief Crea dos contenedores auxiliares donde se almacenarán los valores de las dos
 * mitades que forman el container, luego se comparan los valores de los contenedores
 * auxiliares y se van ordenando en el container original
 *  
 * @tparam T 
 * @param container 
 * @param start 
 * @param middle 
 * @param end 
 */
template <typename T>
void PmergeMe::merge(T &container, int start, int middle, int end)
{
	int auxSize = middle - start + 1;
	int auxSize2 = end - middle;
	T aux1;
	T aux2;

	for (int i = 0; i < auxSize; i++)
		aux1.push_back(container[start + i]);
	for (int i = 0; i < auxSize2; i++)
		aux2.push_back(container[middle + 1 + i]);
	int i = 0, j = 0, k = start;
	while (i < auxSize && j < auxSize2)
	{
		if (aux1[i] <= aux2[j])
		{
			container[k] = aux1[i];
			i++;
		}
		else
		{
			container[k] = aux2[j];
			j++;
		}
		k++;
	}
	while (i < auxSize)
	{
		container[k] = aux1[i];
		i++;
		k++;
	}
}

/**
 * @brief toma un contenedor y lo ordena con el algoritmo de inserción comprobando
 * a pares si el valor de la derecha es menor que el de la izquierda, si es así
 * hace un swap de los valores
 * 
 * @tparam T 
 * @param container 
 */
template <typename T>
void PmergeMe::insertionSort(T &container)
{
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	typename T::iterator it2;
	int tmp;

	while (it != ite)
	{
		it2 = it;
		while (it2 != container.begin() && *it2 < *(it2 - 1))
		{
			tmp = *it2;
			*it2 = *(it2 - 1);
			*(it2 - 1) = tmp;
			it2--;
		}
		it++;
	}
}
