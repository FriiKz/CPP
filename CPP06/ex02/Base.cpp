/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:15:15 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/11 19:00:07 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base::~Base()
{
	return;
}
Base *generate(void)
{
	int	i = std::rand() % 3;

	switch(i)
	{
		case 0:
				std::cout << "A has been instanciated" << std::endl;
				return (new A());
		case 1:
				std::cout << "B has been instanciated" << std::endl;
				return (new B());
		case 2:
				std::cout << "C has been instanciated" << std::endl;
				return (new C());
	}
	return (0);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type: C" << std::endl;
	else
		std::cout << "Something went wrong..." << std::endl;
}

void identify(Base &p)
{
	try 
	{
		(void) dynamic_cast<A&>(p);
        std::cout << "type: A" << std::endl;
		return;
	}
	catch (std::exception& e) {};
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "type: B" << std::endl;
		return;
	}
	catch(std::exception& e) {};
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "type: C" << std::endl;
		return ;
	}
	catch (std::exception& e) {};
	std::cout << "Something went wrong..." << std::endl;
}