#include <stdio.h>
#include <assert.h>

#include "teamTable.h"

const int TEAMCOUNT = 6;
const int TABLENUM = (TEAMCOUNT * (TEAMCOUNT - 1)) / 2;

void teams();

int main()
{
    teams();
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
