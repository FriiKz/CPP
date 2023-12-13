/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:15:25 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/13 20:05:52 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "---BASIC USAGE TEST---" << std::endl;
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---TEST WITH TOO MANY ELEMENTS---" << std::endl;
	Span sp2 = Span(4);
	try 
	{
        sp2.addNumber(6);
    	sp2.addNumber(3);
     	sp2.addNumber(17);
     	sp2.addNumber(9);
      	sp2.addNumber(11);
     	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
     	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
     } 
	 catch (std::exception & e) 
	 {
    	std::cerr << e.what() << std::endl;
     }
	 std::cout << "---TEST WITH TOO FEW ELEMENTS---" << std::endl;
	Span sp3 = Span(5);
	try 
	{
        sp3.addNumber(6);
     	std::cout << sp3.shortestSpan() << std::endl;
     	std::cout << sp3.longestSpan() << std::endl;
     } 
	 catch (std::exception & e) 
	 {
    	std::cerr << e.what() << std::endl;
     }
	return 0;
}