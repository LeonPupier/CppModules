/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:33:48 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/09 10:50:53 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_nb_contact = 0;
	this->_oldest_contact = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	Contact	new_contact;

	new_contact.create();
	if (this->_nb_contact >= 8)
		this->_nb_contact = 0;
	this->_contacts[this->_nb_contact] = new_contact;
	this->_nb_contact++;
}

void	PhoneBook::search(void) const
{
	std::string	desired_contact;

	for (int idx = 0; idx < 8; idx++)
	{
		std::cout << std::setw(10) << idx << "|";
		this->_contacts[idx].display_resume();
	}

	std::cout << "Enter index of the desired contact: ";
	std::getline(std::cin, desired_contact);
	if (desired_contact[0] >= '0' && desired_contact[0] <= '7' && desired_contact.size() == 1)
		this->_contacts[desired_contact[0] - 48].display_all_infos();
	else
		std::cout << "[WARNING] Invalid index, please try again..." << std::endl;
}
