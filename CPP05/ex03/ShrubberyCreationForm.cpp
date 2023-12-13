/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:15:34 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 18:18:02 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Random Target")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &target) : AForm(target)
{
    *this = target;
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &target)
{
	if (this != &target)
	{
		_target = target.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    return ;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execAction() const
{
	std::string file_name = getTarget() + "_shrubbery";
	std::ofstream shrubbery_file(file_name.c_str());
	shrubbery_file
			<< "	          &&& &&  & && " << std::endl
			<< "      && &\\/&\\|& ()|/ @, && " << std::endl
			<< "      &\\/(/&/&||/& /_/)_&/_& " << std::endl
			<< "   &() &\\/&|()|/&\\/ '% & () " << std::endl
			<< "  &_\\_&&_\\ |& |&&/&__%_/_& && " << std::endl
			<< "&&   && & &| &| /& & % ()& /&& " << std::endl
			<< " ()&_---()&\\&\\|&&-&&--%---()~ " << std::endl
			<< "     &&     \\|| " << std::endl
			<< "             ||| " << std::endl
			<< "             ||| " << std::endl
			<< "             ||| " << std::endl
			<< "       , -=-~  .-^- _ " << std::endl;
	shrubbery_file.close();
}