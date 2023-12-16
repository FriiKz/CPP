/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:46:07 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/16 14:39:12 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <cstring>
#include <climits>
#include <typeinfo>

class PmergeMe
{
	private:
			std::vector<unsigned int> _vec1;
			std::vector<unsigned int> _vec2;
			std::deque<unsigned int> _deq1;
			std::deque<unsigned int> _deq2;

	public:
		bool flag;
        unsigned int tmp;
        PmergeMe(int argc, char **argv);
        ~PmergeMe();
        PmergeMe(PmergeMe const &to_copy);
        PmergeMe & operator=(PmergeMe const &target);
        void    print_before(char **argv);

        template <typename T>
        void print_after(struct timeval &end, struct timeval &start, T &container);
        
        void sortVector(int len, char **vec);
        void sortDeque(int len, char **deq);
        void check_input(char *argv, char *argv1);   	
};


#endif