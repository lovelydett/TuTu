#include "point.h"

Point& Point::set(Point& point) 
{
    x = point.x;
    y = point.y;
    return *this;
}

Point& Point::set(float x, float y) 
{
    this->x = x;
    this->y = y;
    return *this;
}

Point& Point::operator= (Point& point) 
{
    x = point.x;
    y = point.y;
    return *this;
}

Point Point::operator- (Point& point) 
{
    return Point(x-point.x,y-point.y);
}

Point& Point::operator+=(Point& point) 
{
    x += point.x;
    y += point.y;
    return *this;
}

Point& Point::operator-=(Point& point) 
{
    x -= point.x;
    y -= point.y;
    return *this;
}

Point Point::operator+ (Point& point) 
{
    return Point(x+point.x,y+point.y);
}

Point Point::operator* (float r) 
{
    return Point(r*x,r*y);
}

Point Point::operator/ (float r) 
{
    return Point(x/r,y/r);
}

Point& Point::operator*= (float r) 
{
    x*=r,y*=r;
    return *this;
}

Point& Point::operator/= (float r) 
{
    x/=r,y/=r;
    return *this;
}



