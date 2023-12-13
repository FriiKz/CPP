/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:08:08 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/12 13:03:55 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.value = 42;
	data.string = "boh";

    std::cout << "Value: " << Serializer::deserialize(Serializer::serialize(&data))->value << std::endl;
    std::cout << "String: " << Serializer::deserialize(Serializer::serialize(&data))->string << std::endl;

	return (0);
}