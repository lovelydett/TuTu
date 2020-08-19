#ifndef CANVAS_H
#define CANVAS_H

#include "bitmap.h"
#include "baseShape.h"
//Canvas是虚拟的“画家”，在底层bitmap上画画
class Canvas{
public:
    static Canvas* instancePtr;
    Bitmap bitmap;    
    //画一个图形，后期需要加上Paint
    bool draw(BaseShape* shape);
    static Canvas& getInstance();
};

#endif