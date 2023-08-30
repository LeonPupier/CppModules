/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:43:30 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/30 08:54:13 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Init
Dog::Dog(): Animal("Dog")
{
	std::cout << GREEN << "[LOG] " << RESET << "Dog class has been created" << std::endl;
}

Dog::Dog(const Dog &obj): Animal(obj)
{
	*this = obj;
}

Dog::~Dog(void)
{
	std::cout << RED << "[LOG] " << RESET << "Dog class has been destroyed" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	(void)obj;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Waf waf waf !!" << std::endl;
}
