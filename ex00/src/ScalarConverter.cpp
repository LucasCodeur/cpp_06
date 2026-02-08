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

#include <cctype>
#include <limits>
#include <sstream>
#include <ios>
#include <iomanip>

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

// ScalarConverter::ScalarConverter& operator= ( const ScalarConverter &other)
// {
// 	static_cast <void>(other);
// 	std::cout << "ScalarConverter Operator = called\n";
// }


bool ScalarConverter::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();

	if (*it == '-')
		++it;
    while (it != s.end() && std::isdigit(*it)) 
		++it;
    return (!s.empty() && it == s.end());
}

void		ScalarConverter::trim_zero(std::string& number)
{
	int	i = 0;

	if (number[0] == '0')
	{
		while (number[i] != '.')
		{
			if (number[i] != '0')
				break ;
			i++;
		}
	}
	if (i != 0)
		number.erase(0, i);
}

type	ScalarConverter::detect_type(std::string number)
{
	type	ret;
	int		i;
	
	ret = NUL;
	i = number.find(".");
	if (number.c_str()[i] == '.')
	{
		i = number.rfind("f");
		if (number.c_str()[i] != 'f')
			ret = DOUBLE;
		else
			ret = FLOAT;
	}
	else
	{
		if (is_number(number) == true)
			ret = INT;
		else if (number.length() < 2 && !std::isdigit(number.c_str()[0]))
			ret = CHAR;
	}
	return (ret);
}

int		ScalarConverter::set_display(std::string& number)
{
	int	nb_of_decs = 0;

	trim_zero(number);
	
	size_t	 i = number.find(".");
	short int integer_part = i;
	if (i++ != std::string::npos)
	{
		while (number[i] != '\0' && number[i] != 'f')
		{
			nb_of_decs++;
			i++;
		}
	}
	nb_of_decs += integer_part;
	if (nb_of_decs > 6)
	{
		std::ios_base::fmtflags ff;
		ff = std::cout.flags();
		ff |= std::cout.scientific;
		std::cout.flags(ff);
	}
	return (nb_of_decs);
}

// void	ScalarConverter::print(void)
// {
//
// }

void	ScalarConverter::printFromDouble(std::string number)
{
	double	double_number;	
	float	float_number;
	char	char_number;
	int		int_number;
	int		nb_of_decs;				
	
	std::string::reverse_iterator rit = number.rbegin();
	if (*rit == '.')
		number += '0';
	std::stringstream	ss(number);

	ss >> double_number;
	int_number = static_cast<int>(double_number);
	char_number = static_cast<char>(double_number);	
	float_number = static_cast<float>(double_number);	

	nb_of_decs = set_display(number);

	std::cout << "char: ";
	if (int_number < 33 || number.length() > 1)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;
	std::cout << "int: ";
	std::cout << int_number << std::endl;
	std::cout << "float: " << std::showpoint << std::setprecision(nb_of_decs) << float_number << "f" << std::endl;
	std::cout << "double: "<< std::showpoint << std::setprecision(nb_of_decs) << double_number << std::endl;

}

void	ScalarConverter::printFromFloat(std::string number)
{
	double	double_number;	
	float	float_number;
	char	char_number;
	int		int_number;
	int		nb_of_decs;				
	
	std::string::reverse_iterator rit = number.rbegin();
	if (*rit == '.')
		number += '0';
	std::stringstream	ss(number);

	ss >> float_number;
	int_number = static_cast<int>(float_number);
	char_number = static_cast<char>(float_number);	
	double_number = static_cast<double>(float_number);	

	nb_of_decs = set_display(number);

	std::cout << "char: ";
	if (int_number < 33 || number.length() > 1)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;
	std::cout << "int: ";
	std::cout << int_number << std::endl;
	std::cout << "float: " << std::showpoint << std::setprecision(nb_of_decs) << float_number << "f" << std::endl;
	std::cout << "double: "<< std::showpoint << std::setprecision(nb_of_decs) << double_number << std::endl;

}

void	ScalarConverter::printFromInt(std::string number)
{
	double			double_number;	
	float			float_number;
	char			char_number;
	long long		int_number;
	
	std::stringstream	ss(number);

	ss >> int_number;
	float_number = static_cast<int>(int_number);
	double_number = static_cast<double>(int_number);	
	char_number = static_cast<char>(int_number);	

	set_display(number);
	std::cout << "char: ";
	if (int_number < 33 || number.length() > 1)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;
	std::cout << "int: ";
	if (int_number > std::numeric_limits<int>::max() || int_number < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_number << std::endl;
	std::cout << "float: " << std::showpoint << std::setprecision(0) << float_number << "0" << "f" << std::endl;
	std::cout << "double: "<< std::showpoint << std::setprecision(0) << double_number << "0" << std::endl;

}

void	ScalarConverter::printFromChar(std::string number)
{
	char				char_number;
	int					int_number;
	std::stringstream	ss(number);


	ss >> int_number;
	std::cout << "char: ";
	if (int_number < 33 || number.length() > 1)
		std::cout << "Non displayable" << std::endl;
	else
	{
		char_number = static_cast<char>(int_number);
		std::cout << char_number << std::endl;
	}
}


void	ScalarConverter::convert(std::string number)
{
	type			ret;
	ScalarConverter	temp;
	
	ret = temp.detect_type(number);
	if (ret == DOUBLE)
		temp.printFromDouble(number);
	else if (ret == FLOAT)
		temp.printFromFloat(number);
	else if (ret == INT)
		temp.printFromInt(number);
	// else if (ret == CHAR)
		// temp.printFromChar(number);
}
