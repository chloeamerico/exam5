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

bigint operator+()
