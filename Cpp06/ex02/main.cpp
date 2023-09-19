/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:30:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/19 11:47:30 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.Class/Base.hpp"
#include <cstdlib>
#include <time.h>

Base	*generate(void)
{
	int	number;

	srand(time(NULL));
	number = rand() % 3 + 1;

	switch (number)
	{
		case 1:
			std::cout << RED << "[LOG] " << RESET << "A class has been destroyed" << std::endl;
			return (new A());
		
		case 2:
			std::cout << RED << "[LOG] " << RESET << "B class has been destroyed" << std::endl;
			return (new B());

		case 3:
		std::cout << RED << "[LOG] " << RESET << "C class has been destroyed" << std::endl;
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Class A found." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class B found." << std::endl;
	else if (dynamic_cast<C* >(p))
		std::cout << "Class C found." << std::endl;
	else
		std::cout << "No matching class..." << std::endl;
}

void	identify(Base& p)
{
	Base	&b = p;

	try{
		b = dynamic_cast<A&>(p);
		std::cout << "Class A found." << std::endl;
	}
	catch (std::exception &e) {}

	try{
		b = dynamic_cast<B&>(p);
		std::cout << "Class B found." << std::endl;
	}
	catch (std::exception &e) {}

	try{
		b = dynamic_cast<C&>(p);
		std::cout << "Class C found." << std::endl;
	}
	catch (std::exception &e) {}
}

int main(void)
{	
	Base	*base;

	base = generate();
	identify(base);
	identify(*base);

	delete base;
	return (0);
}
