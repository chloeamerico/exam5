#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

class vect2 {
private:
	int x;
	int y;

public:
	vect2();
	vect2(int a, int b);
	vect2(const vect2 &src);
	vect2 &operator=(const vect2 &src);
	~vect2();

	int operator[](int idx)const;
	int &operator[](int idx);

	vect2 operator+(const vect2 &src)const;
	vect2 operator-(const vect2 &src)const;
	vect2 operator-();
	vect2 operator*(int multi)const;
	vect2 &operator+=(const vect2 &src);
	vect2 &operator-=(const vect2 &src);
	vect2 &operator*=(int multi);

	vect2 &operator++();
	vect2 operator++(int);
	vect2 &operator--();
	vect2 operator--(int);

	bool operator==(const vect2 &src)const;
	bool operator!=(const vect2 &src)const;
};

vect2 operator*(int multi, const vect2 &src);
std::ostream &operator<<(std::ostream &out, const vect2 &src);