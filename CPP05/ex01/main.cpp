/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:50:39 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 15:43:05 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {

	Bureaucrat bureaucrat("Mario", 65);
	Form form("G12", 150, 150);
	Form form2("F28", 64, 150);

	std::cout << "\n===== PRINTING =====" << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\n===== SIGNING =====" << std::endl;
	try {
		bureaucrat.signForm(form);
		bureaucrat.signForm(form2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== PRINTING =====" << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\n===== INCREMENT AND SIGNING =====" << std::endl;
	try {
		bureaucrat.increaseGrade();
		bureaucrat.signForm(form);
		bureaucrat.signForm(form2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== PRINTING =====" << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\n===== END =====" << std::endl;
}