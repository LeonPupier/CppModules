/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/08 11:17:46 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

# include "ShrubberyCreationForm.Class/ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.Class/RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.Class/PresidentialPardonForm.hpp"

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

class Intern {

private:

	// Form creation
	Form	*_shrubbery_creation(std::string target) const;
	Form	*_robotomy_request(std::string target) const;
	Form	*_presidential_pardon(std::string target) const;

public:

	// Init
	Intern(void);
	Intern(const Intern &obj);
	~Intern(void);
	Intern &operator=(const Intern &obj);

	// Body
	Form	*makeForm(std::string name, std::string target) const;

};

std::ostream &operator<<(std::ostream &out, const Intern &obj);

#endif