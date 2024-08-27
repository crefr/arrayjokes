#include <stdio.h>
#include <assert.h>

struct score_t
{
    int first, second;
};

void swapInts(int *a, int *b);
void fillVal(struct score_t *table, int team1, int team2, int val1, int val2);
struct score_t getVal(struct score_t *table, int team1, int team2);
void printTable(struct score_t *table, int num);
size_t getIndex(int team1, int team2);

const int TEAMCOUNT = 6;
const int TABLENUM = (TEAMCOUNT * (TEAMCOUNT - 1)) / 2;

int main()
{
    struct score_t teamTable[TABLENUM] = {};
    while (1)
    {
        int team1 = 0, team2 = 0, val1 = 0, val2 = 0;
        printf("Enter team1, team2, val1 and val2:\n");
        scanf("%d %d %d %d", &team1, &team2, &val1, &val2);

        fillVal(teamTable, team1, team2, val1, val2);
        printTable(teamTable, TEAMCOUNT);
    }
}

void fillVal(struct score_t *table, int team1, int team2, int val1, int val2)
{
    assert(table != NULL);
    if (team1 > team2)
        swapInts(&val1, &val2);
    size_t index = getIndex(team1, team2);
    table[index].first  = val1;
    table[index].second = val2;
}

struct score_t getVal(struct score_t *table, int team1, int team2)
{
    assert(table != NULL);
    size_t index = getIndex(team1, team2);
    return table[index];
}

size_t getIndex(int team1, int team2)
{
    if (team1 < team2)
        swapInts(&team1, &team2);
    return ((team1 * (team1 - 1)) / 2) + team2;
}

void printTable(struct score_t *table, int num)
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
                struct score_t temp = getVal(table, row, str);
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
