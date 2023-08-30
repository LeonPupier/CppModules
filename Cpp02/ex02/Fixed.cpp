/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:23:35 by lpupier           #+#    #+#             */
/*   Updated: 2023/07/12 16:19:46 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_number = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_number = value << this->_static_number;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(value * (1 << this->_static_number));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(obj.getRawBits());
	return (*this);
}






int	Fixed::getRawBits(void) const
{
	return (this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->_number = raw;
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_static_number);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << this->_static_number));
}





Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.toFloat() <= f2.toFloat())
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.toFloat() <= f2.toFloat())
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.toFloat() >= f2.toFloat())
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.toFloat() >= f2.toFloat())
		return (f1);
	return (f2);
}






std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &obj)
{
	return (this->toFloat() > obj.toFloat());
}

bool Fixed::operator<(const Fixed &obj)
{
	return (this->toFloat() < obj.toFloat());
}

bool Fixed::operator>=(const Fixed &obj)
{
	return (this->toFloat() >= obj.toFloat());
}

bool Fixed::operator<=(const Fixed &obj)
{
	return (this->toFloat() <= obj.toFloat());
}

bool Fixed::operator==(const Fixed &obj)
{
	return (this->toFloat() == obj.toFloat());
}

bool Fixed::operator!=(const Fixed &obj)
{
	return (this->toFloat() != obj.toFloat());
}

Fixed Fixed::operator+(const Fixed &obj)
{
	Fixed	new_obj(this->toFloat() + obj.toFloat());

	return (new_obj);
}

Fixed Fixed::operator-(const Fixed &obj)
{
	Fixed	new_obj(this->toFloat() - obj.toFloat());

	return (new_obj);
}

Fixed Fixed::operator*(const Fixed &obj)
{
	Fixed	new_obj(this->toFloat() * obj.toFloat());

	return (new_obj);
}

Fixed Fixed::operator/(const Fixed &obj)
{
	Fixed	new_obj(this->toFloat() / obj.toFloat());

	return (new_obj);
}

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int value)
{
	Fixed	temp_fixed;

	if (!value)
		value = 1;
	temp_fixed = *this;
	this->setRawBits(this->getRawBits() + value);
	return (temp_fixed);
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int value)
{
	Fixed	temp_fixed;

	if (!value)
		value = 1;
	temp_fixed = *this;
	this->setRawBits(this->getRawBits() - value);
	return (temp_fixed);
}
