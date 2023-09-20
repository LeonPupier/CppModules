/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:55:55 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/20 11:27:30 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::list<int>	lst;
	int 			ints[] = {10, 9, -5, 125, 42, 99, -578, 0, 2, 0, 57, 42, 23};

	lst.assign(ints, ints + 13);

	std::cout << BLUE << "Search 42 in the container:" << RESET << std::endl;
	try
	{
		easyfind(lst, 42);
	}
	catch (std::exception)
	{
		std::cout << "Not in the list." << std::endl;
	}
	return (0);
}