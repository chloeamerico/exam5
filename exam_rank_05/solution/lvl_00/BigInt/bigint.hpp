#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string.h>
#include <iostream>
#include <sstream>

class bigint
{
private:
    std::string m_value;

    void trim();        //supprime les 0 non significatifs (ex 00123 devient 123)
    void check_digits();    //vérifie que la chaîne ne contient que des chiffres

public:
    bigint();   //cree un bigint aui vaut 0
    bigint(unsigned int num);               //convertit un entier classique en bigint
    bigint(const std::string &num);         // crée un bigint à partir d'une chaîne (avec normalisation)
    bigint(const bigint &copy);
    ~bigint();

    bigint &operator=(const bigint &other);
    bigint &operator+=(const bigint &other);

    const std::string &get_value() const;

    bigint &operator<<=(int k);
    bigint &operator>>=(int k);

    //  The compiler distinguishes between prefix and postfix by using a dummy int; postfix uses the dummy int.
    bigint &operator++();
    bigint operator++(int);
};

std::ostream &operator<<(std::ostream &out, const bigint &num);

int compare_string(const std::string &A, const std::string &B);

bool operator==(const bigint &a, const bigint &b);
bool operator!=(const bigint &a, const bigint &b);
bool operator<(const bigint &a, const bigint &b);
bool operator<=(const bigint &a, const bigint &b);
bool operator>(const bigint &a, const bigint &b);
bool operator>=(const bigint &a, const bigint &b);

bigint operator+(const bigint &a, const bigint &b);

bigint operator>>(const bigint &num, int k);
bigint operator<<(const bigint &num, int k);

#endif