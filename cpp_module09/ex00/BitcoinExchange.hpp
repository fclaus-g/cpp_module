#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include <iostream>//para cerr
#include <fstream>//para ifstream
#include <string>//para string
#include <cctype>//para isdigit
#include <map>//
#include <sstream>//para istringstream
#include <iomanip>//para setprecision
#include <cstdlib>//para atoi

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

		void run();//aqui corremos el programa
		void parseDatabase();//aqui parseamos la base de datos
		void parseInput();//aqui parseamos el archivo
		bool checkDate(std::string date) const;//aqui comprobamos si la fecha es valido
};

#endif
