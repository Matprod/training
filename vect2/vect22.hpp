#pragma once

#include <iostream>

class vect2{
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &source);
		vect2 operator=(const vect2 &source);
		~vect2();

		vect2 operator++(int)const;
		vect2 &operator++();
		vect2 operator--(int)const;
		vect2& operator--();


	private:
		int x;
		int y;
};