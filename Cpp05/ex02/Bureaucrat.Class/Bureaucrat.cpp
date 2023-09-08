/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/08 13:36:43 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Init
Bureaucrat::Bureaucrat(): _name("NoName")
{
	std::cout << GREEN << "[LOG] " << RESET << "Bureaucrat class has been created" << std::endl;
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << GREEN << "[LOG] " << RESET << "Bureaucrat class has been created" << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
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

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "." << std::endl;
	}
	catch (Form::GradeTooLowException)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because his grade is too low..." << std::endl;
	}
}

void	Bureaucrat::executeForm(Form &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << "." << std::endl;
	}
	catch (Form::GradeTooLowException)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName()
		<< " because his grade is too low..." << std::endl;
	}
	catch (Form::NotAlreadySigned)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName()
		<< " because the form is not signed..." << std::endl;
	}
}