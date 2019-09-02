#include <stdio.h>

char map[110][110];

void dfs(int r, int c)
{
    if (map[r][c] == '+' || !map[r][c])
        return;
    map[r][c] = '+';
    dfs(r, c + 1);
    dfs(r + 1, c);
    dfs(r, c - 1);
    dfs(r - 1, c);
}

int main()
{
    int n, r, c;
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++)
        scanf(" %s", map[i] + 1);
    scanf(" %d %d", &r, &c);
    dfs(r + 1, c + 1);
    for (int i = 1; i <= n; i++)
        puts(map[i] + 1);
    return 0;
}