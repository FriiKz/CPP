/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:59:08 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/09 12:13:10 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:

	public:
			Intern();
			Intern(const Intern &target);
			Intern& operator=(const Intern &target);
			~Intern();

			AForm		*makeShrubberyCreationForm(std::string target);
			AForm		*makePresidentialPardonForm(std::string target);
			AForm		*makeRobotomyRequestForm(std::string target);
			AForm		*makeForm(std::string formName, std::string target);
			
};









#endif