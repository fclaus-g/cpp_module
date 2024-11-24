#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_exchangeRate;
		std::string						_filename;
	public:
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	run();
		void	parseDatabase();
		void	parseInput();
		bool	checkDate(std::string date) const;
};

#endif
