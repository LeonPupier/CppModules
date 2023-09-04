/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:30:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/04 15:57:55 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.Class/Bureaucrat.hpp"

int main()
{
	// BOB
	std::cout << YELLOW << "Init the bureaucrat Bob:" << RESET << std::endl;
	Bureaucrat	bob("Bob", 42);
	std::cout << bob << std::endl;

	std::cout << YELLOW << "Upgrade Bob's grade:" << RESET << std::endl;
	bob.upperGrade();
	std::cout << bob << std::endl;

	std::cout << YELLOW << "Drop Bob's grade:" << RESET << std::endl;
	bob.lowerGrade();
	std::cout << bob << std::endl;

	// JEAN
	std::cout << BLUE << "\nInit the bureaucrat Jean:" << RESET << std::endl;
	Bureaucrat	jean("Jean", 1);
	std::cout << jean << std::endl;

	try
	{
		std::cout << BLUE << "Try to upgrade Jean's grade:" << RESET << std::endl;
		jean.upperGrade();
		std::cout << jean << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "The error " << e.what() << " was detected..." << std::endl;
	}
	std::cout << jean << std::endl;

	// MARTIN
	std::cout << CYAN << "\nInit the bureaucrat Martin:" << RESET << std::endl;
	Bureaucrat	martin("Martin", 150);
	std::cout << martin << std::endl;
	
	try
	{
		std::cout << CYAN << "Try to drop Martin's grade:" << RESET << std::endl;
		martin.lowerGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "The error " << e.what() << " was detected..." << std::endl;
	}
	std::cout << martin << std::endl;

	// END
	std::cout << RED << "\nDestructors:" << RESET << std::endl;
	return (0);
}
