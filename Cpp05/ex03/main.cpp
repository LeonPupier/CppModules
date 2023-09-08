/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:30:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/08 11:33:55 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.Class/Bureaucrat.hpp"
#include "Form.Class/Form.hpp"
#include "Intern.Class/Intern.hpp"

int main(void)
{
	// INTERN PAUL
	std::cout << YELLOW << "Init the intern Paul:" << RESET << std::endl;
	Intern paul;
	std::cout << paul << std::endl;
	
	// INIT ROBOTOMY REQUEST FORM
	std::cout << BLUE << "\nInit of robotomy request's form by Paul:" << RESET << std::endl;
	Form* rrf;
	
	rrf = paul.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;

	// BUREAUCRAT BOB
	std::cout << CYAN << "\nInit the bureaucrat Bob:" << RESET << std::endl;
	Bureaucrat	bob("Bob", 42);
	std::cout << bob << std::endl;

	// ACTIONS ON RRF
	std::cout << CYAN << "Bob sign robotomy request's form:" << RESET << std::endl;
	bob.signForm(*rrf);

	std::cout << CYAN << "Bob execute robotomy request's form:" << RESET << std::endl;
	bob.executeForm(*rrf);

	// END
	std::cout << RED << "\nDestructors:" << RESET << std::endl;
	delete rrf;

	return (0);
}
