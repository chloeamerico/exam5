#include "bigint.hpp"

bigint::bigint() : str("0") {}

bigint::bigint(unsigned int n)
{
	std::stringstream buffer;
	buffer << n;
	str = buffer.str();
}

bigint::bigint(const bigint& copy)
{
	*this = copy;
}

bigint& bigint::operator=(const bigint& copy)
{
	if (*this != copy)
		this->str = copy.str;

	return *this;
}

bigint::~bigint() {}

//------------------

bigint bigint::operator+(const bigint& srcs) const
{
	//recup les str

	std::string s1 = this->str;
	std::string s2 = srcs.str;

	// check si s1 > s2

	if(s2 > s1)
		std::swap(s1, s2);
	
	//init tout

	int i = s1.length() - 1;
	int j = s2.length() - 1;
	std::string result;
	int retenue = 0;

	//boucle
	while(i >= 0 || j >= 0 || retenue)
	{
		int nb1 = 0;
		if(i >= 0)
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
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint tmp = *this;
	*this += bigint(1);
	return tmp;
}

//comparaison

bool bigint::operator==(const bigint& srcs) const
{
	return(this->str == srcs.str);
}

bool bigint::operator!=(const bigint& srcs) const
{
	return !(*this == srcs);
	//ou return (this->str != srcs.str);
}

bool bigint::operator>(const bigint& srcs) const
{
	if (this->str.length() > srcs.str.length())
		return true;
	else if (this->str.length() == srcs.str.length())
		return (this->str > srcs.str);
	else
		return false;
}

bool bigint::operator<(const bigint& srcs) const
{
	return srcs > *this;
}

bool bigint::operator>=(const bigint& srcs) const
{
	return !(*this < srcs);
}

bool bigint::operator<=(const bigint& srcs) const
{
	return !(*this > srcs);
}


//bitshifting

unsigned int str_to_uint(std::string str)
{
	return (std::stoul(str));
}

//srcs est le nb de bits a ajouter
bigint bigint::operator<<(const bigint &srcs)const
{
	unsigned int n = str_to_uint(srcs.str);
	bigint cpy(*this);
	cpy.str.append(n, '0');
	return cpy;
}

bigint bigint::operator<<(unsigned int n)const
{
	bigint copy(*this);
	copy.str.append(n, '0');
	return copy;
}

//on ajoute des 0
bigint bigint::operator>>(const bigint &src)const
{

}
// bigint operator>>(unsigned int n)const;
// bigint &operator>>=(unsigned int n);
// bigint &operator>>=(const bigint &src);
// bigint &operator<<=(unsigned int n);
// bigint &operator<<=(const bigint &src);