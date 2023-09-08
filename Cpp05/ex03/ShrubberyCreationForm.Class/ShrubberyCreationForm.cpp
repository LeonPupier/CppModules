/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/08 12:33:12 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Init
ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << GREEN << "[LOG] " << RESET << "ShrubberyCreationForm class has been created" << std::endl;
	this->_target = "NoName";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << GREEN << "[LOG] " << RESET << "ShrubberyCreationForm class has been created" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): Form(obj)
{
	*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << RED << "[LOG] " << RESET << "ShrubberyCreationForm class has been destroyed" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	this->_target = obj._target;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj)
{
	out << "The ShrubberyCreationForm '" << obj.getTarget()
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
std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

// Body
void	ShrubberyCreationForm::beExecuted(Bureaucrat const & executor) const
{
	std::ofstream		file;
	std::string const	path = "_shrubbery";
	std::string			content;

	file.open((this->_target + path).c_str());
	if (!file.is_open())
	{
		std::cout << "The file can't be open..." << std::endl;
		return ;
	}
	
	file << "    ###         ###    " << std::endl;
	file << "   #o###       #o###   " << std::endl;
	file << " ##o##o###   ##o##o### " << std::endl;
	file << "#o###|###o# #o###|###o#" << std::endl;
	file << " ##o#|##o#   ##o#|##o# " << std::endl;
	file << "    }|{         }|{    " << std::endl;
	file << "   _}|{_  <3   _}|{_   " << std::endl;
	
	file.close();
	std::cout << executor.getName() << " plant a Shrubbery !" << std::endl;
}
