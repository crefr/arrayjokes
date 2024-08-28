#include <stdio.h>

#include "printSomething.h"

void printInt(void* val)
{
    printf("%d ", *((int*)val));
}

void printDouble(void* val)
{
    printf("%lg ", *((double*)val));
}

void printFloat(void* val)
{
    printf("%f ", *((float*)val));
}

void printChar(void* val)
{
    printf("%c ", *((char*)val));
}

void printString(void* val)
{
    printf("%s ", *((char**)val));
}
