#include "bitmap.h"
#include <cstdio>
bool Bitmap::drawPixels(std::vector<PixelI> pixels) 
{
    for(auto it = pixels.begin();it!=pixels.end();it++){
        bitmap[(*it).x][(*it).y] = [&]()->char{return (*it).c==RED?'&':'#';}();
    }
    return true;
}

bool Bitmap::doDraw() 
{
    printf("\n");
    for (int i = 0; i<SIZE; i++){
        for (int j = 0;j<SIZE;j++){
            printf("%c",bitmap[i][j]);
        }
        printf("\n");
    }
    return true;
}

