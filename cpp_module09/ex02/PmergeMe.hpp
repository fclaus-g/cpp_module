#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>

class PmergeMe
{
	private:
		std::string _input;
		std::vector<int> _vector;
		std::deque<int> _deque;
		std::list<int> _list;

		template <typename T>
		void insertionSort(T &container);

	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void validateArgs(char **matriz);
		void run();

		template <typename T>
		void print(T &container);
		
		template <typename T>
		void mergeInsertionSort(T &container, int start, int end);

		template <typename T>
		void merge(T &container, int start, int middle, int end);
};

#endif
