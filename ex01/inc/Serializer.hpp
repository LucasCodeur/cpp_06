/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:09 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/11 10:07:24 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

#include <stdint.h>

class	Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
	private:
		Serializer	(void);
		Serializer	(int);
		Serializer	(const Serializer &);
		~Serializer (void);
		Serializer& operator= ( const Serializer &);
};

# endif
