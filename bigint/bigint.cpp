#include "bigint.hpp"

bigint::bigint()
{
	this->str = "0";
}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	this->str = ss.str();
}

bigint::bigint(const bigint &source)
{
	*this = source;
}

bigint& bigint::operator=(const bigint& source)
{
	if(this == &source)
		return(*this);
	this->str = source.str;
	return(*this);
}


string bigint::getStr()const
{
	return(this->str);
}

string reverse(const string str)
{
	string reverse;
	int len;

	len = str.length();
	while(len > 0)
	{
		reverse.push_back(str[len - 1]);
		len--;
	}
	return (reverse);
}

string addition(const bigint& obj1, const bigint& obj2)
{
	string str1 = reverse(obj1.getStr());
	string str2 = reverse(obj2.getStr());
	string result;

	size_t len1 = str1.length();
	size_t len2 = str2.length();
	size_t len;

	int digit1 = 0;
	int digit2 = 0;
	int carry = 0;

	if (len1 > len2)
	{
		int diff = len1 - len2;
		while(diff > 0)
		{
			str2.push_back('0');
			diff--;
		}
	}
	if (len2 > len1)
	{
		int diff = len2 - len1;
		while(diff > 0)
		{
			str1.push_back('0');
			diff--;
		}
	}
	len = str1.length();
	for (size_t i = 0; i < len; i++)
	{
		digit1 = str1[i] - '0';
		digit2 = str2[i] - '0';
		int res = digit1 + digit2 + carry;
		if (res > 9)
		{
			carry = res /10;
			result.push_back((res % 10) + '0');
		}
		else
			result.push_back(res + '0');

	}
	if (carry != 0)
	{
		result.push_back(carry + '0');
	}
	return(reverse(result));
}

bigint bigint::operator+(const bigint &other)const
{
	bigint temp = other;
	temp.str.clear();
	string result = addition(other, *this);
	temp.str = result;
	return (temp);
}

bigint& bigint::operator+=(const bigint &other)
{
	(*this) = (*this) + other;
	return (*this);

}

bigint& bigint::operator++()
{
	(*this) = (*this) + bigint(1);
	return (*this);
	
}
bigint bigint::operator++(int)
{
	bigint temp = (*this);
	(*this) = (*this) + bigint(1);
	return (temp);
	
}

bigint bigint::operator<<(unsigned int n)const
{
	bigint temp = *this;
	temp.str.insert(temp.str.end(), n, '0');
	return (temp);
}

bigint bigint::operator>>(unsigned int n)const
{
	bigint temp = *this;
	size_t length = temp.str.length();
	if (n > length)
	{
		temp.str = "0";
	}
	else
	{
		temp.str.erase(length-n, n);
	}
	return temp;
}

bigint& bigint::operator<<=(unsigned int n)
{
	(*this) = (*this) << n;
	return (*this);

}

bigint& bigint::operator>>=(unsigned int n)
{
	(*this) = (*this) >> n;
	return (*this);

}

unsigned int stringToUINT(std::string str)
{
	std::stringstream ss;
	ss << str;
	unsigned int res;

	ss >> res;

	return (res);
}

bigint bigint::operator<<(const bigint& other)const
{
	bigint temp;
	temp = (*this) << stringToUINT(other.str);
	return (temp);
}

bigint bigint::operator>>(const bigint& other)const
{
	bigint temp;
	temp = (*this) >> stringToUINT(other.str);
	return (temp);
}

bigint& bigint::operator>>=(const bigint& other)
{
	(*this) = (*this) >> stringToUINT(other.str);
	return (*this);
}

bigint& bigint::operator<<=(const bigint& other)
{
	(*this) = (*this) << stringToUINT(other.str);
	return (*this);
}

bool bigint::operator==(const bigint& other) const
{
	return this->getStr() == other.getStr();
}

bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}

bool bigint::operator<(const bigint& other) const
{
	string str1 = this->getStr();
	string str2 = other.getStr();
	size_t len1 = str1.length();
	size_t len2 = str2.length();
	if (len1 != len2)
	{
		return (len1 < len2);
	}
	return (str1 < str2);
}

bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}

bool bigint::operator>=(const bigint& other) const
{
	return (*this > other) || (*this == other);
}


bool bigint::operator<=(const bigint& other) const
{
	return (*this < other) || (*this == other);
}


std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.getStr();
	return(output);
}