/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:57:02 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/22 17:54:47 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "[QUIT] The program must take only one argument among: ";
		std::cout << "{DEBUG, INFO, WARNING, ERROR}." << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}
