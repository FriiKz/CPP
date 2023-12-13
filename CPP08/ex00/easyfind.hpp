/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:44:34 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/13 13:26:27 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class NoOccurenceFoundException : public std::exception
{
	public:
			char const* what() const throw ();
};

char const *NoOccurenceFoundException::what() const throw() {
	return ("None");
}

template <typename T>
int easyfind(T &container, int val)
 {
	typename T::iterator index = std::find(container.begin(), container.end(), val);
	if (index == container.end())
		throw NoOccurenceFoundException();
	return (*index);
 }
 
#endif