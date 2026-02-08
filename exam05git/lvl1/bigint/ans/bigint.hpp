#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>

class bigint
{
	private:
		std::string str;

	public:
		bigint();
		bigint(const bigint &src);
		bigint(unsigned int n);
		bigint &operator=(const bigint &src);
		~bigint();

		std::string get_str()const;

		//operations
		bigint operator+(const bigint &src)const;	//renvoie un nv bigint , ne modifie 
		bigint &operator+=(const bigint &src);
		bigint &operator++();
		bigint operator++(int);

		//logic
		bool operator==(const bigint &src)const;
		bool operator!=(const bigint &src)const;
		bool operator>(const bigint &src)const;
		bool operator<(const bigint &src)const;
		bool operator<=(const bigint &src)const;
		bool operator>=(const bigint &src)const;

		//shiftinh
		bigint operator<<(const bigint &src)const;
		bigint operator<<(unsigned int n)const;
		bigint operator>>(const bigint &src)const;
		bigint operator>>(unsigned int n)const;
		bigint &operator>>=(unsigned int n);
		bigint &operator>>=(const bigint &src);
		bigint &operator<<=(unsigned int n);
		bigint &operator<<=(const bigint &src);
};

std::ostream &operator<<(std::ostream &out, const bigint &src);