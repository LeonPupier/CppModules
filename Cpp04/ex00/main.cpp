/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:30:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/21 15:51:15 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.Class/Dog.hpp"
#include "Cat.Class/Cat.hpp"
#include "WrongCat.Class/WrongCat.hpp"

int main()
{
	const Animal* meta				= new Animal();
	const WrongAnimal* wrong_meta	= new WrongAnimal();
	const Animal* dog				= new Dog();
	const Animal* cat				= new Cat();
	const WrongAnimal* wrong_cat	= new WrongCat();

	std::cout << BLUE << "------- GET TYPES ------" << RESET << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << wrong_meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	
	std::cout << BLUE << "------ MAKE SOUNDS -----" << RESET << std::endl;
	meta->makeSound();
	wrong_meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrong_cat->makeSound();
	std::cout << BLUE << "------------------------" << RESET << std::endl;
	
	delete meta;
	delete wrong_meta;
	delete dog;
	delete cat;
	delete wrong_cat;

	return (0);
}
