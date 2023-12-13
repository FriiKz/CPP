/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:29:55 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/13 19:55:00 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():_n(0)
{
	return;
}

Span::Span(unsigned int n): _n(n)
{
	return;
}

Span::Span(Span const &to_copy)
{
	*this = to_copy;
	return;
}

Span &Span::operator=(Span const &target)
{
	this->_n = target._n;
	return (*this);
}
Span::~Span()
{
	return;
}

void Span::addNumber(int n)
{
	if (_list.size() >= _n)
		throw  MaxCapacityReachedException();
	this->_list.push_back(n);
}

void Span::addNumber(int n, int n_times)
{
	try
	{
		for (int j = n; j <= n_times; j++)
			this->addNumber(j);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() <<std::endl;
	}
}

char const * Span::MaxCapacityReachedException::what() const throw()
{
	return ("Can't add any new element");
}

char const * Span::NotEnoughNumbersStoredException::what() const throw()
{
	return ("Too few elements for comparison");
}

int Span::shortestSpan()
{
	int shortest = INT_MAX;
	if (_list.size() < 2)
		throw NotEnoughNumbersStoredException();
	std::list<int>::iterator iter = this->_list.begin();
	for (unsigned int i = 0; i < this->_list.size(); i++)
	{
		std::list<int>::iterator tmp= iter;
		int tmp2 = *iter;
		tmp++;
		for (unsigned int j = i + 1; j < this->_list.size(); j++)
		{
			if (abs(tmp2 - *tmp) < shortest)
				shortest = abs(tmp2 - *tmp);

			tmp++;
		}
		iter++;
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (_list.size() < 2)
		throw NotEnoughNumbersStoredException();
	
	int lowest_value = *std::min_element(this->_list.begin(), this->_list.end());
	int highest_value = *std::max_element(this->_list.begin(), this->_list.end());
	
	return (highest_value - lowest_value);
}