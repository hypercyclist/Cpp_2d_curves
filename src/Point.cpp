#include "Point.h"

Point::Point() : x(0), y(0)
{
}

Point::Point(int _x, int _y) : x(_x), y(_y)
{
}

Point::~Point()
{
}

int Point::getX()
{
    return x;
}

void Point::setX(int _x)
{
    x = _x;
}

int Point::getY()
{
    return y;
}

void Point::setY(int _y)
{
    y = _y;
}

Point& Point::operator+=(const Point& rhs) 
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

const Point Point::operator+(const Point& rhs) const 
{
	return Point(*this) += rhs;
}
