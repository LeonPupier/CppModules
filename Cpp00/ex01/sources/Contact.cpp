/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:33:46 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/09 10:53:50 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::create(void)
{
	this->_first_name = this->_add_info("First Name");
	this->_last_name = this->_add_info("Last Name");
	this->_nickname = this->_add_info("Nickname");
	this->_phone_number = this->_add_info("Phone Number");
	this->_darkest_secret = this->_add_info("Darkest Secret");
}

std::string	Contact::_add_info(std::string text) const
{
	std::string	var;

	while (var.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
	{
		std::cout << text << ": ";
		std::getline(std::cin, var);
	}
	return (var);
}

void	Contact::display_resume(void) const
{
	std::cout << std::setw(10) << this->_format_info(this->_first_name) << "|";
	std::cout << std::setw(10) << this->_format_info(this->_last_name) << "|";
	std::cout << std::setw(10) << this->_format_info(this->_nickname) << "|";
	std::cout << std::endl;
}

std::string	Contact::_format_info(std::string info) const
{
	if (info.empty() == true)
		return ("N/A");
	if (info.size() >= 10)
		return (info.substr(0, 9) + '.');
	return (info);
}

void	Contact::display_all_infos(void) const
{
	if (this->_first_name.empty())
	{
		std::cout << "[WARNING] The selected contact does not exist..." << std::endl;
		return ;
	}

	std::cout << "[Information of the selected contact]" << std::endl;
	std::cout << "First Name: " << this->_first_name << std::endl;
	std::cout << "Last Name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->_darkest_secret << std::endl;
}
