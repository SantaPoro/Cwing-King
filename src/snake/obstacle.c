#include <obstacle.h>

obstacle obstacles[10];
unsigned int nObsticals = 0;

static void render(obstacle *this)
{
    int h = 0;
    for(;h<this->hight; ++h) 
    {
        for(int w=0; w<this->width; ++w) 
        {
            setPixel(this->xPos+w,this->yPos+h,1);   
        }
    }

}

void initObstecle(obstacle *current)
{
    //64 32 to place in middle of screen.
    current->xPos=64;
    current->yPos = 32;
    current->render = render;
    current->width = 8;
    current->hight = 16;
} 

obstacle createObstecle()
{
    initObstecle(&obstacles[nObsticals++]);
}

void obstaclesRender()
{
    for(int i=0; i<nObsticals; ++i)
    {
        obstacles[i].render(&obstacles[i]);
    }

}