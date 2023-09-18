/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/18 08:48:25 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Init
ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "[LOG] " << RESET << "ScalarConverter class has been created" << std::endl;
	this->_type = INVALID;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << RED << "[LOG] " << RESET << "ScalarConverter class has been destroyed" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	this->_value	= obj._value;
	this->_type		= obj._type;
	this->_value_c	= obj._value_c;
	this->_value_i	= obj._value_i;
	this->_value_f	= obj._value_f;
	this->_value_d	= obj._value_d;
	return (*this);
}

// Body
void	ScalarConverter::_byDefault() const
{
	if (this->_value == "-inf" || this->_value == "-inff")
	{
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    " << std::numeric_limits<int>::min() << std::endl;
		std::cout << "float:  " << std::numeric_limits<float>::min() << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::min() << std::endl;
	}
	else if (this->_value == "+inf" || this->_value == "+inff")
	{
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    " << std::numeric_limits<int>::max() << std::endl;
		std::cout << "float:  " << std::numeric_limits<float>::max() << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::max() << std::endl;
	}
	else if (this->_value == "nan" || this->_value == "nanf")
	{
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
		std::cout << "float:  nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
		std::cout << "[ERROR] The input is impossible to convert." << std::endl;
}

bool	ScalarConverter::_isChar()
{
	if (this->_value.length() == 1 && (this->_value[0] < '0' || this->_value[0] > '9'))
	{
		this->_type = CHAR;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::_isInt()
{
	size_t	i;

	for (i = 0; i < this->_value.length(); i++)
	{
		if (this->_value[i] == '-' && i == 0)
			continue;
		if (this->_value[i] < '0' || this->_value[i] > '9')
			return (false);
	}
	this->_type = INT;
	return (true);
}

bool	ScalarConverter::_isFloat()
{
	size_t	i;

	for (i = 0; i < this->_value.length(); i++)
	{
		if (this->_value[i] == '-' && i == 0)
			continue;
		if (this->_value[i] == '.')
			break;
		if (this->_value[i] < '0' || this->_value[i] > '9')
			return (false);
	}
	if (this->_value[i] != '.')
		return (false);
	for (++i; i < this->_value.length(); i++)
	{
		if (this->_value[i] == 'f')
			break;
		if (this->_value[i] < '0' || this->_value[i] > '9')
			return (false);
	}
	if (this->_value[i] != 'f')
		return (false);
	if (++i != this->_value.length())
		return (false);
	this->_type = FLOAT;
	return (true);
}

bool	ScalarConverter::_isDouble()
{
	size_t	i;

	for (i = 0; i < this->_value.length(); i++)
	{
		if (this->_value[i] == '-' && i == 0)
			continue;
		if (this->_value[i] == '.')
			break;
		if (this->_value[i] < '0' || this->_value[i] > '9')
			return (false);
	}
	if (this->_value[i] != '.')
		return (false);
	for (++i; i < this->_value.length(); i++)
	{
		if (this->_value[i] < '0' || this->_value[i] > '9')
			return (false);
	}
	this->_type = DOUBLE;
	return (true);
}

void	ScalarConverter::convert(std::string value)
{
	std::string			overflow;
	std::ostringstream	convert;
	
	this->_value = value;
	if (!this->_isChar())
		if(!this->_isInt())
			if(!this->_isFloat())
				this->_isDouble();

	switch (this->_type)
	{
		case INVALID:
			this->_byDefault();
			return ;

		case CHAR:
			this->_value_c	= this->_value[0];
			this->_value_d	= static_cast<double>(this->_value_c);
			this->_value_i	= static_cast<int>(this->_value_c);
			this->_value_f	= static_cast<float>(this->_value_c);
			break;

		case INT:
			this->_value_i	= atoi(this->_value.c_str());
			convert << this->_value_i;
			this->_value_c	= static_cast<char>(this->_value_i);
			this->_value_d	= static_cast<double>(this->_value_i);
			this->_value_f	= static_cast<float>(this->_value_i);
			break;

		case FLOAT:
			this->_value_f	= atof(this->_value.c_str());
			convert << std::fixed << std::setprecision(1) << this->_value_f;
			this->_value_i	= static_cast<int>(this->_value_f);
			this->_value_c	= static_cast<char>(this->_value_f);
			this->_value_d	= static_cast<double>(this->_value_f);
			break;

		case DOUBLE:
			this->_value_d	= std::strtod(value.c_str(), NULL);
			convert << std::fixed << std::setprecision(1) << this->_value_d;
			this->_value_c	= static_cast<char>(this->_value_d);
			this->_value_i	= static_cast<int>(this->_value_d);
			this->_value_f	= static_cast<float>(this->_value_d);
			break;

		default:
			break;
	}

	overflow = convert.str();
	if (overflow != this->_value)
	{
		std::cout << "[ERROR] The input is impossible to convert (Overflow)." << std::endl;
		return ;
	}

	if ((int)this->_value_c >= 32 && (int)this->_value_c <= 126)
		std::cout << "char:   '" << this->_value_c << "'" << std::endl;
	else
		std::cout << "char:   Not displayable" << std::endl;
	
	std::cout << "int:    " << this->_value_i << std::endl;
	std::cout << "float:  " << std::fixed << std::setprecision(1) << this->_value_f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << this->_value_d << std::endl;
}
