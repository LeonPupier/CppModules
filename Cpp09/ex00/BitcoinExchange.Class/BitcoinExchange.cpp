/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/25 18:20:32 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Init
BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file;
	std::string		line;
	std::string		key;
	double			value;

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
		value = std::strtod(line.substr(line.find(",") + 1).c_str(), NULL);
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
	(void)obj;
	return (*this);
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
		
	return (true);
}

float	BitcoinExchange::valueConverter(std::string value)
{
	size_t	i;
	float	number;
	bool	is_point = false;

	for (i = 0; i < value.length(); i++)
	{
		if (value[i] == '.')
		{
			if (is_point)
				return (0);
			is_point = true;
		}
		else if (value[i] < '0' || value[i] > '9')
			return (0);
	}
	
	number = std::strtof(value.c_str(), NULL);
	if (number < 1 || number > 1000)
		return (0);
	return (number);
}

bool	BitcoinExchange::readFile(std::string path)
{
	std::ifstream	file;
	std::string		line;
	std::string		key;
	std::string		value;
	size_t			pos_delimiter;

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
			std::cout << "[" << key << "] ";
			if (this->valueConverter(value))
				std::cout << "(" << value << ")";
			else
				std::cout << "(" << value << ") Invalid";
			std::cout << std::endl;
		}
	}
	file.close();
	return (true);
}
