/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:54:36 by camerico          #+#    #+#             */
/*   Updated: 2026/02/26 15:33:26 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP


#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

class bigint
{
	private :
		std::string str;	
		
	public:
		bigint();
		bigint(unsigned int n);
		bigint(const bigint& copy);
		bigint operator=(const bigint &copy);
		~bigint();

		//+, +=, ++, ++
		bigint operator+(const bigint &srcs) const;
		bigint &operator+=(const bigint &srcs);
		bigint &operator++();	//++a
		bigint operator++(int);		//a++

		//==, !=, <, >, <=, >=
		bool operator==(const bigint &srcs) const;
		bool operator!=(const bigint &srcs) const;
		bool operator<(const bigint &srcs) const;
		bool operator>(const bigint &srcs) const;
		bool operator<=(const bigint &srcs) const;
		bool operator>=(const bigint &srcs) const;

		//<<, >>, <<=, >>=	bitshifting
		bigint operator<<(const bigint &srcs) const;
		bigint operator<<(unsigned int n) const;
		bigint operator>>(const bigint &srcs) const;
		bigint operator>>(unsigned int n) const;
		bigint &operator<<=(const bigint &srcs);
		bigint &operator<<=(unsigned int n);
		bigint &operator>>=(const bigint &srcs);
		bigint &operator>>=(unsigned int n);
};

std::ostream operator<<(std::ostream &out, const bigint &srcs);

#endif



int a = 12;

std::cout << a++ << std::endl 		12 // a =13
std::cout << ++a << std::endl		13	// a=13


bigint bi;

std::cout << bi << std::endl;
