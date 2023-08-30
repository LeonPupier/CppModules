/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/24 08:47:02 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Init
ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "[LOG] ScavTrap with no name has been initialized" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "[LOG] ScavTrap " << name << " has been initialized" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &obj): ClapTrap(obj)
{
	*this = obj;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[LOG] ScavTrap " << this->getName() << " has been destroyed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	this->setName(obj.getName());
	this->setHitPoints(obj.getHitPoints());
	this->setEnergyPoints(obj.getEnergyPoints());
	this->setAttackDamage(obj.getAttackDamage());
	return (*this);
}

// Body
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " enter in gate keeper" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack because he's dead." << std::endl;
		return ;
	}
	else if (this->_energy_points <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy..." << std::endl;
		return ;
	}
	std::cout << 
		"ScavTrap " << this->_name << " attacks " << target
		<< " causing " << this->_attack_damage << " points of damage!"
	<< std::endl;
	this->_energy_points--;
}
