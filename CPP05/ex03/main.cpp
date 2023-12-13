/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:57:55 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/09 12:27:11 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main () {

	Bureaucrat bureaucrat("Mario", 1);
	Intern someRandomIntern;
	AForm *rrf;
	AForm *ppf;
	AForm *scf;

	ppf = someRandomIntern.makeForm("presidential pardon", "Philip");
	rrf = someRandomIntern.makeForm("robotomy request", "Sheldon");
	scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	someRandomIntern.makeForm("ProvaProva", "BebeBio");
	bureaucrat.signForm(*ppf);
	bureaucrat.executeForm(*ppf);
	bureaucrat.signForm(*rrf);
	bureaucrat.executeForm(*rrf);
	bureaucrat.signForm(*scf);
	bureaucrat.executeForm(*scf);

	delete ppf;
	delete rrf;
	delete scf;

	return (0);
}