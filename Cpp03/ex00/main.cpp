/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:18 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/17 14:01:47 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	wall_e("Wall-E");
	ClapTrap	terminator("Terminator");

	wall_e.setAttackDamage(3);
	terminator.setAttackDamage(4);
	
	wall_e.attack("Terminator");
	terminator.takeDamage(wall_e.getAttackDamage());
	terminator.beRepaired(2);
	terminator.attack("Wall-E");
	wall_e.takeDamage(terminator.getAttackDamage());
	wall_e.attack("Terminator");
	terminator.takeDamage(wall_e.getAttackDamage());
	wall_e.beRepaired(6);

	wall_e.setAttackDamage(6);

	wall_e.attack("Terminator");
	terminator.takeDamage(wall_e.getAttackDamage());
	terminator.beRepaired(10);
	wall_e.attack("Terminator");
	terminator.takeDamage(wall_e.getAttackDamage());
	
	return (0);
}
