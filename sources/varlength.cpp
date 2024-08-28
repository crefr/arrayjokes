#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "varlength.h"

void varlenCtor(varlen_t* varmat, size_t* lenarray, size_t rownum)
{
    assert(varmat   != NULL);
    assert(lenarray != NULL);

    varmat->rownum = rownum;
    varmat->lenarray = (size_t*) calloc(rownum, sizeof(size_t));
    varmat->matrix = (int**) calloc(rownum, sizeof(int *));
    memcpy(varmat->lenarray, lenarray, rownum * sizeof(size_t));

    for (size_t index = 0; index < rownum; index++)
        varmat->matrix[index] = (int *) calloc(lenarray[index], sizeof(int));
}

void varlenDtor(varlen_t* varmat)
{
    assert(varmat != NULL);
    assert(varmat->matrix   != NULL);
    assert(varmat->lenarray != NULL);

    for (size_t rowIndex = 0; rowIndex < varmat -> rownum; rowIndex++)
    {
        free(varmat -> matrix[rowIndex]);
        varmat -> matrix[rowIndex] = NULL;
    }

    free(varmat -> matrix);
    free(varmat -> lenarray);

    varmat -> matrix   = NULL;
    varmat -> lenarray = NULL;
}

void fillVarlen(varlen_t varmat, const int *data)
{
    size_t index = 0;
    for (size_t row = 0; row < varmat.rownum; row++)
        for (size_t rowindex = 0; rowindex < varmat.lenarray[row]; rowindex++, index++)
            varmat.matrix[row][rowindex] = data[index];
}

void printVarlen(varlen_t varmat)
{
    for (size_t arrn = 0; arrn < varmat.rownum; arrn++)
    {
        for (size_t index = 0; index < varmat.lenarray[arrn]; index++)
            printf("%d ", varmat.matrix[arrn][index]);
        putchar('\n');
    }
}
