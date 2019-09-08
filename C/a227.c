#include <stdio.h>

int n, count;
char list[100];

void dfs(int lv, char to)
{
    for (int i = lv; i; i--)
    {
        if (list[i] != to)
        {
            dfs(i - 1, 198 - list[i] - to);
            printf("Move ring %d from %c to %c\n", i, list[i], to);
            list[i] = to;
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
            list[i] = 'A';
        dfs(n, 'C');
        putchar('\n');
    }
    return 0;
}