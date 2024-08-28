#include <stdio.h>
#include <assert.h>

#include "teamTable.h"
#include "rectangle.h"
#include "varlength.h"

int main()
{
    size_t lens[] = {1,5,8,3};
    const size_t LENNUM = sizeof(lens) / sizeof(lens[0]);

    varlen_t var = {};
    varlenCtor(&var, lens, LENNUM);
    printVarlen(var);

    varlenDtor(&var);
    return 0;
}
