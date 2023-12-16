/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:09:30 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/15 19:46:30 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
			std::map<std::string, float> _data;

	public:
			BitcoinExchange();
			BitcoinExchange(const BitcoinExchange &to_copy);
			BitcoinExchange &operator=(const BitcoinExchange &target);
			~BitcoinExchange();

			bool ft_format(std::string str);
			bool ft_date(std::string str);
			bool ft_isDigit(std::string str);
			void converter(std::string str);
			int exchange(char *str);
};



#endif