/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:46:15 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/26 14:39:06 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << RED << "[Error]" << RESET << " Please provide your operation: '<number> <number> <expression>...' (ex: 4 2 +)." << std::endl;
		return (1);
	}
	processRPN(argv[1]);
	return (0);
}
