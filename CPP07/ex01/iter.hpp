/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:33:43 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/12 16:19:59 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*f)(T&))
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void print_t(T &t)
{
	std::cout << t << std::endl;
}

#endif