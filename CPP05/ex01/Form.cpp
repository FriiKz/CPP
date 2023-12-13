/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:25:49 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 15:38:50 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _sign_grade(150), _exec_grade(150)
{
	this->_name = "New Form";
	this->_signed = false;
	std::cout << this->_name << " has been created " << std::endl;
}

Form::Form(Form &other) : _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	this->_name = other._name;
	std::cout << " Copy constructor called " << std::endl;
}

Form::Form(std::string name, const int sign_grade, const int exec_grade) : _sign_grade(sign_grade), _exec_grade(exec_grade)
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

Form &Form::operator=( Form &other )
{
	std::cout << "Assignation operator called" << std::endl;
    this->_signed = other._signed;
    return (*this);
}
Form::~Form()
{
	std::cout << this->_name << " has been deleted " << std::endl;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw (GradeTooLowException());
	this->_signed = true;
}

std::string Form::getName(void) const
{
	return(this->_name);
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getSignGrade() const
{
	return this->_sign_grade;
}

int Form::getExecGrade() const
{
	return this->_exec_grade;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");	
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName()
	<< " Grade to sign: " << form.getSignGrade()
	<< " Grade required to execute: " << form.getExecGrade()
	<< " Sign status:  " << (form.getSigned() ? "Signed" : "Not Signed");
	return (os);
}