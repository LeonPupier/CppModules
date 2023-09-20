/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/20 10:29:26 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Init
template <typename T>
Array<T>::Array()
{
	std::cout << GREEN << "[LOG] " << RESET << "Array class has been created" << std::endl;
	this->_var = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << GREEN << "[LOG] " << RESET << "Array class has been created" << std::endl;
	this->_var = new T[n];
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array &obj)
{
	*this = obj;
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << RED << "[LOG] " << RESET << "Array class has been destroyed" << std::endl;
	delete[] this->_var;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &obj)
{
	this->_var = new T[obj._size];
	for (unsigned int i = 0; i < obj._size; i++)
		this->_var[i] = obj._var[i];
	this->_size = obj._size;
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw (std::exception());
	return (this->_var[index]);
}


// Getters
template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}
