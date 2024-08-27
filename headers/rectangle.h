#ifndef RECTANGLE_INCLUDED
#define RECTANGLE_INCLUDED

typedef struct rectangle
{
    int *matrix;
    size_t sizeX;
    size_t sizeY;
} rectangle_t;

void printRectangle(rectangle_t rect);
rectangle_t newRect(size_t sizeX, size_t sizeY);
void delRect(rectangle_t *rect);
rectangle_t sumRect(rectangle_t mat1, rectangle_t mat2);
void fillRect(rectangle_t rect1, const int *data);

#endif
