/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:09:26 by lud-adam          #+#    #+#             */
/*   Updated: 2026/01/29 17:32:26 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <cmath> 

#include "ScalarConverter.hpp"

static void	t_converts(int argc, char **argv);
static void	t_numeric_limits(void);
static void	t_detectType(void);
static void	t_double(void);
static void	t_int(void);

int	main(int argc , char **argv)
{

	// t_double();
	// t_int();
	t_converts(argc, argv);
	// t_numeric_limits();
	// t_detectType();
	return (0);
}

static void	t_numeric_limits(void)
{
	// float	nb = 1.1f;
	// std::cout << std::numeric_limits<long double>::round_error() << std::endl;
	// std::cout << std::numeric_limits<float>::round_style << std::endl;
	// std::cout << std::numeric_limits<float>::min() << std::endl;
	// if  (std::numeric_limits<float>::min() > -2)
	// 	std::cout << "-2 is inferior\n";
	std::cout << std::numeric_limits<int>::quiet_NaN() << std::endl;
	std::cout << std::isnan(NAN) << std::endl;

}

static void	t_converts(int argc, char **argv)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_converts" << std::endl;
	if (argc != 2)
		return ;

	ScalarConverter	test;

	test.convert(argv[1]);
}

static void	t_double(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_double" << std::endl;
	//    std::ios_base::fmtflags ff;
	//    ff = std::cout.flags();
	//    ff |= std::cout.scientific;
	// std::cout.flags(ff);
	double	nb = .04;
	std::cout << nb << "\n";
}

static void	t_int(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_int" << std::endl;
	std::cout << 2147487649 << std::endl;
}

static void	t_detectType(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_detectType" << std::endl;
	ScalarConverter	test;
	type	ret;
	
	ret = test.detectType("1004");
	if (ret == INT)
		std::cout << "100400000000000000000000: INT" << std::endl;
	ret = test.detectType("100400000000000000000000");
	if (ret == INT)
		std::cout << "1004: INT" << std::endl;
	ret = test.detectType("-1");
	if (ret == INT)
		std::cout << "-1: INT" << std::endl;
	ret = test.detectType("1.0");
	if (ret == DOUBLE)
		std::cout << "1.0: DOUBLE" << std::endl;
	ret = test.detectType("10000000000000000.000000");
	if (ret == DOUBLE)
		std::cout << "10000000000000000.000000: DOUBLE" << std::endl;
	ret = test.detectType("-100000.123430");
	if (ret == DOUBLE)
		std::cout << "-100000.123430: DOUBLE" << std::endl;
	ret = test.detectType("1.0f");
	if (ret == FLOAT)
		std::cout << "1.0f: FLOAT" << std::endl;
	ret = test.detectType("1.00000000f");
	if (ret == FLOAT)
		std::cout << "1.00000000f: FLOAT" << std::endl;
	ret = test.detectType("1000000000000000000000.00000000f");
	if (ret == FLOAT)
		std::cout << "1000000000000000000000.00000000f: FLOAT" << std::endl;
	ret = test.detectType("-1.00000000f");
	if (ret == FLOAT)
		std::cout << "-1.00000000f: FLOAT" << std::endl;
	ret = test.detectType("1");
	if (ret == CHAR)
		std::cout << "1: CHAR" << std::endl;
	else
		std::cout << "1: NOT CHAR" << std::endl;
	ret = test.detectType("9");
	if (ret == CHAR)
		std::cout << "9: CHAR" << std::endl;
	else
		std::cout << "9: NOT CHAR" << std::endl;
	ret = test.detectType("a");
	if (ret == CHAR)
		std::cout << "a: CHAR" << std::endl;
	else
		std::cout << "a: NOT CHAR" << std::endl;
	ret = test.detectType("aa");
	if (ret == CHAR)
		std::cout << "aa: CHAR" << std::endl;
	else
		std::cout << "aa: NOT CHAR" << std::endl;
	ret = test.detectType("'");
	if (ret == CHAR)
		std::cout << "': CHAR" << std::endl;
	else
		std::cout << "': NOT CHAR" << std::endl;
}
