#include <stdio.h>

int x, y;
char map[25][25];

void dfs()
{
    map[x][y] = '#';
    if (map[x + 1][y] == '.')
        ++x, dfs();
    else if (map[x - 1][y] == '.')
        --x, dfs();
    else if (map[x][y + 1] == '.')
        ++y, dfs();
    else if (map[x][y - 1] == '.')
        --y, dfs();
}

void getStart(int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        if (map[i][0] == '.')
        {
            x = i, y = 0; return;
        }
        else if (map[i][m] == '.')
        {
            x = i, y = m; return;
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (map[0][i] == '.')
        {
            x = 0, y = i; return;
        }
        else if (map[n][i] == '.')
        {
            x = n, y = i; return;
        }
    }
}

int main()
{
    int n, m;
    while (scanf(" %d %d", &n, &m) == 2)
    {
        getchar();
        for (int i = 0; i < n; i++)
            gets(map[i]);
        getStart(n - 1, m - 1);
        dfs();
        printf("%d %d\n", x + 1, y + 1);
    }
    return 0;
}