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
		ScalarConverter	(int parameters);
		ScalarConverter	(const ScalarConverter &other);
		~ScalarConverter (void);
		ScalarConverter& operator= ( const ScalarConverter &other);

		type		detectType(std::string number);
		int			setDisplay(std::string& number);
		bool		parsing(std::string& number);
		bool		isNumber(const std::string& s);
		void		trimZero(std::string& number);
		template	<typename T> T print(T number_to_convert, std::string&number, int nb_of_decs);
		void		printFromDouble(std::string number);
		void		printDouble(long double double_number, std::string&number, int nb_of_decs);
		void		printFromInt(std::string number);
		void		printInt(long int int_number, std::string&number, int nb_of_decs, bool check_nan);
		void		printChar(char char_number, std::string&number);
		void		printFloat(long double float_number, std::string&number, int nb_of_decs);
		void		printFromFloat(std::string number);
		void		printFromChar(std::string number);
		static void	convert(std::string	number);
		
	private:
};

# endif
