/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:30:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/21 15:30:34 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.Class/Dog.hpp"
#include "Cat.Class/Cat.hpp"
#include "WrongCat.Class/WrongCat.hpp"

int	main(void)
{
	std::cout << BLUE << "---- MILOU --------" << RESET << std::endl;
	Dog	milou;
	milou.makeSound();
	
	std::cout << YELLOW << "---- GARFIELD -----" << RESET << std::endl;
	Cat	garfield;
	garfield.makeSound();
	
	//std::cout << YELLOW << "-- ANIMAL -------" << RESET << std::endl;
	//Animal	animal;

	std::cout << RED << "---- DESTRUCTORS --" << RESET << std::endl;
	return (0);
}
