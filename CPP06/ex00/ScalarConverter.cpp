/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:04:46 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/10 18:40:34 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter &to_copy)
{
	*this = to_copy;
	return;
}

ScalarConverter::~ScalarConverter()
{
	return;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		this->_input = other._input;
		this->_type = other._type;
		this->_value = other._value;
	}
	return (*this);
}

void ScalarConverter::convert(std::string input)
{
	std::string specialTypes[6] = {"-inff", "+inff", "nanf","-inf", "+inf", "nan"};
	std::string isChar = "";
	int isInt = 0;
	float isFloat = 0;
	double isDouble = 0;

	if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
	{
		isChar = input[0];
		std::cout << "char: " << isChar << std::endl;
		std::cout << "int: " << static_cast<int>(isChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(isChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(isChar[0]) << ".0" << std::endl;
		return;
	}

	isInt = std::atoi(input.c_str());

	if (input[input.length() - 1] == 'f')
	{
		isFloat = std::atof(input.c_str());
		isDouble = static_cast<double>(isFloat);
	}
	else
	{
		isDouble = std::atof(input.c_str());
		isFloat = static_cast<float>(isDouble);
	}

	for (int i = 0; i < 6; ++i)
	{
		if (input == specialTypes[i])
		{
			isChar = "impossible";
			break;
		}
	}
	if (isChar == "" && std::isprint(isInt))
	{
		isChar = "'";
		isChar += static_cast<char>(isInt);
		isChar += "'";
	}
	else if (isChar == "")
		isChar = "Conversion is not displayable";

	std::cout << "char: " << isChar << std::endl;
	if (isChar == "impossible")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << isInt << std::endl;

	if (isChar == "impossible" && isFloat == 0)
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		if (isChar != "impossible" && isFloat - static_cast<int>(isFloat) == 0)
		{
			std::cout << "float: " << isFloat << ".0f" << std::endl;
			std::cout << "double: " << isDouble << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << isFloat << "f" << std::endl;
			std::cout << "double: " << isDouble << std::endl;
		}
	}
}
