#include <stdio.h>
#include <stdlib.h>
#define MAX 500000

typedef struct Point
{
    int x, y;
} Point;

Point list[MAX];

int cmp(const Point* lhs, const  Point* rhs)
{
    return (*rhs).x != (*lhs).x ? (*rhs).x - (*lhs).x : (*rhs).y - (*lhs).y;
}

int main() 
{
    int n, len, yMax;
    for (int kase = 1; scanf(" %d", &n) == 1; kase++)
    {
        for (int i = 0; i < n; i++)
            scanf(" %d %d", &list[i].x, &list[i].y);
        qsort(list, n, sizeof(Point), cmp);
        yMax = list[0].y, len = 1;
        for (int i = 1; i < n; i++)
        {
            if (list[i].y > yMax)
            {
                list[len++] = list[i];
                yMax = list[i].y;
            }
        }
        printf("Case %d:\nDominate Point: %d\n", kase, len);
        for (int i = len - 1; ~i; i--)
            printf("(%d,%d)\n", list[i].x, list[i].y);
    }
    return 0;
}