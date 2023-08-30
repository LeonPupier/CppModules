/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/17 14:27:52 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

private:

	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;

public:

	// Init
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &obj);
	~ClapTrap(void);
	ClapTrap &operator=(const ClapTrap &obj);

	// Getters
	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

	// Setters
	void	setName(std::string new_name);
	void	setHitPoints(unsigned int new_hit_points);
	void	setEnergyPoints(unsigned int new_energy_points);
	void	setAttackDamage(unsigned int new_attack_damage);

	// Body
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};

#endif