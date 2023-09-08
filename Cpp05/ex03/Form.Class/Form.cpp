/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/07 15:52:00 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Init
Form::Form(std::string name, int grade_sign, int grade_exec): _name(name), _grade_to_sign(grade_sign), _grade_to_exec(grade_exec)
{
	std::cout << GREEN << "[LOG] " << RESET << "Form class has been created" << std::endl;
	this->_signed = false;
	
	if (grade_sign < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade_sign > 150)
		throw (Bureaucrat::GradeTooLowException());
	
	if (grade_exec < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade_exec > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Form::Form(const Form &obj): _name(obj._name), _grade_to_sign(obj._grade_to_sign), _grade_to_exec(obj._grade_to_exec)
{
	*this = obj;
}

Form::~Form(void)
{
	std::cout << RED << "[LOG] " << RESET << "Form class has been destroyed" << std::endl;
}

Form &Form::operator=(const Form &obj)
{
	this->_signed = obj._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	out << obj.getName() << " form needs grade "
		<< obj.getGradeToSign() << " to be signed and grade "
		<< obj.getGradeToExec() << " to be executed.";
	return (out);
}


// Exceptions
char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form::GradeTooHighException");
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form::GradeTooLowException");
}

char const	*Form::NotAlreadySigned::what(void) const throw()
{
	return ("Form::NotAlreadySigned");
}


// Getters
std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::isSigned(void) const
{
	return (this->_signed);
}

int	Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

int	Form::getGradeToExec(void) const
{
	return (this->_grade_to_exec);
}


// Body
void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_grade_to_sign)
		this->_signed = true;
	else
		throw (Form::GradeTooLowException());
}

void	Form::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw (Form::NotAlreadySigned());
	if (executor.getGrade() > this->getGradeToExec())
		throw (Form::GradeTooLowException());

	this->beExecuted(executor);
}
