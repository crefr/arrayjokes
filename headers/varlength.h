#ifndef VARLENGTH_INCLUDED
#define VARLENGTH_INCLUDED

typedef struct varlen
{
    int** matrix;
    size_t rownum;
    size_t* lenarray;
} varlen_t;

void varlenCtor(varlen_t* varmat, size_t* lenarray, size_t rownum);
void printVarlen(varlen_t varmat);
void varlenDtor(varlen_t* varmat);
void fillVarlen(varlen_t varmat, const int *data);

#endif
