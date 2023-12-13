/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:04:39 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/12 13:05:16 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <climits>

enum type {
	CHAR,
	NUM,
	FLOAT,
	SPECIAL,
	SPECIAL_F,
	IMPOSSIBLE
};

class ScalarConverter
{
	private:
			std::string _input;
			type _type;
			double _value;
	public:
			ScalarConverter();
			ScalarConverter(const ScalarConverter &to_copy);
			ScalarConverter &operator=(const ScalarConverter &other);
			~ScalarConverter();
			
			static void convert(std::string input);

			
};

#endif