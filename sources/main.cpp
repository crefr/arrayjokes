#include <stdio.h>
#include <assert.h>

#include "teamTable.h"
#include "rectangle.h"
#include "varlength.h"

int main()
{
    size_t lens[] = {1,5,8,3};
    const int data[17] = {1,5,3,4,8,8,4,8,54,8,584,4,5,9,8,6,666};
    const size_t LENNUM = sizeof(lens) / sizeof(lens[0]);

    varlen_t var = {};
    varlenCtor(&var, lens, LENNUM);
    fillVarlen(var, data);
    printVarlen(var);

    varlenDtor(&var);
    return 0;
}
