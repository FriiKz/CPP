/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:15:52 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 18:15:19 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "stdlib.h"

class RobotomyRequestForm : public AForm
{
	private:
			std::string _target;
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm(RobotomyRequestForm &target);
			RobotomyRequestForm& operator=(RobotomyRequestForm &target);
			~RobotomyRequestForm();

			std::string getTarget() const;
			void		execAction() const;
};



#endif