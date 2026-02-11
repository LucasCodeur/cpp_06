/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:04 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/11 11:32:05 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
	
Base::~Base (void)
{
	std::cout << "Base Destructeur called\n";
}

Base * Base::generate(void)
{
	srand(time(0));
	int temp =  std::rand() % 3;
	if (temp == 0)
	{
		return (new A);
	}
	else if (temp == 1)
	{
		return (new B);
	}
	else if (temp == 2)
	{
		return (new C);
	}
	return (NULL);
}

void Base::identify(Base* p)
{
	A* ptrA;
	B* ptrB;
	C* ptrC;
	
	ptrA = dynamic_cast<A*>(p);
	if (ptrA)
		std::cout << "Base is A" << std::endl;
	ptrB = dynamic_cast<B*>(p);
	if (ptrB)
		std::cout << "Base is B" << std::endl;
	ptrC = dynamic_cast<C*>(p);
	if (ptrC)
		std::cout << "Base is C" << std::endl;
}

void Base::identify(Base& p)
{
	A* ptrA;
	B* ptrB;
	C* ptrC;
	
	ptrA = dynamic_cast<A*>(&p);
	if (ptrA)
		std::cout << "Base is A" << std::endl;
	ptrB = dynamic_cast<B*>(&p);
	if (ptrB)
		std::cout << "Base is B" << std::endl;
	ptrC = dynamic_cast<C*>(&p);
	if (ptrC)
		std::cout << "Base is C" << std::endl;
}
