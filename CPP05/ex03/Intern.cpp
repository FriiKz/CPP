/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:59:20 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/09 12:36:05 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	return;
}

Intern::Intern(const Intern &target)
{
	*this = target;
	return;
}

Intern &Intern::operator=(const Intern &target)
{
	(void)target;
	return (*this);
}

Intern::~Intern()
{
	return;
}

AForm	*Intern::makePresidentialPardonForm(std::string target){
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm *form = NULL;
    std::string selection[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    while (i < 3)
    {
        if (formName == selection[i])
			break;
		i++;
    }
	switch (i)
	{
		case 0:
			form = this->makeShrubberyCreationForm(target);
			break;
		case 1:
			form = this->makeRobotomyRequestForm(target);
			break;
		case 2:
			form = this->makePresidentialPardonForm(target);
			break;
		default:
			std::cout << "Couldn't make any form for: " << formName << " ...better check your arguments!" << std::endl;
			return (NULL);
			break;
	}
	std::cout << form->getName() << " has been created by an Intern" << std::endl;
	return (form);
}