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
static void	t_double(void);
static void	t_float(void);
static void	t_int(void);
static void	t_template(void);

int	main(int argc , char **argv)
{

	t_double();
	t_int();
	t_float();
	t_numeric_limits();
	t_template();
	t_converts(argc, argv);
	return (0);
}

static void	t_numeric_limits(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_numeric_limits" << std::endl;
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

	ScalarConverter::convert(argv[1]);
}

static void	t_double(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_double" << std::endl;
	//    std::ios_base::fmtflags ff;
	//    ff = std::cout.flags();
	//    ff |= std::cout.scientific;
	// std::cout.flags(ff);
	double	nb = INFINITY;
	std::cout << nb << "\n";
}

static void	t_float(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_float" << std::endl;
	//    std::ios_base::fmtflags ff;
	//    ff = std::cout.flags();
	//    ff |= std::cout.scientific;
	// std::cout.flags(ff);
	float	nb = NAN;
	std::cout << nb << "\n";
}

static void	t_int(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_int" << std::endl;
	std::cout << 2147487649 << std::endl;
}

#include <iostream>
template <typename T> T myMax(T x, T y){
		return (x > y) ? x : y;
}

static void	t_template(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_template" << std::endl;
	std::cout << "Max of 3 and 7 is: " << myMax<int>(3, 7) << std::endl;
	std::cout << "Max of 3.5 and 7.5 is :" << myMax<double>(3.5, 7.5) << std::endl;
}
