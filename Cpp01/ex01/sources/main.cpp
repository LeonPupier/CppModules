/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:13:48 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/10 10:09:12 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	int	number = 10;

	Zombie	*horde = zombieHorde(number, "choupi");

	for (int nb = 0; nb < number; nb++)
		horde[nb].announce();

	delete [] horde;
}
