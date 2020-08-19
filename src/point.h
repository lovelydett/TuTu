/*
tt 
2020.8.18
version 1.0 : Implementation only, no care of performance and robustness.
*/
# ifndef POINT_H
# define POINT_H
class Point{
public:
    float x;
    float y;
    Point(): x(.0),y(.0){}
    Point(float xx,float yy):x(xx),y(yy){}
    Point(Point& point):x(point.x),y(point.y){}
    Point& set(Point& point);
    Point& set(float x, float y);
    Point& operator= (Point& point);
    Point operator- (Point& point);
    Point operator+ (Point& point);
    Point operator* (float r);
    Point operator/ (float r);
    Point& operator+=(Point& point);
    Point& operator-=(Point& point);
    Point& operator*=(float r);
    Point& operator/=(float r);
};




# endif