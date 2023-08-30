/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:54:41 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/30 09:12:04 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Init
Cat::Cat(): Animal("Cat")
{
	std::cout << GREEN << "[LOG] " << RESET << "Cat class has been created" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &obj): Animal(obj)
{
	*this = obj;
}

Cat::~Cat(void)
{
	std::cout << RED << "[LOG] " << RESET << "Cat class has been destroyed" << std::endl;
	delete this->_brain;
}

Brain *Cat::getBrain(void) const
{
	return (this->_brain);
}

Cat &Cat::operator=(const Cat &obj)
{
	if (this == &obj)
		return (*this);
	this->_brain = new Brain(*obj.getBrain());
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaaaaoouuuu..." << std::endl;
}
