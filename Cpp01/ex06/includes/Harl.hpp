/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:49:15 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/17 10:36:38 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {

public:

	Harl(void);
	~Harl(void);

	void	complain(std::string level);

private:

	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
	
};

#endif