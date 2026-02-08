#include <ostream>
#include <iostream>
#include <algorithm>
#include <string>

class bigint {
private:
	std::string str;

public:
	bigint();
	bigint(unsigned int n);
	bigint(const bigint &src);
	bigint &operator=(const bigint &src);
	~bigint();

	std::string get_str()const;

	bool operator!=(const bigint &src)const;
	bool operator==(const bigint &src)const;
	bool operator>(const bigint &src)const;
	bool operator>=(const bigint &src)const;
	bool operator<(const bigint &src)const;
	bool operator<=(const bigint &src)const;

	bigint operator+(const bigint &src)const;
	bigint &operator++();
	bigint operator++(int);
	bigint &operator+=(const bigint &src);

	bigint operator<<(const bigint &src)const;
	bigint operator<<(unsigned int n)const;
	bigint operator>>(const bigint &src)const;
	bigint operator>>(unsigned int n)const;
	bigint &operator<<=(const bigint &src);
	bigint &operator<<=(unsigned int n);
	bigint &operator>>=(const bigint &src);
	bigint &operator>>=(unsigned int n);

};

std::ostream &operator<<(std::ostream &out, const bigint &src);