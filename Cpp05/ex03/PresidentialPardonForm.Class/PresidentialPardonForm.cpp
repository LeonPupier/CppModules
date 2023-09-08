/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/07 16:44:21 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Init
PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5)
{
	std::cout << GREEN << "[LOG] " << RESET << "PresidentialPardonForm class has been created" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): Form(obj)
{
	*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED << "[LOG] " << RESET << "PresidentialPardonForm class has been destroyed" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	this->_target = obj._target;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &obj)
{
	out << "The PresidentialPardonForm '" << obj.getTarget()
		<< "' is ";
	
	if (obj.isSigned())
		out << "signed. ";
	else
		out << "not signed. ";
	
	out << obj.getGradeToSign() << " grade to be signed and grade "
		<< obj.getGradeToExec() << " to be executed.";

	return (out);
}

// Getters
std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

// Body
void	PresidentialPardonForm::beExecuted(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " was excused by Zaphod Beeblebrox." << std::endl;
	return ;
}
