#ifndef VARLENGTH_INCLUDED
#define VARLENGTH_INCLUDED

typedef struct array
{
    void *array;
    size_t len;
    size_t element_size;
} array_t;

//typedef struct varlen
//{
//    array_t *matrix;
//    size_t rownum;
//} varlen_t;

void arrayCtor(array_t *arr, size_t elsize, size_t len);
void arrayDtor(array_t *arr);
void printArray(array_t arr, const char *printflag);
void fillArray(array_t arr, void *data, size_t size);
void *arrayGetElement(array_t arr, size_t index);

void varlenCtor(array_t* varmat, size_t elsize, size_t* lenarray, size_t rownum);
void varlenDtor(array_t* varmat);
void printVarlen(array_t varmat, const char *printflag);
void fillVarlen(array_t arr, void *data, size_t size);

void ptrprintf(const char *format, ...);
// void fillVarlen(varlen_t varmat, const int *data);
// void arrayCtor(array_t *arr, size_t elsize, size_t len);
// void varlenCtor(varlen_t* varmat, size_t* lenarray, size_t rownum);

#endif
