/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:15:58 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 18:12:49 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Random Target")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &target) : AForm(target)
{
    *this = target;
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &target)
{
	if (this != &target)
	{
		_target = target.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    return ;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execAction() const
{
	std::cout << " *DRILLING NOISES* " << std::endl;
	if (rand() % 2)
		std::cout << getTarget() << " has been successfully robotomized!" << std::endl;
	else
		std::cout << getTarget() << " failed to get robotomized.." << std::endl;
	
}