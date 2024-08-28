#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "varlength.h"

varlen_t varlenCtor(size_t* lenarray, size_t strnum)
{
    varlen_t varmat = {};
    varmat.strnum = strnum;
    varmat.lenarray = (size_t*) calloc(strnum, sizeof(size_t));
    varmat.matrix = (int**) calloc(strnum, sizeof(int *));
    memcpy(varmat.lenarray, lenarray, strnum * sizeof(size_t));

    for (size_t index = 0; index < strnum; index++)
        varmat.matrix[index] = (int *) calloc(lenarray[index], sizeof(int));
    return varmat;
}

void varlenDtor(varlen_t* varmat)
{
    assert(varmat != NULL);
    assert(varmat->matrix   != NULL);
    assert(varmat->lenarray != NULL);

    free(varmat -> matrix);
    free(varmat -> lenarray);

    varmat -> matrix   = NULL;
    varmat -> lenarray = NULL;
}

void printVarlen(varlen_t varmat)
{
    for (size_t arrn = 0; arrn < varmat.strnum; arrn++)
    {
        for (size_t index = 0; index < varmat.lenarray[arrn]; index++)
            printf("%d ", varmat.matrix[arrn][index]);
        putchar('\n');
    }
}
