#ifndef TEAMTABLE_INCLUDED
#define TEAMTABLE_INCLUDED

struct score_t
{
    int first, second;
};

void teamFillVal(struct score_t *table, int team1, int team2, int val1, int val2);
struct score_t teamGetVal(struct score_t *table, int team1, int team2);
void printTeamTable(struct score_t *table, int num);
size_t teamGetIndex(int team1, int team2);
void swapInts(int *a, int *b);

#endif
