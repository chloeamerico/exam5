#include "bigint.hpp"

bigint::bigint() : str("0"){}

bigint::bigint(unsigned int n)
{
	std::stringstream buffer;
	buffer << n;
	str = buffer.str();
}

bigint::bigint(const bigint& copy) : str(copy.str) {}

bigint& bigint::operator=(const bigint& copy)
{
	if (*this != copy)
		str = copy.str;
	
	return *this;
}

bigint::~bigint() {}

//addition 

bigint bigint::operator+(const bigint& srcs) const
{
	//recup
	std::string s1 = str;
	std::string s2 = srcs.str;

	//s1 > s2
	if(s1.length() < s2.length())
		std::swap(s1, s2);

	//init
	std::string result;
	int i = s1.length() - 1;
	int j = s2.length() - 1;
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
	bigint resultat;
	resultat.str = result;
	return resultat;
}

bigint& bigint::operator+=(const bigint& srcs)
{
	*this = *this + srcs;
	return (*this);
}

bigint& bigint::operator++()
{
	return *this += bigint(1);
}

bigint bigint::operator++(int)
{
	bigint copy(*this);
	*this += bigint(1);
	return copy;
}

//comparaison

bool bigint::operator==(const bigint &srcs) const
{
	return (this->str == srcs.str);
}

bool bigint::operator!=(const bigint &srcs) const
{
	return !(*this == srcs);
}

bool bigint::operator<(const bigint &srcs) const
{
	if(str.length() < srcs.str.length())
		return (true);
	else if (str.length() == srcs.str.length())
		return (str < srcs.str);
	else
		return false;
}

bool bigint::operator>(const bigint &srcs) const
{
	return srcs < *this;
}

bool bigint::operator<=(const bigint &srcs) const
{
	return !(*this > srcs);
}

bool bigint::operator>=(const bigint &srcs) const
{
	return !(*this < srcs);
}

//bitshifting

unsigned int str_to_uint(std::string str)
{
	return (std::stoul(str));
}

//on ajoute des 0 avec append
bigint bigint::operator<<(const bigint& srcs)const
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

//on supprime des char avec erase
bigint bigint::operator>>(const bigint& srcs)const
{
	unsigned int n = str_to_uint(srcs.str);
	bigint copy(*this);
	
	//si on veut enlever plus de char qu'il n'y en a
	if (n >= copy.str.length())
		copy.str = "0";
	else
		copy.str.erase(copy.str.length() - n, n);
	return copy;
}

bigint bigint::operator>>(unsigned int n)const
{
	bigint	copy(*this);
	if(n >= copy.str.length())
		copy.str = "0";
	else
		copy.str.erase(copy.str.length() - n, n);
	return copy;
}

bigint& bigint::operator<<=(const bigint& srcs)
{
	*this = *this << srcs;
	return *this;
}

bigint& bigint::operator<<=(unsigned int n)
{
	*this = *this << n;
	return *this;
}

bigint& bigint::operator>>=(const bigint& srcs)
{
	*this = *this >> srcs;
	return *this;
}

bigint& bigint::operator>>=(unsigned int n)
{
	*this = *this >> n;
	return *this;
}

//getter 

std::string	bigint::get_str() const
{
	return str;
}

//ostream
std::ostream& operator<<(std::ostream &out, const bigint& srcs)
{
	out << srcs.get_str();
	return (out);
}