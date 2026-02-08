#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <sstream>

class bigint
{
	private :
		std::string nb_in_str;		//nombre stocke en string

	public :

		bigint();
		bigint(unsigned int nb);		//entier en big int
		bigint(const bigint &copy);		//constructeur de recopie
		bigint &operator=(const bigint& copy);
		~bigint();

		// getter
		std::string get_nb() const;
	
		//addition
		bigint operator+(const bigint &src) const;		//renvoie un nv bigint , ne modifie rien
		bigint &operator+=(const bigint &src);			//renvoie une reference, on modif l'objet
		bigint &operator++();	//++a		//renvoie l'objet modifie
		bigint operator++(int);		//a++		//renvoie une copie de l'objet avant modif

		//comparaison (==, !=, <, >, >=, <=)
		bool operator==(const bigint &srcs)const;
		bool operator!=(const bigint &srcs)const;
		bool operator<(const bigint &srcs)const;
		bool operator>(const bigint &srcs)const;
		bool operator<=(const bigint &srcs)const;
		bool operator>=(const bigint &srcs)const;

		//bitshifting (<<, >>, >>=, <<=)
		bigint operator<<(const bigint &srcs)const;
		bigint operator<<(unsigned int n)const;
		bigint operator>>(const bigint &srcs) const;
		bigint operator>>(unsigned int n) const;
		bigint &operator<<=(const bigint &srcs)const;
		bigint &operator<<=(unsigned int n)const;
		bigint &operator<<=(const bigint &srcs)const;
		bigint &operator<<=(unsigned int n)const;

};

std::ostream &operator<<(std::ostream &out, const bigint &src);

#endif


// addition : +=, +, compaison : >, <, !=, ==, <=, >=, Digitshift : >>, <<, <<=, >>=
//++ (prefix et suffix)

