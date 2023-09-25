/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/25 18:16:19 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <algorithm>
# include <limits>
# include <cmath>
# include <map>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

class BitcoinExchange {

private:

	std::map<std::string, double>	_database;

	bool	isNumber(std::string str);
	bool	dateIsValid(std::string date);
	float	valueConverter(std::string value);

public:

	// Init
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &obj);
	~BitcoinExchange(void);
	BitcoinExchange &operator=(const BitcoinExchange &obj);

	// Body
	bool	readFile(std::string path);
};

#endif