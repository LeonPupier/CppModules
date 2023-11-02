/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:13:57 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/27 10:23:15 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << RED << "[Error] " << RESET << "Please a list of numbers like: 0 -5 7 -9 2" << std::endl;
		return (1);
	}

	PmergeMe(argv);
	return (0);
}