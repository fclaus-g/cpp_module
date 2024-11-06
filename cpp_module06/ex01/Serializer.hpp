#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# define GRE "\033[1;32m"
# define RED "\033[1;31m"
# define RES "\033[0m"

#include "Data.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <stdint.h>
 
class Serializer
{
	private:
		Serializer();
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
