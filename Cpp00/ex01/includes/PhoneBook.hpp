/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:57:50 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/09 10:45:39 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(void) const;

private:

	Contact	_contacts[8];
	int		_nb_contact;
	int		_oldest_contact;

};

#endif