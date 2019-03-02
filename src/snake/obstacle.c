#include <obstacle.h>
#include "snake.h"
#include "graphics.h"

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

static void updateObstacle(obstacle* this, Snake* snake)
{
	
}

void updateObstacles(Snake* snake)
{
	for(int i=0; i<nObsticals; ++i)
    {
        obstacles[i].update(&obstacles[i], snake);
    }
}

void initObstecle(obstacle *current)
{
    //64 32 to place in middle of screen.
    current->xPos=64;
    current->yPos = 32;
    current->render = render;
	current->update = updateObstacle;
    current->width = 8;
    current->hight = 16;
} 

void createObstecle()
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