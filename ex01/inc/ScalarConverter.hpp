/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:09 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/29 17:19:51 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>

class	ScalarConverter
{
	public:
		static void	convert(std::string	number);
		
	private:
		ScalarConverter	(void);
		ScalarConverter	(int);
		ScalarConverter	(const ScalarConverter &);
		~ScalarConverter (void);
		ScalarConverter& operator= ( const ScalarConverter &);
};

# endif
