/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:55:07 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/21 13:07:56 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "../WrongAnimal.Class/WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

public:

	// Init
	WrongCat();
	WrongCat(const WrongCat &obj);
	~WrongCat(void);
	WrongCat &operator=(const WrongCat &obj);

	// Body
	void	makeSound(void) const;

};

#endif