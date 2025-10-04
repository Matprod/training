#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
using std::string;
using std::cout;
using std::endl;

class bigint
{
	private:
		string str;
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint& source);

		std::string getStr()const;

		bigint& operator=(const bigint& source);

		// addition
		bigint operator+(const bigint& other)const;
		bigint& operator+=(const bigint& other);

		// increments
		bigint& operator++(); // ++x
		bigint operator++(int); // x++

		// shift with num
		bigint operator<<(unsigned int n)const;
		bigint operator>>(unsigned int n)const;
		bigint& operator<<=(unsigned int n);
		bigint& operator>>=(unsigned int n);

		//shift with object
		bigint operator<<(const bigint& other)const;
		bigint operator>>(const bigint& other)const;
		bigint& operator<<=(const bigint& other);
		bigint& operator>>=(const bigint& other);

		// ==, !=, <, >, <=, >=
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;
		//
};
std::ostream& operator<<(std::ostream& output, const bigint& obj);
