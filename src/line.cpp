#include <cmath>
#include "line.h"
#include "log.h"
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
    //LOG("record","Drawing a line between "+x0+","+y0+" to "+x1+","+y1)
    printf("drawing a line between %d,%d and %d,%d\n",x0,y0,x1,y1);
    float k = (y1-y0)/ ((x1-x0)<EPSILON?EPSILON:(x1-x0));
    bool isXBase = true;//指示当前是否以x为基底
    if (fabs(k)>1) {
        //决定以谁为基准
        isXBase = false;
        swap<int>(x0,y0); 
        swap<int>(x1,y1);
    }
    //dx和dy的正负号与直线起点终点关系有关！
    int dx = x0<x1?1:-1;
    int dy = y0<y1?1:-1;
    //计算a和b,d在(x0,y0)位置为0，第一个要判断的其实是a+b/2,即2a+b
    int a = y0-y1, b = x1-x0;
    int deltaD1 = 2*a, deltaD2 = 2*(a+b),d = 2*a+b;
    std::vector<PixelI> pixels;
    //pixels.reserve(x1-x0+1);//点的数量是确定的,超过限制预留大小，不能这样写
    //开始画线
    if(isXBase)pixels.push_back(PixelI(x0,y0,c));
    else pixels.push_back(PixelI(y0,x0,c));
    printf("a = %d, b = %d\n",a,b);
    printf("d1 = %d, d2 = %d\n",deltaD1,deltaD2);
    if(isXBase)printf("以x为基准\n");
    else printf("以y为基准\n");
    int x = x0, y = y0;
    while(x!=x1){
        d<0?(x+=dx,y+=dy,d+=deltaD2):(x+=dx,d+=deltaD1);
        if(isXBase)pixels.push_back(PixelI(x,y,c));
        else pixels.push_back(PixelI(y,x,c));//需要根据当前基准判断放入像素的坐标顺序
        printf("d = %d, ",d);
        if (isXBase)printf("point at: %d,%d\n",x,y);
        else printf("point at: %d,%d\n",y,x);
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
