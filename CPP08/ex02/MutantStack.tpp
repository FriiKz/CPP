/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:56:30 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/14 18:17:25 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
	return;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &to_copy)
{
	*this = to_copy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &target)
{
	this->c = target.c;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	return;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}