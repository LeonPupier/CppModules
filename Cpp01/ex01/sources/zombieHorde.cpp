/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:04:27 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/10 10:05:16 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];

	for (int nb = 0; nb < N; nb++)
		horde[nb].give_name(name);
	
	return (horde);
}
