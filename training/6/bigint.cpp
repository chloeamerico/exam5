#include "bigint.hpp"

bigint bigint::operator+(const bigint &srcs) const
{
	//on recuper

	std::string s1 = str;
	std::string s2 = srcs.str;

	//s1 > s2
	if (s1 < s2)
		std::swap(s1, s2);

	//init

	int i = s1.length();
	int j = s2.length();
	int retenue;
	std::string result;

	//boucle
	while(j >= 0 || i >= 0 || retenue)
	{
		int nb1 = 0;
		if (i >= 0)
			nb1 = s1[i] - '0';

		int nb2 = 0;
		if(j >= 0)
			nb2 = s2[j] - '0';

		int sum = nb1 + nb2 + retenue;
		result.push_back((sum % 10) + '0');
		retenue = sum / 10;

		i--;
		j--;
	}
	std::reverse(result.begin(), result.end());
	bigint res;
	res.str = result;
	return res;
}

bigint& bigint::operator+=(const bigint& srcs)
{
	*this = *this + srcs;
	return *this;
}

bigint& bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bool bigint::operator==(const bigint &src)const
{
	return (this->str == src.str);
}

bool bigint::operator!=(const bigint &src)const
{
	return !(*this == src);
}

bool bigint::operator>(const bigint &src)const
{
	if (this->str.length() > src.str.length())
		return true;
	if(this->str.length() == src.str.length())
		return (this->str > src.str);
	else
		return false;
}

bool bigint::operator<(const bigint &src)const
{
	return (src > *this);
}

bool bigint::operator>=(const bigint &src)const
{
	return !(*this < src);
}


bool bigint::operator<=(const bigint &src)const
{
	return !(*this > src);
}



//

unsigned int str_to_uint(std::string str)
{
	return std::stoul(str);
}

//on rajoute un nb
bigint bigint::operator<<(const bigint &src)const
{
	bigint copy(*this);
	unsigned int n = str_to_uint(str);
	copy.str.append(n, '0');
	return copy;
}

bigint bigint::operator<<(unsigned int n)const
{
	bigint copy(*this);
	copy.str.append(n, '0');
	return copy;
}


bigint bigint::operator>>(const bigint &src)const
{
	bigint copy(*this);
	unsigned int n = str_to_uint(str);
	copy.str.erase(copy.str.length() - n, n);
	return copy;
}

bigint bigint::operator>>(unsigned int n)const
{
	bigint copy(*this);
	copy.str.erase(copy.str.length() - n, n);
	return copy;
}

bigint& bigint::operator<<=(const bigint &srcs)
{
	*this = *this << srcs;
	return *this;
}

bigint& bigint::operator<<=(unsigned int n)
{
	*this = *this << n;
	return *this;
}


std::ostream operator<<(std::ostream &out, const bigint &srcs)
{
	out << srcs.get_str();
	return out;
}
