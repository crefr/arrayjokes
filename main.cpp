#include <stdio.h>

void swapInts(int *a, int *b);
void fillVal(int *table, int team1, int team2, int val);
int getVal(int *table, int team1, int team2);
void printTable(int *table, int num);
size_t getIndex(int team1, int team2);

const int TEAMCOUNT = 6;
const int TABLENUM = (TEAMCOUNT * (TEAMCOUNT - 1)) / 2;

int main()
{
    int teamTable[TABLENUM] = {};
    while (1)
    {
        int team1 = 0, team2 = 0, val = 0;
        printf("Enter team1, team2 and val:\n");
        scanf("%d %d %d", &team1, &team2, &val);

        fillVal(teamTable, team1, team2, val);
        printTable(teamTable, TEAMCOUNT);
    }
}

void fillVal(int *table, int team1, int team2, int val)
{
    size_t index = getIndex(team1, team2);
    table[index] = val;
}

int getVal(int *table, int team1, int team2)
{
    size_t index = getIndex(team1, team2);
    return table[index];
}

size_t getIndex(int team1, int team2)
{
    if (team1 < team2)
        swapInts(&team1, &team2);
    return ((team1 * (team1 - 1)) / 2) + team2;
}

void printTable(int *table, int num)
{
    printf("  ");
    for (int i = 0; i < num; i++)
        printf("%d ", i);

    putchar('\n');
    for (int str = 0; str < num; str++)
    {
        printf("%d ", str);
        for (int row = 0; row < num; row++)
        {
            if (row >= str)
                printf("x ");
            else
                printf("%d ", getVal(table, row, str));
        }
        putchar('\n');
    }
}

void swapInts(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
