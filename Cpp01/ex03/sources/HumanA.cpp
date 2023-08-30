/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:06:48 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/10 14:39:23 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon)
{
	this->_name = name;
	this->_weapon = weapon;
	std::cout << this->_name << " want to fight!" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this->_name << " fled the fight..." << std::endl;
}

void	HumanA::setWeapon(Weapon new_weapon)
{
	this->_weapon = new_weapon;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attack with their " << this->_weapon.getType() << std::endl;
}
