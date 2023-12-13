/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:51:12 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/07 18:23:43 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->name = "default";
	this->grade = 150;
	std::cout << "Bureaucrat " << this->name << " has been created with grade " << this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	this->grade = other.grade;
	this->name = other.name;
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		this->grade = grade;
		this->name = name;
		std::cout << "Bureaucrat " << this->name << " has been created with grade " << this->grade << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other )
{
	std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << this->name << " has been destroyed" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return(this->name);
}

int Bureaucrat::getGrade(void) const
{
	return(this->grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");	
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void Bureaucrat::increaseGrade()
{
	if ((this->grade - 1) < 1)
		throw GradeTooHighException();
	else
	{
		this->grade -= 1;
		std::cout << this->name << "'s grade has been increased by 1: " << this->grade << std::endl;
	}
}

void Bureaucrat::decreaseGrade()
{
	if ((this->grade + 1) > 150)
		throw GradeTooLowException();
	else
	{
		this->grade += 1;
		std::cout << this->name << "'s grade has been decreased by 1: " << this->grade << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}