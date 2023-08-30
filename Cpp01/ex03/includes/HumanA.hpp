/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:06:56 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/10 14:28:58 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "../includes/Weapon.hpp"

class HumanA {

public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	setWeapon(Weapon new_weapon);
	void	attack(void);

private:

	std::string	_name;
	Weapon		&_weapon;

};

#endif