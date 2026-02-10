#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

class bigint
{
	private :
		std::string str;
	
	public :

		//form canonique

		bigint();
		bigint(unsigned int n);
		bigint(const bigint& copy);		//constructeur de recopie
		bigint& operator=(const bigint& copy);
		~bigint();

		//getter
		std::string get_str() const;

		//addition (+, +=, ++ , ++)
		bigint operator+(const bigint& srcs) const;
		bigint& operator+=(const bigint& srcs);
		bigint& operator++();	//++a
		bigint operator++(int);

		//comparaison(==, !=, >, <, >=, <=)
		bool operator==(const bigint& srcs) const;
		bool operator!=(const bigint& srcs) const;
		bool operator<(const bigint& srcs) const;
		bool operator>(const bigint& srcs) const;
		bool operator<=(const bigint& srcs) const;
		bool operator>=(const bigint& srcs) const;

		//bitshifting (>>, <<, >>=, <<=)
		bigint operator<<(const bigint& srcs) const;
		bigint operator<<(unsigned int n) const;
		bigint operator>>(const bigint& srcs) const;
		bigint operator>>(unsigned int n) const;
		bigint &operator>>=(const bigint& srcs);
		bigint &operator>>=(unsigned int n);
		bigint &operator<<=(const bigint& srcs);
		bigint &operator<<=(unsigned int n);
};

std::ostream &operator<<(std::ostream &out, const bigint &srcs);

#endif