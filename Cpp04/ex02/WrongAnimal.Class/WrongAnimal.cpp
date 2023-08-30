/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/21 15:47:53 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Init
WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "[LOG] " << RESET << "WrongAnimal class has been created" << std::endl;
	this->_type = "WrongAnt";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << GREEN << "[LOG] " << RESET << "WrongAnimal class has been created" << std::endl;
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	*this = obj;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "[LOG] " << RESET << "WrongAnimal class has been destroyed" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	this->_type = obj.getType();
	return (*this);
}

// Getters
std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

// Body
void	WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong noise..." << std::endl;
}