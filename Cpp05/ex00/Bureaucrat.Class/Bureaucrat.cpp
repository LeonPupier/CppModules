/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/04 15:50:28 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Init
Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << GREEN << "[LOG] " << RESET << "Bureaucrat class has been created" << std::endl;
	this->_name = name;
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << "[LOG] " << RESET << "Bureaucrat class has been destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->_name = obj._name;
	this->_grade = obj._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (out);
}

// Exceptions
char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

// Getters
std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// Body
void	Bureaucrat::upperGrade(void)
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw (Bureaucrat::GradeTooHighException());
}


void	Bureaucrat::lowerGrade(void)
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw (Bureaucrat::GradeTooLowException());
}
