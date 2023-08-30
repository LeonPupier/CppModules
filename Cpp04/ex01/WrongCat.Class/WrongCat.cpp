/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:54:41 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/24 15:31:58 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Init
WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << GREEN << "[LOG] " << RESET << "WrongCat class has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj): WrongAnimal(obj)
{
	*this = obj;
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << "[LOG] " << RESET << "WrongCat class has been destroyed" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	(void)obj;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong Miaaaaoouuuu..." << std::endl;
}
