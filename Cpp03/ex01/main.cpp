/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:18 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/24 08:29:23 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	wall_e("Wall-E");

	wall_e.setAttackDamage(3);
	wall_e.attack("Terminator");
	wall_e.beRepaired(5);
	wall_e.guardGate();
	wall_e.attack("Terminator");
	wall_e.setAttackDamage(5);
	wall_e.attack("C-3PO");
	wall_e.takeDamage(3);
	wall_e.beRepaired(1);

	return (0);
}
