/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/20 15:55:11 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Init
template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << GREEN << "[LOG] " << RESET << "MutantStack class has been created" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &obj)
{
	*this = obj;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << RED << "[LOG] " << RESET << "MutantStack class has been destroyed" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &obj)
{
	(void)obj;
	return (*this);
}
