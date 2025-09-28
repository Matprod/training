#include "vect22.hpp"

vect2::vect2()
{
	this->x = 0;
	this->y = 0;
}

vect2::vect2(int num, int num2)
{
	this->x = num;
	this->y = num2;
}

vect2::vect2(const vect2 &source)
{
	*this = source;
}

vect2 vect2::operator=(const vect2 &source)
{
	if (this != &source)
	{
		this->x = source.x;
		this->y = source.y;
	}
	return (*this);
}

vect2& vect2::operator++()
{
	
	return(*this);
}

















vect2::~vect2()
{

}