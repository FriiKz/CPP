/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:09:43 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/12 17:13:44 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(new T[0]), _size(0)
{
	std::cout << "Empty array created" << std::endl;
	return;
}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n)
{
	std::cout << n << " arrays have been created" << std::endl;
	return;
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Array has been destroyed" << std::endl;
	delete[] _array;
	return;
}

template <typename T>
Array<T>::Array(const Array &to_copy) :_array(new T[to_copy.size()]), _size(to_copy.size())
{
	std::cout << "Array has been copied" << std::endl;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = to_copy._array[i];
	return;
}

template <typename T>
Array<T> & Array<T>::operator= (const Array<T> &target) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &target)
		return (*this);

	delete[] _array;
	_size = target.size();
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = target[i];
	return (*this);
}

template <typename T>
T & Array<T>::operator[] (unsigned int i) {
	if (i >= _size)
		throw Array<T>::IndexOutOfBoundsException();
	return (_array[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
