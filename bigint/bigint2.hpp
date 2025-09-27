#pragma once

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class bigint
{
	public:
		bigint();
		bigint(unsigned int);
		bigint(const bigint& src);

		string getStr();

		bigint &operator=(const bigint& other);

		bigint operator+(const bigint& other)const;
		bigint &operator+=(const bigint& other);

		bigint &operator++();
		bigint operator++(int);

		bigint operator<<(unsigned int num)const;
		bigint operator>>(unsigned int num)const;
		bigint &operator<<=(unsigned int num);
		bigint &operator>>=(unsigned int num);

		bigint operator<<(const bigint &other)const;
		bigint operator>>(const bigint &other)const;
		bigint &operator<<=(const bigint &other);
		bigint &operator>>=(const bigint &other);

		bool operator<(const bigint &other)const;
		bool operator>(const bigint &other)const;
		bool operator==(const bigint &other)const;
		bool operator!=(const bigint &other)const;
		bool operator<=(const bigint &other)const;
		bool operator>=(const bigint &other)const;


	private:
		string str;
};
std::ostream &operator<<(std::ostream &obj,const bigint &bigint);

