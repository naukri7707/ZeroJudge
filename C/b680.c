#include <stdio.h>
#include <stdlib.h>
#define MAX 210

typedef struct Node
{
    int Num;
    double Record;
}Runner;

Runner list[MAX];

int cmp(const Runner* lhs, const Runner* rhs)
{
    return lhs->Record > rhs->Record ? 1 : -1;
}

int main()
{
    int n, g, g2, g4, g6, g8;
    while (scanf(" %d", &n) == 1)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d %lf", &list[i].Num, &list[i].Record);
        qsort(list + 1, n, sizeof(Runner), cmp);
        g = n >> 3, g2 = g << 1, g4 = g << 2, g6 = g2 + g4, g8 = n;
        for (int i = 1; i <= g; i++)
        {
            printf("%d %d %d %d %d %d %d %d %d\n", i, list[g6 + i].Num, list[g4 + i].Num, list[g2 + i].Num, list[i].Num,
                list[g2 + 1 - i].Num, list[g4 + 1 - i].Num, list[g6 + 1 - i].Num, list[g8 + 1 - i].Num);
        }
    }
    return 0;
}