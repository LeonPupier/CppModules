/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:49:30 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/20 09:42:16 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int	tab[] = {0, 1, 2, 3, 4};
	Awesome	tab2[5];

	std::cout << BLUE << "Test the template function:" << RESET << std::endl;
	::iter(tab, 5, print);

	std::cout << CYAN << "\nTest with the class table:" << RESET << std::endl;
	::iter(tab2, 5, print);
}
