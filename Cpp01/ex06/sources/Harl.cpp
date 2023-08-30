/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:59:00 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/22 16:32:48 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

typedef void (Harl::*list_function)(void);

void	Harl::complain(std::string level)
{
	int				idx;
	std::string		list_action[4]	= {"DEBUG", "INFO", "WARNING", "ERROR"};
	list_function	functions[4]	= {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	
	for (idx = 0; idx < 4; idx++)
		if (level == list_action[idx])
			break ;

	switch (idx) {
		case 0: {
			(this->*(functions[0]))();
		}
		case 1: {
			(this->*(functions[1]))();
		}
		case 2: {
			(this->*(functions[2]))();
		}
		case 3: {
			(this->*(functions[3]))();
			break ;
		}
		default: {
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		}
	}
}

void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I don't know how to code in Brainfuck..." << std::endl;
	std::cout << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I am a good developper." << std::endl;
	std::cout << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I don't have a degree in computer science but I know how to code" << std::endl;
	std::cout << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "There is a problem, I don't understand this syntax :(" << std::endl;
	std::cout << std::endl;
}
