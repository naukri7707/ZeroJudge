#include <stdio.h>
#include <math.h>

typedef struct Point
{
    int X, Y;
}Point;

Point list[1010], ans;

int main()
{
    double best, tmp;
    int n;
    while (scanf(" %d", &n) == 1)
    {
        best = 0;
        for (int i = 0; i < n; i++)
        {
            scanf(" %d %d", &list[i].X, &list[i].Y);
            for (int j = 0; j < i; j++)
            {
                tmp = sqrt((list[i].X - list[j].X) * (list[i].X - list[j].X) + (list[i].Y - list[j].Y) * (list[i].Y - list[j].Y));
                if (best < tmp)
                {
                    best = tmp;
                    ans.X = j;
                    ans.Y = i;
                }
            }
        }
        printf("%d %d\n", ans.X, ans.Y);
    }
    return 0;
}