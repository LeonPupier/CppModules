/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:41:20 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/28 13:21:25 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "../Animal.Class/Animal.hpp"
# include "../Brain.Class/Brain.hpp"

class Dog: public Animal {

private:

	Brain*	_brain;

public:

	// Init
	Dog();
	Dog(const Dog &obj);
	virtual ~Dog(void);
	Dog &operator=(const Dog &obj);

	// Getters
	Brain	*getBrain(void) const;

	// Body
	void	makeSound(void) const;

};

#endif