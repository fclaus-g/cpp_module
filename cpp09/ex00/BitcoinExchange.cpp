#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename)
{
	this->_filename = filename;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	if (this != &other)
		*this = other;
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_exchangeRate = other._exchangeRate;
		this->_filename = other._filename;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::parseDatabase()
{
	std::ifstream	database("data.csv");
	std::string		line;
	std::string		date;
	float			value;

	if (!database.is_open())
	{
		std::cerr << "Error: could not open database." << std::endl;
		return ;
	}
	std::getline(database, line);
	while (std::getline(database, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, ','))
		{
			iss >> value;
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
		}
		if (checkDate(date) == false)
		{
			continue ;
		}
		if (value < 0)
		{
			std::cerr << "Error: values must be positive." << std::endl;
			continue ;
		}
		this->_exchangeRate[date] = value;
	}
}

bool BitcoinExchange::checkDate(std::string date) const
{
	std::string	year = date.substr(0, 4);
	std::string	month = date.substr(5, 2);
	std::string	day = date.substr(8, 2);
	
	if ((year.find_first_not_of("0123456789") != std::string::npos \
		|| month.find_first_not_of("0123456789") != std::string::npos \
		|| day.find_first_not_of("0123456789") != std::string::npos) && date.size() != 10)
	{
		return false;
	}	
	int	yearInt = std::atoi(year.c_str());
	int	monthInt = std::atoi(month.c_str());
	int	dayInt = std::atoi(day.c_str());
	if (yearInt < 2009 || (yearInt == 2009 && monthInt < 1) || (yearInt == 2009 && monthInt == 1 && dayInt < 3))
	{
		return false;
	}
	if ((monthInt < 1 || monthInt > 12) || (dayInt < 1 || dayInt > 31))
		return false;
	if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
		return false;
	if (monthInt == 2)
	{
		bool isLeapYear = (yearInt % 4 == 0 && yearInt % 100 != 0) || (yearInt % 400 == 0);
		if (dayInt > (isLeapYear ? 29 : 28))
			return false;
	}
	std::time_t	t = std::time(0);
	std::tm	*now = std::localtime(&t);
	if (yearInt > now->tm_year + 1900 || (yearInt == now->tm_year + 1900 && monthInt > now->tm_mon + 1) || (yearInt == now->tm_year + 1900 && monthInt == now->tm_mon + 1 && dayInt > now->tm_mday))
	{
		std::cerr << "Error: no data available for this date => " << date << std::endl;
		return false;
	}
	return(true);
}


void BitcoinExchange::parseInput()
{
	std::ifstream	input(this->_filename.c_str());
	std::string		line;
	std::string		date;
	float			value;

	if (!input.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return ;
	}
	if (input.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error: empty input file." << std::endl;
		return ;
	}
	std::getline(input, line);
	while (std::getline(input, line))
	{
		std::istringstream iss(line);
		if (line.empty())
			continue ;
		if (std::getline(iss, date, '|'))
		{
			iss >> value;
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
		}
		if (checkDate(date) == false)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}
		if (value < 0 || value > 1000)
		{
			if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else
				std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		std::map<std::string, float>::iterator it = this->_exchangeRate.lower_bound(date);
		if (it == this->_exchangeRate.end() || it->first != date)
		{
			if (it == this->_exchangeRate.begin())
			{
				std::cerr << "Error: no data available for this date => " << date << std::endl;
				continue ;
			}
			it--;
		}
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
}

void BitcoinExchange::run()
{
	parseDatabase();
	parseInput();

}
