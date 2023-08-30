/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/24 08:49:19 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Init
FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "[LOG] FragTrap with no name has been initialized" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "[LOG] FragTrap " << name << " has been initialized" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &obj): ClapTrap(obj)
{
	*this = obj;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[LOG] FragTrap " << this->getName() << " has been destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	this->setName(obj.getName());
	this->setHitPoints(obj.getHitPoints());
	this->setEnergyPoints(obj.getEnergyPoints());
	this->setAttackDamage(obj.getAttackDamage());
	return (*this);
}

// Body
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " wants to do a high five" << std::endl;
}
