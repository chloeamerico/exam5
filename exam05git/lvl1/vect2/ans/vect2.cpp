#include "vect2.hpp"

vect2::vect2(): x(0), y(0)
{}

vect2::vect2(int a, int b): x(a), y(b)
{}

vect2::vect2(const vect2 &src)
{
	*this = src;
}

vect2 &vect2::operator=(const vect2 &src)
{
	this->x = src.x;
	this->y = src.y;
	return (*this);
}

vect2::~vect2()
{
}

int vect2::operator[](int index)const
{
	if (index == 0)
		return (this->x);
	return (this->y);
}

int &vect2::operator[](int index)
{
	if (index == 0)
		return (this->x);
	return (this->y);
}

vect2 vect2::operator+(const vect2 &src)const
{
	vect2 cpy(*this);
	cpy.x += src.x;
	cpy.y += src.y;
	return (cpy);
}

vect2 vect2::operator-(const vect2 &src)const
{
	vect2 cpy(*this);
	cpy.x -= src.x;
	cpy.y -= src.y;
	return (cpy);
}

vect2 vect2::operator*(int multi)const
{
	vect2 cpy(*this);
	cpy.x *= multi;
	cpy.y *= multi;
	return (cpy);
}

vect2 vect2::operator-()
{
	return (vect2(-this->x, -this->y));
}

vect2 &vect2::operator+=(const vect2 &src)
{
	*this = *this + src;
	return (*this);
}

vect2 &vect2::operator-=(const vect2 &src)
{
	*this = *this - src;
	return (*this);
}

vect2 &vect2::operator*=(int multi)
{
	*this = *this * multi;
	return (*this);
}

vect2 &vect2::operator++()
{
	return (*this += vect2(1, 1));
}

vect2 vect2::operator++(int)
{
	vect2 cpy(*this);
	*this += vect2(1, 1);
	return (cpy);
}

vect2 &vect2::operator--()
{
	return (*this -= vect2(1, 1));
}

vect2 vect2::operator--(int)
{
	vect2 cpy(*this);
	*this -= vect2(1, 1);
	return (cpy);
}

bool vect2::operator==(const vect2 &src)const
{
	return (this->x == src.x && this->y == src.y);
}

bool vect2::operator!=(const vect2 &src)const
{
	return !(*this == src);
}

vect2 operator*(int multi, const vect2 &src)
{
	vect2 cpy(src);
	cpy *= multi;
	return (cpy);
}

std::ostream &operator<<(std::ostream &out, const vect2 &src)
{
	out << "{" << src[0] << ", " << src[1] << "}";
	return (out);
}