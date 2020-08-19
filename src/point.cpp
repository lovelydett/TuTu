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
    Point p(x-point.x,y-point.y);
    return p;
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
    Point p(x+point.x,y+point.y);
    return p;
}

Point Point::operator* (float r) 
{
    Point p(x*r,y*r);
    return p;
}

Point Point::operator/ (float r) 
{
    Point p(x/r,y/r);
    return p;
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



