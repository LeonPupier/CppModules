/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:30:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/07 16:48:11 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.Class/Bureaucrat.hpp"
#include "Form.Class/Form.hpp"
#include "ShrubberyCreationForm.Class/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.Class/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.Class/PresidentialPardonForm.hpp"

int main(void)
{
	// BOB
	std::cout << YELLOW << "Init the bureaucrat Bob:" << RESET << std::endl;
	Bureaucrat	bob("Bob", 42);
	std::cout << bob << std::endl;

	// SHRUBBERY CREATION FORM
	std::cout << BLUE << "\nCreation of yard's form:" << RESET << std::endl;
	ShrubberyCreationForm	yard("yard");
	std::cout << yard << std::endl;

	std::cout << BLUE << "Bob execute yard's form:" << RESET << std::endl;
	bob.executeForm(yard);

	std::cout << BLUE << "Bob sign yard's form:" << RESET << std::endl;
	bob.signForm(yard);

	std::cout << BLUE << "Bob execute yard's form:" << RESET << std::endl;
	bob.executeForm(yard);

	// ROBOTOMY REQUEST FORM
	std::cout << CYAN << "\nCreation of drill's form:" << RESET << std::endl;
	RobotomyRequestForm	drill("drill");
	std::cout << drill << std::endl;

	std::cout << CYAN << "Bob sign drill's form:" << RESET << std::endl;
	bob.signForm(drill);

	std::cout << CYAN << "Bob execute drill's form:" << RESET << std::endl;
	bob.executeForm(drill);

	// PRESIDENTIAL PARDON FORM
	std::cout << MAGENTA << "\nCreation of pardon's form:" << RESET << std::endl;
	PresidentialPardonForm	pardon("pardon");
	std::cout << pardon << std::endl;

	std::cout << MAGENTA << "Bob sign pardon's form:" << RESET << std::endl;
	bob.signForm(pardon);

	std::cout << MAGENTA << "Bob execute pardon's form:" << RESET << std::endl;
	bob.executeForm(pardon);

	// UPGRADE BOB'S GRADE
	std::cout << YELLOW << "Upgrade Bob's grade to 25:" << RESET << std::endl;
	while (bob.getGrade() > 25)
		bob.upperGrade();
	std::cout << bob << std::endl;

	// BOB SIGN THE PRESIDENTIAL PARDON FORM
	std::cout << MAGENTA << "Bob sign pardon's form:" << RESET << std::endl;
	bob.signForm(pardon);

	// UPGRADE BOB'S GRADE
	std::cout << YELLOW << "Upgrade Bob's grade to 3:" << RESET << std::endl;
	while (bob.getGrade() > 3)
		bob.upperGrade();
	std::cout << bob << std::endl;

	// BOB EXECUTE THE PRESIDENTIAL PARDON FORM
	std::cout << MAGENTA << "Bob execute pardon's form:" << RESET << std::endl;
	bob.executeForm(pardon);

	std::cout << RED << "\nDestructors:" << RESET << std::endl;
	return (0);
}
