#include "bigint.hpp"

bigint::bigint(): str("0")
{}

bigint::bigint(const bigint &src)
{
	*this = src;
}

//unsignedint vers string
bigint::bigint(unsigned int nb) 
{
	std::ostringstream buffer;
	buffer << nb;
	this->str = buffer.str();
}

bigint &bigint::operator=(const bigint &src)
{
	this->str = src.str;
	return (*this);
}

bigint::~bigint()
{}

bigint bigint::operator+(const bigint &src)const
{
	// recupere les deux bigint
	std::string s1 = this->str;
	std::string s2 = src.str;
	// le premier chiffre doit toujours etre > a l'autre. Plus ismple pour le calcul
	if (s1.length() < s2.length()) 
		std::swap(s1, s2);
	std::string res;
	int i = s1.length() - 1; // index sur dernier chiffre de s1
	int j = s2.length() - 1; // index sur dernier chiffre de s2
	int carry = 0;  // la retenue
	while (i >= 0 || j >=0 || carry)
	{
		// int digit1 = i >= 0 ? s1[i] - '0' : 0; // si il reste des chiffres dans la string, on le convertit en int
		// int digit2 = j >= 0 ? s2[j] - '0' : 0; // sinon c'est egale a 0
		int digit1 = 0;
        if (i >= 0)
            digit1 = s1[i] - '0';

        int digit2 = 0;
        if (j >= 0)
            digit2 = s2[j] - '0';
		
		int sum = digit1 + digit2 + carry; 
		res.push_back((sum % 10) + '0'); // On ajoute à la chaîne le chiffre résultat (sum % 10) converti en char
		carry = sum / 10; // On calcule la retenue pour l'iteration suivante
		i--;
		j--;
	}
	std::reverse(res.begin(), res.end());
	bigint result;
	result.str = res;
	return (result);
}

bigint &bigint::operator+=(const bigint &src)
{
	*this = *this + src; // equivalent a : a + b = a
	return (*this);
}

bigint &bigint::operator++()
{
	return(*this += bigint(1)); // retourne a + 1
}

bigint bigint::operator++(int)
{
	bigint cpy(*this); // Copier l'etat avant l'incrementation
	*this += bigint(1); // Incrementation
	return (cpy); // return ancienne valeur
}

std::string bigint::get_str()const
{
	return (this->str); // retorune la string du bigint
}

bool bigint::operator==(const bigint &src)const
{
	// Deux bigint sont égaux si :
	// 1. Ils ont la même longueur
	// 2. Leurs strings sont identiques
	return (/*this->str.length() == src.str.length() &&*/ this->str == src.str);
}

bool bigint::operator!=(const bigint &src)const
{
	// Deux bigint sont différents si ils ne sont pas égaux
	return !(*this == src);
}

bool bigint::operator>(const bigint &src)const
{
	// Un bigint est plus grand qu'un autre si :
	// 1. Il a plus de chiffres
	// 2. S'ils ont le même nombre de chiffres, on compare les strings directement
	if (this->str.length() > src.str.length())
		return (true);
	else if (this->str.length() == src.str.length())
		return (this->str > src.str);
	return (false);
}

bool bigint::operator<(const bigint &src)const
{
	// Un bigint est plus petit qu'un autre si l'autre est plus grand que lui
	return (src > *this /* && *this != src*/ );
}

bool bigint::operator>=(const bigint &src)const
{
	// Si a < b est faux, alors a >= b est vrai.
	return !(*this < src);
}

bool bigint::operator<=(const bigint &src)const
{
	// Si a > b est faux, alors a <= b est vrai.
	return !(*this > src);
}



unsigned int str_to_uint(std::string str)
{
	// Convertit une string en unsigned int
	// stoul = string to unsigned long
	return (stoul(str));
}

// Decalage vers la gauche, rajouter des 0 a la fin
bigint bigint::operator<<(const bigint &src)const
{
	unsigned int n = str_to_uint(src.str); // Convertit la str en int
	bigint cpy(*this); // cree une copie de l'objet courant
	cpy.str.append(n, '0'); // ajoute n zeros la fin de la string
	return (cpy); // retourne la copie modifiee
}

bigint bigint::operator<<(unsigned int n)const
{
	//pareil
	bigint cpy(*this);
	cpy.str.append(n, '0');
	return (cpy);
}

// Decalage vers la droite, supprimer les derniers caracteres
bigint bigint::operator>>(const bigint &src)const
{
	unsigned int n = str_to_uint(src.str);
	bigint cpy(*this);
	if (n >= cpy.str.size()) // Si on souhaite enlever plus de caracteres qu'ils n'exsient
		cpy.str = "0";
	else
		cpy.str.erase(cpy.str.size() - n, n); // sinon enlever n derniers chiffres
	return (cpy);
}

bigint bigint::operator>>(unsigned int n)const
{
	// pareil
	bigint cpy(*this);
	if (n >= cpy.str.size())
		cpy.str = "0";
	else
		cpy.str.erase(cpy.str.size() - n, n);
	return (cpy);
}

bigint &bigint::operator>>=(unsigned int n)
{
	*this = *this >> n;
	return (*this);
}

bigint &bigint::operator>>=(const bigint &src)
{
	*this = *this >> src;
	return (*this);
}

bigint &bigint::operator<<=(unsigned int n)
{
	*this = *this << n;
	return (*this);
}

bigint &bigint::operator<<=(const bigint &src)
{
	*this = *this << src;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const bigint &src)
{
	out << src.get_str();
	return (out);
}