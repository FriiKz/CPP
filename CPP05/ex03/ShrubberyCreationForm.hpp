/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:15:25 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 18:12:20 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
			std::string _target;

	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string target);
			ShrubberyCreationForm(ShrubberyCreationForm &target);
			ShrubberyCreationForm& operator=(ShrubberyCreationForm &target);
			~ShrubberyCreationForm();

			std::string getTarget() const;
			void		execAction() const;
};

#endif