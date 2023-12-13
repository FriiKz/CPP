/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:44:20 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/13 13:28:40 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	std::cout << "---TEST WITH OCCURRENCES---" << std::endl;
	try
        {
            std::cout << "Ocurrence found : " << easyfind(nums, 3) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
	std::cout << "---TEST WITH NO OCCURRENCES---" << std::endl;
	try
        {
            std::cout << "Ocurrence found : " << easyfind(nums, 7) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
}