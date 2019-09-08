#include <stdio.h>

int n, count;
char list[100];

void dfs(int lv, char to)
{
    for (int i = lv; i; i--)
    {
        if (lv == n)
            to = i & 1 ? 'b' : 'c';
        if (list[i] != to)
        {
            dfs(i - 1, 294 - list[i] - to);
            printf("ring %d : %c -> %c\n", i, list[i], to);
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
            list[i] = 'a';
        dfs(n, '?');
        printf("共移動了 %d 步\n", count);
    }
    return 0;
}