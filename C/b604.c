#include <stdio.h>
#include <stdlib.h>
#define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct node
{
    double x, y;
}Point;

Point pList[10000];

int cmp(const Point* lhs, const Point* rhs)
{
    return lhs->x - rhs->x;
}

int main()
{
    int n, pLen;
    char allPair;
    while (scanf(" %d", &n) == 1 && n)
    {
        Point midPoint = { 0 };
        pLen = 0, allPair = 1;
        for (int i = 0; i < n; i++)
        {
            scanf(" %lf %lf", &pList[pLen].x, &pList[pLen].y);
            midPoint.x += pList[pLen].x;
            midPoint.y += pList[pLen++].y;
        }
        midPoint.x /= n, midPoint.y /= n;
        for (int i = 0; i < n; i++)
            pList[i].x = ABS(pList[i].x - midPoint.x) + ABS(pList[i].y - midPoint.y);
        qsort(pList, n, sizeof(Point), cmp);
        for (int i = 1; i < n; i += 2)
        {
            if (pList[i].x != pList[i - 1].x)
            {
                allPair = 0;
                break;
            }
        }
        puts(allPair ? "yes" : "no");
    }
    return 0;
}