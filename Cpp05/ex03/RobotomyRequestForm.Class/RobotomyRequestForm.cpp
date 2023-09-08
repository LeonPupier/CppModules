/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/08 12:32:39 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Init
RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45)
{
	std::cout << GREEN << "[LOG] " << RESET << "RobotomyRequestForm class has been created" << std::endl;
	this->_target = "NoName";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45)
{
	std::cout << GREEN << "[LOG] " << RESET << "RobotomyRequestForm class has been created" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): Form(obj)
{
	*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED << "[LOG] " << RESET << "RobotomyRequestForm class has been destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	this->_target = obj._target;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj)
{
	out << "The RobotomyRequestForm '" << obj.getTarget()
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
std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

// Body
void	RobotomyRequestForm::beExecuted(Bureaucrat const & executor) const
{
	int random;

	std::srand(time(NULL));

	std::cout << "*Drill noises* Brrrzzz...." << std::endl;
	random = rand() % 2 + 1;
	if (random == 1)
		std::cout << executor.getName() << " was robotomized." << std::endl;
	else
		std::cout << "The operation failed..." << std::endl;
}
