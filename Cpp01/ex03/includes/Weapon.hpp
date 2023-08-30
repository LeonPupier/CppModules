/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:06:50 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/15 10:00:03 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {

private:

	std::string _type;

public:

	Weapon(std::string type);
	~Weapon(void);

	std::string const & getType(void);
	void				setType(std::string const &_type);
	
};

#endif