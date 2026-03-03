/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:00:44 by camerico          #+#    #+#             */
/*   Updated: 2026/02/26 12:25:59 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class vect2
{
	private:
		int x;
		int y;

	public :

		vect2();
		vect2(int a, int b);
		vect2(const vect2& copy);
		vect2& operator=(const vect2& copy);
		~vect2();

		//[], []
		vect2 operator[](const vect2& srcs) const;
		vect2 &operator[](const vect2& srcs);

		//+, -, *, -
		vect2 operator+(const vect2& srcs) const;
		vect2 operator-(const vect2& srcs) const;
		vect2 operator*(int multi) const;
		vect2 operator-();

		//+=, -=, *=
		vect2 &operator+=(const vect2& srcs);
		vect2 &operator-=(const vect2& srcs);
		vect2 &operator*=(int multi);

		//++, ++, --, --
		vect2 operator++(int);	//v++
		vect2 &operator++();	//++v
		vect2 operator--(int);
		vect2 &operator--();	//--v

		//bool comparaison (==, !=)

		bool operator==(const vect2& srcs) const;
		bool operator!=(const vect2& srcs) const;
		
};


//*, <<