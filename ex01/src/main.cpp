/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:09:26 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/11 10:08:38 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <stdint.h>
#include <iostream>

int	main(void)
{
	Data	data;
	Data*	ptr = &data;
	Data*	newDataPtr = NULL;
	uintptr_t	newPtr = 0;
		
	data.nb = 42;
	data.nb2 = 43;
	newPtr = Serializer::serialize(ptr);
	std::cout << "data ptr :" << ptr << std::endl;
	std::cout << "uintptr_t newPtr :" << newPtr << std::endl;
	newDataPtr = Serializer::deserialize(newPtr);
	std::cout << "newDataPtr :" << newDataPtr << std::endl;
	return (0);
}
