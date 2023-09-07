/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/07 15:20:31 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

# include "../Bureaucrat.Class/Bureaucrat.hpp"

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

class Bureaucrat;

class Form {

private:

	const std::string	_name;
	bool				_signed;
	const int			_grade_to_sign;
	const int			_grade_to_exec;

public:

	// Init
	Form(std::string type, int grade_sign, int grade_exec);
	Form(const Form &obj);
	virtual ~Form(void);
	Form &operator=(const Form &obj);

	// Exceptions
	class	GradeTooHighException: public std::exception {
		public:
			virtual char const	*what(void) const throw();
	};
	
	class	GradeTooLowException: public std::exception {
		public:
			virtual char const	*what(void) const throw();
	};

	class	NotAlreadySigned: public std::exception {
		public:
			virtual char const	*what(void) const throw();
	};

	// Getters
	std::string		getName(void) const;
	bool			isSigned(void) const;
	int				getGradeToSign(void) const;
	int				getGradeToExec(void) const;

	// Body
	void			beSigned(Bureaucrat const &bureaucrat);
	void			execute(Bureaucrat const & executor) const;
	virtual void	beExecuted(Bureaucrat const &bureaucrat) const = 0;

};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif