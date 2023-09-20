/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/20 11:28:13 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <list>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

template <typename T>
void	easyfind(T lst, int number)
{
	std::list<int>::const_iterator	it;
	std::list<int>::const_iterator	ite = lst.end();
	int								index = 1;

	for (it = lst.begin(); it != ite; ++it)
	{
		if (*it == number)
		{
			std::cout << "The number is the " << index << " in the list." << std::endl;
			return ;
		}
		index++;
	}
	throw (std::exception());
}

#endif