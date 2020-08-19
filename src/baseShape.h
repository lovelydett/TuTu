/*
tt 
2020.8.18
version 1.0 : Implementation only, no care of performance and robustness.
*/
#ifndef BASESHAPE_H
#define BASESHAPE_H

#include <vector>

#include "point.h"
#define EPSILON 1e-5f
template<class T>
void swap(T& a, T& b){T temp = a; a = b; b = temp;}
enum Color {RED = 1,BLUE,GREEN};//颜色
typedef struct PixelInt{
    int x;
    int y;
    Color c;
    PixelInt(int x, int y, Color c):x(x),y(y),c(c){}
}PixelI;//用int表示的像素点，前期用
typedef struct PixelFloat{
    float x;
    float y;
    Color c;
    PixelFloat(float x,float y, Color c):x(x),y(y),c(c){}
    
}PixelF;//用float表示的像素点，以后有了绘图引擎用

class BaseShape{
public:
    /*
    包围该图形的平行四边形框选框
    pt[0]-pt[3]顺时针
    */
    Point points[4];

    //图形颜色
    Color c;

    /*
    返回值：图形边界的坐标列表
    */
    virtual std::vector<PixelI> draw() = 0;
    //virtual std::vector<PixelF> draw() = 0;

    /*
    根据图形当前的位置和形状更新框选框的四个点
    */
    virtual bool updateSelectPoints()=0;
    bool setColor(Color c){this->c = c; return true;}
    
    BaseShape():c(RED){}
    BaseShape(Color c):c(c){}
};
#endif

