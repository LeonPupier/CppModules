/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:43:30 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/30 09:12:13 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Init
Dog::Dog(): Animal("Dog")
{
	std::cout << GREEN << "[LOG] " << RESET << "Dog class has been created" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &obj): Animal(obj)
{
	*this = obj;
}

Dog::~Dog(void)
{
	std::cout << RED << "[LOG] " << RESET << "Dog class has been destroyed" << std::endl;
	delete this->_brain;
}

Brain *Dog::getBrain(void) const
{
	return (this->_brain);
}

Dog &Dog::operator=(const Dog &obj)
{
	if (this == &obj)
		return (*this);
	this->_brain = new Brain(*obj.getBrain());
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Waf waf waf !!" << std::endl;
}