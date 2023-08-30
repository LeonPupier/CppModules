/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/30 09:45:37 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Init
Brain::Brain()
{
	std::cout << GREEN << "[LOG] " << RESET << "Brain class has been created" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	*this = obj;
}

Brain::~Brain(void)
{
	std::cout << RED << "[LOG] " << RESET << "Brain class has been destroyed" << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
	std::copy(obj._ideas, obj._ideas + 100, this->_ideas);
	return (*this);
}

// Getters
std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index > 99)
		return (NULL);
	return (this->_ideas[index]);
}

// Body
void	Brain::setIdea(std::string idea, int index)
{
	if (index < 0 || index > 99)
		return ;
	this->_ideas[index] = idea;
}
