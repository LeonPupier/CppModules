/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:18:45 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/09 08:32:19 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	char	letter;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int arg = 1; arg < argc; arg++)
		{
			for (int idx = 0; argv[arg][idx]; idx++)
			{
				letter = argv[arg][idx];
				if (letter >= 97 && letter <= 122)
					letter -= 32;
				std::cout << letter;
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
