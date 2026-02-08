#include "test.hpp"

bigint::bigint() : str("0") {}

bigint::bigint(unsigned int n) {
	if (n == 0)
		this->str = "0";
	while (n > 0) {
		this->str.push_back((n % 10) + '0');
		n = n / 10;
	}
	std::reverse(this->str.begin(), this->str.end());
}

bigint& bigint::operator=(const bigint &src) {
	this->str = src.str;
	return *this;
}

bigint::~bigint() {}

std::string bigint::get_str()const {
	return this->str;
}

bool bigint::operator!=(const bigint &src)const {
	return !(*this == src);
}

bool bigint::operator==(const bigint &src)const {
	return (this->str == src.str);
}

bool bigint::operator>(const bigint &src)const {
	if (this->str.length() > src.str.length())
		return true;
	else if (this->str.length() == src.str.length())
		return (this->str > src.str);
	return false;
}

bool bigint::operator>=(const bigint &src)const {
	return !(*this < src);
}

bool bigint::operator<(const bigint &src)const {
	return (src > *this);
}

bool bigint::operator<=(const bigint &src)const {
	return !(*this > src);
}

bigint bigint::operator+(const bigint &src)const {
	std::string s1 = this->str;
	std::string s2 = src.str;

	if (s1.length() < s2.length())
		std::swap(s1, s2);
	std::string res;
	int i = s1.length() - 1;
	int j = s2.length() - 1;
	int carry = 0;

	while(i >= 0 || j >= 0 || carry) {
		int digit1 = i >= 0 ? s1[i] - '0' : 0;
		int digit2 = j >= 0 ? s2[j] - '0' : 0;
		int sum = digit1 + digit2 + carry;
		res.push_back((sum % 10) + '0');
		carry = sum / 10;
		i--;
		j--;
	}
	std::reverse(res.begin(), res.end());
	bigint result;
	result.str = res;
	return result;
}

bigint &bigint::operator++() {
	return (*this += bigint(1));
}

bigint bigint::operator++(int) {
	bigint cpy(*this);
	*this += bigint(1);
	return (cpy);
}

bigint &bigint::operator+=(const bigint &src) {
	*this = *this + src;
	return *this;
}

unsigned int str_to_unit(std::string str) {
	return (stoul(str));
}

bigint bigint::operator<<(const bigint &src)const {
	unsigned int n = str_to_unit(src.str);
	bigint cpy(*this);
	cpy.str.append(n, '0');
	return cpy;
}

bigint bigint::operator<<(unsigned int n)const {
	bigint cpy(*this);
	cpy.str.append(n, '0');
	return cpy;
}

bigint bigint::operator>>(const bigint &src)const {
	unsigned int n = str_to_unit(src.str);
	bigint cpy(*this);
	if (n >= cpy.str.size())
		cpy.str = "0";
	else
		cpy.str.erase(cpy.str.size() - n, n);
	return cpy;
}

bigint bigint::operator>>(unsigned int n)const {
	bigint cpy(*this);
	if (n >= cpy.str.size())
		cpy.str = "0";
	else
		cpy.str.erase(cpy.str.size() - n, n);
	return cpy;
}

bigint &bigint::operator>>=(const bigint &src) {
	*this = *this >> src;
	return *this;
}

bigint &bigint::operator>>=(unsigned int n) {
	*this = *this >> n;
	return *this;
}

bigint &bigint::operator<<=(const bigint &src) {
	*this = *this << src;
	return *this;
}

bigint &bigint::operator<<=(unsigned int n) {
	*this = *this << n;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const bigint &src) {
	out << src.get_str();
	return out;
}
