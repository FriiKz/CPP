/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:25:49 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 16:04:30 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _sign_grade(150), _exec_grade(150)
{
	this->_name = "New AForm";
	this->_signed = false;
	std::cout << this->_name << " has been created " << std::endl;
}

AForm::AForm(AForm &other) : _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	this->_name = other._name;
	std::cout << " Copy constructor called " << std::endl;
}

AForm::AForm(std::string name, const int sign_grade, const int exec_grade) : _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw (GradeTooHighException());
	else if (sign_grade > 150 || exec_grade > 150)
		throw (GradeTooLowException());
	else
	{
		this->_name = name;
		this->_signed = false;
		std::cout << this->_name << " has been created with grade to sign in: " << this->_sign_grade << " and grade required to execute: " << this->_exec_grade << std::endl;
	}
}

AForm &AForm::operator=( AForm &other )
{
	std::cout << "Assignation operator called" << std::endl;
    this->_signed = other._signed;
    return (*this);
}
AForm::~AForm()
{
	std::cout << this->_name << " has been deleted " << std::endl;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw (GradeTooLowException());
	this->_signed = true;
}

std::string AForm::getName(void) const
{
	return(this->_name);
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getSignGrade() const
{
	return this->_sign_grade;
}

int AForm::getExecGrade() const
{
	return this->_exec_grade;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (!getSigned())
		throw AForm::FormNotSignException();
	execAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");	
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

char const* AForm::FormNotSignException::what() const throw ()
{
	return ("Form: Big boss haven't authorized yet!");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form: " << form.getName()
	<< " Grade to sign: " << form.getSignGrade()
	<< " Grade required to execute: " << form.getExecGrade()
	<< " Sign status:  " << (form.getSigned() ? "Signed" : "Not Signed");
	return (os);
}