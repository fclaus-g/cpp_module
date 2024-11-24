#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <exception>

class RPN
{
	private:
		std::string			_input;
		std::stack<float>	_stack;
		int					_result;
	public:
		RPN(std::string input);
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);
		~RPN();
		void	calculate();
};

#endif
