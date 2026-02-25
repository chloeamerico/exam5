#include "bigint.hpp"

bigint::bigint() : str("0") {}

bigint::bigint(unsigned int n)
{
	std::stringstream buffer;
	buffer << n;
	str = buffer.str();
}

bigint::bigint(const bigint& copy) : str(copy.str) {}

bigint& bigint::operator=(const bigint& copy)
{
	if (this != &copy)
	{
		str = copy.str;
	}
	return *this;
}

bigint::~bigint() {}


//getter
std::string bigint::get_str() const
{
	return str;
}

bigint bigint::operator+(const bigint& srcs) const
{
	//recup les string
	
	std::string s1 = str;
	std::string s2 = srcs.str;

	//s1 > s2

	if (s1.length() < s2.length())
		std::swap(s1, s2);

	//init

	int i = s1.length() - 1;
	int j = s2.length() - 1;
	std::string result;
	int retenue;

	//boucle
	while(i >= 0 || j >= 0 || retenue)
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
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint copy(*this);
	*this += bigint(1);
	return *this;
}

//comparaison

bool bigint::operator==(const bigint &src)const
{
	return(this->str == src.str);
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
	{
		return(str > src.str);
	}
	else
		return false;
}

bool bigint::operator<(const bigint &src)const
{
	return !(src > *this);
}

bool bigint::operator<=(const bigint &src)const
{
	return !(*this > src);
}

bool bigint::operator>=(const bigint &src)const
{
	return !(*this < src);
}

//bitshigting

unsigned int str_to_uint(std::string str)
{
	return (std::stoul(str));
}

//on ajoute avec append 
bigint bigint::operator<<(const bigint& srcs) const
{
	unsigned int n = str_to_uint(srcs.str);
	bigint copy(*this);
	copy.str.append(n, '0');
	return copy;
}

bigint bigint::operator<<(unsigned int n) const
{
	bigint copy(*this);
	copy.str.append(n, '0');
	return copy;
}

bigint bigint::operator>>(const bigint& srcs) const
{
	unsigned int n = str_to_uint(srcs.str);
	bigint copy(*this);

	if(n >= copy.str.length())
		copy.str = "0";
	else
		copy.str.erase(copy.str.length() - n, n);

	return copy;
}

bigint bigint::operator>>(unsigned int n) const
{
	bigint copy(*this);

	if(n >= copy.str.length())
		copy.str = "0";
	else
		copy.str.erase(copy.str.length() - n, n);

	return copy;
}

bigint&	bigint::operator<<=(const bigint& srcs)
{
	*this = *this << srcs;
	return *this;
}

bigint&	bigint::operator<<=(unsigned int n)
{
	*this = *this << n;
	return *this;
}

bigint&	bigint::operator>>=(const bigint& srcs)
{
	*this = *this >> srcs;
	return *this;
}

bigint&	bigint::operator>>=(unsigned int n)
{
	*this = *this >> n;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const bigint &src)
{
	out << src.get_str();
	return out;
}