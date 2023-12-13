/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:16:13 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/08 18:13:29 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
			std::string _target;

	public:
			PresidentialPardonForm();
			PresidentialPardonForm(const std::string target);
			PresidentialPardonForm(const PresidentialPardonForm &target);
			PresidentialPardonForm &operator=(const PresidentialPardonForm &target);
			~PresidentialPardonForm();

			std::string getTarget() const;
			void		execAction() const;
};

#endif