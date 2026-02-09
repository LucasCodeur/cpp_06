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
#include <cmath>

ScalarConverter::ScalarConverter (void)
{
	// std::cout << "ScalarConverter Default constructeur called\n";
	return ;
}

ScalarConverter::ScalarConverter (const ScalarConverter &other)
{
	static_cast <void>(other);
	// std::cout << "ScalarConverter Copy constructeur called\n";
	return ;
}

ScalarConverter::ScalarConverter (int parameters)
{
	static_cast <void>(parameters);
	// std::cout << "ScalarConverter Copy constructeur called\n";
	return ;
}

ScalarConverter::~ScalarConverter (void)
{
	// std::cout << "ScalarConverter Destructeur called\n";
	return ;
}


ScalarConverter& ScalarConverter::operator= ( const ScalarConverter &other)
{
	static_cast<void>(other);
	return (*this);
}


bool ScalarConverter::isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();

	if (*it == '-')
		++it;
    while (it != s.end() && std::isdigit(*it)) 
		++it;
    return (!s.empty() && it == s.end());
}

void		ScalarConverter::trimZero(std::string& number)
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

type	ScalarConverter::detectType(std::string number)
{
	type	ret;
	int	i;
	
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
		if (isNumber(number) == true)
			ret = INT;
		else if (number.length() < 2 && !std::isdigit(number.c_str()[0]))
			ret = CHAR;
	}
	return (ret);
}

int	ScalarConverter::setDisplay(std::string& number)
{
	int	nb_of_decs = 0;

	trimZero(number);
	
	size_t	 i = number.find(".");
	short int integer_part = i;
	if (number[0] == '-')
		integer_part--;
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

void	ScalarConverter::printDouble(long double double_number, std::string&number, int nb_of_decs)
{
	long double		float_number;
	long long		int_number;
	char			char_number;

	int_number = static_cast<int>(double_number);
	char_number = static_cast<char>(double_number);	
	float_number = static_cast<float>(double_number);	

	std::cout << "char: ";
	if (int_number < 33 || number.length() > 1)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;
	std::cout << "int: ";
	if (int_number >= std::numeric_limits<int>::max() || int_number <= std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_number << std::endl;
	if ((float_number > -1 && float_number >= std::numeric_limits<float>::max()) || (float_number < 0 && std::numeric_limits<float>::min() <= float_number))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::showpoint << std::setprecision(nb_of_decs) << float_number << "f" << std::endl;
	if ((double_number > -1 && double_number >= std::numeric_limits<double>::max()) || (double_number < 0 && std::numeric_limits<double>::min() <= double_number))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: "<< std::showpoint << std::setprecision(nb_of_decs) << double_number << std::endl;


}

void	ScalarConverter::printFromDouble(std::string number)
{
	long double	double_number;	
	int		nb_of_decs;				
	
	std::string::reverse_iterator rit = number.rbegin();
	if (*rit == '.')
		number += '0';

	std::stringstream	ss(number);

	ss >> double_number;
	nb_of_decs = this->setDisplay(number);
	this->printDouble(double_number, number, nb_of_decs);
}

void	ScalarConverter::printFloat(long double float_number, std::string&number, int nb_of_decs)
{

	long double	double_number;
	long long	int_number;
	char		char_number;

	int_number = static_cast<int>(float_number);
	char_number = static_cast<char>(float_number);	
	double_number = static_cast<float>(float_number);	
	std::cout << "char: ";
	if (int_number < 33 || number.length() > 1)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;
	std::cout << "int: ";
	if (int_number >= std::numeric_limits<int>::max() || int_number <= std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_number << std::endl;
	if ((float_number > -1 && float_number >= std::numeric_limits<float>::max()) || (float_number < 0 && std::numeric_limits<float>::min() <= float_number))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::showpoint << std::setprecision(nb_of_decs) << float_number << "f" << std::endl;
	if ((double_number > -1 && double_number >= std::numeric_limits<double>::max()) || (double_number < 0 && std::numeric_limits<double>::min() <= double_number))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: "<< std::showpoint << std::setprecision(nb_of_decs) << double_number << std::endl;


}

void	ScalarConverter::printFromFloat(std::string number)
{
	long double	float_number;
	int		nb_of_decs;				

	std::string::reverse_iterator rit = number.rbegin();
	if (*rit == '.')
		number += '0';

	std::stringstream	ss(number);

	ss >> float_number;
	nb_of_decs = this->setDisplay(number);
	this->printFloat(float_number, number, nb_of_decs);
}

void	ScalarConverter::printInt(long int int_number, std::string&number, int nb_of_decs, bool check_nan)
{
	long double	double_number;	
	long double	float_number;
	char		char_number;

	float_number = static_cast<float>(int_number);
	double_number = static_cast<double>(int_number);	
	char_number = static_cast<char>(int_number);	
		
	std::cout << "char: ";
	if (check_nan == true)
		std::cout << "impossible" << std::endl;
	else if (int_number < 33 || number.length() > 1)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;
	std::cout << "int: ";
	if (int_number >= std::numeric_limits<int>::max() || int_number <= std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else if (check_nan == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_number << std::endl;
	if ((float_number > -1 && float_number >= std::numeric_limits<float>::max()) || (float_number < 0 && std::numeric_limits<float>::min() <= float_number))
		std::cout << "float: impossible" << std::endl;
	else if (check_nan == true)
		std::cout << "float: nanf" << std::endl;
	else
		std::cout << "float: " << std::showpoint << std::setprecision(nb_of_decs) << float_number << "f" << std::endl;
	if ((double_number > -1 && double_number >= std::numeric_limits<double>::max()) || (double_number < 0 && std::numeric_limits<double>::min() <= double_number))
		std::cout << "double: impossible" << std::endl;
	else if (check_nan == true)
		std::cout << "double: nan" << std::endl;
	else
		std::cout << "double: "<< std::showpoint << std::setprecision(nb_of_decs) << double_number << std::endl;
}

void	ScalarConverter::printFromInt(std::string number)
{
	long long		int_number = 0;
	short int		nb_of_decs = 0;
	bool			check_nan = false;	
	std::stringstream	ss(number);

	if (number == "nan")
		check_nan = true;
	else
	{
		check_nan = std::isnan(int_number);
		ss >> int_number;
	}
	if (check_nan == false && number.length() > 6)
	{
		std::ios_base::fmtflags ff;
		ff = std::cout.flags();
		ff |= std::cout.scientific;
		std::cout.flags(ff);
	}
	nb_of_decs = number.length();
	if (int_number > 0)
		nb_of_decs++;
	this->printInt(int_number, number, nb_of_decs, check_nan);
}

void	ScalarConverter::printChar(char char_number , std::string&number)
{
	long double	double_number;	
	long double	float_number;
	long int	int_number;


	int_number = static_cast<int>(char_number);
	float_number = static_cast<float>(int_number);
	double_number = static_cast<double>(int_number);	

	std::cout << "char: ";
	if (int_number < 33 || number.length() > 1)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;
	std::cout << "int: ";
	if (int_number >= std::numeric_limits<int>::max() || int_number <= std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_number << std::endl;
	if ((float_number > -1 && float_number >= std::numeric_limits<float>::max()) || (float_number < 0 && std::numeric_limits<float>::min() <= float_number))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::showpoint << std::setprecision(2) << float_number << "0f" << std::endl;
	if ((double_number > -1 && double_number >= std::numeric_limits<double>::max()) || (double_number < 0 && std::numeric_limits<double>::min() <= double_number))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: "<< std::showpoint << std::setprecision(2) << double_number << "0" << std::endl;
}

void	ScalarConverter::printFromChar(std::string number)
{

	char			char_number;
	std::stringstream	ss(number);

	ss >> char_number;
	this->printChar(char_number, number);
}

bool	ScalarConverter::parsing(std::string& number)
{
	if (number == "nan")
		return (true);
	size_t	 j = number.find(".");
	if (number[0] == '.' || number[j + 1] == '\0')
		return (false);
	if (number[j] == '.' && !std::isdigit(number[j + 1]))
		return (false);
	j = 0;
	while (number[j] != 'f' && number[j])
		j++;
	if (number[j] == 'f' && number[j + 1] != '\0')
		return (false);
	for (int i = 0; number[i] != '\0'; i++)
	{
		if (std::isspace(number[i]))
			return (false);
	}
	return (true);
}


void	ScalarConverter::convert(std::string number)
{
	type		ret;
	ScalarConverter	temp;


	if (temp.parsing(number) == false)
	{
		std::cout << "wrong arguments" << std::endl;
		return ;
	}
	if (number == "nan")
	{
		temp.printFromInt(number);
		return ;
	}
	ret = temp.detectType(number);
	if (ret == DOUBLE)
		temp.printFromDouble(number);
	else if (ret == FLOAT)
		temp.printFromFloat(number);
	else if (ret == INT)
		temp.printFromInt(number);
	else if (ret == CHAR)
		temp.printFromChar(number);
}

template	<typename T> T print(T number_to_convert, std::string&number, int nb_of_decs)
{
	long double	double_number;	
	long double	float_number;
	char		char_number;

	float_number = static_cast<float>(number_to_convert);
	double_number = static_cast<double>(number_to_convert);	
	char_number = static_cast<char>(number_to_convert);	
		
	std::cout << "char: ";
	if (check_nan == true)
		std::cout << "impossible" << std::endl;
	else if (int_number < 33 || number.length() > 1)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << char_number << std::endl;
	std::cout << "int: ";
	if (int_number >= std::numeric_limits<int>::max() || int_number <= std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else if (check_nan == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << int_number << std::endl;
	if ((float_number > -1 && float_number >= std::numeric_limits<float>::max()) || (float_number < 0 && std::numeric_limits<float>::min() <= float_number))
		std::cout << "float: impossible" << std::endl;
	else if (check_nan == true)
		std::cout << "float: nanf" << std::endl;
	else
		std::cout << "float: " << std::showpoint << std::setprecision(nb_of_decs) << float_number << "f" << std::endl;
	if ((double_number > -1 && double_number >= std::numeric_limits<double>::max()) || (double_number < 0 && std::numeric_limits<double>::min() <= double_number))
		std::cout << "double: impossible" << std::endl;
	else if (check_nan == true)
		std::cout << "double: nan" << std::endl;
	else
		std::cout << "double: "<< std::showpoint << std::setprecision(nb_of_decs) << double_number << std::endl;
}

