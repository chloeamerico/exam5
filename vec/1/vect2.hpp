/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:33:20 by camerico          #+#    #+#             */
/*   Updated: 2026/02/25 16:01:13 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private :
		int x;
		int y;

	public :

		vect2();
		vect2(int a, int b);
		vect2(const vect2 &copy);
		vect2& operator=(const vect2 &copy);
		~vect2();

		//[], []

		int operator[](int index) const;
		int &operator[](int index);

		//+, -, *, -
		vect2 operator+(const vect2 &srcs) const;
		vect2 operator-(const vect2 &srcs) const;
		vect2 operator*(int multi) const;
		vect2 operator-();

		//+=, -=, *=
		vect2 &operator+=(const vect2 &srcs);
		vect2 &operator-=(const vect2 &srcs);
		vect2 &operator*=(int multi);

		//++, ++, --, --
		vect2 &operator++();
		vect2 operator++(int);
		vect2 &operator--();
		vect2 operator--(int);

		//==, !=
		bool operator==(const vect2& srcs) const;
		bool operator!=(const vect2& srcs) const;
		
};

//<< , *
vect2 operator*(int multi, const vect2& srcs);
std::ostream& operator<<(std::ostream& out, const vect2& srcs);

#endif