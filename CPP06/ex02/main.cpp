/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:43:42 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/11 18:47:13 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>

class BaseFail : public Base
{
};

int main()
{
    std::srand(std::time(0));
    Base *base = generate();
    identify(base);
    delete base;
    Base &ref = *generate();
    identify(ref);

    std::cout << std::endl;
    std::cout << "------- Testing to fail -------" << std::endl;
    Base *nullBase = new BaseFail;
    identify(nullBase);
    delete nullBase;
    Base &nullRef = *new BaseFail;
    identify(nullRef);
    return 0;
}