/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:12:01 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/12 15:32:15 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
int a = 2;
int b = 3;
std::cout << "a = " << a << ", b = " << b << std::endl;
::swap( a, b );
std::cout << "swap(a, b)" << std::endl;
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
std::string c = "string1";
std::string d = "string2";
std::cout << "c = " << c << ", d = " << d << std::endl;
::swap(c, d);
std::cout << "swap(c, d)" << std::endl;
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
return 0;
}