/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:13:48 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/10 08:58:34 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie	*zombie_1 = newZombie("Moliere");
	Zombie	*zombie_2 = newZombie("Rousseau");
	
	randomChump("Malraux");
	
	zombie_1->announce();
	
	randomChump("Baudelaire");

	zombie_2->announce();

	delete zombie_1;
	delete zombie_2;

	return (0);
}
