/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:04 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/10 18:00:48 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cctype>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter (void)
{
	std::cout << "ScalarConverter Default constructeur called\n";
}

ScalarConverter::ScalarConverter (const ScalarConverter &)
{
	std::cout << "ScalarConverter Copy constructeur called\n";
}

ScalarConverter::ScalarConverter (int)
{
	std::cout << "ScalarConverter Copy constructeur called\n";
}

ScalarConverter::~ScalarConverter (void)
{
	std::cout << "ScalarConverter Destructeur called\n";
}

ScalarConverter& ScalarConverter::operator= ( const ScalarConverter &)
{
	return (*this);
}

static bool	parsing(std::string& number)
{
	int	size = number.length();

	if (size == 1)
		return (true);
	if (number == "nan" || number == "nanf" || number == "inf" || number == "inff" || number == "-inff" || number == "-inf" || number == "+inf" || number == "+inff")
		return (true);

	size_t	 j = number.find(".");
	size_t	 k = number.rfind(".");

	if (j != k)
		return (false);
	if (number[0] == '.' || (j != std::string::npos && number[j + 1] == '\0'))
		return (false);
	if (j != std::string::npos && (number[j] == '.' && !std::isdigit(number[j + 1])))
		return (false);
	j = 0;
	while (number[j] != 'f' && number[j])
		j++;
	if (number[j] == 'f' && number[j + 1] != '\0')
		return (false);

	int	i = 0;

	while (number[i] && i != size - 1)
	{
		if (std::isspace(number[i]) || std::isalpha(number[i]))
			return (false);
		i++;
	}
	if (number[i] == 'f')
		return (true);
	else if (!std::isdigit(number[i]))
		return (false);
	return (true);
}


template <typename T> T strConvert(std::string& number, bool* check_inf, bool* check_nan)
{
	std::stringstream	ss(number);
	T			number_convert = 0;
	
	if (number.length() > 1 || isdigit(number[0]))
	{
		ss >> number_convert;
		if (ss.fail())
			*check_inf = true;
	}
	else
		number_convert = static_cast<char>(number[0]);
	if (number == "inf" || number == "inff" || number == "+inf" || number == "+inff")
		*check_inf = true;
	else if (number == "nan" || number == "nanf")
		*check_nan = true;
	return (number_convert);
}

static int	setDisplay(std::string& number)
{
	int	nb_of_decs = 0;

	size_t	 i = number.find(".");
	if (i++ != std::string::npos)
	{
		while (number[i] != '\0' && number[i] != 'f')
		{
			nb_of_decs++;
			i++;
		}
	}
	else
		nb_of_decs++;
	return (nb_of_decs);
}

static void	printFromDouble(std::string& number)
{
	bool		check_nan = false;
	bool		check_inf = false;
	double		double_number = 0;	
	int		nb_of_decs = 0;
	
	std::string::reverse_iterator rit = number.rbegin();
	if (*rit == '.')
		number += '0';

	double_number = strConvert<double>(number, &check_inf, &check_nan);
	nb_of_decs = setDisplay(number);

	if (check_nan == true)
		std::cout << "double: nan" << std::endl;
	else if (check_inf == true)
	{
		std::string res = (number[0] == '-') ? "-inf" : "+inf";
		std::cout << "double: " << res << std::endl;
	}
	else
		std::cout << "double: "<< std::fixed << std::showpoint << std::setprecision(nb_of_decs) << double_number << std::endl;
}

static void	printFromFloat(std::string& number)
{
	float		float_number = 0;
	int		nb_of_decs = 0;
	bool		check_inf = false;
	bool		check_nan = false;

	std::string::reverse_iterator rit = number.rbegin();
	if (*rit == '.')
		number += '0';

	float_number = strConvert<float>(number, &check_inf, &check_nan);
	nb_of_decs = setDisplay(number);

	if (check_nan == true)
		std::cout << "float: nanf" << std::endl;
	else if (check_inf == true)
	{
		std::string res = (number[0] == '-') ? "-inff" : "inff";
		std::cout << "float: " << res << std::endl;
	}
	else
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(nb_of_decs) << float_number << "f" << std::endl;

}

static void	printFromInt(std::string& number)
{
	long long		int_number = 0;
	bool			check_nan = false;
	bool			check_inf = false;

	int_number = strConvert<int>(number, &check_inf, &check_nan);

	std::cout << "int: ";
	if (int_number >= std::numeric_limits<int>::max() || int_number <= std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else if (check_nan == true || check_inf == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_number << std::endl;

}

static void	printFromChar(std::string& number)
{
	int		int_number = 0;
	unsigned char	char_number = 0;
	bool		check_inf = false; 
	bool		check_nan = false; 
	
	int_number = strConvert<int>(number, &check_inf, &check_nan);
	char_number = static_cast<char>(int_number);
	std::cout << "char: ";
	if (check_nan == true || check_inf == true)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(char_number))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;
}

void	ScalarConverter::convert(std::string number)
{
	if (parsing(number) == false)
	{
		std::cout << "wrong arguments" << std::endl;
		return ;
	}
	printFromChar(number);
	printFromInt(number);
	printFromFloat(number);
	printFromDouble(number);
}
