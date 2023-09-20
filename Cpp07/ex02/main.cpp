/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:05:31 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/20 10:25:26 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.Class/Array.hpp>

template <typename T>
void printArray(Array<T> &a)
{
	std::cout << "[";
    for (unsigned int i = 0; i < a.size(); i++)
    {
        if (i != a.size() - 1)
            std::cout << a[i] << ", ";
        else
            std::cout << a[i];
    }
    std::cout << "]" << std::endl;
}

int main(void)
{
	{
		std::cout << BLUE << "------- EMPTY ARRAY -------\n" << WHITE << std::endl;
		Array<int> empty;
		std::cout << "Empty: ";
		printArray(empty);
	}
	{
		std::cout << BLUE << "\n------- INT ARRAY -------\n" << WHITE << std::endl;
		Array<int> a(10);
		for (int i(0); i < 10; i++)
			a[i] = i;
		std::cout << "Int: ";
		printArray(a);
	}
	{
		std::cout << BLUE << "\n------- STRING ARRAY -------\n" << WHITE << std::endl;
		Array<std::string> a(10);
		for (int i(0); i < 10; i++)
			a[i] = "gtr";
		std::cout << "String: ";
		printArray(a);
	}
	{
		std::cout << BLUE << "\n------- COPY & ASSIGNEMENT ARRAY -------\n" << WHITE << std::endl;
		Array<std::string> a(10);
		for (int i(0); i < 10; i++)
			a[i] = "gtr";
		Array<std::string> b(a);
		b[5] = "nissan";
		Array<std::string> c = b;
		c[6] = "porsche";
		std::cout << "String a: ";
		printArray(a);
		std::cout << "String b: ";
		printArray(b);
		std::cout << "String c: ";
		printArray(c);
	}
	{
		std::cout << BLUE << "\n------- CATCH EXCEPTION -------\n" << WHITE << std::endl;
		try
		{
			Array<std::string> a(10);
			for (int i(0); i < 11; i++)
				a[i] = "gtr";
			std::cout << "String: ";
			printArray(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
