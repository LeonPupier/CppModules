/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/20 15:13:15 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Init
Span::Span()
{
	std::cout << GREEN << "[LOG] " << RESET << "Span class has been created" << std::endl;
	this->_N = 0;
}

Span::Span(unsigned int N)
{
	std::cout << GREEN << "[LOG] " << RESET << "Span class has been created" << std::endl;
	this->_N = N;
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span::~Span(void)
{
	std::cout << RED << "[LOG] " << RESET << "Span class has been destroyed" << std::endl;
}

Span &Span::operator=(const Span &obj)
{
	(void)obj;
	return (*this);
}

// Body
void	Span::addNumber(int number)
{
	if (this->_lst.size() + 1 > this->_N)
		throw (std::exception());
	this->_lst.push_back(number);
}

void    Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end)
{
    if (this->_lst.size() + std::distance(begin, end) > this->_N)
        throw (std::exception());
    this->_lst.insert(this->_lst.end(), begin, end);
}


int	Span::shortestSpan()
{
	if (this->_lst.size() < 2)
		throw (std::exception());

	this->_lst.sort();

	std::list<int>::const_iterator	it1 = this->_lst.begin();
	std::list<int>::const_iterator	it2 = this->_lst.begin();
	
	std::list<int>::const_iterator	ite = this->_lst.end();
	int								min;

	++it2;
	if (*it1 >= *it2)
		min = *it1 - *it2;
	else
		min = *it2 - *it1;
	while (it2 != ite)
	{
		if (*it1 >= *it2 && *it1 - *it2 < min)
			min = *it1 - *it2;
		else if (*it1 < *it2 && *it2 - *it1 < min)
			min = *it2 - *it1;
		++it1;
		++it2;
	}
	return (min);
}

int Span::longestSpan()
{
	if (this->_lst.size() < 2)
		throw (std::exception());
		
	std::list<int>::const_iterator	it;
	std::list<int>::const_iterator	ite = this->_lst.end();
	int								max = *(this->_lst.begin());
	int								min = *(this->_lst.begin());

	for (it = this->_lst.begin(); it != ite; ++it)
	{
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
	}
	return (max - min);
}