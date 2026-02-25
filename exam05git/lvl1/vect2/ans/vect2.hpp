#pragma once

#include <iostream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int a, int b);
		vect2(const vect2 &src);
		vect2 &operator=(const vect2 &src);
		~vect2();

		int operator[](int index)const;
		int &operator[](int index);

		//cree un nv vec
		vect2 operator+(const vect2 &src)const;	//cree un nv vec sans modif *this
		vect2 operator-(const vect2 &src)const;	//cree un nv vec sans modif *this	pour v1 - v2
		vect2 operator*(int multi)const;		//multiplie par un scalaire (v * 3)
		vect2 operator-();		//pour -v

		//modifie *this
		vect2 &operator+=(const vect2 &src);
		vect2 &operator-=(const vect2 &src);
		vect2 &operator*=(int multi);

		vect2 &operator++();		//++v
		vect2 operator++(int);		//v++
		vect2 &operator--();
		vect2 operator--(int);

		//comparaison
		bool operator==(const vect2 &src)const;
		bool operator!=(const vect2 &src)const;
};

vect2 operator*(int multi, const vect2 &src);	//pour 3 * v

std::ostream &operator<<(std::ostream &out, const vect2 &src);