/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:04:52 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 15:33:08 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	
	private:
			std::string _name;
			bool 		_signed;
			const int   _sign_grade;
			const int	_exec_grade;
	
	public:
			Form();
			Form( Form &other );
			Form( std::string name, const int sign_grade, const int exec_grade );
			Form& operator=( Form &other );
			~Form();

			void		beSigned(Bureaucrat &bureaucrat);
			std::string getName(void) const;
			bool		getSigned() const;
			int 		getSignGrade() const;
			int 		getExecGrade() const;

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

std::ostream &operator<<(std::ostream &os, const Form &form);



#endif