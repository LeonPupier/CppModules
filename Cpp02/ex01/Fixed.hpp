/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:20:47 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/12 14:01:49 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

private:

	int					_number;
	static const int	_static_number = 8;

public:

	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &obj);
	~Fixed(void);
	Fixed &operator=(const Fixed &obj);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int 	toInt(void) const;
	float 	toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif