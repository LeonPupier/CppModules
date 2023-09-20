/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:07:37 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/20 15:12:44 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.Class/Span.hpp"

int main()
{
	{
		try
		{
			std::cout << BLUE << "\n------- STACK FULL -------\n\n" << RESET << std::endl;
			Span stack(100);
			for(int i = 0; i < 100; i++)
				stack.addNumber(i);
			stack.addNumber(100);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << BLUE << "\n------- 1 ELEMENT -------\n\n" << RESET << std::endl;
		Span stack(4);
		try
		{
			stack.addNumber(1);
			std::cout << "Max span: " << stack.longestSpan() << std::endl;
			std::cout << "Min span: " << stack.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << BLUE << "\n------- MAX & MIN SPAN -------\n\n" << RESET << std::endl;
		Span stack(5);
		try
		{
			stack.addNumber(6);
			stack.addNumber(3);
			stack.addNumber(17);
			stack.addNumber(9);
			stack.addNumber(11);
			std::cout << "Max span: " << stack.longestSpan() << std::endl;
			std::cout << "Min span: " << stack.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << BLUE << "\n------- BIG STACK-------\n\n" << RESET << std::endl;
		Span stack(10042);
		std::list<int> s1;
		try
		{
			for(int i(0); i < 10042; i++)
				s1.push_back(i);
			stack.addNumber(s1.begin(), s1.end());
			std::cout << "Max span: " << stack.longestSpan() << std::endl;
			std::cout << "Min span: " << stack.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
