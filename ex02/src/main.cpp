/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:09:26 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/11 11:38:18 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"

#include <iostream>

static void	t_generate(void);
static void t_identify_ptr(void);
static void t_identify_ref(void);

int	main(void)
{
	// t_generate();	
	t_identify_ptr();
	t_identify_ref();
	return (0);
}

static void	t_generate(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_generate" << std::endl;
	Base temp;
	Base* ptr;

	ptr = temp.generate();
	delete ptr;
}

static void t_identify_ptr(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_identify ptr" << std::endl;
	Base temp;
	Base* ptr;

	ptr = temp.generate();
	temp.identify(ptr);
	delete ptr;
}

static void t_identify_ref(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_identify ref" << std::endl;
	// Base* temp;
	// Base temp1;
	A	a;

	// temp = temp1.generate();
	// temp->identify(*temp);
	a.identify(a);
	// delete temp;
}
