#ifndef VARLENGTH_INCLUDED
#define VARLENGTH_INCLUDED

typedef struct varlen
{
    int** matrix;
    size_t rownum;
    size_t* lenarray;
} varlen_t;

varlen_t varlenCtor(size_t* lenarray, size_t strnum);
void printVarlen(varlen_t varmat);
void varlenDtor(varlen_t* varmat);

#endif
