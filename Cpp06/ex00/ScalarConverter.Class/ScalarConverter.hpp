/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/18 08:47:24 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include <sstream>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

enum {
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter {

private:

	// Body
	static void		byDefault(std::string value);
	static int		isChar(int type, std::string value);
	static int		isInt(int type, std::string value);
	static int		isFloat(int type, std::string value);
	static int		isDouble(int type, std::string value);

public:

	// Init
	ScalarConverter();
	ScalarConverter(std::string type, int grade);
	ScalarConverter(const ScalarConverter &obj);
	~ScalarConverter(void);
	ScalarConverter &operator=(const ScalarConverter &obj);

	// Body
	static void		convert(std::string value);
};

#endif