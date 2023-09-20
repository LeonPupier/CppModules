/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 08:27:16 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/20 15:10:50 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

class Span {

private:

	std::list<int>	_lst;
	unsigned int	_N;

public:

	// Init
	Span();
	Span(unsigned int N);
	Span(const Span &obj);
	~Span(void);
	Span &operator=(const Span &obj);

	// Body
	void	addNumber(int number);
	void	addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end);
	int		shortestSpan();
	int		longestSpan();

};

#endif