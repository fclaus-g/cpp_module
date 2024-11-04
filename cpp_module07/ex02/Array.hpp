#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#define GRE "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

template <typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		~Array();

		Array &operator=(Array const &src);
		T &operator[](unsigned int index) const;
		
		unsigned int size() const;
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& array);

#include "Array.tpp"

#endif
