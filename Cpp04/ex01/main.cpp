/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:30:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/30 09:58:26 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.Class/Dog.hpp"
#include "Cat.Class/Cat.hpp"
#include "WrongCat.Class/WrongCat.hpp"

int	main(void)
{
	int		max = 4;
	int		i;
	Animal	*animals[max];
	
	// Init the table of animals
	std::cout << BLUE << "-----CREATE DOGS-----" << RESET << std::endl;
	for (i = 0; i < max / 2; i++)
	{
		std::cout << GREEN << "Dog n•" << i << RESET << std::endl;
		animals[i] = new Dog();
	}
	std::cout << BLUE << "-----CREATE CATS-----" << RESET << std::endl;
	for (i = max / 2; i < max; i++)
	{
		std::cout << GREEN << "Cat n•" << i << RESET << std::endl;
		animals[i] = new Cat();
	}

	// Use the table to get types
	std::cout << BLUE << "-----ANIMALS TYPES-----" << RESET << std::endl;
	for (i = 0; i < max; i++)
	{
		std::cout << animals[i]->getType() << std::endl;
	}
	
	// Free the memory
	std::cout << BLUE << "----DELETED ANIMALS----" << RESET << std::endl;
	for (i = 0; i < max; i++)
	{	
		std::cout << RED << "Delete animal n•" << i << RESET << std::endl;
		delete animals[i];
	}

	// Fill brain ideas
	std::cout << BLUE << "------FILL BRAIN-------" << RESET << std::endl;
	
	std::cout << GREEN << "Init Milou:" << RESET << std::endl;
	Dog	*milou = new Dog();
	milou->getBrain()->setIdea("My name is Milou!", 0);
	
	std::cout << GREEN << "Pluto is a copy of Milou." << RESET << std::endl;
	Dog	*pluto = milou;

	std::cout << YELLOW << "Idea of Milou: " << milou->getBrain()->getIdea(0) << RESET << std::endl;
	std::cout << YELLOW << "Idea of Pluto: " << pluto->getBrain()->getIdea(0) << RESET << std::endl;
	
	delete	milou;

	// Test deep copy
	std::cout << BLUE << "-------DEEP COPY-------" << RESET << std::endl;
	
	Dog	basic;
	{
		Dog	tmp = basic;
	}

	return (0);
}
