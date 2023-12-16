/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:39:43 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/15 19:43:02 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) 
	{
        std::cout << "Error: file needed as parameter" << std::endl;
        return 1;
    }
    BitcoinExchange bit;
    return bit.exchange(argv[1]);
}
