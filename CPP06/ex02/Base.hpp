/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:16:12 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/11 18:51:46 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <stdlib.h>
#include <typeinfo>


class Base
{
	public:
			virtual ~Base();
};

Base *generate(void);
void  identify(Base *p);
void  identify(Base &p);



#endif
