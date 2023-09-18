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

	// Variables
	std::string	_value;
	int			_type;
	char		_value_c;
	int			_value_i;
	float		_value_f;
	double		_value_d;

	// Body
	void		_byDefault() const;
	bool		_isChar();
	bool		_isInt();
	bool		_isFloat();
	bool		_isDouble();

public:

	// Init
	ScalarConverter();
	ScalarConverter(std::string type, int grade);
	ScalarConverter(const ScalarConverter &obj);
	~ScalarConverter(void);
	ScalarConverter &operator=(const ScalarConverter &obj);

	// Body
	void	convert(std::string value);
};

#endif