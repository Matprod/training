#pragma once

#include <iostream>

class vect2{
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &source);
		vect2 &operator=(const vect2 &source);
		~vect2();

		int &operator[](int index);
		int operator[](int index)const;
		vect2 operator-() const;

		vect2 operator++(int);
		vect2 &operator++();
		vect2 operator--(int);
		vect2& operator--();

		vect2& operator+=(const vect2 &obj);
		vect2& operator-=(const vect2 &obj);
		vect2& operator*=(int num);

		vect2 operator*(int num)const;
		vect2 operator+(const vect2 &obj)const;
		vect2 operator-(const vect2 &obj)const;
		vect2 operator*(const vect2 &obj)const;
		

		
		bool operator==(const vect2& obj) const;
		bool operator!=(const vect2& obj) const;

	private:
		int x;
		int y;
};

std::ostream &operator<<(std::ostream &stream, const vect2 &obj);
vect2 operator*(int num, const vect2 &obj);