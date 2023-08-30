/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:18 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/24 11:16:01 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap/ScavTrap.hpp"

int	main(void)
{
	FragTrap	wall_e("Wall-E");
	ScavTrap	terminator("Terminator");

	terminator.beRepaired(2);
	wall_e.setAttackDamage(3);
	wall_e.attack("Terminator");
	wall_e.beRepaired(5);
	wall_e.highFivesGuys();
	wall_e.attack("Terminator");
	wall_e.setAttackDamage(5);
	wall_e.attack("C-3PO");
	wall_e.takeDamage(3);
	wall_e.highFivesGuys();
	wall_e.beRepaired(1);

	return (0);
}
