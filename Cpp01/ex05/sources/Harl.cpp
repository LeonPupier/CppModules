/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:59:00 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/16 13:06:21 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

typedef void (Harl::*list_function)(void) const;

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level) const
{
	std::string		list_action[]	= {"DEBUG", "INFO", "WARNING", "ERROR"};
	list_function	list_ptr[]		= {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	int				idx				= 0;

	for (idx = 0; idx < 4; idx++)
	{
		if (!list_action[idx].compare(level))
			(this->*list_ptr[idx])();
	}
}

void	Harl::_debug(void) const
{
	std::cout << "I don't know how to code in Brainfuck..." << std::endl;
}

void	Harl::_info(void) const
{
	std::cout << "I am a good developper." << std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << "I don't have a degree in computer science but I know how to code" << std::endl;
}

void	Harl::_error(void) const
{
	std::cout << "There is a problem, I don't understand this syntax :(" << std::endl;
}
