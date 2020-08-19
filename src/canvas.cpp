#include "canvas.h"
Canvas* Canvas::instancePtr = nullptr;
bool Canvas::draw(BaseShape* shape) 
{
    return bitmap.drawPixels(shape->draw()) && bitmap.doDraw();
}

Canvas& Canvas::getInstance() 
{
    if(instancePtr==nullptr) instancePtr = new Canvas();
    return *instancePtr;
}
