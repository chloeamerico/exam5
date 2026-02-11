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
		bigint(const bigint& copy);		//constructeur de recopie
		bigint& operator=(const bigint& copy);
		~bigint();

		//addition (+, += ++, ++)
		bigint operator+(const bigint& srcs) const;
		bigint& operator+=(const bigint& srcs);
		bigint& operator++();
		bigint operator++(int);

		//comparaison (==, !=, <, >, <=, >=)
		bool operator==(const bigint& srcs) const;
		bool operator!=(const bigint& srcs) const;
		bool operator>(const bigint& srcs) const;
		bool operator<(const bigint& srcs) const;
		bool operator>=(const bigint& srcs) const;
		bool operator<=(const bigint& srcs) const;

		//bitshifting(<<, >>, <<=, >>=)
		bigint operator<<(const bigint& srcs) const;
		bigint operator<<(unsigned int n) const;
		bigint operator>>(const bigint& srcs) const;
		bigint operator>>(unsigned int n) const;
		bigint& operator<<=(const bigint& srcs);
		bigint& operator<<=(unsigned int n);
		bigint& operator>>=(const bigint& srcs);
		bigint& operator>>=(unsigned int n);

		//getter
		std::string get_str() const;
};

std::ostream& operator<<(std::ostream& out, const bigint& srcs);

#endif