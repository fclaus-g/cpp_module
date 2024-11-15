/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:42:19 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/12 17:27:34 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n) : _size(n) {}

Span::~Span() {}

Span::Span(const Span &copy)
{
	if (this != &copy)
		*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy) {
		this->_size = copy._size;
		this->_container = copy._container;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_container.size() >= this->_size)
		throw NotEnoughSpace();
	this->_container.push_back(n);
}

unsigned int Span::getSize() const
{
	return this->_size;
}

std::vector<int> Span::getContainer() const
{
	return this->_container;
}



int Span::shortestSpan()
{
	if (this->_container.size() <= 1)
		throw NotEnoughElementsException();
	std::sort(this->_container.begin(), this->_container.end());
	int min = this->_container[1] - this->_container[0];
	for (std::vector<int>::iterator i = this->_container.begin() + 1; i != this->_container.end(); i++) {
		if (*i - *(i - 1) < min)
			min = *i - *(i - 1);
	}
	return min;
}

int Span::longestSpan()
{
	if (this->_container.size() <= 1)
		throw NotEnoughElementsException();
	std::sort(this->_container.begin(), this->_container.end());
	int max = this->_container[this->_container.size() - 1] - this->_container[0];
	return max;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_container.size() + std::distance(begin, end) > this->_size)
		throw std::exception();
	this->_container.insert(this->_container.end(), begin, end);
}

const char *Span::NotEnoughElementsException::what() const throw()
{
	return "Span: Not Enough Elements Exception ";
}

const char *Span::NotEnoughSpace::what() const throw()
{
	return "Span: Not Enough Space Exception ";
}

std::ostream &operator<<(std::ostream &out, const Span &span)
{
	std::vector<int> container = span.getContainer();
	for (std::vector<int>::iterator i = container.begin(); i != container.end(); i++)
		out << *i << " ";
	return out;
}
