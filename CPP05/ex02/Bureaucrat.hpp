/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:51:00 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 18:05:22 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	
	private:
			std::string name;
			int 		grade;
	
	public:

			Bureaucrat();
			Bureaucrat( const Bureaucrat &other);
			Bureaucrat( const std::string name, int grade );
			Bureaucrat& operator=( const Bureaucrat &other );
			~Bureaucrat();

			std::string getName(void) const;
			int getGrade(void) const;
			void increaseGrade(void);
			void decreaseGrade(void);
			void signForm(AForm &form);
			void executeForm(AForm const &form);

			class GradeTooHighException : public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif