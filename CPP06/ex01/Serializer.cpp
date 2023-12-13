/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:54 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/10 19:07:00 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	return;
}

Serializer::Serializer(const Serializer &to_copy)
{
	*this = to_copy;
}

Serializer& Serializer::operator=(const Serializer &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

Serializer::~Serializer()
{
	return;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}