#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

#include "varlength.h"

void arrayCtor(array_t *arr, size_t elsize, size_t len)
{
    assert(arr != NULL);

    arr->len = len;
    arr->element_size = elsize;
    arr->array = calloc(len, elsize);
}

void arrayDtor(array_t *arr)
{
    free(arr->array);
    arr->array = NULL;
}

void *arrayGetElement(array_t arr, size_t index)
{
    return (void *) ((size_t) (arr.array) + index * arr.element_size);
}

void printArray(array_t arr, const char *printflag)
{
    for(size_t index = 0; index < arr.len; index++)
        ptrprintf(printflag, (void *)((size_t)arr.array + index * arr.element_size));
    putchar('\n');
}

void fillArray(array_t arr, void *data, size_t size)
{
    assert(data != NULL);
    memcpy(arr.array, data, size);
}

void varlenCtor(array_t* varmat, size_t elsize, size_t* lenarray, size_t rownum)
{
    assert(varmat   != NULL);
    assert(lenarray != NULL);

    varmat->len           = rownum;
    varmat->element_size  = sizeof(array_t);
    varmat->array         = calloc(rownum, sizeof(array_t));

    for (size_t rowindex = 0; rowindex < rownum; rowindex++)
    {
        array_t *ptr = ((array_t *)(varmat->array)) + rowindex;
        arrayCtor(ptr, elsize, lenarray[rowindex]);
    }
}

void varlenDtor(array_t* varmat)
{
    assert(varmat != NULL);
    assert(varmat->array != NULL);

    for (size_t rowIndex = 0; rowIndex < varmat->len; rowIndex++)
    {
        array_t *ptr = (array_t *)(((array_t *)(varmat->array)) + rowIndex)->array;
        arrayDtor(ptr);
    }
    arrayDtor(varmat);
}

void fillVarlen(array_t arr, void *data, size_t size)
{
    for (size_t row = 0; row < arr.len; row++)
    {
        array_t rowarr = *((array_t *)arrayGetElement(arr, row));
        printf("%llu\n", rowarr.len);

        size_t possize = rowarr.len * rowarr.element_size;
        if (size > possize)
        {
            fillArray(rowarr, data, possize);
            data = (void *) ((size_t)data + possize);
            size -= possize;
        }
        else
        {
            fillArray(rowarr, data, size);
            return;
        }
    }
}

// void fillVarlen(varlen_t varmat, const int *data)
// {
//     assert(data != NULL);
//     size_t index = 0;
//     for (size_t row = 0; row < varmat.rownum; row++)
//         for (size_t rowindex = 0; rowindex < varmat.matrix[row].len; rowindex++, index++)
//             varmat.matrix[row].array[rowindex] = data[index];
// }
//
void printVarlen(array_t varmat, const char *printflag)
{
    for (size_t arrn = 0; arrn < varmat.len; arrn++)
        printArray( ((array_t *)(varmat.array))[arrn], printflag);
}

void ptrprintf(const char *format, ...)
{
    assert(format != NULL);
    va_list ap;
    va_start(ap, format);

    const char *p;
    int lflag = 0;
    for (p = format; *p != '\0'; p++)
    {
        if(*p != '%' && !lflag)
        {
            putchar(*p);
            continue;
        }

        if (lflag)
            lflag = 0;
        else
            p++;

        switch(*p)
        {
            case 'l':
                lflag = 1;
                break;
            case 'd':
                printf("%d", *va_arg(ap, int*));
                break;
            case 'f': case 'g':
                printf("%lg", *va_arg(ap, double*));
                break;
            case 's':
                printf("%s", *va_arg(ap, char**));
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}
