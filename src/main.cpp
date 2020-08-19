#include <cstdio>
#include <cstdlib>

#include"baseShape.h"
#include"line.h"
#include"canvas.h"

int main(){
    Canvas& canvas = Canvas::getInstance();
    char input;
    BaseShape* shape = nullptr;
    srand((int)time(0));
    while((input = getchar())!='e'){
        printf("\nthis is a 2D single_thread drawing board\n");
        switch (input)
        {
        case 'l':
            shape = new Line(rand()%SIZE,rand()%SIZE,rand()%SIZE,rand()%SIZE);
            break;
        default:
            break;
        }
        canvas.draw(shape);
    }
    return 0;
}