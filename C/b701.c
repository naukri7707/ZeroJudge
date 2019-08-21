#include <stdio.h>

int map[515][515], x, y, r, l, u, d, a;

void dfs(int y, int x)
{
    a++;
    map[y][x] = 0;
    if (map[y][x - 1])
    {
        dfs(y, x - 1);
        if (l > x - 1)
            l = x - 1;
    }
    if (map[y][x + 1])
    {
        dfs(y, x + 1);
        if (r < x + 1)
            r = x + 1;
    }
    if (map[y + 1][x])
    {
        dfs(y + 1, x);
        if (d < y + 1)
            d = y + 1;
    }
    if (map[y - 1][x])
    {
        dfs(y - 1, x);
        if (u > y - 1)
            u = y - 1;
    }
}

int main()
{
    while (scanf(" %d %d", &x, &y) == 2)
    {
        for (int i = 1; i <= y; i++)
        {
            for (int j = 1; j <= x; j++)
                scanf(" %d", &map[i][j]);
        }
        for (int i = 1; i <= y; i++)
        {
            for (int j = 1; j <= x; j++)
            {
                if (map[i][j])
                {
                    l = j, u = i, r = j, d = i, a = 0;
                    map[i][j] = 0;
                    dfs(i, j);
                    printf("%d %d %d %d %d\n", l - 1, u - 1, r - 1, d - 1, a);
                }
            }
        }
    }
    return 0;
}