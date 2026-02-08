#include "bigint.hpp"

bigint::bigint() : nb_in_str("0") {}

//unsigned int en str
bigint::bigint(unsigned int nb)
{
	std::stringstream buffer;
	buffer << nb;
	this->nb_in_str = buffer.str();
}

bigint::bigint(const bigint& copy) : nb_in_str(copy.nb_in_str) {}

bigint& bigint::operator=(const bigint& copy)
{
	if(this != &copy)
	{
		this->nb_in_str = copy.nb_in_str;
	}
	return *this;
}

bigint::~bigint() {}

//getter
std::string bigint::get_nb() const
{
	return nb_in_str;
}

//addition +, +=, ++, ++

bigint bigint::operator+(const bigint& src) const
{
	//1- on recup les deux bigint

	std::string s1 = this->nb_in_str;
	std::string s2 = src.nb_in_str;

	//2- premier toujours > a l'autre

	if (s2.length() > s1.length())
		std::swap(s1, s2);

	//3- on initialise tout

	int i = s1.length() - 1;
	int j = s2.length() - 1;
	int retenue = 0;
	std::string resultat;

	//4- boucle

	while (i >= 0 || j >= 0 || retenue)
	{
		int nb1 = 0;
		if(i >= 0)
			nb1 = s1[i] - '0';		//char -> int : - '0'
		
		int nb2 = 0;
		if(j >= 0)
			nb2 = s2[j] - '0';
		
		int sum = nb1 + nb2 + retenue;
		resultat.push_back((sum % 10) + '0');	//int -> char : + '0'
		retenue = sum / 10;

		i--;
		j--;
	}

	//on cree le result en le retournant 

	std::reverse(resultat.begin(), resultat.end());

	bigint res;

	res.nb_in_str = resultat;
	return res;

}

// bigint &operator+=(const bigint& srcs)
bigint& bigint::operator+=(const bigint &src)
{
	*this = *this + src;
	return *this;
}

bigint& bigint::operator++()		//++a
{
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int)	//a++
{
	//on copie l'etat avant incrementation
	bigint copy(*this);

	*this += bigint(1);
	return copy;
}


//comparaison (==, !=, <, >, >=, <=)

bool bigint::operator==(const bigint &srcs) const
{
	if (this->nb_in_str == srcs.nb_in_str)
		return true;
	else
		return false;
}

bool bigint::operator!=(const bigint &srcs) const
{
	if (this->nb_in_str != srcs.nb_in_str)
		return true;
	else
		return false;
}

bool bigint::operator<(const bigint &srcs) const
{
	return srcs > *this; 
}

bool bigint::operator>(const bigint &srcs) const
{
	if (this->nb_in_str.length() > srcs.nb_in_str.length())
		return true;
	else if (this->nb_in_str.length() == srcs.nb_in_str.length())
		return (this->nb_in_str > srcs.nb_in_str);
	else
		return false;
}

bool bigint::operator<=(const bigint &srcs) const
{
	return !(*this < srcs); 
}

bool bigint::operator>=(const bigint &srcs) const
{
	return !(*this > srcs);
}
