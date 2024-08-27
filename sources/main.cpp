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
    rectangle_t matrix1 = newRect(sizeX, sizeY);
    rectangle_t matrix2 = newRect(sizeX, sizeY);
    rectangle_t matsum  = newRect(sizeX, sizeY);

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
    fillRect(matrix1, (const int *)data1);
    fillRect(matrix2, (const int *)data2);

    printRectangle(matrix1);
    putchar('\n');

    printRectangle(matrix2);
    putchar('\n');

    matsum = sumRect(matrix1, matrix2);
    printRectangle(matsum);

    delRect(&matrix1);
    delRect(&matrix2);
    delRect(&matrix1);
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
