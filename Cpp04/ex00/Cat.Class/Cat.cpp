/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:54:41 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/30 08:55:09 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Init
Cat::Cat(): Animal("Cat")
{
	std::cout << GREEN << "[LOG] " << RESET << "Cat class has been created" << std::endl;
}

Cat::Cat(const Cat &obj): Animal(obj)
{
	*this = obj;
}

Cat::~Cat(void)
{
	std::cout << RED << "[LOG] " << RESET << "Cat class has been destroyed" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	(void)obj;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaaaaoouuuu..." << std::endl;
}
