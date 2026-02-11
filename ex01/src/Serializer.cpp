/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:04 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/11 09:59:43 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>
#include <stdint.h>

Serializer::Serializer (void)
{
	std::cout << "Serializer Default constructeur called\n";
}

Serializer::Serializer (const Serializer &)
{
	std::cout << "Serializer Copy constructeur called\n";
}

Serializer::Serializer (int)
{
	std::cout << "Serializer Copy constructeur called\n";
}

Serializer::~Serializer (void)
{
	std::cout << "Serializer Destructeur called\n";
}

Serializer& Serializer::operator= ( const Serializer &)
{
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	if (!ptr)
		return (0);
	uintptr_t	ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data*	ret = reinterpret_cast<Data*>(raw);
	if (!ret)
		return (NULL);
	return (ret);
}
