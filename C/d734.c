#include <stdio.h>

int n, count, tmp;
char now[25], end[25];

void dfs(int lv, char to)
{
    for (int i = lv; i; i--)
    {
        if (lv == n)
            to = end[i];
        if (now[i] != to)
        {
            dfs(i - 1, 294 - now[i] - to);
            printf("ring %d : %c -> %c\n", i, now[i], to);
            now[i] = to;
            count++;
        }
    }
}

int main()
{
    while (scanf(" %d", &n) == 1)
    {
        count = 0;
        for (int i = 1; i <= n; i++)
            scanf(" %d", &tmp), now[i] = tmp + 96;
        for (int i = 1; i <= n; i++)
            scanf(" %d", &tmp), end[i] = tmp + 96;
        dfs(n, 0);
        printf("%d\n", count);
    }
    return 0;
}