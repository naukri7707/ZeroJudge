#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct node
{
    int x, y;
}Point;

Point list[MAX], * sort[MAX];

int cmp(const Point** lhs, const Point** rhs)
{
    return (*lhs)->x == (*rhs)->x ? (*lhs)->y - (*rhs)->y : (*lhs)->x - (*rhs)->x;
}

int main()
{
    for (int i = 0; i < MAX; i++)
        sort[i] = &list[i];
    int n;
    while (scanf(" %d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
            scanf(" %d %d", &list[i].x, &list[i].y);
        qsort(sort, n, sizeof(Point*), cmp);
        for (int i = 0; i < n; i++)
            printf("%d %d\n", sort[i]->x, sort[i]->y);
    }
    return 0;
}