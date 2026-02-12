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
static void	t_converts_multiples(void);

int	main(int argc , char **argv)
{

	t_double();
	t_int();
	t_float();
	t_numeric_limits();
	t_template();
	t_converts(argc, argv);
	t_converts_multiples();
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

static void	t_converts_multiples(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_converts_multiples" << std::endl;

	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "1 :\n";
	ScalarConverter::convert("1");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "-1 :\n";
	ScalarConverter::convert("-1");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "-1.0 :\n";
	ScalarConverter::convert("-1.0");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "1.0 :\n";
	ScalarConverter::convert("1.0");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "1.0f :\n";
	ScalarConverter::convert("1.0f");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "-1.0f :\n";
	ScalarConverter::convert("-1.0f");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "2147483647 :\n";
	ScalarConverter::convert("2147483647");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "-2147483648 :\n";
	ScalarConverter::convert("-2147483648");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "* :\n";
	ScalarConverter::convert("*");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "42 :\n";
	ScalarConverter::convert("42");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "inf :\n";
	ScalarConverter::convert("inf");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "-inf :\n";
	ScalarConverter::convert("-inf");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "-inff :\n";
	ScalarConverter::convert("-inff");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "NaN :\n";
	ScalarConverter::convert("NaN");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "nan :\n";
	ScalarConverter::convert("nan");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "-nan :\n";
	ScalarConverter::convert("-nan");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "nanf :\n";
	ScalarConverter::convert("nanf");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "vide : \"\"\n";
	ScalarConverter::convert("");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "FLOAT MAX: "<< std::numeric_limits<float>::max() << std::endl;
	ScalarConverter::convert("340282346638528859811704183484516925440");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "FLOAT MIN: "<< -std::numeric_limits<float>::max() << std::endl;
	ScalarConverter::convert("-340282346638528859811704183484516925440");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "DOUBLE MAX: "<< std::numeric_limits<double>::max() << std::endl;
	ScalarConverter::convert("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "DOUBLE MIN: "<< -std::numeric_limits<double>::max() << std::endl;
	ScalarConverter::convert("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368");
	std::cout << "--------------------------------------------------------\n" << std::endl;
	std::cout << "BEYOND DOUBLE MIN: "<< -std::numeric_limits<double>::max() << std::endl;
	ScalarConverter::convert("-1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583680000000000");
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
