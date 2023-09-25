/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:35:23 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/21 13:33:44 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.Class/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	// Check the argument(s)
	if (argc != 2)
	{
		std::cout << RED << "Error: " << RESET << "could not open file." << std::endl;
		return (1);
	}

	// Init the Bitcoin Exchange
	BitcoinExchange	btc = BitcoinExchange();
	
	// Open and read the input file
	if (!btc.readFile(argv[1]))
		return (1);
	
	return (0);
}