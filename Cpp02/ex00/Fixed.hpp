/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:20:47 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/12 13:05:26 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

private:

	int					_number;
	static const int	_static_number = 8;

public:

	Fixed(void);
	Fixed(const Fixed &obj);
	~Fixed(void);
	Fixed &operator=(const Fixed &obj);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif