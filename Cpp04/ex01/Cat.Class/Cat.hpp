/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:55:07 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/28 13:20:07 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "../Animal.Class/Animal.hpp"
# include "../Brain.Class/Brain.hpp"

class Cat: public Animal {

private:

	Brain*	_brain;

public:

	// Init
	Cat();
	Cat(const Cat &obj);
	virtual ~Cat(void);
	Cat &operator=(const Cat &obj);

	// Getters
	Brain	*getBrain(void) const;

	// Body
	void	makeSound(void) const;

};

#endif