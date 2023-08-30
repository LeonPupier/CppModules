/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:06:53 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/10 14:49:11 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "../includes/Weapon.hpp"

class HumanB {

public:

	HumanB(std::string name);
	~HumanB(void);

	void	setWeapon(Weapon &new_weapon);
	void	attack(void);

private:

	std::string	_name;
	Weapon		*_weapon;

};

#endif