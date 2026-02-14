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
#include <iomanip>
#include <cmath>

#include <stdlib.h>

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

static bool	parsing(std::string& number)
{
	int	size = number.length();

	if (size == 1)
		return (true);
	if (number == "nan" || number == "nanf" || number == "inf" || number == "inff" || number == "-inff" || number == "-inf" || number == "+inf" || number == "+inff" || number == "NaN")
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

static bool isNumber(const std::string& s)
{

	if (s.empty())
		return (false);
	std::string::const_iterator it = s.begin();

	if (*it == '-')
		++it;
	while (it != s.end() && std::isdigit(*it)) 
		++it;
	return (it == s.end());
}

static type	detectType(std::string& number)
{
	type	ret = NUL;
	size_t	i = 0;
	
	if (number == "nan"  || number == "inf" || number == "-inf" || number == "+inf" || number == "NaN")
		return (DOUBLE);
	else if (number == "nanf" || number == "inff" || number == "-inff" || number == "+inff")
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

template <typename T> T strConvert(std::string& number, bool* check_inf, bool* check_nan)
{
	T	number_convert = 0;
	
	if (number.length() > 1 || isdigit(number[0]))
	{
		char*	end = NULL;
		number_convert = std::strtod(number.c_str(), &end);
	}
	else
		number_convert = static_cast<char>(number[0]);
	if (number == "inf" || number == "inff" || number == "+inf" || number == "+inff" || number == "-inf" || number == "-inff")
		*check_inf = true;
	else if (number == "nan" || number == "nanf" || number == "NaN")
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

template <typename T> static void check_inf_and_nan(T number, bool *check_nan, bool *check_inf)
{
	if  (check_nan == false)
		*check_nan = std::isnan(number);
	else if (check_inf == false)
		*check_inf = std::isinf(number);
}

template <typename T> static void print(T number, std::string& strNumber,  bool& check_inf, bool& check_nan, short int nb_of_decs)
{
	float		float_number = 0;
	long long	int_number = 0;
	char		char_number = 0;

	int_number = static_cast<long>(number);
	char_number = static_cast<char>(int_number);
	float_number = static_cast<float>(number);

	std::cout << "char: ";
	if (check_nan == true || check_inf == true)
		std::cout << "impossible" << std::endl;
	else if (int_number  < 33 || int_number > 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;

	std::cout << "int: ";
	if (int_number > std::numeric_limits<int>::max() || int_number < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else if (check_nan == true || check_inf == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_number << std::endl;

	std::cout << "float: ";
	check_inf_and_nan(float_number, &check_nan, &check_inf);
	if (check_nan == true)
		std::cout << "nanf" << std::endl;
	else if (check_inf == true)
	{
		std::string res = (strNumber[0] == '-') ? "-inff" : "inff";
		std::cout << res << std::endl;
	}
	else
		std::cout << std::fixed << std::showpoint << std::setprecision(nb_of_decs) << float_number << "f" << std::endl;

	std::cout << "double: ";
	check_inf_and_nan(number, &check_nan, &check_inf);
	if (check_nan == true)
		std::cout << "nan" << std::endl;
	else if (check_inf == true)
	{
		std::string res = (strNumber[0] == '-') ? "-inf" : "inf";
		std::cout << res << std::endl;
	}
	else
		std::cout << std::fixed << std::showpoint << std::setprecision(nb_of_decs) << number << std::endl;
}

static void	printFromFloating(std::string& number)
{
	double		double_number = 0;
	int		nb_of_decs = 0;
	bool		check_inf = false;
	bool		check_nan = false;

	nb_of_decs = setDisplay(number);
	double_number = strConvert<double>(number, &check_inf, &check_nan);
	print(double_number, number, check_inf, check_nan, nb_of_decs);
}

static void	printFromInt(std::string& number)
{
	double		double_number = 0;
	bool		check_nan = false;
	bool		check_inf = false;

	double_number = strConvert<double>(number, &check_inf, &check_nan);
	print(double_number, number, check_inf, check_nan, 1);
}

static void	printFromChar(std::string& number)
{
	int	int_number = 0;
	bool	check_inf = false; 
	bool	check_nan = false; 
	
	int_number = strConvert<int>(number, &check_inf, &check_nan);
	print(int_number, number, check_inf, check_nan, 1);
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
		printFromFloating(number);
	else if (ret == FLOAT)
		printFromFloating(number);
	else if (ret == INT)
		printFromInt(number);
	else if (ret == CHAR)
		printFromChar(number);
}
