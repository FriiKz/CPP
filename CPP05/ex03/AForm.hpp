/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:04:52 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 18:03:25 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>


class Bureaucrat;

class AForm
{
	
	private:
			std::string _name;
			bool 		_signed;
			const int   _sign_grade;
			const int	_exec_grade;
	
	public:
			AForm();
			AForm( AForm &other );
			AForm( std::string name, const int sign_grade, const int exec_grade );
			AForm& operator=( AForm &other );
			virtual ~AForm();

			void		beSigned(Bureaucrat &bureaucrat);
			std::string getName(void) const;
			bool		getSigned() const;
			int 		getSignGrade() const;
			int 		getExecGrade() const;
			void execute(Bureaucrat const &executor) const;
			virtual void execAction() const = 0;

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
			class FormNotSignException : public std::exception
			{
				public:
						char const* what() const throw ();
			};

};

std::ostream &operator<<(std::ostream &os, const AForm &form);



#endif