/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:49:15 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/16 12:28:44 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {

public:

	Harl(void);
	~Harl(void);

	void	complain(std::string level) const;

private:

	void	_debug(void) const;
	void	_info(void) const;
	void	_warning(void) const;
	void	_error(void) const;
	
};

#endif