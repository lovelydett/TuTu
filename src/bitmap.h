/*
tt 
2020.8.18
version 1.0 : Implementation only, no care of performance and robustness.
*/
#ifndef BITMAP_H
#define BITMAP_H

#define SIZE 100
#include <cstring>
#include "baseShape.h"

/*
实际画图发生的内存实体
*/
class Bitmap{
public:
    //画图实际发生的位置
    char bitmap [SIZE][SIZE];

    //初始化画布
    Bitmap(){memset(bitmap,'#',SIZE*SIZE);}
    
    //将像素实际画到画布上，暂时用命令行实现，后期用其他画图引擎
    bool drawPixels(std::vector<PixelI> pixels);
    
    //将当前画布上有的东西实际画出来
    bool doDraw();
    
    //清理画布
    bool clear(){memset(bitmap,'#',SIZE*SIZE);}

};
#endif