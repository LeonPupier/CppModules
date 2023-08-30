/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/17 14:28:21 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Init
ClapTrap::ClapTrap(void)
{
	std::cout << "[LOG] ClapTrap with no name has been initialized" << std::endl;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	this->_name = "N/A";
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "[LOG] ClapTrap " << name << " has been initialized" << std::endl;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	*this = obj;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[LOG] ClapTrap " << this->_name << " has been destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	this->_hit_points = obj.getHitPoints();
	this->_energy_points = obj.getEnergyPoints();
	this->_attack_damage = obj.getAttackDamage();
	this->_name = obj.getName();
	return (*this);
}


// Getters
std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hit_points);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energy_points);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attack_damage);
}


// Setters
void	ClapTrap::setName(std::string new_name)
{
	this->_name = new_name;
}

void	ClapTrap::setHitPoints(unsigned int new_hit_points)
{
	this->_hit_points = new_hit_points;
}

void	ClapTrap::setEnergyPoints(unsigned int new_energy_points)
{
	this->_energy_points = new_energy_points;
}

void	ClapTrap::setAttackDamage(unsigned int new_attack_damage)
{
	this->_attack_damage = new_attack_damage;
}


// Body
void ClapTrap::attack(const std::string &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack because he's dead." << std::endl;
		return ;
	}
	else if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy..." << std::endl;
		return ;
	}
	std::cout << 
		"ClapTrap " << this->_name << " attacks " << target
		<< " causing " << this->_attack_damage << " points of damage!"
	<< std::endl;
	this->_energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return ;
	}
	std::cout << 
		"ClapTrap " << this->_name << " take " << amount << " points of damage!"
	<< std::endl;
	this->_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't fix himself because he's dead." << std::endl;
		return ;
	}
	else if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy..." << std::endl;
		return ;
	}
	std::cout << 
		"ClapTrap " << this->_name << " be repaired with "
		<< amount << " new points of life!"
	<< std::endl;
	this->_hit_points += amount;
	this->_energy_points--;
}
