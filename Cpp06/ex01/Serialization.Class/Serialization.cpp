/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/19 10:35:49 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

// Init
Serialization::Serialization()
{
	std::cout << GREEN << "[LOG] " << RESET << "Serialization class has been created" << std::endl;
}

Serialization::Serialization(const Serialization &obj)
{
	*this = obj;
}

Serialization::~Serialization(void)
{
	std::cout << RED << "[LOG] " << RESET << "Serialization class has been destroyed" << std::endl;
}

Serialization &Serialization::operator=(const Serialization &obj)
{
	(void)obj;
	return (*this);
}

// Body
uintptr_t	Serialization::serialize(Data* ptr)
{
	return (reinterpret_cast <uintptr_t>(ptr));
}

Data*		Serialization::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data *>(raw));
}
