/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:49:07 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/20 09:40:30 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

// TEST CLASS FROM THE SUBJECT
class Awesome {

public:
	Awesome(void): _n(42) {return ;}
	int get(void) const {return this->_n;}

private:
	int	_n;
};

std::ostream & operator<<(std::ostream & o, Awesome const & rhs)
{
	o << rhs.get();
	return o;
}

// PRINT FUNCTION
template<typename Z>
void	print(Z const & x)
{
	std::cout << x <<std::endl;
	return ;
}

// ITER FUNCTION
template <typename T>
void	iter(T *array, size_t length, void (*function)(T const &))
{
	size_t	i;

	for (i = 0; i < length; i++)
		function(array[i]);
}

#endif