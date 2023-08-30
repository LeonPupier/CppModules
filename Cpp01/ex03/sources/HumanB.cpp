/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:06:45 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/15 10:05:12 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
	std::cout << this->_name << " want to fight!" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->_name << " fled the fight..." << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->_weapon = &new_weapon;
}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attack with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attack with their hands" << std::endl;
}
