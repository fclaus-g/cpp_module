#include "RPN.hpp"

RPN::RPN(std::string input)
{
	this->_input = input;
	this->_result = 0;
}

RPN::RPN(const RPN &rpn)
{
	this->_input = rpn._input;
	this->_result = rpn._result;
}

RPN &RPN::operator=(const RPN &rpn)
{
	if (this!= &rpn)
	{
		this->_input = rpn._input;
		this->_result = rpn._result;
	}
	return *this;
}

RPN::~RPN()
{
}

void RPN::calculate()
{
	std::istringstream iss(this->_input);
	std::string token;

	while (std::getline(iss, token, ' '))//lee la cadena de entrada y la divide en tokens separados por espacios
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")//si encuentra un operador
		{
			if (this->_stack.size() < 2)//si no hay suficientes operandos
			{
				std::cerr << "Error: not enough operands" << std::endl;
				return ;
			}
			float a = this->_stack.top();//tomamos el valor del elemento en la parte superior de la pila
			this->_stack.pop();//y lo eliminamos de la pila
			float b = this->_stack.top();//tomamos el siguiente elemento que es ahora el nuevo elemento en la parte superior de la pila
			this->_stack.pop();//y lo eliminamos de la pila
			//Ahora haremos las operaciones correspondientes y agregaremos el resultado a la pila
			if (token == "+")
				this->_stack.push(b + a);
			else if (token == "-")
				this->_stack.push(b - a);
			else if (token == "*")
				this->_stack.push(b * a);
			else if (token == "/")
			{
				if (a == 0)//protegemos la division por cero
				{
					std::cerr << "Error: division by zero" << std::endl;
					return ;
				}	this->_stack.push(b / a);
			}
		}
		else//si no es un operador, entonces es un operando realmente es lo primero que nos encontraremos
		{
			try
			{
				float value;
				std::stringstream ss(token);//creamos un flujo de cadena con el token esto nos permitira convertir el token a un valor flotante
				ss >> value;//convertimos el token a un valor flotante
				if (ss.fail() || !ss.eof())//si falla la conversion o no se llega al final del flujo
					throw std::invalid_argument("Invalid token");
				this->_stack.push(value);//agregamos el valor a la pila que entrará en la parte superior
			}
			catch(const std::invalid_argument& e)
			{
				std::cerr << "Error: invalid token" << std::endl;
				return ;
			}
			catch(const std::out_of_range& e)
			{
				std::cerr << "Error: token out of range '" << token << "'" << std::endl;
				return ;
			}
		}
		if (iss.eof())//si llegamos al final de la cadena de entrada
		{
			this->_result = this->_stack.top();//el resultado es el valor en la parte superior de la pila
			std::cout << this->_result << std::endl;
		}	
			
	}
}

