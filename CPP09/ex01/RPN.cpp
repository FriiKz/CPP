/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:53:59 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/15 23:07:52 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	return;
}

RPN::RPN(const RPN &to_copy)
{
	*this = to_copy;
}

RPN& RPN::operator=(const RPN &target)
{
	if (this != &target)
		this->_nums = target._nums;
	return (*this);
}

RPN::~RPN()
{
	return;
}

int RPN::exec_rpn(const std::string &input)
{
	std::istringstream iss(input);
    std::string token;                                                                        
    std::stack<int> stack;
    while (iss >> token) 
	{
        if (token == "+" || token == "-" || token == "*" || token == "/")
		{
            if (stack.size() < 2)
                throw std::runtime_error("Invalid expression");                                    
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();                                                                   
            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/")
			{
                if (b == 0)
                    throw std::runtime_error("Division by zero");
                stack.push(a / b);
            }
        } 
		else
		{                                                         
            int i = 0;
            if (token[i] == '-')
                i++;
            while (token[i]) 
			{
                if (!isdigit(token[i]) && token[0] != '-')
                    throw std::runtime_error("Only digit");
                i++;
            }
            int num = std::atoi(token.c_str());                                                                                        
            if (num > 9 || num < -9)
                throw std::runtime_error("Less than 10 or greater than -10 numbers expected");
            stack.push(num);
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Invalid expression");                                                                             
    return stack.top();
}