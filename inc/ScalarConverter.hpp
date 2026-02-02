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

class	ScalarConverter
{
	public:
		ScalarConverter	(void);
		// ScalarConverter	(//Parameters);
		ScalarConverter	(const ScalarConverter &other);
		~ScalarConverter (void);
		ScalarConverter& operator= ( const ScalarConverter &other);
	private:

};

# endif
