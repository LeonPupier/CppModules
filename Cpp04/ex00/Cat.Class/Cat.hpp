/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:55:07 by lpupier           #+#    #+#             */
/*   Updated: 2023/08/21 15:59:25 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "../Animal.Class/Animal.hpp"

class Cat: public Animal {

public:

	// Init
	Cat();
	Cat(const Cat &obj);
	virtual ~Cat(void);
	Cat &operator=(const Cat &obj);

	// Body
	void	makeSound(void) const;

};

#endif