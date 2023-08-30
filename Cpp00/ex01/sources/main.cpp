/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:33:53 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/09 08:47:58 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "[Welcome in my awesome PhoneBook]" << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, command);
		if (!command.compare("ADD"))
			phonebook.add();
		if (!command.compare("SEARCH"))
			phonebook.search();
		if (!command.compare("EXIT"))
			break;
	}
	return (0);
}
