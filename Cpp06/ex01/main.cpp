/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:30:14 by lpupier           #+#    #+#             */
/*   Updated: 2023/09/19 10:22:17 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.Class/Serialization.hpp"

int main(void)
{	
	Serialization	serialization = Serialization();
	Data			data;
	Data			*new_data;
	uintptr_t		data_package;

	// Fill Data structure
	data.str = "Forty Two";
	data.i = 42;
	std::cout << "Data str: " << data.str << std::endl;
	std::cout << "Data int: " << data.i << std::endl;
	
	// Serialize the struct
	data_package = serialization.serialize(&data);
	std::cout << "\nData package: " << data_package << std::endl;

	// Deserialize the package
	new_data = serialization.deserialize(data_package);
	std::cout << "\nNew Data str: " << new_data->str << std::endl;
	std::cout << "New Data int: " << new_data->i << std::endl;

	// Adresses
	std::cout << "\nData adresse: " << &data << std::endl;
	std::cout << "New Data adresse: " << new_data << std::endl;
	return (0);
}
