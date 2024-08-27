#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "rectangle.h"

rectangle_t newRect(size_t sizeX, size_t sizeY)
{
    rectangle_t rect = {};
    int *pointer = (int *)calloc(sizeX * sizeY, sizeof(int));
    rect.matrix = pointer;
    rect.sizeX  = sizeX;
    rect.sizeY  = sizeY;

    return rect;
}

void delRect(rectangle_t *rect)
{
    assert(rect != NULL);
    free(rect -> matrix);
    rect -> matrix = NULL;
}

void printRectangle(rectangle_t rect)
{
    for (size_t y = 0; y < rect.sizeY; y++)
    {
        for (size_t x = 0; x < rect.sizeX; x++)
            printf("%d ", *(rect.matrix + rect.sizeX * y + x));
    printf("\n");
    }
}

rectangle_t sumRect(rectangle_t mat1, rectangle_t mat2)
{
    assert(mat1.sizeX == mat2.sizeX);
    assert(mat1.sizeY == mat2.sizeY);

    assert(mat1.matrix != NULL);
    assert(mat2.matrix != NULL);

    rectangle_t summat = newRect(mat1.sizeX, mat1.sizeY);
    for (size_t y = 0; y < summat.sizeY; y++)
        for (size_t x = 0; x < summat.sizeX; x++)
            summat.matrix[y * summat.sizeX + x] = mat1.matrix[y * summat.sizeX + x] + mat2.matrix[y * summat.sizeX + x];
    return summat;
}

void fillRect(rectangle_t rect1, const int *data)
{
    assert(data != NULL);
    for (size_t index = 0; index < rect1.sizeX * rect1.sizeY; index++)
        rect1.matrix[index] = data[index];
}



