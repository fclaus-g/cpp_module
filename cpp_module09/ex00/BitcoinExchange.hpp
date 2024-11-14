#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>//para cerr
#include <fstream>//para ifstream
#include <string>//para string
#include <map>//
#include <vector>
#include <sstream>//para istringstream
#include <iomanip>//para setprecision

class BitcoinExchange
{
	private:
		std::map<std::string, float> _exchangeRate;//aqui guardaremos el valor de la fecha y el valor de la moneda
		std::string _filename;//aqui guardaremos el nombre del archivo que se nos pasa por parametro
	public:
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void parseFile();//aqui parseamos el archivo
		void run();//aqui corremos el programa
};

#endif
