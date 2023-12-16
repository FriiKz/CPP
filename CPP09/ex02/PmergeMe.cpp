/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:12:28 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/16 14:49:59 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(PmergeMe const &to_copy)
{
    *this = to_copy;
}

PmergeMe & PmergeMe::operator=(PmergeMe const &target)
{
    if (this != &target)
    {
        this->_vec1 = target._vec1;
        this->_vec2 = target._vec2;
        this->_deq1 = target._deq1;
        this->_deq2 = target._deq2;
        this->flag = target.flag;
        this->tmp = target.tmp;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
	return;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    this->flag = false;
    if ((argc - 1) % 2 != 0)
    {
        this->flag = true;
        this->tmp = std::atoi(argv[argc - 1]);
        if (std::atoi(argv[argc - 1]) < 0 || isalpha(*argv[argc - 1]))
        {
            std::cout << "Error: " << argv[argc - 1] << " is not a valid number" << std::endl;
            exit(1);
        }
        argc -= 1;
    }
    else if (argc == 1)
    {
        std::cout << "Error: please insert a list of numbers to be sorted" << std::endl;
        exit(1);
    }
    
    for (int i = 1; i < argc - 1; i+=2)
        this->check_input(argv[i], argv[i+1]);
    
    this->print_before(argv);
    struct timeval  start, end;

    gettimeofday(&start, NULL);
    this->sortVector(argc - 1, argv);
    this->print_after(start, end, this->_vec2);
    struct timeval  start1, end1;
    gettimeofday(&start1, NULL);
    this->sortDeque(argc - 1, argv);
    this->print_after(start1, end1, this->_deq2);
}

void PmergeMe::sortVector(int len, char **sequence)
{
    if (flag == true)
    {
        len++;
    }
    for (int i = 0; i < len; i++)
		this->_vec1.push_back(std::strtol(sequence[i+1], NULL, 10));
	bool isStraggler = false;
	long straggler = 0;
	if (len % 2) {
		isStraggler = true;
		straggler = this->_vec1.back();
		this->_vec1.pop_back();
	}

	std::vector<std::pair<unsigned, unsigned> > pairs;
	for (std::vector<unsigned>::iterator it = this->_vec1.begin(); it != this->_vec1.end(); it +=2)
		pairs.push_back(std::make_pair(*it, *(it+1)));
	for (std::vector<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		if (it->first > it->second)
			std::swap(it->first, it->second);
	for (std::vector<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		for (std::vector<std::pair<unsigned, unsigned> >::iterator jt = it; jt != pairs.end(); jt++)
			if (it->first > jt->first)
				std::swap(*it, *jt);
	for (std::vector<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::vector<unsigned>::iterator jt = std::lower_bound(this->_vec2.begin(), this->_vec2.end(), it->first);
		this->_vec2.insert(jt, it->first);
		jt = std::lower_bound(this->_vec2.begin(), this->_vec2.end(), it->second);
		this->_vec2.insert(jt, it->second);
	}
	if (isStraggler)
	{
		std::vector<unsigned>::iterator jt = std::lower_bound(this->_vec2.begin(), this->_vec2.end(), straggler);
		this->_vec2.insert(jt, straggler);
	}
}

void PmergeMe::sortDeque(int len, char **sequence)
{
    if (flag == true)
    {
        len++;
    }
    for (int i = 0; i < len; i++)
		this->_deq1.push_back(std::strtol(sequence[i+1], NULL, 10));
	bool isStraggler = false;
	long straggler = 0;
	if (len % 2) {
		isStraggler = true;
		straggler = this->_deq1.back();
		this->_deq1.pop_back();
	}

	std::deque<std::pair<unsigned, unsigned> > pairs;
	for (std::deque<unsigned>::iterator it = this->_deq1.begin(); it != this->_deq1.end(); it +=2)
		pairs.push_back(std::make_pair(*it, *(it+1)));
	for (std::deque<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		if (it->first > it->second)
			std::swap(it->first, it->second);
	for (std::deque<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		for (std::deque<std::pair<unsigned, unsigned> >::iterator jt = it; jt != pairs.end(); jt++)
			if (it->first > jt->first)
				std::swap(*it, *jt);
	for (std::deque<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::deque<unsigned>::iterator jt = std::lower_bound(this->_deq2.begin(), this->_deq2.end(), it->first);
		this->_deq2.insert(jt, it->first);
		jt = std::lower_bound(this->_deq2.begin(), this->_deq2.end(), it->second);
		this->_deq2.insert(jt, it->second);
	}
	if (isStraggler)
	{
		std::deque<unsigned>::iterator jt = std::lower_bound(this->_deq2.begin(), this->_deq2.end(), straggler);
		this->_deq2.insert(jt, straggler);
	}
}

void    PmergeMe::check_input(char *argv, char *argv1)
{
    if (std::atoi(argv) < 0 || isalpha(*argv))
    {
        std::cout << "Error: " << argv << " is not a valid number" << std::endl;
        exit(1);
    }
    if (std::atoi(argv1) < 0 || isalpha(*argv1))
    {
        std::cout << "Error: " << argv1 << " is not a valid number" << std::endl;
        exit(1);
    }
}

void    PmergeMe::print_before(char **argv)
{
    std::cout << "Before: ";
    for (int i = 1; argv[i]; i++)
    {
        if (i > 3)
        {
            std::cout << "[...]";
            break;
        }
        std::cout << argv[i] << " ";
    }
}

template <typename T>
void    PmergeMe::print_after(struct timeval &start, struct timeval &end, T &container)
{
    gettimeofday(&end, NULL);
    
    std::cout << std::endl;
    long seconds, useconds;
    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    long    mtime = (seconds * 1000000) + useconds;
    
    double time_in_us = mtime / 1000000.0;

    if (typeid(container) == typeid(std::vector<unsigned int>))
    {
        std::cout << "After: ";
        for (size_t i = 0; i < container.size(); i++)
		{
			if (i > 3)
        	{
           	 	std::cout << "[...]";
           	 	break;
			}
            std::cout << container[i] << " ";
		}
        std::cout << std::fixed << std::setprecision(5) << std::endl << "Time to process a range of " << container.size() << " elements with std::vector : " << time_in_us << " us ";
    }
    else
        std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << container.size() << " elements with std::deque : " << time_in_us << " us " << std::endl;
}