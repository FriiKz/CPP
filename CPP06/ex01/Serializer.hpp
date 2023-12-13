/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:34 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/12 13:00:17 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
			Serializer();
			Serializer(const Serializer &to_copy);
			Serializer& operator=(const Serializer &target);
			~Serializer();

			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);
};


#endif