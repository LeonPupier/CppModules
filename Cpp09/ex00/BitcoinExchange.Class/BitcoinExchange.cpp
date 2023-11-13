/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/11/13 14:44:23 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Init
BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file;
	std::string		line;
	std::string		key;
	float			value;

	std::cout << GREEN << "[LOG] " << RESET << "BitcoinExchange class has been created" << std::endl;

	file.open("data.csv", std::ifstream::in);
	if (!file.is_open())
	{
		std::cout << RED << "[ERROR] " << RESET << "Failed to open the database (data.csv)." << std::endl;
		return ;
	}
	while (!file.eof())
	{
		std::getline(file, line);
		key = line.substr(0, line.find(","));
		value = std::strtof(line.substr(line.find(",") + 1).c_str(), NULL);
		this->_database[key] = value;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << RED << "[LOG] " << RESET << "BitcoinExchange class has been destroyed" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	this->_database = obj.getDatabase();
	return (*this);
}

// Getter
std::map<std::string, float>	BitcoinExchange::getDatabase() const
{
	return (this->_database);
}

// Setter
void	BitcoinExchange::setDatabase(std::map<std::string, float> database)
{
	this->_database = database;
}

// Body
bool	BitcoinExchange::isNumber(std::string str)
{
	size_t	i;

	for (i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);	
	}
	return (true);
}

bool	BitcoinExchange::dateIsValid(std::string date)
{
	int	year	= 0;
	int	month	= 0;
	int	day		= 0;
	
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	if (this->isNumber(date.substr(0, 4).c_str()))
		year = std::atoi(date.substr(0, 4).c_str());
	if (this->isNumber(date.substr(5, 2).c_str()))
		month = std::atoi(date.substr(5, 2).c_str());
	if (this->isNumber(date.substr(8, 2).c_str()))
		day = std::atoi(date.substr(8, 2).c_str());

	if (!year || !month || !day)
		return (false);

	if (month > 12)
		return (false);

	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) \
	&& day > 31)
		return (false);
	else if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);

	if (month == 2)
	{
		if (year % 4 == 0 && day > 29)
			return (false);
		else if (year % 4 != 0 && day > 28)
			return (false);
	}
		
	return (true);
}

float	BitcoinExchange::valueConverter(std::string key, std::string value)
{
	size_t	i = 0;
	bool	is_point = false;
	float	number;

	while (value[i] && i < value.length())
	{
		if (i == 0 && value[0] == '-')
			i++;
		if (value[i] == '.')
		{
			if (is_point)
			{
				std::cout << RED << "Error: " << RESET << "bad input => " << key << std::endl;
				return (ERR_VALUE);
			}
			is_point = true;
		}
		else if (value[i] < '0' || value[i] > '9')
		{
			std::cout << RED << "Error: " << RESET << "bad input => " << key << std::endl;
			return (ERR_VALUE);
		}
		i++;
	}
	
	number = std::strtof(value.c_str(), NULL);
	if (number < 0)
	{
		std::cout << RED << "Error: " << RESET << "not a positive number." << std::endl;
		return (ERR_VALUE);
	}
	else if (number > 1000)
	{
		std::cout << RED << "Error: " << RESET << "too large a number." << std::endl;
		return (ERR_VALUE);
	}
	
	return (number);
}

float	BitcoinExchange::findValueInDB(std::string date)
{
	float	number;

	if (this->_database.find(date) != this->_database.end())
		number = this->_database[date];
	else
	{
		std::map<std::string, float>::iterator it = this->_database.lower_bound(date);
		if (it == this->_database.begin())
			return (0);
		it--;
		number = it->second;
	}

	return (number);
}

bool	BitcoinExchange::readFile(std::string path)
{
	std::ifstream	file;
	std::string		line;
	std::string		key;
	std::string		value;
	size_t			pos_delimiter;
	float			value_converted;

	file.open(path.c_str(), std::ifstream::in);
	if (!file.is_open())
	{
		std::cout << RED << "[ERROR] " << RESET << "Failed to open the file (" << path << ")." << std::endl;
		return (false);
	}
	
	while (!file.eof())
	{
		std::getline(file, line);
		line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
		
		if (line.empty())
			continue ;
		if (line == "date|value")
			continue ;

		pos_delimiter = line.find("|");
		if (pos_delimiter != std::string::npos)
		{
			key = line.substr(0, line.find("|"));
			value = line.substr(line.find("|") + 1);
		}
		else
		{
			key = line;
			value = "BadInput";
		}
		
		key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
		value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
		
		if (this->dateIsValid(key))
		{
			value_converted = this->valueConverter(key, value);
			if (value_converted != ERR_VALUE)
				std::cout << key << " => " << value_converted << " = " << (this->findValueInDB(key) * value_converted) << std::endl;
		}
		else
			std::cout << RED << "Error: " << RESET << "not a valid date." << std::endl;
	}
	file.close();
	return (true);
}
