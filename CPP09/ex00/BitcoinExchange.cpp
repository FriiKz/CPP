/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:36:47 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/15 20:39:45 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data/data.csv");
    std::string fileName = "";
    std::getline(file, fileName);

    while (std::getline(file, fileName)) 
	{
        float f_num = 0.0;
        size_t comma = fileName.find(',');
        std::string string_val = fileName.substr(comma + 1);
        std::istringstream iss(string_val);
        iss >> f_num;
        _data[fileName.substr(0, comma)] = f_num;
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &to_copy)
{
	*this = to_copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &target)
{
	if (this != &target)
		_data = target._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::ft_format(std::string str)
{
	if (str.size() < 13)
	        return false;
	for (int i =0; str[i]; i++) 
	{
	    if (!isdigit(str[i]) && (i <= 3 || i == 5 || i == 6 || i == 8 || i == 9))
	            return false;
	    if (str[i] != '-' && (i == 4 || i == 7))
	            return false;
	    if (str[i] != ' ' && (i == 10 || i == 12))
	            return false;
	    if (str[i] != '|' && i == 11)
	            return false;
	}
	return true;
}

bool BitcoinExchange::ft_date(std::string str)
{
    std::string str_year = str.substr(0, 4);
    std::string str_month = str.substr(5, 2);
    std::string str_day = str.substr(8, 2);
    int year, month, day;
    std::istringstream(str_year) >> year;
    std::istringstream(str_month) >> month;
    std::istringstream(str_day) >> day;
    if (year > 2022 || year < 2009)
        return false;
    if (month > 12 || month < 1)
        return false;
    if (day > 31 || day < 1)
        return false;
    return true;
}

bool BitcoinExchange::ft_isDigit(std::string str) 
{
	int is_dot = 0;
	
    for (size_t i = 0; i < str.size(); i++)
	{
        if (!isdigit(str[i]) && str[i] != '.')
            return false;
        if (str[i] == '.')
            is_dot++;
        else if (is_dot > 1)
            return false;
    }
    return true;
}

void BitcoinExchange::converter(std::string line) 
{                                                                                     
    if (!ft_format(line))
	{
        std::cout << "Error: invalid date: " << line << std::endl;
        return;
    }
    std::string date = line.substr(0, 10);
    std::string valueStr = line.substr(13, line.size() - 13);                                                                                                          
    if (!ft_date(date))
	{
        std::cout << "Error: invalid date: " << line << std::endl;
        return;
    }                                                                                                         
    if (!ft_isDigit(valueStr))
	{
            std::cout << "Error: invalid number" << std::endl;
            return;
    }                                                                                                     
    float valueFloat = 0.0f;
    std::istringstream(valueStr) >> valueFloat;
    if (valueFloat > 1000) 
	{
        std::cout << "Error: number too high" << std::endl;
        return;
    }                                                                          
    std::map<std::string, float>::iterator it = _data.upper_bound(date);
    if (it != _data.begin())
        it--;
    std::cout << date << " => " << valueFloat << " = " << valueFloat * it->second << std::endl;
}

int BitcoinExchange::exchange(char* argv)
{                                                                                                        
    std::ifstream input(argv);
    if (!input.good()) 
	{
    	std::cerr << "Error: could not open any file" << std::endl;
        return 1;
    }                                                                                          
    std::string line;
    std::getline(input, line);
    while (std::getline(input, line))
        converter(line);
    input.close();
    return 0;
}
