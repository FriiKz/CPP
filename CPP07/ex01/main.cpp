/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:33:20 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/12 16:15:41 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
	int i = 5;
    int integers[] = { 1, 2, 3, 4, 5 };

    std::cout << "integers: " << std::endl;
    iter(integers, i, &print_t);

    double doubles[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    std::cout << "\ndoubles: " << std::endl;
    iter(doubles, i, &print_t);

    char chars[] = { 'a', 'b', 'c', 'd', 'e' };

    std::cout << "\nchars: " << std::endl;
    iter(chars, i, &print_t);

    std::string strings[] = { "hey", "ciao", "hola", "salut", "hallo" };

    std::cout << "\nstrings: " << std::endl;
    iter(strings, i, &print_t);

    return 0;
}