#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) 
{
	std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n]();
	this->_size = n;
	std::cout << "Array param constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(Array const &src)
{
	_array = new T[src._size]();
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = src._array[i];
	}
	std::cout << "Array copied" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
	std::cout << "Array deleted" << std::endl;
}

template <typename T>
Array<T>&	Array<T>::operator=(Array const &src)
{
	if (this != &src) {
		delete[] _array;
		_array = new T[src._size]();
		_size = src._size;
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = src._array[i];
		}
	}
	std::cout << "Array assigned" << std::endl;
	return *this;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size) {
		throw std::out_of_range("Index out of range\n");
	}
	return _array[index];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& array)
{
	for (unsigned int i = 0; i < array.size(); i++) {
		out << array[i] << " ";
	}
	//out << std::endl;
	return out;
}

#endif
