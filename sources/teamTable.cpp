#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "teamTable.h"

void teamFillVal(struct score_t *table, int team1, int team2, int val1, int val2)
{
    assert(table != NULL);
    if (team1 > team2)
        swapInts(&val1, &val2);
    size_t index = teamGetIndex(team1, team2);
    table[index].first  = val1;
    table[index].second = val2;
}

struct score_t teamGetVal(struct score_t *table, int team1, int team2)
{
    assert(table != NULL);
    size_t index = teamGetIndex(team1, team2);
    return table[index];
}

size_t teamGetIndex(int team1, int team2)
{
    if (team1 < team2)
        swapInts(&team1, &team2);
    return ((team1 * (team1 - 1)) / 2) + team2;
}

void printTeamTable(struct score_t *table, int num)
{
    assert(table != NULL);
    printf("  ");
    for (int i = 0; i < num; i++)
        printf(" %d  ", i);

    putchar('\n');
    for (int str = 0; str < num; str++)
    {
        printf("%d ", str);
        for (int row = 0; row < num; row++)
        {
            if (row >= str)
                printf(" x  ");
            else
            {
                struct score_t temp = teamGetVal(table, row, str);
                printf("%d:%d ", temp.first, temp.second);
            }
        }
        putchar('\n');
    }
}

void swapInts(int *a, int *b)
{
    assert(a != NULL);
    assert(b != NULL);
    int c = *a;
    *a = *b;
    *b = c;
}

