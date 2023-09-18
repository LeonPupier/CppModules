/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:30:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/18 14:31:46 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.Class/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "[ERROR] The program needs an argument." << std::endl;
		return (1);
	}
	
	ScalarConverter	converter = ScalarConverter();
	converter.convert(argv[1]);

	return (0);
}
