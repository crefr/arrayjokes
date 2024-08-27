#ifndef RECTANGLE_INCLUDED
#define RECTANGLE_INCLUDED

typedef struct rectangle
{
    int *matrix;
    size_t sizeX;
    size_t sizeY;
} rectangle_t;

void printRectangle(rectangle_t rect);
rectangle_t rectCtor(size_t sizeX, size_t sizeY);
void rectDtor(rectangle_t *rect);
rectangle_t sumRect(rectangle_t mat1, rectangle_t mat2);
rectangle_t multRect(rectangle_t mat1, rectangle_t mat2);
void fillRect(rectangle_t rect1, const int *data);
int *rectVal(rectangle_t rect, size_t x, size_t y);
long long int determinator(rectangle_t rect);


#endif
