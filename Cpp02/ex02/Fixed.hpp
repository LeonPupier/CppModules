/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:20:47 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/12 16:19:50 by lpupier          ###   ########.fr       */
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

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	int 				toInt(void) const;
	float 				toFloat(void) const;
	static Fixed		&min(Fixed &f1, Fixed &f2);
	static const Fixed	&min(const Fixed &f1, const Fixed &f2);
	static Fixed		&max(Fixed &f1, Fixed &f2);
	static const Fixed	&max(const Fixed &f1, const Fixed &f2);

	bool operator>(const Fixed &obj);
	bool operator<(const Fixed &obj);
	bool operator>=(const Fixed &obj);
	bool operator<=(const Fixed &obj);
	bool operator==(const Fixed &obj);
	bool operator!=(const Fixed &obj);

	Fixed operator+(const Fixed &obj);
	Fixed operator-(const Fixed &obj);
	Fixed operator*(const Fixed &obj);
	Fixed operator/(const Fixed &obj);

	Fixed &operator++(void);
	Fixed operator++(int value);
	Fixed &operator--(void);
	Fixed operator--(int value);
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif