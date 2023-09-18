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
	(void)obj;
	return (*this);
}

// Body
void	ScalarConverter::byDefault(std::string value)
{
	if (value == "-inf" || value == "-inff")
	{
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    " << std::numeric_limits<int>::min() << std::endl;
		std::cout << "float:  " << std::numeric_limits<float>::min() << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::min() << std::endl;
	}
	else if (value == "+inf" || value == "+inff")
	{
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    " << std::numeric_limits<int>::max() << std::endl;
		std::cout << "float:  " << std::numeric_limits<float>::max() << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::max() << std::endl;
	}
	else if (value == "nan" || value == "nanf")
	{
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
		std::cout << "float:  nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
		std::cout << "[ERROR] The input is impossible to convert." << std::endl;
}

int	ScalarConverter::isChar(int type, std::string value)
{
	if (value.length() == 1 && (value[0] < '0' || value[0] > '9'))
	{
		return (CHAR);
	}
	return (type);
}

int	ScalarConverter::isInt(int type, std::string value)
{
	size_t	i;

	for (i = 0; i < value.length(); i++)
	{
		if (value[i] == '-' && i == 0)
			continue;
		if (value[i] < '0' || value[i] > '9')
			return (type);
	}
	return (INT);
}

int	ScalarConverter::isFloat(int type, std::string value)
{
	size_t	i;

	for (i = 0; i <value.length(); i++)
	{
		if (value[i] == '-' && i == 0)
			continue;
		if (value[i] == '.')
			break;
		if (value[i] < '0' || value[i] > '9')
			return (type);
	}
	if (value[i] != '.')
		return (type);
	for (++i; i < value.length(); i++)
	{
		if (value[i] == 'f')
			break;
		if (value[i] < '0' || value[i] > '9')
			return (type);
	}
	if (value[i] != 'f')
		return (type);
	if (++i != value.length())
		return (type);
	return (FLOAT);
}

int	ScalarConverter::isDouble(int type, std::string value)
{
	size_t	i;

	for (i = 0; i < value.length(); i++)
	{
		if (value[i] == '-' && i == 0)
			continue;
		if (value[i] == '.')
			break;
		if (value[i] < '0' || value[i] > '9')
			return (type);
	}
	if (value[i] != '.')
		return (type);
	for (++i; i < value.length(); i++)
	{
		if (value[i] < '0' || value[i] > '9')
			return (type);
	}
	return (DOUBLE);
}

void	ScalarConverter::convert(std::string value)
{
	char		value_c;
	int			value_i;
	float		value_f;
	double		value_d;
	int			type = INVALID;

	std::string			overflow;
	std::ostringstream	convert;
	
	type = isChar(type, value);
	if (type != CHAR)
	{
		type = isInt(type, value);
		if (type != INT)
		{	
			type = isFloat(type, value);
			if (type != FLOAT)
				type = isDouble(type, value);
		}
	}

	switch (type)
	{
		case INVALID:
			byDefault(value);
			return ;

		case CHAR:
			value_c	= value[0];
			value_d	= static_cast<double>(value_c);
			value_i	= static_cast<int>(value_c);
			value_f	= static_cast<float>(value_c);
			break;

		case INT:
			value_i	= atoi(value.c_str());
			convert << value_i;
			value_c	= static_cast<char>(value_i);
			value_d	= static_cast<double>(value_i);
			value_f	= static_cast<float>(value_i);
			break;

		case FLOAT:
			value_f	= atof(value.c_str());
			convert << std::fixed << std::setprecision(1) << value_f;
			value_i	= static_cast<int>(value_f);
			value_c	= static_cast<char>(value_f);
			value_d	= static_cast<double>(value_f);
			break;

		case DOUBLE:
			value_d	= std::strtod(value.c_str(), NULL);
			convert << std::fixed << std::setprecision(1) << value_d;
			value_c	= static_cast<char>(value_d);
			value_i	= static_cast<int>(value_d);
			value_f	= static_cast<float>(value_d);
			break;

		default:
			break;
	}

	if (type != CHAR)
	{
		overflow = convert.str();
		if (overflow != value)
		{
			std::cout << "[ERROR] The input is impossible to convert (Overflow)." << std::endl;
			return ;
		}
	}

	if ((int)value_c >= 32 && (int)value_c <= 126)
		std::cout << "char:   '" << value_c << "'" << std::endl;
	else
		std::cout << "char:   Not displayable" << std::endl;
	
	std::cout << "int:    " << value_i << std::endl;
	std::cout << "float:  " << std::fixed << std::setprecision(1) << value_f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << value_d << std::endl;
}
