typedef struct tObstacle 
{
    int xPos;   // bas position is for buttom left corner
    int yPos;
    
    int width;
    int hight;
    
    void (*update)(struct tObstacle*);
    void (*render)(struct tObstacle*);
} obstacle;

extern obstacle obsticals[];
extern unsigned int nObsticals;