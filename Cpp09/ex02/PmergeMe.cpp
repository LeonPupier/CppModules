/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/11/02 15:41:42 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
static T	calcul(T arrayA, T arrayB)
{
	T	array;

	while (arrayA.size() && arrayB.size())
	{
		if (arrayA[0] > arrayB[0])
		{
			array.push_back(arrayB[0]);
			arrayB.erase(arrayB.begin());
		}
		else
		{
			array.push_back(arrayA[0]);
			arrayA.erase(arrayA.begin());
		}
	}

	while (arrayA.size())
	{
		array.push_back(arrayA[0]);
		arrayA.erase(arrayA.begin());
	}

	while (arrayB.size())
	{
		array.push_back(arrayB[0]);
		arrayB.erase(arrayB.begin());
	}

	return (array);
}

template <typename T>
static T insertion(T array)
{
	int		key;
	size_t	j;

	for (size_t i = 1; i < array.size(); i++)
	{
		key = array[i];
		j = i;
		
		while (j > 0 && array[j - 1] > key)
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = key;
	}
	return (array);
}

template <typename T>
static T	descent(T array)
{
	T		arrayA;
	T		arrayB;
	size_t	i;

	if (array.size() == 1)
		return (array);

	for (i = 0; i < array.size() / 2; i++)
		arrayA.push_back(array[i]);
	for (i = array.size() / 2; i < array.size(); i++)
		arrayB.push_back(array[i]);

	arrayA = insertion(arrayA);
	arrayB = insertion(arrayB);

	return (calcul(arrayA, arrayB));
}

bool	PmergeMe(char **argv)
{
	std::vector<int>			array_vector;
	std::deque<int>				array_deque;
	std::vector<int>			sorted_vector;
	long						number;
	std::vector<int>::iterator	it;
	clock_t						start, end;
	double						time_vector, time_deque;

	for (size_t i = 1; argv[i]; i++)
	{
		for (size_t j = 0; argv[i][j]; j++)
		{
			if (!std::isdigit(argv[i][j]))
			{
				if (argv[i][j] == '-')
					std::cout << RED << "[Error] " << RESET << "Non positive integer." << std::endl;
				else
					std::cout << RED << "[Error] " << RESET << "Non digit." << std::endl;
				return (false);
			}
		}
		number = std::strtol(argv[i], NULL, 10);
		if (number > INT_MAX || number < 0)
		{
			std::cout << RED << "[Error] " << RESET << "Overflow." << std::endl;
			return (false);
		}
		array_vector.push_back(number);
		array_deque.push_back(number);
	}

	size_t	i = 0;
	std::cout << "Before:	";
	for (it = array_vector.begin(); it != array_vector.end(); it++)
	{
		if (i >= 4 && array_vector.size() > 5)
			break ;
		std::cout << *it << " ";
		i++;
	}
	if (it != array_vector.end())
		std::cout << "[...]";
	std::cout << std::endl;

	// Vector method
	start = clock();
	sorted_vector = descent(array_vector);
	end = clock();
	time_vector = ((double)end - (double)start)/CLOCKS_PER_SEC * 1000000;

	// Deque method
	start = clock();
	descent(array_deque);
	end = clock();
	time_deque = ((double)end - (double)start)/CLOCKS_PER_SEC * 1000000;

	i = 0;
	std::cout << "After:	";
	for (it = sorted_vector.begin(); it != sorted_vector.end(); it++)
	{
		if (i >= 4 && sorted_vector.size() > 5)
			break ;
		std::cout << *it << " ";
		i++;
	}
	if (it != sorted_vector.end())
		std::cout << "[...]";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << array_vector.size()
	<< " elements with std::vector : " << time_vector << "μs" <<std::endl;

	std::cout << "Time to process a range of " << array_vector.size()
	<< " elements with std::deque  : " << time_deque << "μs" <<std::endl;

	return (true);
}
