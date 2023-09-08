/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/08 12:33:19 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>

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

class ShrubberyCreationForm: public Form {

private:

	std::string		_target;

public:

	// Init
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

	// Getters
	std::string	getTarget(void) const;

	// Body
	void		beExecuted(Bureaucrat const & executor) const;
	
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj);

#endif