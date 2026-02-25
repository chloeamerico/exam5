/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:17:12 by camerico          #+#    #+#             */
/*   Updated: 2026/02/19 15:27:15 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

class bigint
{
	private :

		std::string str;

	public :

		bigint();
		bigint(unsigned int n);
		bigint(const bigint& copy);
		bigint& operator=(const bigint& copy);
		~bigint();

		//getter
		std::string get_str() const;
		
		//addition (+, +=, ++)
		bigint operator+(const bigint& srcs) const;
		bigint &operator+=(const bigint& srcs);
		bigint &operator++();
		bigint operator++(int);

		//comparaison(==, != , <, >, <=, >=)
		bool operator==(const bigint& copy) const;
		bool operator!=(const bigint& copy) const;
		bool operator<(const bigint& copy) const;
		bool operator>(const bigint& copy) const;
		bool operator<=(const bigint& copy) const;
		bool operator>=(const bigint& copy) const;
		
		//bitshifting(<<, >>, <<=, >>=)
		bigint operator<<(const bigint& srcs) const;
		bigint operator<<(unsigned int n) const;
		bigint operator>>(const bigint& srcs) const;
		bigint operator>>(unsigned int n) const;
		bigint &operator<<=(const bigint& srcs);
		bigint &operator<<=(unsigned int n);
		bigint &operator>>=(const bigint& srcs);
		bigint &operator>>=(unsigned int n);
};

std::ostream &operator<<(std::ostream &out, const bigint& srcs);

#endif