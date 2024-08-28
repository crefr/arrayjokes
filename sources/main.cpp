#include <stdio.h>
#include <assert.h>

#include "teamTable.h"
#include "rectangle.h"
#include "varlength.h"

int main()
{
    array_t arrayInt = {};
    arrayCtor(&arrayInt, sizeof(int), 20);
    int data[] = {2,5,6,48,4,5,4,5,1,8,5};
    fillArray(arrayInt, (void *)data, sizeof(data));
    printArray(arrayInt, "%d ");

    putchar('\n');

    size_t lens[] = {2,5,16,5};
    const int LENNUM = sizeof(lens) / sizeof(lens[0]);
    array_t arrayArrayInt = {};
    varlenCtor(&arrayArrayInt, sizeof(int), lens, LENNUM);
    fillVarlen(arrayArrayInt, (void *) data, sizeof(data));
    printVarlen(arrayArrayInt, "%d ");
    return 0;
}
