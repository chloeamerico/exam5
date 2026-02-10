#include "bigint.hpp"

bigint::bigint() : str("0") {}

bigint::bigint(unsigned int n)
{
	std::ostringstream	buffer;
	buffer << n;
	str = buffer.str();
}

bigint::bigint(const bigint& copy) : str(copy.str) {}

bigint& bigint::operator=(const bigint& copy)
{
	if(*this != copy)
		str = copy.str;
	return *this;
}

bigint::~bigint() {}


//------------------

//getter

std::string bigint::get_str() const
{
	return str;
}


//addition

bigint bigint::operator+(const bigint& srcs) const
{
	//1- recup les chaines

	std::string s1 = this->str;
	std::string s2 = srcs.str;

	//2- s1 doit etre < s2

	if (s1.length() > s2.length())
		std::swap(s1, s2);
	
	//3- on initialise

	int i = s1.length() - 1;
	int j = s2.length() - 1;
	std::string result;
	int retenue = 0;

	//boucle
	while(retenue || j >= 0 || i >= 0)
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
	return (resultat);
}

bigint& bigint::operator+=(const bigint& srcs)
{
	*this = *this + srcs;
	return *this;
}

bigint& bigint::operator++()
{
	return (*this += bigint(1));
}

bigint bigint::operator++(int)
{
	bigint copy(*this);
	*this += bigint(1);
	return copy;

}