/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:30:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/07 17:13:32 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.Class/Bureaucrat.hpp"
#include "Form.Class/Form.hpp"

static void	debug_signed_form(Form const & form)
{
	std::cout << "The form " << form.getName() << " is ";
	if (form.isSigned())
		std::cout << "signed." << std::endl;
	else
		std::cout << "not signed." << std::endl;
}

int main(void)
{
	// FORM A-38
	std::cout << YELLOW << "Init the form A-38:" << RESET << std::endl;
	Form	a38("A-38", 38, 42);
	std::cout << a38 << std::endl;

	std::cout << YELLOW << "State of the form A-38:" << RESET << std::endl;
	debug_signed_form(a38);

	// BOB
	std::cout << BLUE << "\nInit the bureaucrat Bob:" << RESET << std::endl;
	Bureaucrat	bob("Bob", 39);
	std::cout << bob << std::endl;

	std::cout << BLUE << "Bob try to sign the form A-38:" << RESET << std::endl;
	bob.signForm(a38);

	std::cout << BLUE << "Bob gets a rank increase:" << RESET << std::endl;
	bob.upperGrade();
	std::cout << bob << std::endl;

	std::cout << BLUE << "Bob retry to sign the form A-38:" << RESET << std::endl;
	bob.signForm(a38);

	std::cout << BLUE << "State of the form A-38:" << RESET << std::endl;
	debug_signed_form(a38);

	// END
	std::cout << RED << "\nDestructors:" << RESET << std::endl;
	return (0);
}
