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

enum type { INT, FLOAT, DOUBLE, CHAR, NUL };

class	ScalarConverter
{
	public:
		ScalarConverter	(void);
		// ScalarConverter	(//Parameters);
		ScalarConverter	(const ScalarConverter &other);
		~ScalarConverter (void);
		ScalarConverter& operator= ( const ScalarConverter &other);

		void		print(void);
		int			set_display(std::string& number);
		void		trim_zero(std::string& number);
		bool		is_number(const std::string& s);
		type		detect_type(std::string number);
		void		printFromDouble(std::string number);
		void		printFromInt(std::string number);
		void		printFromFloat(std::string number);
		void		printFromChar(std::string number);
		static void	convert(std::string	number);
		
	private:

};

# endif
