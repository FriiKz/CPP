/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:36:52 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/15 22:59:21 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) 
{
    if (argc != 2) 
	{
            std::cerr << "Error: Polish mathematical expression expected as argument" << std::endl;
            return 1;
    }
    std::string expression = argv[1];
    try {
            RPN calculator;
            int result = calculator.exec_rpn(expression);
            std::cout << result << std::endl;
    } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
    }
    return 0;
}
