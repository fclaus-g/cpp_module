#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

#include <iostream>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iomanip>

class PmergeMe
{
	private:
		std::string			_input;
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		std::list<int>		_list;

		//vector and deque functions
		template <typename T>
		void		createPairs(T &container, T &large, T&small);
		template <typename T>
		void		insertSmallInLarge(T &large, T &small);
		
		//list functions
		void		createPairsList(std::list<int> &container, std::list<int> &large, std::list<int> &small);
		void		insertSmallInLargeList(std::list<int> &large, std::list<int> &small);

	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	validateArgs(char **matriz);
		void	run();

		template <typename T>
		void	print(T &container);
		
		template <typename T>
		void	mergeInsertionSort(T &container);

		void	mergeInsertionSortList(std::list<int> &container);
};

#endif
