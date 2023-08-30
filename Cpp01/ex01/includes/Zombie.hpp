/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:13:41 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/10 09:07:51 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:

	Zombie(void);
	~Zombie(void);

	void		announce(void);
	void		give_name(std::string name);

private:

	std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
