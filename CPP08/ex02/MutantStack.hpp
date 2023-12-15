/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:25:18 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/14 17:23:53 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <sstream>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
			MutantStack();
			MutantStack(const MutantStack<T> &to_copy);
			MutantStack &operator=(const MutantStack<T> &target);
			~MutantStack();
			
			typedef typename std::stack<T>::container_type::iterator iterator;
			iterator begin();
			iterator end();
};

#include "MutantStack.tpp"

#endif