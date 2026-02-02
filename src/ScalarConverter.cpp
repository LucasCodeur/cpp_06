/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:04 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/29 17:28:15 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter (void)
{
	std::cout << "ScalarConverter Default constructeur called\n";
}

ScalarConverter::ScalarConverter (const ScalarConverter &other)
{
	static_cast <void>(other);
	std::cout << "ScalarConverter Copy constructeur called\n";
}

ScalarConverter::~ScalarConverter (void)
{
	std::cout << "ScalarConverter Destructeur called\n";
}

ScalarConverter::ScalarConverter& operator= ( const ScalarConverter &other)
{
	static_cast <void>(other);
	std::cout << "ScalarConverter Operator = called\n";
}
