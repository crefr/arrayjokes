#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "rectangle.h"

rectangle_t rectCtor(size_t sizeX, size_t sizeY)
{
    rectangle_t rect = {};
    int *pointer = (int *)calloc(sizeX * sizeY, sizeof(int));
    rect.matrix = pointer;
    rect.sizeX  = sizeX;
    rect.sizeY  = sizeY;

    return rect;
}

void rectDtor(rectangle_t *rect)
{
    assert(rect != NULL);
    free(rect -> matrix);
    rect -> matrix = NULL;
}

void fillRect(rectangle_t rect1, const int *data)
{
    assert(data != NULL);
    for (size_t index = 0; index < rect1.sizeX * rect1.sizeY; index++)
        rect1.matrix[index] = data[index];
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

int *rectVal(rectangle_t rect, size_t x, size_t y)
{
    assert(x < rect.sizeX);
    assert(y < rect.sizeY);
    return rect.matrix + rect.sizeX * y + x;
}

rectangle_t sumRect(rectangle_t mat1, rectangle_t mat2)
{
    assert(mat1.sizeX == mat2.sizeX);
    assert(mat1.sizeY == mat2.sizeY);

    assert(mat1.matrix != NULL);
    assert(mat2.matrix != NULL);

    rectangle_t summat = rectCtor(mat1.sizeX, mat1.sizeY);
    for (size_t y = 0; y < summat.sizeY; y++)
        for (size_t x = 0; x < summat.sizeX; x++)
            summat.matrix[y * summat.sizeX + x] = mat1.matrix[y * summat.sizeX + x] + mat2.matrix[y * summat.sizeX + x];
    return summat;
}

rectangle_t multRect(rectangle_t mat1, rectangle_t mat2)
{
    assert(mat1.sizeX == mat2.sizeY);
    assert(mat1.matrix != NULL);
    assert(mat2.matrix != NULL);

    size_t len = mat1.sizeX; // = mat2.sizeY
    rectangle_t multrect = rectCtor(mat2.sizeX, mat1.sizeY);
    for (size_t resY = 0; resY < multrect.sizeY; resY++)
        for (size_t resX = 0; resX < multrect.sizeX; resX++)
            for (size_t now = 0; now < len; now++)
                *rectVal(multrect, resX, resY) += *rectVal(mat1, now, resY) * *rectVal(mat2, resX, now);
    return multrect;
}




