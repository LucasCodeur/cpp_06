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
#include <ios>
#include <iomanip>
#include <cmath>

enum type { INT, FLOAT, DOUBLE, CHAR, NUL };

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

static bool isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();

	if (*it == '-')
		++it;
    while (it != s.end() && std::isdigit(*it)) 
		++it;
    return (!s.empty() && it == s.end());
}

static void	trimZero(std::string& number)
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

static bool	parsing(std::string& number)
{
	int	size = number.length();

	if (size == 1)
		return (true);
	if (number == "nan" || number == "nanf" || number == "inf" || number == "inff" || number == "-inff" || number == "-inf")
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

static type	detectType(std::string& number)
{
	type	ret = NUL;
	size_t	i = 0;
	
	if (number == "nan"  || number == "inf" || number == "-inf")
		return (DOUBLE);
	else if (number == "nanf" || number == "inff" || number == "-inff")
		return (FLOAT);
	i = number.find(".");
	if (i != std::string::npos && number.c_str()[i] == '.')
	{
		i = number.rfind("f");
		if (i != std::string::npos && number.c_str()[i] != 'f')
			ret = DOUBLE;
		else
			ret = FLOAT;
	}
	else
	{
		if (isNumber(number) == true)
			ret = INT;
		else if (number.length() < 2 && !std::isdigit(number.c_str()[0]))
			ret = CHAR;
	}
	return (ret);
}

static int	setDisplay(std::string& number)
{
	int	nb_of_decs = 0;

	trimZero(number);
	
	size_t	 i = number.find(".");
	if (i++ != std::string::npos)
	{
		while (number[i] != '\0' && number[i] != 'f')
		{
			nb_of_decs++;
			i++;
		}
	}
	return (nb_of_decs);
}

void print(std::string&number, int nb_of_decs, bool check_nan, bool check_inf)
{
	double			number_to_convert = 0;	
	long double		float_number = 0;
	long int		int_number = 0;
	char			char_number = 0;
	std::stringstream	ss(number);


	if (number.length() > 1 || isdigit(number[0]))
	{
		ss >> number_to_convert;
		if (ss.fail() || (!ss.eof() && number[number.length() - 1] != 'f'))
			check_inf = true;
	}
	else
		number_to_convert = number[0];	

	float_number = static_cast<float>(number_to_convert);
	char_number = static_cast<char>(number_to_convert);	
	int_number = static_cast<int>(number_to_convert);	
		
	std::cout << "char: ";
	if (check_nan == true || check_inf == true)
		std::cout << "impossible" << std::endl;
	else if (int_number < 33 || number.length() > 1)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;

	std::cout << "int: ";
	if (number_to_convert >= std::numeric_limits<int>::max() || number_to_convert <= std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else if (check_nan == true || check_inf == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_number << std::endl;

	if (check_nan == true)
		std::cout << "float: nanf" << std::endl;
	else if (check_inf == true)
	{
		std::string res = (number[0] == '-') ? "-inff" : "inff";
		std::cout << "float: " << res << std::endl;
	}
	else if ((number_to_convert > -1 && number_to_convert >= std::numeric_limits<float>::max()) || (number_to_convert < 0 && std::numeric_limits<float>::min() <= number_to_convert))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(nb_of_decs) << float_number << "f" << std::endl;
	
	if (check_nan == true)
		std::cout << "double: nan" << std::endl;
	else if (check_inf == true)
	{
		std::string res = (number[0] == '-') ? "-inf" : "inf";
		std::cout << "double: " << res << std::endl;
	}
	else if ((number_to_convert > -1 && number_to_convert >= std::numeric_limits<double>::max()) || (number_to_convert < 0 && std::numeric_limits<double>::min() <= number_to_convert))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: "<< std::fixed << std::showpoint << std::setprecision(nb_of_decs) << number_to_convert << std::endl;
}

static void	printFromDouble(std::string& number)
{
	bool		check_nan = false;
	bool		check_inf = false;
	long double	double_number = 0;	
	int		nb_of_decs = 0;
	
	std::string::reverse_iterator rit = number.rbegin();
	if (*rit == '.')
		number += '0';

	if (number == "nan" || number == "nanf")
		check_nan = true;
	else
		check_nan = std::isnan(double_number);
	if (number == "inf" || number == "inff")
		check_inf = true;
	nb_of_decs = setDisplay(number);
	print(number, nb_of_decs, check_nan, check_inf);
}

static void	printFromFloat(std::string& number)
{
	long double	float_number = 0;
	int		nb_of_decs = 0;
	bool		check_inf = false;
	bool		check_nan = false;

	std::string::reverse_iterator rit = number.rbegin();
	if (*rit == '.')
		number += '0';

	std::stringstream	ss(number);

	ss >> float_number;
	if (number == "nan" || number == "nanf")
		check_nan = true;
	if (number == "inf" || number == "inff")
		check_inf = true;
	nb_of_decs = setDisplay(number);
	print(number, nb_of_decs, check_nan, check_inf);
}

static void	printFromInt(std::string& number)
{
	long long		int_number = 0;
	bool			check_nan = false;
	bool			check_inf = false;
	std::stringstream	ss(number);


	ss >> int_number;
	if (number == "nan" || number == "nanf")
		check_nan = true;
	else
		check_nan = std::isnan(int_number);
	if (number == "inf" || number == "inff")
		check_inf = true;
	else
		check_inf = std::isinf(int_number);
	print(number, 1, check_nan, check_inf);
}

static void	printFromChar(std::string& number)
{
	char			char_number = 0;
	bool			check_nan = false;
	bool			check_inf = false;
	std::stringstream	ss(number);	
	
	ss >> char_number;
	if (number == "nan" || number == "nanf")
		check_nan = true;
	else
		check_nan = std::isnan(char_number);
	if (number == "inf" || number == "inff")
		check_inf = true;
	else
		check_inf = std::isinf(char_number);
	print(number, 1, check_nan, check_inf);
}

void	ScalarConverter::convert(std::string number)
{
	type		ret = NUL;

	if (parsing(number) == false)
	{
		std::cout << "wrong arguments" << std::endl;
		return ;
	}
	ret = detectType(number);
	if (ret == DOUBLE)
	{
		std::cout << "double" << std::endl;
		printFromDouble(number);
	}
	else if (ret == FLOAT)
	{
		std::cout << "float" << std::endl;
		printFromFloat(number);
	}
	else if (ret == INT)
	{
		std::cout << "int" << std::endl;
		printFromInt(number);
	}
	else if (ret == CHAR)
	{
		std::cout << "char" << std::endl;
		printFromChar(number);
	}
}
