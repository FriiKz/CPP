/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:25:04 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/14 18:33:33 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "---SUBJECT TEST---" << std::endl;
	std::cout << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;
	std::cout << "---TEST WITH LIST---" << std::endl;
	std::cout << std::endl;
	MutantStack<int> a;
	std::list<int> b;

	a = mstack;
	b.push_back(5);
	b.push_back(17);
	std::cout << b.back() << std::endl;
	b.back();
	b.pop_back();
	std::cout << b.size() << std::endl;
	b.push_back(3);
	b.push_back(5);
	b.push_back(737);
	b.push_back(0);

	std::list<int>::iterator itList = b.begin();
	std::list<int>::iterator itendList = b.end();
	
	while (itList != itendList)
	{
		std::cout << *itList << std::endl;
		itList++;
	}
	return 0;
}