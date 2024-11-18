#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

class PmergeMe
{
	private:
		std::string _input;
		std::vector<int> _vector;
		std::list<int> _list;

	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void print();
};

#endif
