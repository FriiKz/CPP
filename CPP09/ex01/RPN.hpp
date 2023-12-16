/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:42:58 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/15 22:57:13 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <cstdlib>
# include <sstream>

class RPN 
{
	private:
			std::stack<int> _nums;
    public:
            RPN();
            RPN(const RPN &to_copy);
            RPN& operator=(const RPN &target);
            ~RPN();

            int exec_rpn(const std::string &input);
};

#endif