/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/24 08:59:00 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap/ClapTrap.hpp"

class FragTrap: public ClapTrap {

public:

	// Init
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &obj);
	~FragTrap(void);
	FragTrap &operator=(const FragTrap &obj);

	// Body
	void	highFivesGuys(void);

};

#endif