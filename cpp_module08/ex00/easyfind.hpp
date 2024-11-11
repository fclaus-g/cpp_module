#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <map>

#define GRE "\033[32m"
#define RED "\033[31m"
#define RES "\033[0m"

class NotFoundException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Value not found";
	}
};

template <typename T, typename V>
int easyfind(T& container, V value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return *it;
}
template <typename Key, typename V>
int easyfind(std::map<Key, V>& container, Key value)
{
	typename std::map<Key, V>::iterator it = container.find(value);
	if (it == container.end())
		throw NotFoundException();
	return it->second;
}

#endif
