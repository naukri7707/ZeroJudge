#include <stdio.h>

typedef struct Node
{
    int User, Time;
} Toilet;

int n, a, b;
Toilet list[22];

inline char serchToilet()
{
    for (int i = 1; i <= n; i++)
    {
        if (list[i].User) continue;
        for (int j = i; j <= n; j++)
        {
            if (!list[j - 1].User && !list[j].User && !list[j + 1].User)
            {
                list[j].User = a;
                list[j].Time = b;
                return 1;
            }
        }
        list[i].User = a;
        list[i].Time = b;
        return 1;
    }
    return 0;
}

int main()
{
    scanf(" %d", &n);
    while (scanf(" %d %d", &a, &b) == 2)
    {
        if (!serchToilet())
            puts("  Not enough");
        printf("Number:");
        for (int i = 1; i <= n; i++)
            printf(" %d", list[i].User);
        printf("\n  Time:");
        for (int i = 1; i <= n; i++)
        {
            printf(" %d", list[i].Time);

            if (list[i].Time < 2)
                list[i].User = list[i].Time = 0;
            else 
                list[i].Time--;
        }
        putchar('\n');
    }
    return 0;
}