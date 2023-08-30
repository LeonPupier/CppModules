/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/17 16:54:02 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap/ClapTrap.hpp"

class ScavTrap: public ClapTrap {

public:

	// Init
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &obj);
	~ScavTrap(void);
	ScavTrap &operator=(const ScavTrap &obj);

	// Body
	void	guardGate(void);
	void	attack(const std::string& target);

};

#endif