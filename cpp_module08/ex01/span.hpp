#ifndef SPAN_HPP
#define SPAN_HPP

#define MAX_SIZE 50

#define GRN "\033[32m"
#define RED "\033[31m"
#define YEL "\033[33m"
#define RST "\033[0m" 

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _container;
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span &copy);
		Span &operator=(const Span &copy);

		unsigned int		getSize() const;
		std::vector<int>	getContainer() const;

		void				addNumber(int n);
		int					shortestSpan();
		int					longestSpan();
		void				addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NotEnoughSpace : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Span &span);

#endif
