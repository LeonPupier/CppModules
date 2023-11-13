/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/11/03 13:07:29 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	processRPN(std::string operation)
{
	std::stack<double>	stack;
	double				a;
	double				b;
	double				result;

	if (operation.empty())
	{
		std::cout << RED << "[Error] " << RESET << "Empty operation." << std::endl;
		return (false);
	}

	for (size_t i = 0; i < operation.length(); i++)
	{
		if (operation[i] == ' ')
			continue ;
		else if (operation[i] == '+' || operation[i] == '-' || operation[i] == '/' || operation[i] == '*')
		{
			if (stack.size() < 2)
			{
				std::cout << RED << "[Error] " << RESET << "Not enough numbers." << std::endl;
				return (false);
			}

			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			
			if (operation[i] == '+')
				result = b + a;
			else if (operation[i] == '-')
				result = b - a;
			else if (operation[i] == '/')
			{
				if (!a)
				{
					std::cout << RED << "[Error] " << RESET << "Division by 0." << std::endl;
					return (false);
				}
				result = b / a;
			}
			else if (operation[i] == '*')
				result = b * a;
			
			if (result > INT_MAX || result < INT_MIN)
			{
				std::cout << RED << "[Error] " << RESET << "Overflow." << std::endl;
				return (false);
			}
			stack.push(result);

		}
		else if (operation[i] >= '0' && operation[i] <= '9')
			stack.push(operation[i] - 48);
		else
		{
			std::cout << RED << "[Error] " << RESET << "Invalid character: '" << operation[i] << "'." << std::endl;
			return (false);
		}
	}

	if (stack.size() != 1)
	{
		std::cout << RED << "[Error] " << RESET << "Not enough operators." << std::endl;
		return (false);
	}

	std::cout << GREEN << "[Result] " << RESET << stack.top() << std::endl;
	return (true);
}