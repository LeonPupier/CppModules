/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/08 11:28:40 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

typedef Form *(Intern::*list_function)(std::string target) const;

// Init
Intern::Intern(void)
{
	std::cout << GREEN << "[LOG] " << RESET << "Intern class has been created" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
}

Intern::~Intern(void)
{
	std::cout << RED << "[LOG] " << RESET << "Intern class has been destroyed" << std::endl;
}

Intern &Intern::operator=(const Intern &obj)
{
	(void)obj;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Intern &obj)
{
	(void)obj;
	out << "The intern is alive.";
	return (out);
}

// Body
Form	*Intern::makeForm(std::string name, std::string target) const
{
	std::string		list_action[]	= {"shrubbery creation", "robotomy request", "presidential pardon"};
	list_function	list_ptr[]		= {&Intern::_shrubbery_creation, &Intern::_robotomy_request, &Intern::_presidential_pardon};
	int				idx				= 0;

	for (idx = 0; idx < 3; idx++)
	{
		if (!list_action[idx].compare(name))
			return (this->*list_ptr[idx])(target);
	}

	std::cout << RED << "[ERROR] " << RESET << "The request form type does not exist..." << std::endl;

	return (NULL);
}

// Form creation
Form	*Intern::_shrubbery_creation(std::string target) const
{
	ShrubberyCreationForm	*form = new ShrubberyCreationForm(target);
	std::cout << "Intern creates a Shrubbery Creation Form." << std::endl;
	return (form);
}

Form	*Intern::_robotomy_request(std::string target) const
{
	RobotomyRequestForm	*form = new RobotomyRequestForm(target);
	std::cout << "Intern creates a Robotomy Request Form." << std::endl;
	return (form);
}

Form	*Intern::_presidential_pardon(std::string target) const
{
	PresidentialPardonForm	*form = new PresidentialPardonForm(target);
	std::cout << "Intern creates a Presidential Pardon Form." << std::endl;
	return (form);
}
