/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:19:19 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/09 10:51:17 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {

public:

	Contact(void);
	~Contact(void);

	void		create(void);
	void		display_resume(void) const;
	void		display_all_infos(void) const;

private:

	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

	std::string	_add_info(std::string text) const;
	std::string	_format_info(std::string info) const;
};

#endif
