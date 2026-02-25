/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:21:39 by camerico          #+#    #+#             */
/*   Updated: 2026/02/25 16:16:59 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int a, int b) : x(a), y(b) {}

vect2::vect2(const vect2 &copy)
{
	*this = copy;
}

vect2& vect2::operator=(const vect2 &copy)
{
	if (this != &copy)
	{
		this->x = copy.x;
		this->y = copy.y;
	}
	return *this;
}

vect2::~vect2() {}

//////

int vect2::operator[](int index) const
{
	if (index == 0)
		return x;

	return y;
}

int& vect2::operator[](int index)
{
	if (index == 0)
		return x;

	return y;
}

vect2 vect2::operator+(const vect2 &srcs) const
{
	vect2 copy(*this);
	copy.x += srcs.x;
	copy.y += srcs.y;
	return copy;
}

vect2 vect2::operator-(const vect2 &srcs) const
{
	vect2 copy(*this);
	copy.x -= srcs.x;
	copy.y -= srcs.y;
	return copy;
}

vect2 vect2::operator*(int multi) const
{
	vect2 copy(*this);
	copy.x *= multi;
	copy.y *= multi;
	return copy;
}

vect2 vect2::operator-()
{
	vect2 copy(*this);
	copy.x = -copy.x;
	copy.y = -copy.y;
	return copy;
	// OU return(vect2(-this->x, -this->y));
}

vect2&	vect2::operator+=(const vect2 &srcs)
{
	*this = *this + srcs;
	return *this;
}

vect2&	vect2::operator-=(const vect2 &srcs)
{
	*this = *this - srcs;
	return *this;
}

vect2&	vect2::operator*=(int multi)
{
	*this = *this * multi;
	return *this;
}

//++v
vect2& vect2::operator++()
{
	*this += vect2(1, 1);
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 copy(*this);
	*this += vect2(1, 1);
	return copy;
}

vect2& vect2::operator--()
{
	*this -= vect2(1, 1);
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 copy(*this);
	*this -= vect2(1, 1);
	return copy;
}

bool vect2::operator==(const vect2& srcs) const
{
	if ((this->x == srcs.x) && (this->y == srcs.y))
		return true;
	return false;
}

bool vect2::operator!=(const vect2& srcs) const
{
	return !(*this == srcs);
}

vect2 operator*(int multi, const vect2 &src)
{
	vect2 copy(src);
	copy *= multi;
	return copy;
}

std::ostream &operator<<(std::ostream &out, const vect2 &src)
{
	out << "{" << src[0] << ", " << src[1] << "}";
	return out;
}