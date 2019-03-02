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

static void DetectCollision(int x, int y, obstacle* this)
{

    if(((x < (this->xPos + this->width)) && (x > this->xPos)) && ((y < this->yPos) && (y > (this->yPos - this->hight))))
    {
        int test = 2;
    } 
}

static void updateObstacle(obstacle* this, Snake* snake)
{
    int corners[2][4] = {
                        {snake->xPos,snake->yPos},                              //Buttom left corner
                        {snake->xPos + snake->size, snake->size},               //Buttom right corner
                        {snake->xPos, snake->yPos - snake->size},               //Top left corner
                        {snake->xPos+ snake->size, snake->yPos - snake->size}   //Top right corner
                        };
                        
	for(int c=0; c<4; ++c) 
    {
        DetectCollision(corners[1][c], corners[2][c], this);
    }
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