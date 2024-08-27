#include <stdio.h>
#include <assert.h>

#include "teamTable.h"
#include "rectangle.h"

const int TEAMCOUNT = 6;
const int TABLENUM = (TEAMCOUNT * (TEAMCOUNT - 1)) / 2;

const int sizeX = 3;
const int sizeY = 2;

void teams();

int main()
{
    rectangle_t matrix1 = rectCtor(sizeX, sizeY);
    rectangle_t matrix2 = rectCtor(sizeX, sizeY);
    rectangle_t matrix3 = rectCtor(sizeY, sizeX);
    const int data1[][3] =
        {
            {1,2,3},
            {4,5,6}
        };
    const int data2[][3] =
        {
            {3,3,3},
            {4,5,6}
        };
    const int data3[][2] =
        {
            {3,3},
            {4,5},
            {6,7}
        };
    fillRect(matrix1, (const int *)data1);
    fillRect(matrix2, (const int *)data2);
    fillRect(matrix3, (const int *)data3);

    printRectangle(matrix1);
    putchar('\n');

    printRectangle(matrix2);
    putchar('\n');

    printRectangle(matrix3);
    putchar('\n');

    rectangle_t matsum = sumRect(matrix1, matrix2);
    printRectangle(matsum);
    putchar('\n');

    rectangle_t matmult = multRect(matrix2, matrix3);
    printRectangle(matmult);
    putchar('\n');

    rectDtor(&matrix1);
    rectDtor(&matrix2);
    rectDtor(&matrix3);
    rectDtor(&matsum);
    rectDtor(&matmult);
    return 0;
}

void teams()
{
    struct score_t teamTable[TABLENUM] = {};
    while (1)
    {
        int team1 = 0, team2 = 0, val1 = 0, val2 = 0;
        printf("Enter team1, team2, val1 and val2:\n");
        scanf("%d %d %d %d", &team1, &team2, &val1, &val2);

        teamFillVal(teamTable, team1, team2, val1, val2);
        printTeamTable(teamTable, TEAMCOUNT);
    }
}
