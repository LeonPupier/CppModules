/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:41:20 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/21 15:59:30 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "../Animal.Class/Animal.hpp"

class Dog: public Animal {

public:

	// Init
	Dog();
	Dog(const Dog &obj);
	virtual ~Dog(void);
	Dog &operator=(const Dog &obj);

	// Body
	void	makeSound(void) const;

};

#endif