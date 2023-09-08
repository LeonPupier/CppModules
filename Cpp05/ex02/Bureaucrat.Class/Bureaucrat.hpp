/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/08 13:29:56 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# include "../Form.Class/Form.hpp"

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

class Form;

class Bureaucrat {

private:

	std::string const	_name;
	int					_grade;

public:

	// Init
	Bureaucrat();
	Bureaucrat(std::string type, int grade);
	Bureaucrat(const Bureaucrat &obj);
	~Bureaucrat(void);
	Bureaucrat &operator=(const Bureaucrat &obj);

	// Exceptions
	class	GradeTooHighException: public std::exception {
		public:
			virtual char const	*what(void) const throw();
	};
	
	class	GradeTooLowException: public std::exception {
		public:
			virtual char const	*what(void) const throw();
	};

	// Getters
	std::string		getName(void) const;
	int				getGrade(void) const;

	// Body
	void			upperGrade(void);
	void			lowerGrade(void);
	void			signForm(Form &form);
	void			executeForm(Form &form);

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif