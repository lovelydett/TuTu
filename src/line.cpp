#include <cmath>
#include "line.h"
Line& Line::set(float startX, float startY, float endX, float endY) 
{
    start.x = startX;
    start.y = startY;
    end.x = endX;
    end.y = endY;
    return *this;
}

Line& Line::set(Point& start, Point& end) 
{
    this->start = start;
    this->end = end;
    return *this;
}

std::vector<PixelI> Line::draw() 
{
    //中点画线法实现直线扫描转换算法
    int x0 = start.x, y0 = start.y;
    int x1 = end.x, y1 = end.y;
    float k = (y1-y0)/ (x1-x0)<EPSILON?EPSILON:(x1-x0);
    if (fabs(k)>1) {
        //决定以谁为基准
        swap<int>(x0,y0); 
        swap<int>(x1,y1);
        k = 1.f/k;
    }
    //计算a和b,d在(x0,y0)位置为0，第一个要判断的其实是a+b/2,即2a+b
    int a = y0-y1, b = x0-x1;
    int deltaD1 = 2*a, deltaD2 = 2*(a+b),d = 2*a+b;
    std::vector<PixelI> pixels;
    pixels.reserve(x1-x0+1);//点的数量是确定的
    //开始画线
    pixels.push_back(PixelI(x0,y0,c));
    for(int x = x0;x<x1;x++){
        if(d<0){
            //中点在直线下，应画上方点，增量为deltaD2
            pixels.push_back(PixelI(x+1,x+1,c));
            d+=deltaD2;
        }else{
            pixels.push_back(PixelI(x+1,x,c));
            d+=deltaD1; 
        }
    }
    return pixels;
}

bool Line::updateSelectPoints() 
{
    //直线不管怎么变，都是不会发生错切的
    points[0] = points[1] = start.y>end.y? start: end;
    points[2] = points[3] = start.y>end.y? end  : start;
    return true;
}
