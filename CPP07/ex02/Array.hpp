/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:20:49 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/12 17:30:57 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <class T>
class Array
{
	private:
			T* 			 _array;
			unsigned int _size;
			
	public:
			Array();
			Array(const Array &to_copy);
			Array(unsigned int n);
			~Array();
			
			Array &operator=(const Array &target);
			T &operator[](unsigned int i);
			unsigned int size() const;

			class IndexOutOfBoundsException : public std::exception
			{
				public:
						virtual const char *what() const throw()
						{
							return ("Array's index out of bounds!");
						}
			};
};

#include "Array.tpp"

#endif