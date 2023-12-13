/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:29:46 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/13 19:48:44 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <limits.h>
#include <exception>

class Span
{
	private:
			unsigned int _n;
			std::list<int> _list;
			Span();

	public:
			Span(unsigned int N);
			Span(Span const &to_copy);
			Span &operator=(Span const &target);
			~Span();

			void addNumber(int n);
			void addNumber(int n, int n_times);
			int  shortestSpan();
			int  longestSpan();

			class MaxCapacityReachedException : public std::exception
			{
				public:
						char const *what() const throw();
			};

			class NotEnoughNumbersStoredException : public std::exception
			{
				public:
						char const *what() const throw(); 
			};
};
 



#endif