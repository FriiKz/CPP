/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:50:39 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/07 19:11:22 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat bureaucrat("Prot", 150);
	Bureaucrat bureaucrat2("Top", 1);
	Bureaucrat bureaucrat3;
	bureaucrat3 = bureaucrat2;
	Bureaucrat *bureaucrat4 = new Bureaucrat("New", 5);

	try
	{
		bureaucrat.decreaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		bureaucrat2.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		bureaucrat3.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << bureaucrat3;
	std::cout << bureaucrat2;

	try
	{
		bureaucrat4->decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat5("New", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete bureaucrat4;
}