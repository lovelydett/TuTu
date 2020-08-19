#ifndef LINE_H
#define LINE_H

#include "baseShape.h"
#include "point.h"

class Line : public BaseShape{
public:
    Point start;
    Point end;
    Line():start(0,0),end(0,0),BaseShape(RED){}
    Line(Point& start, Point& end):start(start),end(end){}
    Line(float startX, float startY, float endX, float endY):start(startX,startY),end(endX,endY){}
    Line& set(float startX, float startY, float endX, float endY);
    Line& set(Point& start, Point& end);
    std::vector<PixelI> draw();
    bool updateSelectPoints();
};



#endif