/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/21 13:02:27 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Init
Animal::Animal()
{
	std::cout << GREEN << "[LOG] " << RESET << "Animal class has been created" << std::endl;
	this->_type = "Ant";
}

Animal::Animal(std::string type)
{
	std::cout << GREEN << "[LOG] " << RESET << "Animal class has been created" << std::endl;
	this->_type = type;
}

Animal::Animal(const Animal &obj)
{
	*this = obj;
}

Animal::~Animal(void)
{
	std::cout << RED << "[LOG] " << RESET << "Animal class has been destroyed" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
	this->_type = obj.getType();
	return (*this);
}

// Getters
std::string	Animal::getType(void) const
{
	return (this->_type);
}

// Body
void	Animal::makeSound(void) const
{
	return ;
}